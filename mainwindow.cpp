#include "mainwindow.h"
#include "qsignalmapper.h"
#include "AgentGraphicsView.h"
#include "qtimer.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QIntValidator>
#include <QMessageBox>
#include <QWheelEvent>
#include <QMouseEvent>
#include <unistd.h>
#include <sys/stat.h>


bool isRunning = false;

void MainWindow::setRunFileName(QString filename){
    this->filename=filename;
}

QString MainWindow::getRunFileName() const{
    return this->filename;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsViewAgent->setScene(new QGraphicsScene(this));
    ui->graphicsViewSimulation->setScene(biosimWidget);
    ui->survivalView->setScene(new QGraphicsScene(this));
    ui->diversityView->setScene(new QGraphicsScene(this));

    // Install the event filter on ui->graphicsViewAgent
    ui->graphicsViewAgent->viewport()->installEventFilter(this);

    QColor paramGUIBackgroundColor = QColor(33, 41, 67);

    QPalette p( ui->scrollArea->palette() );
    p.setColor( QPalette::Window,  paramGUIBackgroundColor);
    ui->scrollArea->setPalette( p );

    ui->graphicsViewAgent->setRenderHint(QPainter::Antialiasing);
    ui->graphicsViewAgent->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsViewAgent->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
    ui->graphicsViewAgent->setOptimizationFlag(QGraphicsView::DontSavePainterState);
    ui->graphicsViewAgent->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsViewAgent->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    ui->actionLoad_Button->setIcon(QIcon(":/assets/img/folder.png"));
    ui->actionRunSimulation_Button->setIcon(QIcon(":/assets/img/play.png"));
    ui->actionResetSimulation_Button->setIcon(QIcon(":/assets/img/reset.png"));
    ui->actionPauseSimulation_Button->setIcon(QIcon(":/assets/img/pause.png"));
    ui->actionExitSimulation_Button->setIcon(QIcon(":/assets/img/stop.png"));

    QString paramButtonCSS="QPushButton {background-color: #0099ff; color: #3c4043} ";
    paramButtonCSS+="QPushButton:hover {background-color: #0284db; border-color: #dadce0;color: #202124;} QPushButton:pressed {border-color: #027ed1;outline: none;}";

    QString paramInputCSS="QLineEdit {border: 1px solid #c0c0c0;border-radius: 4px;padding: 1px;}";
    paramInputCSS+="QLineEdit:focus {border-color: #4CAF50;}";

    // QString paramLabelCSS="QLabel {margin-left:5px ;font-size:17pt; color:#f6f5f4;} QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}";
    QString paramLabelCSS="QLabel {margin-left:5px; font-size: 20px;color: #333333;} QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}";

    QString checkBoxCSS = "QCheckBox:unchecked{ color: black; }QCheckBox:checked{ color: black; }";
    checkBoxCSS+="QCheckBox::indicator{width:30px;height:30px;}";
    checkBoxCSS+="QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}";

    ui->saveConfigButton->setStyleSheet(paramButtonCSS);

    //numThreads
    QString numThreadToolTip = "numThreads must be 1 or greater. Best value is less than or equal to the number of CPU cores.\nCannot be changed after a simulation starts.";
    ui->numThreadsDownButton->setStyleSheet(paramButtonCSS);
    ui->numThreadsUpButton->setStyleSheet(paramButtonCSS);
    ui->numThreadsInput->setStyleSheet(paramInputCSS);
    ui->numThreadsLabel->setStyleSheet(paramLabelCSS);
    ui->numThreadsLabel->setToolTip(numThreadToolTip);
    connect(ui->numThreadsInput, &QLineEdit::editingFinished, this, &MainWindow::numThreadsInputEditingFinished);

    autoRepeatTimer = new QTimer(this);
    autoRepeatTimer->setInterval(200); // Initial interval.
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateNumThreads);

    //sizeX
    QString sizeXToolTip = "sizeX, sizeY define the size of the 2D world. Minimum size is 16,16. Maximum size is 32767, 32767.\nCannot be changed after a simulation starts.";
    ui->sizeXDownButton->setStyleSheet(paramButtonCSS);
    ui->sizeXUpButton->setStyleSheet(paramButtonCSS);
    ui->sizeXInput->setStyleSheet(paramInputCSS);
    ui->sizeXLabel->setStyleSheet(paramLabelCSS);
    ui->sizeXLabel->setToolTip(sizeXToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateSizeX);

    //sizeY
    QString sizeYToolTip = sizeXToolTip;
    ui->sizeYDownButton->setStyleSheet(paramButtonCSS);
    ui->sizeYUpButton->setStyleSheet(paramButtonCSS);
    ui->sizeYInput->setStyleSheet(paramInputCSS);
    ui->sizeYLabel->setStyleSheet(paramLabelCSS);
    ui->sizeYLabel->setToolTip(sizeXToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateSizeY);

    //population
    QString populationToolTip = "Population at the start of each generation. Maximum value = 32766.\nCannot be changed after a simulation starts.";
    ui->populationDownButton->setStyleSheet(paramButtonCSS);
    ui->populationUpButton->setStyleSheet(paramButtonCSS);
    ui->populationInput->setStyleSheet(paramInputCSS);
    ui->populationLabel->setStyleSheet(paramLabelCSS);
    ui->populationLabel->setToolTip(populationToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updatePopulation);

    // stepsPerGeneration
    QString stepsPerGenerationToolTip = "Number of simulation steps per generation. Range 1..INT_MAX.";
    ui->stepsPerGenerationDownButton->setStyleSheet(paramButtonCSS);
    ui->stepsPerGenerationUpButton->setStyleSheet(paramButtonCSS);
    ui->stepsPerGenerationInput->setStyleSheet(paramInputCSS);
    ui->stepsPerGenerationLabel->setStyleSheet(paramLabelCSS);
    ui->stepsPerGenerationLabel->setToolTip(stepsPerGenerationToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateStepsPerGeneration);

    // maxGenerations
    QString maxGenerationsToolTip = "The simulator will stop when the generation number == maxGenerations. Range 1..INT_MAX";
    ui->maxGenerationsDownButton->setStyleSheet(paramButtonCSS);
    ui->maxGenerationsUpButton->setStyleSheet(paramButtonCSS);
    ui->maxGenerationsInput->setStyleSheet(paramInputCSS);
    ui->maxGenerationsLabel->setStyleSheet(paramLabelCSS);
    ui->maxGenerationsLabel->setToolTip(maxGenerationsToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateMaxGenerations);

    // genomeInitialLengthMin
    QString genomeInitialLengthMinToolTip = "genomeInitialLengthMin and genomeInitialLengthMax should be set to the same value.\n(For future use, the max length might be larger to allow mutations that lengthen the genome.) Range 1..INT_MAX \nand must be no larger than genomeMaxLength. Cannot be changed after a simulation starts.";
    ui->genomeInitialLengthMinDownButton->setStyleSheet(paramButtonCSS);
    ui->genomeInitialLengthMinUpButton->setStyleSheet(paramButtonCSS);
    ui->genomeInitialLengthMinInput->setStyleSheet(paramInputCSS);
    ui->genomeInitialLengthMinLabel->setStyleSheet(paramLabelCSS);
    ui->genomeInitialLengthMinLabel->setToolTip(genomeInitialLengthMinToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateGenomeInitialLengthMin);

    // genomeInitialLengthMax
    QString genomeInitialLengthMaxToolTip = genomeInitialLengthMinToolTip;
    ui->genomeInitialLengthMaxDownButton->setStyleSheet(paramButtonCSS);
    ui->genomeInitialLengthMaxUpButton->setStyleSheet(paramButtonCSS);
    ui->genomeInitialLengthMaxInput->setStyleSheet(paramInputCSS);
    ui->genomeInitialLengthMaxLabel->setStyleSheet(paramLabelCSS);
    ui->genomeInitialLengthMaxLabel->setToolTip(genomeInitialLengthMaxToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateGenomeInitialLengthMax);

    // genomeMaxLength
    QString genomeMaxLengthToolTip = "The range of genomeMaxLength is genomeInitialLengthMax..INT_MAX. Cannot be changed after a simulation starts.";
    ui->genomeMaxLengthDownButton->setStyleSheet(paramButtonCSS);
    ui->genomeMaxLengthUpButton->setStyleSheet(paramButtonCSS);
    ui->genomeMaxLengthInput->setStyleSheet(paramInputCSS);
    ui->genomeMaxLengthLabel->setStyleSheet(paramLabelCSS);
    ui->genomeMaxLengthLabel->setToolTip(genomeMaxLengthToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateGenomeMaxLength);

    // maxNumberNeurons
    QString maxNumberNeuronsToolTip = "maxNumberNeurons is the maximum number of internal neurons that may be addressed by genes in the genome.\nRange 1..INT_MAX. Cannot be changed after a simulation starts.";
    ui->maxNumberNeuronsDownButton->setStyleSheet(paramButtonCSS);
    ui->maxNumberNeuronsUpButton->setStyleSheet(paramButtonCSS);
    ui->maxNumberNeuronsInput->setStyleSheet(paramInputCSS);
    ui->maxNumberNeuronsLabel->setStyleSheet(paramLabelCSS);
    ui->maxNumberNeuronsLabel->setToolTip(maxNumberNeuronsToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateMaxNumberNeurons);

    // killEnable
    QString killEnableToolTip = "If killEnable is true and the \"kill\" action neuron is enabled in sensors-actions.h and compiled in,\nthen agents are permitted to kill their neighbor in the adjacent location in the direction of forward movement.\nIf false, the neighbors are safe.";
    // ui->killEnableCheckBox->setStyleSheet(paramLabelCSS);
    ui->killEnableCheckBox->setToolTip(killEnableToolTip);
    ui->killEnableCheckBox->setStyleSheet(checkBoxCSS);

    // sexualReproduction
    QString sexualReproductionToolTip = "If sexualReproduction is false, newborns inherit the genes from a\nsingle parent. If true, newborns inherit a mixture of genes from\ntwo parents.";
    //ui->sexualReproductionCheckBox->setStyleSheet(paramLabelCSS);
    ui->sexualReproductionCheckBox->setToolTip(sexualReproductionToolTip);
    ui->sexualReproductionCheckBox->setStyleSheet(checkBoxCSS);

    // chooseParentsByFitness
    QString chooseParentsByFitnessToolTip = "If chooseParentByFitness is false, then every agent that survives\nthe selection criterion has equal chance of reproducing. If true, then\n preference is given to those parents who passed the selection criterion\nwith a greater score. Fitness scores are determined in survival-criteria.cpp.";
    //ui->chooseParentsByFitnessCheckBox->setStyleSheet(paramLabelCSS);
    ui->chooseParentsByFitnessCheckBox->setToolTip(chooseParentsByFitnessToolTip);
    ui->chooseParentsByFitnessCheckBox->setStyleSheet(checkBoxCSS);

    // pointMutationRate
    QString pointMutationRateToolTip = "pointMutationRate is the probability per gene of having a single-bit\nmutation during spawning. Range 0.0 .. 1.0. A reasonable range is\n0.0001 to 0.01.";
    ui->pointMutationRateDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->pointMutationRateUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->pointMutationRateInput->setStyleSheet(paramInputCSS);
    ui->pointMutationRateLabel->setStyleSheet(paramLabelCSS);
    ui->pointMutationRateLabel->setToolTip(pointMutationRateToolTip);
    ui->pointMutationRateDownButton->setDisabled(true);
    ui->pointMutationRateUpButton->setDisabled(true);

    // geneInsertionDeletionRate
    QString geneInsertionDeletionRateToolTip = "geneInsertionDeletionRate and deletionRatio are for future use to\nallow mutations that lengthen or shorten the genome. Ignored for now.";
    ui->geneInsertionDeletionRateDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->geneInsertionDeletionRateUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->geneInsertionDeletionRateInput->setStyleSheet(paramInputCSS + "QLineEdit:disabled {background-color: #d6d6d6;}");
    ui->geneInsertionDeletionRateLabel->setStyleSheet(paramLabelCSS);
    ui->geneInsertionDeletionRateLabel->setToolTip(geneInsertionDeletionRateToolTip);
    ui->geneInsertionDeletionRateDownButton->setDisabled(true);
    ui->geneInsertionDeletionRateUpButton->setDisabled(true);
    ui->geneInsertionDeletionRateInput->setDisabled(true);

    //deletionRatio
    //QString deletionRatioToolTip = "geneInsertionDeletionRate and deletionRatio are for future use to\nallow mutations that lengthen or shorten the genome. Ignored for now.";
    ui->deletionRatioDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->deletionRatioUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->deletionRatioInput->setStyleSheet(paramInputCSS + "QLineEdit:disabled {background-color: #d6d6d6;}");
    ui->deletionRatioLabel->setStyleSheet(paramLabelCSS);
    ui->deletionRatioLabel->setToolTip(geneInsertionDeletionRateToolTip);
    ui->deletionRatioDownButton->setDisabled(true);
    ui->deletionRatioUpButton->setDisabled(true);
    ui->deletionRatioInput->setDisabled(true);

    // responsivenessCurveKFactor
    QString responsivenessCurveKFactorToolTip = "responsivenessCurveKFactor is a small positive integer that determines\nthe shape of the curve that determines how reactive an agent is to its\nsensory inputs. Typical values are # 1, 2, 3, or 4, but greater values\nare allowed experimentally.";
    ui->responsivenessCurveKFactorDownButton->setStyleSheet(paramButtonCSS);
    ui->responsivenessCurveKFactorUpButton->setStyleSheet(paramButtonCSS);
    ui->responsivenessCurveKFactorInput->setStyleSheet(paramInputCSS);
    ui->responsivenessCurveKFactorLabel->setStyleSheet(paramLabelCSS);
    ui->responsivenessCurveKFactorLabel->setToolTip(responsivenessCurveKFactorToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateResponsivenessCurveKFactor);

    //populationSensorRadius
    QString populationSensorRadiusToolTip = "populationSensorRadius is the radius in which the population sensor\nlooks for neighbors. Floating point value. A value of 1.5 includes\nall the immediate eight-neighborhood. Larger values incur exponentially\nincreasing processor overhead. Range 0.5 up to (float)max(sizeX, sizeY).";
    ui->populationSensorRadiusDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->populationSensorRadiusUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->populationSensorRadiusInput->setStyleSheet(paramInputCSS);
    ui->populationSensorRadiusLabel->setStyleSheet(paramLabelCSS);
    ui->populationSensorRadiusLabel->setToolTip(populationSensorRadiusToolTip);
    ui->populationSensorRadiusDownButton->setDisabled(true);
    ui->populationSensorRadiusUpButton->setDisabled(true);

    //longProbeDistance
    QString longProbeDistanceToolTip = "longProbeDistance is the default distance that the long-probe sensors\nare able to see. Applies to long-probe population sensor and long-probe\nsignal (pheromone) sensor. Range 1..INT_MAX.";
    ui->longProbeDistanceDownButton->setStyleSheet(paramButtonCSS);
    ui->longProbeDistanceUpButton->setStyleSheet(paramButtonCSS);
    ui->longProbeDistanceInput->setStyleSheet(paramInputCSS);
    ui->longProbeDistanceLabel->setStyleSheet(paramLabelCSS);
    ui->longProbeDistanceLabel->setToolTip(longProbeDistanceToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateLongProbeDistance);

    //shortProbeBarrierDistance
    QString shortProbeBarrierDistanceToolTip = "shortProbeBarrierDistance is the distance that the short-probe sensor\ncan see. Range 1..INT_MAX.";
    ui->shortProbeBarrierDistanceDownButton->setStyleSheet(paramButtonCSS);
    ui->shortProbeBarrierDistanceUpButton->setStyleSheet(paramButtonCSS);
    ui->shortProbeBarrierDistanceInput->setStyleSheet(paramInputCSS);
    ui->shortProbeBarrierDistanceLabel->setStyleSheet(paramLabelCSS);
    ui->shortProbeBarrierDistanceLabel->setToolTip(shortProbeBarrierDistanceToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateShortProbeBarrierDistance);

    //signalSensorRadius
    QString signalSensorRadiusToolTip = "signalSensorRadius is the radius in which the signal (pheromone) sensor\nlooks for pheromones. Floating point value. A value of 1.5 includes\nall the immediate eight-neighborhood. Larger values incur exponentially\nincreasing processor overhead. Range 0.5 up to (float)max(sizeX, sizeY).";
    ui->signalSensorRadiusDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->signalSensorRadiusUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->signalSensorRadiusInput->setStyleSheet(paramInputCSS);
    ui->signalSensorRadiusLabel->setStyleSheet(paramLabelCSS);
    ui->signalSensorRadiusLabel->setToolTip(signalSensorRadiusToolTip);
    ui->signalSensorRadiusDownButton->setDisabled(true);
    ui->signalSensorRadiusUpButton->setDisabled(true);

    //signalLayers
    QString signalLayersToolTip = "signalLayers defines the number of pheromone layers. Must be 1 for now.\nValues > 1 are for future use. Cannot be changed after a simulation starts.";
    ui->signalLayersDownButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->signalLayersUpButton->setStyleSheet(paramButtonCSS + "QPushButton:disabled {background-color: #d6d6d6;}");
    ui->signalLayersInput->setStyleSheet(paramInputCSS + "QLineEdit:disabled {background-color: #d6d6d6;}");
    ui->signalLayersLabel->setStyleSheet(paramLabelCSS);
    ui->signalLayersLabel->setToolTip(signalLayersToolTip);
    ui->signalLayersInput->setDisabled(true);
    ui->signalLayersDownButton->setDisabled(true);
    ui->signalLayersUpButton->setDisabled(true);

    //imageDir
    QString imageDirToolTip="imageDir is the relative or absolute directory path where generation\nmovies are created.";
    ui->imageDirInput->setStyleSheet(paramInputCSS + "QLineEdit:disabled {background-color: #d6d6d6;}");
    ui->imageDirLabel->setStyleSheet(paramLabelCSS);
    ui->imageDirLabel->setToolTip(imageDirToolTip);
    ui->imageDirButton->setStyleSheet(paramButtonCSS);
    ui->imageDirInput->setDisabled(true);

    //logDir
    QString logDirToolTip="logDir is the relative or absolute directory path where text log files\nare created.";
    ui->logDirInput->setStyleSheet(paramInputCSS + "QLineEdit:disabled {background-color: #d6d6d6;}");
    ui->logDirLabel->setStyleSheet(paramLabelCSS);
    ui->logDirLabel->setToolTip(imageDirToolTip);
    ui->logDirButton->setStyleSheet(paramButtonCSS);
    ui->logDirInput->setDisabled(true);

    //displayScale
    QString displayScaleToolTip = "displayScale scales the generation movie. Typical values are\n1 for actual size, or 2, 4, 8, 16, or 32 to scale up the movie.";
    ui->displayScaleDownButton->setStyleSheet(paramButtonCSS);
    ui->displayScaleUpButton->setStyleSheet(paramButtonCSS);
    ui->displayScaleInput->setStyleSheet(paramInputCSS);
    ui->displayScaleLabel->setStyleSheet(paramLabelCSS);
    ui->displayScaleLabel->setToolTip(displayScaleToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateDisplayScale);

    // agentSize
    QString agentSizeToolTip = "agentSize controls the size of the dot used to represent\nan agent in the generation movie. Typical value is displayScale / 2.";
    ui->agentSizeDownButton->setStyleSheet(paramButtonCSS);
    ui->agentSizeUpButton->setStyleSheet(paramButtonCSS);
    ui->agentSizeInput->setStyleSheet(paramInputCSS);
    ui->agentSizeLabel->setStyleSheet(paramLabelCSS);
    ui->agentSizeLabel->setToolTip(agentSizeToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateAgentSize);

    //videoSaveFirstFrames
    QString videoSaveFirstFramesToolTip = "If videoSaveFirstFrames is 0, then only the parameter videoStride controls\nhow often generation movies are made. If videoSaveFirstFrames is nonzero,\nthen generation movies will also be generated for every generation from 0\nthrough videoSaveFirstFrames (because the first few generations are often\nthe most interesting). Range 1..INT_MAX.";
    ui->videoSaveFirstFramesDownButton->setStyleSheet(paramButtonCSS);
    ui->videoSaveFirstFramesUpButton->setStyleSheet(paramButtonCSS);
    ui->videoSaveFirstFramesInput->setStyleSheet(paramInputCSS);
    ui->videoSaveFirstFramesLabel->setStyleSheet(paramLabelCSS);
    ui->videoSaveFirstFramesLabel->setToolTip(videoSaveFirstFramesToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateVideoSaveFirstFrames);

    // updateGraphLog
    QString updateGraphLogToolTip = "updateGraphLog can be set to true to cause the simulator program to\ninvoke graphlog.gp to update the simulation progress graph. If true,\nthen updateGraphLogStride controls how often it is invoked. If\nupdateGraphLog is false, then the simulator program will not invoke\ngraphlog.gp.";
    ui->updateGraphLogCheckBox->setToolTip(updateGraphLogToolTip);
    ui->updateGraphLogCheckBox->setStyleSheet(checkBoxCSS);

    // saveVideo
    QString saveVideoToolTip = "If saveVideo is true, the simulator program will create generation\nmovies in the directory named by imageDir at the intervals set by\nvideoSaveFirstFrames and videoStride.";
    ui->saveVideoCheckBox->setToolTip(saveVideoToolTip);
    ui->saveVideoCheckBox->setStyleSheet(checkBoxCSS);

    // videoStride
    QString videoStrideToolTip = "videoStride determines how often generation movies will be created. Also see saveVideo and videoSaveFirstFrames. Range 1..INT_MAX.";
    ui->videoStrideDownButton->setStyleSheet(paramButtonCSS);
    ui->videoStrideUpButton->setStyleSheet(paramButtonCSS);
    ui->videoStrideInput->setStyleSheet(paramInputCSS);
    ui->videoStrideLabel->setStyleSheet(paramLabelCSS);
    ui->videoStrideLabel->setToolTip(videoStrideToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateVideoStride);

    // genomeComparisonMethod
    QString genomeComparisonMethodToolTip = "When the genomic statistics are printed (see genomeAnalysisStride), the\nmethod used to measure genome diversity in the population is determined\nby genomeComparisonMethod. May be set to 0 for Jaro-Winkler method (useful\nfor future use if genomes are allowed to grow or shrink in size); or 1\nfor a Hamming measure bit-by-bit, or 2 for a Hamming measure byte-by-byte.\nTypically set to 1.";
    QStringList genomeComparisonMethodList=(QStringList()<<"Jaro-Winkler method"<<"Hamming measure bit-by-bit"<<"Hamming measure byte-by-byte");
    //ui->genomeComparisonMethodComboBox->setStyleSheet(paramInputCSS);
    ui->genomeComparisonMethodComboBox->addItems(genomeComparisonMethodList);
    ui->genomeComparisonMethodLabel->setStyleSheet(paramLabelCSS);
    ui->genomeComparisonMethodLabel->setToolTip(genomeComparisonMethodToolTip);

    //displaySampleGenomes
    QString displaySampleGenomesToolTip = "When genomic statistics are printed (see genomeAnalysisStride), the number\nof genomes sampled from the population and printed to stdout is determined\nby displaySampleGenomes. Range 0 to population size.";
    ui->displaySampleGenomesDownButton->setStyleSheet(paramButtonCSS);
    ui->displaySampleGenomesUpButton->setStyleSheet(paramButtonCSS);
    ui->displaySampleGenomesInput->setStyleSheet(paramInputCSS);
    ui->displaySampleGenomesLabel->setStyleSheet(paramLabelCSS);
    ui->displaySampleGenomesLabel->setToolTip(displaySampleGenomesToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateDisplaySampleGenomes);

    //challenge
    QString challengeToolTip = "challenge determines the selection criterion for reproduction. This is\ntypically always under active development. See survival-criteria.cpp for\nmore information.";
    QStringList challengeList=(QStringList()<<
                                 "circle"<<
                                 "right half"<<
                                 "right quarter"<<
                                 "neighbor count"<<
                                 "center weighted"<<
                                 "corner 1/4 radius"<<
                                 "corner 1/4 radius weighted"<<
                                 "migrate distance"<<
                                 "center sparse"<<
                                 "left eighth"<<
                                 "radioactive walls"<<
                                 "against any wall"<<
                                 "touch any wall any time"<<
                                 "east-west eighths"<<
                                 "near barrier"<<
                                 "pairs"<<
                                 "contact location sequence"<<
                                 "altruism, circle + NE corner"<<
                                 "altruism sacrifice"<<
                                 "center unweighted");
    //ui->genomeComparisonMethodComboBox->setStyleSheet(paramInputCSS);
    ui->challengeComboBox->addItems(challengeList);
    ui->challengeLabel->setStyleSheet(paramLabelCSS);
    ui->challengeLabel->setToolTip(challengeToolTip);

    //barrierType
    QString barrierTypeToolTip = "The simulator supports a feature called \"barriers.\" Barriers are locations\nin the simulated 2D world where agents may not occupy. The value of\nbarrierType is typically under active development. See createBarrier.cpp\nfor more information.";
    QStringList barrierTypeList=(QStringList()<<
                                 "none"<<
                                 "vertical bar constant location"<<
                                 "vertical bar random locations"<<
                                 "five staggered vertical bars"<<
                                 "horiz bar constant location north center"<<
                                 "floating islands"<<
                                 "sequence of spots");
    ui->barrierTypeComboBox->addItems(barrierTypeList);
    ui->barrierTypeLabel->setStyleSheet(paramLabelCSS);
    ui->barrierTypeLabel->setToolTip(barrierTypeToolTip);

    //deterministic
    QString deterministicToolTip = "If true, then the random number generator (RNG) will be seeded by the value\nin RNGSeed, causing each thread to receive a deterministic sequence from\nthe RNG. If false, the RNG will be randomly seeded and program output will\nbe non-deterministic. Cannot be changed after a simulation starts.";
    ui->deterministicCheckBox->setToolTip(deterministicToolTip);
    ui->deterministicCheckBox->setStyleSheet(checkBoxCSS);

    //RNGSeed
    QString RNGSeedToolTip = "If deterministic is true, the random number generator will be seeded with\nthis value. If deterministic is false, this value is ignored. Legal values\nare integers 0 to 4294967295. Cannot be changed after a simulation starts.";
    ui->RNGSeedDownButton->setStyleSheet(paramButtonCSS);
    ui->RNGSeedUpButton->setStyleSheet(paramButtonCSS);
    ui->RNGSeedInput->setStyleSheet(paramInputCSS);
    ui->RNGSeedLabel->setStyleSheet(paramLabelCSS);
    ui->RNGSeedLabel->setToolTip(RNGSeedToolTip);
    connect(autoRepeatTimer, &QTimer::timeout, this, &MainWindow::updateRNGSeed);

    QString defaultFileName = "biosim4.ini";
    QString lastTimeIniFileName = this->getLastTimeIniFileName();
    if (lastTimeIniFileName == ""){
        this->setRunFileName(defaultFileName);
    }else{
        this->setRunFileName(lastTimeIniFileName);
    }

    QString iniFilePath = this->getRunFileName();
    biosimParser.parseIniFile(iniFilePath); // parse ini file

    // Display the contents of the INI file in the QTextEdit
    this->setParameters();

    // Also initialize the BiosimRunner with the parsed parameters
    biosimRunner.initialize(biosimParser.getParameters());

    // Connect signals and slots
    connect(&biosimRunner, &BiosimRunner::simulationUpdated, this, &MainWindow::updateSimulationView);
    connect(&biosimRunner, &BiosimRunner::stepUpdated, this, &MainWindow::updateStep);
    connect(&biosimRunner, &BiosimRunner::generationUpdated, this, &MainWindow::updateGeneration);
    connect(&biosimRunner, &BiosimRunner::agentImageUpdated, this, &MainWindow::updateAgentImage);
    connect(&biosimRunner, &BiosimRunner::plotsUpdated, this, &MainWindow::updatePlots);
    connect(&biosimRunner, &BiosimRunner::survivorsUpdated, this, &MainWindow::updateSurvivorsInfo);
    connect(&biosimRunner, &BiosimRunner::loggerUpdated, this, &MainWindow::logger);

}

