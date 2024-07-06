// simulator.cpp - Main thread

// This file contains simulator(), the top-level entry point of the simulator.
// simulator() is called from main.cpp with a copy of argc and argv.
// If there is no command line argument, the simulator will read the default
// config file ("biosim4.ini" in the current directory) to get the simulation
// parameters for this run. If there are one or more command line args, then
// argv[1] must contain the name of the config file which will be read instead
// of biosim4.ini. Any args after that are ignored. The simulator code is
// in namespace BS (for "biosim").

#include <iostream>
#include <omp.h>
#include <unistd.h>
#include "simulator.h"     // the simulator data structures
#include "imageWriter.h"   // this is for generating the movies
#include <QPromise>
#include <QDebug>

#include "zlib.h"
#include <fstream>

namespace BS {

extern void initializeGeneration0();
extern unsigned spawnNewGeneration(unsigned generation, unsigned murderCount);
extern void displaySampleGenomes(unsigned count);
extern void executeActions(Indiv &indiv, std::array<float, Action::NUM_ACTIONS> &actionLevels);
extern void endOfSimStep(unsigned simStep, unsigned generation);
extern void endOfGeneration(unsigned generation);

RunMode runMode = RunMode::STOP;
Grid grid;        // The 2D world where the creatures live
Signals pheromoneSignals;  // A 2D array of pheromones that overlay the world grid
Peeps peeps;      // The container of all the individuals in the population
ImageWriter imageWriter; // This is for generating the movies

// Declare shared variables
bool paused = false;

QString globalFilename;

bool instanceRunning =false;
QFuture<void> future;

// The paramManager maintains a private copy of the parameter values, and a copy
// is available read-only through global variable p. Although this is not
// foolproof, you should be able to modify the config file during a simulation
// run and modify many of the parameters. See params.cpp and params.h for more info.
ParamManager paramManager;
const Params &p { paramManager.getParamRef() }; // read-only params

BiosimRunner*runner;
/**********************************************************************************************
Execute one simStep for one individual.

This executes in its own thread, invoked from the main simulator thread. First we execute
indiv.feedForward() which computes action values to be executed here. Some actions such as
signal emission(s) (pheromones), agent movement, or deaths will have been queued for
later execution at the end of the generation in single-threaded mode (the deferred queues
allow the main data structures (e.g., grid, signals) to be freely accessed read-only in all threads).

In order to be thread-safe, the main simulator-wide data structures and their
accessibility are:

    grid - read-only
    signals - (pheromones) read-write for the location where our agent lives
        using signals.increment(), read-only for other locations
    peeps - for other individuals, we can only read their index and genome.
        We have read-write access to our individual through the indiv argument.

The other important variables are:

    simStep - the current age of our agent, reset to 0 at the start of each generation.
         For many simulation scenarios, this matches our indiv.age member.
    randomUint - global random number generator, a private instance is given to each thread
**********************************************************************************************/
void simStepOneIndiv(Indiv &indiv, unsigned simStep)
{
    ++indiv.age; // for this implementation, tracks simStep
    auto actionLevels = indiv.feedForward(simStep);
    executeActions(indiv, actionLevels);
}


/********************************************************************************
Start of simulator

All the agents are randomly placed with random genomes at the start. The outer
loop is generation, the inner loop is simStep. There is a fixed number of
simSteps in each generation. Agents can die at any simStep and their corpses
remain until the end of the generation. At the end of the generation, the
dead corpses are removed, the survivors reproduce and then die. The newborns
are placed at random locations, signals (pheromones) are updated, simStep is
reset to 0, and a new generation proceeds.

The paramManager manages all the simulator parameters. It starts with defaults,
then keeps them updated as the config file (biosim4.ini) changes.

The main simulator-wide data structures are:
    grid - where the agents live (identified by their non-zero index). 0 means empty.
    signals - multiple layers overlay the grid, hold pheromones
    peeps - an indexed set of agents of type Indiv; indexes start at 1

The important simulator-wide variables are:
    generation - starts at 0, then increments every time the agents die and reproduce.
    simStep - reset to 0 at the start of each generation; fixed number per generation.
    randomUint - global random number generator

The threads are:
    main thread - simulator
    simStepOneIndiv() - child threads created by the main simulator thread
    imageWriter - saves image frames used to make a movie (possibly not threaded
        due to unresolved bugs when threaded)
********************************************************************************/

void initSimulator(){

}

void setSimulatorParams(const Params &params){

}

void runSimulation(QString filename, BiosimRunner*bioRunner){

    if(!instanceRunning){
        //qDebug()<<filename;
        instanceRunning =true;
        globalFilename=filename;
        runMode=RunMode::RUN;
        paused=false;
        runner=bioRunner;
        future = QtConcurrent::run(BS::simulator,2,filename);
    }
}

void pauseSimulation() {
    // {
    //     std::lock_guard<std::mutex> lock(pauseMutex);
    //     paused = true;
    // }
    // pauseCondVar.notify_all();
    if(instanceRunning){
        if(paused==false){
            paused=true;
            future.setSuspended(paused);
            emit runner->loggerUpdated("Simulator Paused");
        }
    }
}

void resumeSimulation() {
    // shouldResume.store(true, std::memory_order_relaxed);
    // pauseCondVar.notify_all();
    if(instanceRunning){
        if(paused==true){
            paused=false;
            future.setSuspended(paused);
            emit runner->loggerUpdated("Simulator Resumed");
        }
    }
}

void resetSimulation() {
    if(instanceRunning){
        //Version: 1
        // first, we suspend what is going on
        // if(paused==false){
        //     paused=true;
        //     future.setSuspended(paused);
        // }
        // usleep(500);
        // future.cancel();
        // future.waitForFinished();

        // // qDebug()<<"Sleep 5s";
        // // usleep(5000);

        // if(future.isCanceled() && future.isFinished()){
        //     paused=false;
        //     future = QtConcurrent::run(BS::simulator,2,globalFilename);
        // }

        //Version: 2
        if(paused==false){
            paused=true;
            future.setSuspended(paused);
            emit runner->loggerUpdated("Simulator Paused");
        }

        future.cancel();

        future.waitForFinished();
        instanceRunning=false;
        if(future.isCanceled() && future.isFinished()){
            future = QtConcurrent::run(BS::simulator,2,globalFilename);
            paused=false;
            emit runner->loggerUpdated("Simulator Reset");
        }
    }
}

void exitSimulation() {
    // shouldExit.store(true, std::memory_order_relaxed);
    // pauseCondVar.notify_all();
    if(instanceRunning){
        // if(paused==false){
        //     paused=true;
        //     future.setSuspended(paused);

        //     do {
        //         if(future.isSuspended()){
        //             break;
        //         }
        //     }while(future.isSuspending());
        // }else if(future.isSuspended()){
        //     paused=false;
        // }

        // {
        //     QFuture<void> *tmp = &future;
        //     tmp = NULL;
        // }

        future.cancel();
        future.waitForFinished();
        emit runner->generationUpdated(0);
        emit runner->stepUpdated(0);

        paused=false;
        instanceRunning=false;
    }
}

std::string retrieveLatestState(QString dirName){
    QDir directory(dirName);
    QStringList states = directory.entryList(QStringList() << "*.dat",QDir::Files);

    if(states.size()>0){
        int max = 0;
        int maxIndex = 0;
        for (int i = 0; i < states.size(); ++i) {
            QString fileName = states[i];
            int epoch = fileName.replace(".dat","",Qt::CaseInsensitive).split("_")[1].toInt();
            if(max<epoch){
                max = epoch;
                maxIndex = i;
            }
        }

        return states[maxIndex].toUtf8().data();
    }else{
        return "0";
    }
}

void simulator(QPromise<void> &promise, int argc, QString filename)
{
    //printSensorsActions(); // show the agents' capabilities

    // Simulator parameters are available read-only through the global
    // variable p after paramManager is initialized.
    // Todo: remove the hardcoded parameter filename.
    paramManager.setDefaults();
    paramManager.registerConfigFile(argc > 1 ? filename : "biosim4.ini");
    paramManager.updateFromConfigFile(0);
    paramManager.checkParameters(); // check and report any problems

    randomUint.initialize(); // seed the RNG for main-thread use

    // Allocate container space. Once allocated, these container elements
    // will be reused in each new generation.
    grid.init(p.sizeX, p.sizeY); // the land on which the peeps live
    pheromoneSignals.init(p.signalLayers, p.sizeX, p.sizeY);  // where the pheromones waft
    peeps.init(p.population); // the peeps themselves

    // If imageWriter is to be run in its own thread, start it here:
    //std::thread t(&ImageWriter::saveFrameThread, &imageWriter);

    // Unit tests:
    //unitTestConnectNeuralNetWiringFromGenome();
    //unitTestGridVisitNeighborhood();

    unsigned generation = 0;
    unsigned murderCount;
    initializeGeneration0(); // starting population
    // The grid has already been allocated, just clear and reuse it
    grid.zeroFill();
    grid.createBarrier(p.barrierType);

    // The signal layers have already been allocated, so just reuse them
    pheromoneSignals.zeroFill();

    runMode = RunMode::RUN;

    // -----------------------------------------------------------test load state code
    QString state_dir = "./states/";
    std::string latestState = retrieveLatestState(state_dir);

    if(latestState != "0"){
        generation = QString::fromStdString(latestState).replace(".dat","",Qt::CaseInsensitive).split("_")[1].toUInt();
        emit runner->generationUpdated(generation);
        std::vector<Indiv> t = peeps.getAllIndivs();
        loadStateAsync(t,state_dir.toUtf8().data() + latestState);
        peeps.setAllIndivs(t);

        for (uint16_t index = 1; index <= p.population; ++index) {
            peeps[index].initialize(index, grid.findEmptyLocation(), (Genome)t[index].genome);
        }
    }else{
        for (uint16_t index = 1; index <= p.population; ++index) {
            peeps[index].initialize(index, grid.findEmptyLocation(), makeRandomGenome());
        }
    }
    //--------------------------------------------------------------------------------

    // Inside the parallel region, be sure that shared data is not modified. Do the
    // modifications in the single-thread regions.
    #pragma omp parallel num_threads(p.numThreads) default(shared)
    {
        randomUint.initialize(); // seed the RNG, each thread has a private instance

        while (runMode == RunMode::RUN && generation < p.maxGenerations) { // generation loop
            // promise.suspendIfRequested();
            // if (promise.isCanceled()){
            //     break;
            // }

            #pragma omp single
            murderCount = 0; // for reporting purposes

            for (unsigned simStep = 0; simStep < p.stepsPerGeneration; ++simStep) {
                // multithreaded loop: index 0 is reserved, start at 1
                #pragma omp for schedule(auto)
                for (unsigned indivIndex = 1; indivIndex <= p.population; ++indivIndex) {
                    if (peeps[indivIndex].alive) {
                        simStepOneIndiv(peeps[indivIndex], simStep);
                    }
                }


                // if (instanceRunning == false || promise.isCanceled()){
                //     emit runner->loggerUpdated("Simulator Aborted.");
                //     promise.finish();
                //     break;
                // }
                promise.suspendIfRequested();

                // In single-thread mode: this executes deferred, queued deaths and movements,
                // updates signal layers (pheromone), etc.
                #pragma omp single
                {
                    using namespace BS;
                    murderCount += peeps.deathQueueSize();
                    endOfSimStep(simStep, generation);

                    if(p.saveVideo &&
                        ((generation % p.videoStride) == 0
                         || generation <= p.videoSaveFirstFrames
                         || (generation >= p.parameterChangeGenerationNumber
                        && generation <= p.parameterChangeGenerationNumber + p.videoSaveFirstFrames))){
                        emit runner->simulationUpdated(getLastFrame());
                    }
                    emit runner->stepUpdated(simStep);
                }

                if(promise.isCanceled()){
                    // qDebug()<<"cancel";
                    // resetLastFrame();
                    // emit runner->simulationUpdated(getLastFrame());

                    emit runner->loggerUpdated("Simulator Aborted.");
                    instanceRunning=false;
                    promise.finish();
                    break;
                }
            }
            if(promise.isCanceled()){
                break;
            }
            promise.suspendIfRequested();
            #pragma omp single
            {
                endOfGeneration(generation);
                //------ test state saving func
                if (((generation % p.videoStride) == 0
                     || generation <= p.videoSaveFirstFrames
                     || (generation >= p.parameterChangeGenerationNumber
                         && generation <= p.parameterChangeGenerationNumber + p.videoSaveFirstFrames))) {
                    saveStateAsync(peeps.getAllIndivs(),"./states/state_" + std::to_string(generation) + ".dat");
                }
                //------

                paramManager.updateFromConfigFile(generation + 1);
                unsigned numberSurvivors = spawnNewGeneration(generation, murderCount);
                emit runner->survivorsUpdated(QString::fromStdString("Gen " +  std::to_string(generation) + ", " + std::to_string(numberSurvivors) + " survivors"));

                if (numberSurvivors > 0 && (generation % p.genomeAnalysisStride == 0)) {
                    // displaySampleGenomes(p.displaySampleGenomes);
                    peeps[1].printIGraphEdgeList();

                    if(instanceRunning == true)
                        emit runner->agentImageUpdated("./net.png");
                }

                if (numberSurvivors == 0) {
                    generation = 0;  // start over
                } else {
                    ++generation;
                }
                // survival plot
                // diversity plot
                if(instanceRunning == true)
                    emit runner->plotsUpdated();
                emit runner->generationUpdated(generation);
            }
        }
        promise.finish();
    }
    //displaySampleGenomes(3); // final report, for debugging
    emit runner->loggerUpdated("Simulator exit.");
    instanceRunning=false;
    emit runner->stepUpdated(-1); // The consumer of the signal in MainWindows will add 1
    emit runner->generationUpdated(0);
    // If imageWriter is in its own thread, stop it and wait for it here:
    //imageWriter.abort();
    //t.join();
}

void saveStateAsync(const std::vector<Indiv>& population, const std::string& filename) {
    std::async(std::launch::async, [&]() {
        std::ofstream file(filename, std::ios::binary);
        if (file.is_open()) {
            // Compress the data using zlib
            std::stringstream buffer;
            for (const auto& individual : population) {
                individual.serialize(buffer);
            }
            std::string compressed_data = compress(buffer.str());

            // Write the compressed data to the file
            file.write(compressed_data.data(), compressed_data.size());
            file.close();
            emit runner->loggerUpdated("State saved to file: "+QString::fromStdString(filename));
        } else {
            emit runner->loggerUpdated("Unable to open file for writing: "+QString::fromStdString(filename));
        }
    });
}

void loadStateAsync(std::vector<Indiv>& population, const std::string& filename) {
    std::async(std::launch::async, [&]() {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            // Read the compressed data from the file
            std::string compressed_data((std::istreambuf_iterator<char>(file)),
                                        std::istreambuf_iterator<char>());
            file.close();

            // Decompress the data using zlib
            std::string decompressed_data = decompress(compressed_data);

            // Deserialize the individuals
            std::stringstream buffer(decompressed_data);
            population.clear();
            while (buffer.peek() != EOF) {
                Indiv individual;
                individual.deserialize(buffer);
                population.push_back(individual);
            }
            emit runner->loggerUpdated("State loaded from file: "+QString::fromStdString(filename));
        } else {
            emit runner->loggerUpdated("Unable to open file for reading: "+QString::fromStdString(filename));
        }
    });
}

