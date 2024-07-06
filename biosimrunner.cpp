#include "biosimrunner.h"
#include "biosim4/simulator.h"

BiosimRunner::BiosimRunner(QObject *parent)
    : QObject(parent)
{
    // Initialize the biosim4 simulator
}

void BiosimRunner::initialize(const QMap<QString, QString> &parameters)
{
    // Pass the parameters to the biosim4 simulator
    BS::Params params;
    for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
        QString key = it.key();
        QString value = it.value();
        if (key == "population") {
            params.population = value.toUInt();
        } else if (key == "stepsPerGeneration") {
            params.stepsPerGeneration = value.toUInt();
        } else if (key == "maxGenerations") {
            params.maxGenerations = value.toUInt();
        } // Add more parameter mappings as needed
    }
    BS::setSimulatorParams(params);
}



void BiosimRunner::run(QString filename)
{
    // Start or resume the biosim4 simulation
    // qDebug()<<"FileName"<<filename;
    BS::runSimulation(filename, this);
}

void BiosimRunner::pause()
{
    // Pause the biosim4 simulation
    BS::pauseSimulation();
}

void BiosimRunner::resume(){
    // Resume the biosim4 simulation
    BS::resumeSimulation();
}

void BiosimRunner::reset()
{
    // Reset the biosim4 simulation to its initial state
    BS::resetSimulation();
}

void BiosimRunner::exit(){
    BS::exitSimulation();
}