void MainWindow::updatePlots(){
    //qDebug()<<"Update Image";
    {
        if (parameters.value("updateGraphLog") == "true") {
            #pragma GCC diagnostic ignored "-Wunused-result"
            WinExec("gnuplot --persist ./tools/survival-plot.gp", SW_HIDE);
            WinExec("gnuplot --persist ./tools/diversity-plot.gp", SW_HIDE);
            //system(graphLogUpdateCommand.toLatin1().data());
        }
    }
    usleep(100);

    if ((!ui->survivalView || !ui->survivalView->scene()) || (!ui->diversityView || !ui->diversityView->scene())) {
        qDebug() << "Scenes not available";
        return;
    }

    QGraphicsScene *diversityScene = ui->diversityView->scene();
    QGraphicsScene *survivalScene = ui->survivalView->scene();
    survivalScene->clear(); // Ensure this is safe to call
    diversityScene->clear(); // Ensure this is safe to call

    // survival plot
    QString survivalPlotDir = ".\\images\\survivors.png";
    //diversity plot
    QString diversityPlotDir = ".\\images\\diversity.png";

    QPixmap pixmap;

    if (QFileInfo::exists(survivalPlotDir)){
        survivorPlotImageList.append(QImage(survivalPlotDir));
        pixmap = QPixmap::fromImage(survivorPlotImageList[0]);
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);

        survivalScene->addItem(pixmapItem);

        ui->survivalView->fitInView(pixmapItem, Qt::KeepAspectRatio);
        // Output the file name for debugging purposes
        // qDebug() << "Loaded PNG file:" << survivalPlotDir;

        survivorPlotImageList.pop_front();
    }else{
        qDebug() << "File does not exist:" << survivalPlotDir;
    }

    if (QFileInfo::exists(diversityPlotDir)){
        diversityPlotImageList.append(QImage(diversityPlotDir));
        pixmap = QPixmap::fromImage(diversityPlotImageList[0]);
        //pixmap.rect().setRect(0,0,ui->diversityView->geometry().width(),ui->diversityView->geometry().height());
        QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
        diversityScene->addItem(pixmapItem);

        ui->diversityView->fitInView(pixmapItem, Qt::KeepAspectRatio);
        // Output the file name for debugging purposes
        // qDebug() << "Loaded PNG file:" << diversityPlotDir;

        diversityPlotImageList.pop_front();
    }else{
        qDebug() << "File does not exist:" << diversityPlotDir;
    }
}