std::string compress(const std::string& data) {
    z_stream zs;
    zs.zalloc = Z_NULL;
    zs.zfree = Z_NULL;
    zs.opaque = Z_NULL;
    deflateInit(&zs, Z_DEFAULT_COMPRESSION);

    zs.avail_in = data.size();
    zs.next_in = reinterpret_cast<Bytef*>(const_cast<char*>(data.data()));

    std::string compressed_data;
    char buffer[4096];

    do {
        zs.avail_out = sizeof(buffer);
        zs.next_out = reinterpret_cast<Bytef*>(buffer);

        deflate(&zs, Z_FINISH);

        compressed_data.append(buffer, sizeof(buffer) - zs.avail_out);
    } while (zs.avail_out == 0);

    deflateEnd(&zs);

    return compressed_data;
}

std::string decompress(const std::string& compressed_data) {
    z_stream zs;
    zs.zalloc = Z_NULL;
    zs.zfree = Z_NULL;
    zs.opaque = Z_NULL;
    inflateInit(&zs);

    zs.avail_in = compressed_data.size();
    zs.next_in = reinterpret_cast<Bytef*>(const_cast<char*>(compressed_data.data()));

    std::string decompressed_data;
    char buffer[4096];

    do {
        zs.avail_out = sizeof(buffer);
        zs.next_out = reinterpret_cast<Bytef*>(buffer);

        inflate(&zs, Z_NO_FLUSH);

        decompressed_data.append(buffer, sizeof(buffer) - zs.avail_out);
    } while (zs.avail_out == 0);

    inflateEnd(&zs);

    return decompressed_data;
}

} // end namespace BS