void MainWindow::updateAgentImage(QString fileName) {
    //qDebug()<<"Update Image";
    if (!ui->graphicsViewAgent || !ui->graphicsViewAgent->scene()) {
        qDebug() << "Scene not available";
        return;
    }


    QGraphicsScene *scene = ui->graphicsViewAgent->scene();
    scene->clear(); // Ensure this is safe to call

    // Check if the SVG file exists
    if (QFileInfo::exists(fileName)) {
        agentImageList.append(QImage(fileName));

        try {
            QPixmap pixmap = QPixmap::fromImage(agentImageList[0]); // always get the first one
            QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(pixmap);
            scene->addItem(pixmapItem);

            pixmapItem->setPos(
                pixmapItem->mapFromScene(
                    QPointF(
                        (ui->graphicsViewAgent->width() - int(pixmapItem->boundingRect().width()))/2,
                        (ui->graphicsViewAgent->height() - int(pixmapItem->boundingRect().height()))/2)
                    )
                );
            //ui->graphicsViewAgent->setScene(scene);

            // Output the file name for debugging purposes
            // qDebug() << "Loaded SVG file:" << fileName;

            agentImageList.pop_front();
        } catch (...) {
            qDebug() << "Failed to loaded SVG file:" << fileName;
        }

    } else {
        // Log an error or handle the case where the file does not exist
        qDebug() << "File does not exist:" << fileName;
    }
}

void MainWindow::updateSurvivorsInfo(QString survivorsInfo){
    ui->lastGenSurvivorsLabel->setText(survivorsInfo);
}

void MainWindow::logger(QString log){
    // suppose to deligate every logging.
    ui->quickInfo->setText(log);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->graphicsViewAgent->viewport() && event->type() == QEvent::Wheel) {
        QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);
        ui->graphicsViewAgent->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

        double scaleFactor = 1.15;
        double currentScale = ui->graphicsViewAgent->transform().m11();

        if (wheelEvent->angleDelta().y() > 0 && currentScale < 10.0) {
            ui->graphicsViewAgent->scale(scaleFactor, scaleFactor);
        } else if (wheelEvent->angleDelta().y() < 0 && currentScale > 0.1) {
            ui->graphicsViewAgent->scale(1 / scaleFactor, 1 / scaleFactor);
        }
        return true; // Consume the event
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Check if the event is on the viewport of the graphicsViewAgent
    if (event->button() == Qt::MiddleButton && this->childAt(event->pos()) == ui->graphicsViewAgent->viewport()) {
        lastMousePos = event->pos();
        isPanning = true;
        setCursor(Qt::ClosedHandCursor);
    } else {
        QMainWindow::mousePressEvent(event);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPanning && this->childAt(event->pos()) == ui->graphicsViewAgent->viewport()) {
        QPointF delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();
        ui->graphicsViewAgent->translate(delta.x(), delta.y());
    } else {
        QMainWindow::mouseMoveEvent(event);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton && this->childAt(event->pos()) == ui->graphicsViewAgent->viewport()) {
        isPanning = false;
        setCursor(Qt::ArrowCursor);
    } else {
        QMainWindow::mouseReleaseEvent(event);
    }
}

QString MainWindow::getLastTimeIniFileName(){
    QMap<QString, QString> appConfigMap;
    QFile appConfig(appInitFileName);
    if (!appConfig.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    // get parameters
    QTextStream fileStream(&appConfig);
    QStringList configPair;
    while (!fileStream.atEnd()) {
        QString line = fileStream.readLine();
        if(line.startsWith("#") || line.isEmpty())
            continue;
        configPair = line.split(" = ");

        appConfigMap[configPair[0].trimmed()]=configPair[1].trimmed();
    }

    return appConfigMap["lastTimeIniFile"];
}

void MainWindow::updateSimulationView(QImage lastFrame){
    biosimWidget->clear();
    QPixmap pixmap = QPixmap::fromImage(lastFrame);
    QGraphicsPixmapItem *item = biosimWidget->addPixmap(pixmap);

    item->setPos(
        item->mapFromScene(
            QPointF(
                (biosimWidget->width() - int(item->boundingRect().width()))/2,
                (biosimWidget->height() - int(item->boundingRect().height()))/2)
            )
        );
    ui->graphicsViewSimulation->setCurrentPixmap(pixmap);
    ui->graphicsViewSimulation->setStep(this->step);
    ui->graphicsViewSimulation->setGeneration(this->generation);
}

void MainWindow::updateStep(int step){
    ui->stepLabel->setText("Step: "+QString::number(step+1));
    this->step = step+1;
}

void MainWindow::updateGeneration(int generation){
    ui->generationLabel->setText("Generation: "+QString::number(generation));
    this->generation = generation;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete autoRepeatTimer;
}

QMap<QString, QString> MainWindow::getParametersInUse() const
{
    return this->parameters;
}


void MainWindow::setParameters(){
    // beautify the parameter GUI
    parameters = biosimParser.getParameters();

    //now we want a better GUI view
    ui->numThreadsInput->setText(parameters.value("numThreads"));
    ui->sizeXInput->setText(parameters.value("sizeX"));
    ui->sizeYInput->setText(parameters.value("sizeX"));
    ui->populationInput->setText(parameters.value("population"));
    ui->stepsPerGenerationInput->setText(parameters.value("stepsPerGeneration"));
    ui->maxGenerationsInput->setText(parameters.value("maxGenerations"));
    ui->genomeInitialLengthMinInput->setText(parameters.value("genomeInitialLengthMin"));
    ui->genomeInitialLengthMaxInput->setText(parameters.value("genomeInitialLengthMax"));
    ui->genomeMaxLengthInput->setText(parameters.value("genomeMaxLength"));
    ui->maxNumberNeuronsInput->setText(parameters.value("maxNumberNeurons"));

    ui->killEnableCheckBox->setChecked(parameters.value("killEnable") == "true");
    ui->sexualReproductionCheckBox->setChecked(parameters.value("sexualReproduction") == "true");
    ui->chooseParentsByFitnessCheckBox->setChecked(parameters.value("chooseParentsByFitness") == "true");

    ui->pointMutationRateInput->setText(parameters.value("pointMutationRate"));

    // disabled
    ui->geneInsertionDeletionRateInput->setText(parameters.value("geneInsertionDeletionRate"));
    ui->deletionRatioInput->setText(parameters.value("deletionRatio"));

    ui->responsivenessCurveKFactorInput->setText(parameters.value("responsivenessCurveKFactor"));
    ui->populationSensorRadiusInput->setText(parameters.value("populationSensorRadius"));
    ui->longProbeDistanceInput->setText(parameters.value("longProbeDistance"));
    ui->shortProbeBarrierDistanceInput->setText(parameters.value("shortProbeBarrierDistance"));
    ui->signalSensorRadiusInput->setText(parameters.value("signalSensorRadius"));
    ui->signalLayersInput->setText(parameters.value("signalLayers"));

    //select diretories
    ui->imageDirInput->setText(parameters.value("imageDir"));
    ui->logDirInput->setText(parameters.value("logDir"));

    ui->displayScaleInput->setText(parameters.value("displayScale"));
    ui->agentSizeInput->setText(parameters.value("agentSize"));
    ui->videoSaveFirstFramesInput->setText(parameters.value("videoSaveFirstFrames"));
    ui->updateGraphLogCheckBox->setChecked(parameters.value("updateGraphLog") == "true");
    ui->saveVideoCheckBox->setChecked(parameters.value("saveVideo") == "true");
    ui->videoStrideInput->setText(parameters.value("videoStride"));
    ui->genomeComparisonMethodComboBox->setCurrentIndex(parameters.value("genomeComparisonMethod").toInt());
    ui->displaySampleGenomesInput->setText(parameters.value("displaySampleGenomes"));
    ui->challengeComboBox->setCurrentIndex(parameters.value("challenge").toInt());
    ui->barrierTypeComboBox->setCurrentIndex(parameters.value("barrierType").toInt());
    ui->deterministicCheckBox->setChecked(parameters.value("deterministic") == "true");
    ui->RNGSeedInput->setText(parameters.value("RNGSeed"));

    parameterModified = false;
}

bool MainWindow::isShortTypeParam(QString paramName){
    if(std::find(notShortParamName.begin(), notShortParamName.end(), paramName ) != notShortParamName.end()){
        return false;
    }else{
        return true;
    }
}

//ButtonClicked
void MainWindow::onButtonClicked(QString paramName,short increment, unsigned int low, unsigned int high, QLineEdit*target){
    if(activeParam=="RNGSeed"){
        if(parameters["RNGSeed"].toUInt()==UINT_MAX-1 && increment>0){
            parameters["RNGSeed"] = QString::number(UINT_MAX);
            ui->RNGSeedInput->setText(QString::number(UINT_MAX));
            parameterModified = true;
            return;
        }else if(parameters["RNGSeed"]=="1" && increment<0){
            parameters["RNGSeed"] = QString::number(0);
            ui->RNGSeedInput->setText(QString::number(0));
            parameterModified = true;
            return;
        }
    }

    // low and high are inclusive
    bool ok;
    unsigned paramValue;
    if(isShortTypeParam(paramName)){
        paramValue = parameters.value(paramName).toUShort(&ok,10);
    }else{
        paramValue = parameters.value(paramName).toUInt(&ok,10);
    }

    paramValue+=increment;
    QString paramValueQString = QString::number(paramValue);
    if(ok && (paramValue-1<paramValue) && (paramValue+1>paramValue) && (paramValue>=low && paramValue <= high)){
        parameters[paramName] = paramValueQString;
        target->setText(paramValueQString);
        parameterModified = true;
        // Won't let simulator know until reset
        if (!isRunning){

        }else{

        }
    }else{
        //out of range
    }
}

//ButtonUp
void MainWindow::onButtonUpPressed(short * incrementValue){
    autoRepeatStage = 0; // Reset the stage every time the button is pressed
    *incrementValue = 1;
    autoRepeatTimer->start(); // Start the repeating timer
}

void MainWindow::onButtonUpReleased(short * incrementValue){
    autoRepeatStage = 0;
    *incrementValue = 0;
    autoRepeatTimer->setInterval(200);
    autoRepeatTimer->stop(); // Stop the repeating timer when the button is released
    hasTimerActived = false;
    activeParam="";
}

//ButtonDown
void MainWindow::onButtonDownPressed(short * incrementValue){
    autoRepeatStage = 0; // Reset the stage every time the button is pressed
    *incrementValue = -1;
    autoRepeatTimer->start(); // Start the repeating timer
}

void MainWindow::onButtonDownReleased(short * incrementValue){
    autoRepeatStage = 0;
    *incrementValue = 0;
    autoRepeatTimer->setInterval(200);
    autoRepeatTimer->stop(); // Stop the repeating timer when the button is released
    hasTimerActived = false;
    activeParam="";
}

void MainWindow::updateParam(QString paramName,short increment, unsigned int low, unsigned int high, QLineEdit*target){
    if (increment!=0 && activeParam==""){
        activeParam = paramName;
    }else if(paramName!=activeParam){
        return;
    }else if(activeParam=="RNGSeed"){
        //qDebug()<<parameters["RNGSeed"];
        if(parameters["RNGSeed"].toUInt()==UINT_MAX-1 && increment>0){
            parameters["RNGSeed"] = QString::number(UINT_MAX);
            ui->RNGSeedInput->setText(QString::number(UINT_MAX));
            parameterModified = true;
            return;
        }else if(parameters["RNGSeed"]=="1" && increment<0){
            parameters["RNGSeed"] = QString::number(0);
            ui->RNGSeedInput->setText(QString::number(0));
            parameterModified = true;
            return;
        }
    }
    //qDebug()<<increment;
    bool ok;
    unsigned paramValue;
    if(isShortTypeParam(paramName)){
        paramValue = parameters.value(paramName).toUShort(&ok,10);
    }else{
        paramValue = parameters.value(paramName).toUInt(&ok,10);
    }

    paramValue+=increment;
    QString paramQString = QString::number(paramValue);
    // qDebug()<<paramValue;
    if(ok && (paramValue-1<paramValue) && (paramValue+1>paramValue) && (paramValue>=low && paramValue <= high)){
        parameters[paramName] = paramQString;
        target->setText(paramQString);
        parameterModified = true;
    }else{
        // overflow and out of range situations can both reach here, causing conflicts.
        autoRepeatStage=0;
        autoRepeatTimer->stop();//double stop?
        hasTimerActived = false;
        return;
    }

    // Change the speed of the timer based on the stage
    if(autoRepeatStage == 0){
        // autoRepeatTimer->setInterval(4000);
        autoRepeatStage++;
        hasTimerActived = true;
    } else if(autoRepeatStage < 2){
        autoRepeatTimer->setInterval(200);
        autoRepeatStage++;
    } else if(autoRepeatStage < 4){
        autoRepeatTimer->setInterval(100);
        autoRepeatStage++;
    } else {
        autoRepeatTimer->setInterval(15); // Fastest interval for stage 5 and onwards
    }
    //qDebug()<<autoRepeatStage;
}

//menu button actions
void MainWindow::on_actionLoad_Button_triggered()
{
    // Load from file
    // Open up a file dialog
    QString fileName = QFileDialog::getOpenFileName(this,"Load Ini file", "./");
    if(fileName == ""){
        //No file selected
        return;
    }

    biosimParser.parseIniFile(fileName); // parse ini file

    if(biosimParser.getIsFileOpened()){
        this->setParameters();

        ui->quickInfo->setText("");

        this->setRunFileName(fileName);

        parameterModified = false;

        saveLastTimeActiveConfigToIniiFile(fileName);
    }else{
        std::string errorInfo="Cannot open file: " "\'" +fileName.toStdString()+   "\'";
        ui->quickInfo->setStyleSheet("QLabel {color : red; }");
        ui->quickInfo->setText(QString::fromStdString(errorInfo));
    }
}

void MainWindow::on_actionRunSimulation_Button_triggered()
{
    startNewRun();
}

void MainWindow::on_actionPauseSimulation_Button_triggered()
{
    if(!pause){
        biosimRunner.pause();
        pause=true;
    }else{
        biosimRunner.resume();
        pause=false;
    }
}

void MainWindow::on_actionResetSimulation_Button_triggered()
{
    // biosimRunner.reset();
    if(isRunning){
        clearUpLastRun();

        //pause
        usleep(500);

        //------run-------
        startNewRun();
    }
}

void MainWindow::on_actionExitSimulation_Button_triggered()
{
    clearUpLastRun();
}

void MainWindow::on_actionLoad_triggered()
{
    this->on_actionLoad_Button_triggered();
}

void MainWindow::on_actionRun_triggered()
{
    this->on_actionRunSimulation_Button_triggered();
}

void MainWindow::on_actionPause_triggered()
{
    this->on_actionPauseSimulation_Button_triggered();
}

void MainWindow::on_actionReset_triggered()
{
    this->on_actionResetSimulation_Button_triggered();
}

//
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index!=0){
        //not parameter tab
        ui->saveConfigButton->hide();
    }else{
        ui->saveConfigButton->show();
    }
}

void MainWindow::on_saveConfigButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Current Figuration"), "",
                                                    tr("biosim4 configuration file(*.ini)"));
    if (fileName.isEmpty())
        return;
    else {
        if(!fileName.endsWith(".ini")){
            QStringList fileSeg = fileName.split(".");
            fileName = fileSeg[0] + ".ini";
        }
        qDebug()<<fileName;

        // save to file
        saveCurrentConfigToFile(fileName);

        parameterModified = false;
    }
}

void MainWindow::closeEvent (QCloseEvent *closeEvent)
{
    if(focusWidget()!=nullptr){
        focusWidget()->clearFocus();
    }
    if (!parameterModified){
        closeEvent->accept();

        // pause current simulation
        on_actionPauseSimulation_Button_triggered();

        if (isRunning){
            QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit Simulator",
                                                                       tr("Simulation running, confirm EXIT?\n"),
                                                                       QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                       QMessageBox::Yes);
            if (resBtn == QMessageBox::No) {
                closeEvent->ignore();
                // RESUME current simulation
                on_actionPauseSimulation_Button_triggered();
            }else if(resBtn == QMessageBox::Yes) {
                closeEvent->accept();

                clearUpLastRun();
            }else {
                closeEvent->ignore();

                // resume if nothing happened
                on_actionPauseSimulation_Button_triggered();
            }
        }
        return;
    }

    // pause current simulation
    on_actionPauseSimulation_Button_triggered();

    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit Simulator",
                                                               tr("Save current parameters before exit?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if (resBtn == QMessageBox::No) {
        //Do not save
        closeEvent->accept();

        // exit simulation
        clearUpLastRun();
    }else if(resBtn == QMessageBox::Yes) {
        //Please let me save my config
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Current Figuration"), "",
                                                        tr("biosim4 configuration file(*.ini)"));
        if (fileName.isEmpty())
            return;
        else {
            if(!fileName.endsWith(".ini")){
                QStringList fileSeg = fileName.split(".");
                fileName = fileSeg[0] + ".ini";
            }
            qDebug()<<fileName;

            // save to file
            saveCurrentConfigToFile(fileName);
        }
        closeEvent->accept();

        // exit simulation
        clearUpLastRun();
    } else {
        closeEvent->ignore();

        // resume if nothing happened
        on_actionPauseSimulation_Button_triggered();
    }
}

void MainWindow::startNewRun(){
    if(focusWidget()!=nullptr){
        focusWidget()->clearFocus();
    }

    saveTempConfigToTempFile();

    if(!isRunning){
        biosimRunner.run(this->getRunFileName());
        isRunning = true;
        ui->generationLabel->setText("Generation: 0");
        ui->stepLabel->setText("Step: 0");
    }
}

void MainWindow::clearUpLastRun(){
    biosimRunner.exit();
    isRunning=false;
    pause=false;
    tempFile.close();

    logger("Simulator Exit");

    //reset labels
    ui->generationLabel->setText("Generation: 0");
    ui->stepLabel->setText("Step: 0");

    // reset images
    // plots
    ui->survivalView->scene()->clear();
    ui->diversityView->scene()->clear();

    // agent network view
    ui->graphicsViewAgent->scene()->clear();

    // clear simulation image
    biosimWidget->clear();
    ui->graphicsViewSimulation->scene()->clear();

    QApplication::processEvents();
    QCoreApplication::processEvents();
}

void MainWindow::saveTempConfigToTempFile(){
    //save current config to temp file
    if (tempFile.open()) {
        QString fileName;
        QString iniContent;
        QTextStream stream(&tempFile);

        fileName = tempFile.fileName(); //returns the unique file name
        //qDebug()<<tempFile.filesystemSymLinkTarget();

        for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
            if (it.key() == "")
                continue;
            iniContent += it.key() + " = " + it.value() + "\n";
        }
        stream << iniContent;

        //set the config as current config.
        this->setRunFileName(fileName);
    }
}

void MainWindow::saveCurrentConfigToFile(QString fileName){
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite)) {
        file.resize(0);
        QTextStream stream(&file);
        QString iniContent;
        for (auto it = parameters.constBegin(); it != parameters.constEnd(); ++it) {
            if (it.key() == "")
                continue;
            iniContent += it.key() + " = " + it.value() + "\n";
        }
        stream << iniContent;

        saveLastTimeActiveConfigToIniiFile(fileName);
    }
}

void MainWindow::saveLastTimeActiveConfigToIniiFile(QString configFileName){
    // set as last active config file
    // This function may have more parameters
    // open config file
    QFile appConfigFile(appInitFileName);

    if (!appConfigFile.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    // get parameters
    QMap<QString, QString> appConfigMap;
    QTextStream fileStream(&appConfigFile);
    QStringList configPair;
    while (!fileStream.atEnd()) {
        QString line = fileStream.readLine();
        if(line.startsWith("#") || line.isEmpty())
            continue;
        configPair = line.split(" = ");

        appConfigMap[configPair[0].trimmed()]=configPair[1].trimmed();
    }

    appConfigFile.resize(0);

    appConfigMap["lastTimeIniFile"] = configFileName;

    QString content;
    for (auto it = appConfigMap.constBegin(); it != appConfigMap.constEnd(); ++it) {
        content += it.key() + " = " + it.value() + "\n";
    }
    fileStream << content;
}

void MainWindow::on_actionSave_Config_triggered()
{
    //Please let me save my config
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Current Figuration"), "",
                                                    tr("biosim4 configuration file(*.ini)"));
    if (fileName.isEmpty())
        return;
    else {
        if(!fileName.endsWith(".ini")){
            QStringList fileSeg = fileName.split(".");
            fileName = fileSeg[0] + ".ini";
        }
        qDebug()<<fileName;

        // save to file
        saveCurrentConfigToFile(fileName);

        logger("Saved current parameters to: "+fileName);
    }
}

