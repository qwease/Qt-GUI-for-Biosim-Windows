#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "biosimparser.h"
#include "biosimrunner.h"
#include "biosimwidget.h"
#include "qlineedit.h"
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QTemporaryFile>
#include <QCloseEvent>
#include <vector>

#include <Windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void setParameters();
    void setRunFileName(QString filename);
    QMap<QString, QString> getParametersInUse() const;
    QString getRunFileName() const;

    QList<QImage> agentImageList;
    QList<QImage> survivorPlotImageList;
    QList<QImage> diversityPlotImageList;

    QString graphLogUpdateCommand = "start /B gnuplot --persist ./tools/survival-plot.gp && gnuplot --persist ./tools/diversity-plot.gp";

    int step = 0;
    int generation = 0;

    //signal response function
    void updateSimulationView(QImage lastFrame);
    void updateStep(int step);
    void updateGeneration(int generation);
    void updateAgentImage(QString fileName);
    void updatePlots();
    void updateSurvivorsInfo(QString survivorsInfo);

    void logger(QString log);

    ~MainWindow();

private:
    QString appInitFileName = "./application.ini";
    void startNewRun();
    void clearUpLastRun();
    void saveTempConfigToTempFile();
    void saveCurrentConfigToFile(QString fileName);
    void saveLastTimeActiveConfigToIniiFile(QString configFileName);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPointF lastMousePos;
    bool isPanning;

private:
    Ui::MainWindow *ui;
    BiosimParser biosimParser;
    BiosimRunner biosimRunner;
    // Create an instance of BiosimWidget and set it as the scene
    BiosimWidget *biosimWidget = new BiosimWidget(this);

    QString filename;
    QMap<QString, QString> parameters;
    QString getLastTimeIniFileName();

    bool pause = false;

    QTimer *autoRepeatTimer;
    unsigned short autoRepeatStage=0;

    void onButtonClicked(QString paramName,short increment, unsigned int low, unsigned int high, QLineEdit*target);
    void onButtonDownPressed(short * incrementValue);
    void onButtonDownReleased(short * incrementValue);
    void onButtonUpPressed(short * incrementValue);
    void onButtonUpReleased(short * incrementValue);

    std::vector<QString> notShortParamName {"stepsPerGeneration","maxGenerations","genomeInitialLengthMin","genomeInitialLengthMax","genomeMaxLength","maxNumberNeurons","responsivenessCurveKFactor","longProbeDistance","shortProbeBarrierDistance","displayScale","videoSaveFirstFrames","videoStride","updateGraphLogStride","genomeAnalysisStride","displaySampleGenomes","RNGSeed"};
    void updateParam(QString paramName,short increment, unsigned int low, unsigned int high, QLineEdit*target);
    bool isShortTypeParam(QString paramName);
    void genomeMaxLengthCheckCap();
    bool hasTimerActived = false;
    QString activeParam = "";
    QTemporaryFile tempFile;
    void closeEvent(QCloseEvent *closeEvent) override;

    bool parameterModified = false;

    void updateNumThreads();
    void updateSizeX();
    void updateSizeY();
    void updatePopulation();
    void updateStepsPerGeneration();
    void updateMaxGenerations();
    void updateGenomeInitialLengthMin();
    void updateGenomeInitialLengthMax();
    void updateGenomeMaxLength();
    void updateMaxNumberNeurons();
    void updateResponsivenessCurveKFactor();
    void updateLongProbeDistance();
    void updateShortProbeBarrierDistance();
    void updateDisplayScale();
    void updateAgentSize();
    void updateVideoSaveFirstFrames();
    void updateVideoStride();
    void updateDisplaySampleGenomes();
    void updateRNGSeed();
    short numThreadsAmount=0;
    short sizeXAmount=0;
    short sizeYAmount=0;
    short populationAmount=0;
    short stepsPerGenerationAmount=0;
    short maxGenerationsAmount=0;
    short genomeInitialLengthMinAmount=0;
    short genomeInitialLengthMaxAmount=0;
    short genomeMaxLengthAmount=0;
    short maxNumberNeuronsAmount=0;
    short responsivenessCurveKFactorAmount=0;
    short longProbeDistanceAmount=0;
    short shortProbeBarrierDistanceAmount=0;
    short displayScaleAmount=0;
    short agentSizeAmount=0;
    short videoSaveFirstFramesAmount=0;
    short videoStrideAmount=0;
    short displaySampleGenomesAmount=0;
    short RNGSeedAmount=0;

private slots:
    void on_actionLoad_Button_triggered();

    void on_actionRunSimulation_Button_triggered();

    void on_actionPauseSimulation_Button_triggered();

    void on_actionResetSimulation_Button_triggered();

    void on_actionLoad_triggered();

    void on_actionRun_triggered();

    void on_actionPause_triggered();

    void on_actionReset_triggered();

    void on_actionExitSimulation_Button_triggered();

    void on_numThreadsDownButton_clicked();

    void on_numThreadsUpButton_clicked();

    void numThreadsInputEditingFinished();

    void on_numThreadsUpButton_pressed();

    void on_numThreadsUpButton_released();

    void on_numThreadsInput_textChanged(const QString &arg1);

    void on_numThreadsDownButton_pressed();

    void on_numThreadsDownButton_released();

    void on_sizeXInput_editingFinished();

    void on_sizeXInput_textChanged(const QString &arg1);

    void on_sizeYInput_editingFinished();

    void on_sizeYInput_textChanged(const QString &arg1);

    void on_sizeXUpButton_clicked();

    void on_sizeXUpButton_pressed();

    void on_sizeXUpButton_released();

    void on_sizeXDownButton_clicked();

    void on_sizeXDownButton_pressed();

    void on_sizeXDownButton_released();

    void on_sizeYUpButton_clicked();

    void on_sizeYUpButton_pressed();

    void on_sizeYUpButton_released();

    void on_sizeYDownButton_clicked();

    void on_sizeYDownButton_pressed();

    void on_sizeYDownButton_released();

    void on_populationUpButton_clicked();

    void on_populationUpButton_pressed();

    void on_populationUpButton_released();

    void on_populationDownButton_clicked();

    void on_populationDownButton_pressed();

    void on_populationDownButton_released();

    void on_populationInput_editingFinished();

    void on_populationInput_textChanged(const QString &arg1);

    void on_maxGenerationsUpButton_clicked();

    void on_maxGenerationsUpButton_pressed();

    void on_maxGenerationsUpButton_released();

    void on_maxGenerationsDownButton_clicked();

    void on_maxGenerationsDownButton_pressed();

    void on_maxGenerationsDownButton_released();

    void on_maxGenerationsInput_editingFinished();

    void on_maxGenerationsInput_textChanged(const QString &arg1);

    void on_stepsPerGenerationUpButton_clicked();

    void on_stepsPerGenerationUpButton_pressed();

    void on_stepsPerGenerationUpButton_released();

    void on_stepsPerGenerationDownButton_clicked();

    void on_stepsPerGenerationDownButton_pressed();

    void on_stepsPerGenerationDownButton_released();

    void on_stepsPerGenerationInput_editingFinished();

    void on_stepsPerGenerationInput_textChanged(const QString &arg1);

    void on_genomeInitialLengthMinUpButton_clicked();

    void on_genomeInitialLengthMinUpButton_pressed();

    void on_genomeInitialLengthMinUpButton_released();

    void on_genomeInitialLengthMinDownButton_clicked();

    void on_genomeInitialLengthMinDownButton_pressed();

    void on_genomeInitialLengthMinDownButton_released();

    void on_genomeInitialLengthMinInput_editingFinished();

    void on_genomeInitialLengthMinInput_textChanged(const QString &arg1);

    void on_genomeInitialLengthMaxUpButton_clicked();

    void on_genomeInitialLengthMaxUpButton_pressed();

    void on_genomeInitialLengthMaxUpButton_released();

    void on_genomeInitialLengthMaxDownButton_clicked();

    void on_genomeInitialLengthMaxDownButton_pressed();

    void on_genomeInitialLengthMaxDownButton_released();

    void on_genomeInitialLengthMaxInput_editingFinished();

    void on_genomeInitialLengthMaxInput_textChanged(const QString &arg1);

    void on_genomeMaxLengthUpButton_clicked();

    void on_genomeMaxLengthUpButton_pressed();

    void on_genomeMaxLengthUpButton_released();

    void on_genomeMaxLengthDownButton_clicked();

    void on_genomeMaxLengthDownButton_pressed();

    void on_genomeMaxLengthDownButton_released();

    void on_genomeMaxLengthInput_editingFinished();

    void on_genomeMaxLengthInput_textChanged(const QString &arg1);

    void on_maxNumberNeuronsUpButton_clicked();

    void on_maxNumberNeuronsUpButton_pressed();

    void on_maxNumberNeuronsUpButton_released();

    void on_maxNumberNeuronsDownButton_clicked();

    void on_maxNumberNeuronsDownButton_pressed();

    void on_maxNumberNeuronsDownButton_released();

    void on_maxNumberNeuronsInput_editingFinished();

    void on_maxNumberNeuronsInput_textChanged(const QString &arg1);

    void on_killEnableCheckBox_stateChanged(int arg1);

    void on_sexualReproductionCheckBox_stateChanged(int arg1);

    void on_chooseParentsByFitnessCheckBox_stateChanged(int arg1);

    void on_pointMutationRateUpButton_clicked();

    void on_pointMutationRateUpButton_pressed();

    void on_pointMutationRateUpButton_released();

    void on_pointMutationRateDownButton_clicked();

    void on_pointMutationRateDownButton_pressed();

    void on_pointMutationRateDownButton_released();

    void on_pointMutationRateInput_editingFinished();

    void on_pointMutationRateInput_textChanged(const QString &arg1);

    void on_responsivenessCurveKFactorUpButton_clicked();

    void on_responsivenessCurveKFactorUpButton_pressed();

    void on_responsivenessCurveKFactorUpButton_released();

    void on_responsivenessCurveKFactorDownButton_clicked();

    void on_responsivenessCurveKFactorDownButton_pressed();

    void on_responsivenessCurveKFactorDownButton_released();

    void on_responsivenessCurveKFactorInput_editingFinished();

    void on_responsivenessCurveKFactorInput_textChanged(const QString &arg1);

    void on_populationSensorRadiusInput_editingFinished();

    void on_populationSensorRadiusInput_textChanged(const QString &arg1);

    void on_longProbeDistanceUpButton_clicked();

    void on_longProbeDistanceUpButton_pressed();

    void on_longProbeDistanceUpButton_released();

    void on_longProbeDistanceDownButton_clicked();

    void on_longProbeDistanceDownButton_pressed();

    void on_longProbeDistanceDownButton_released();

    void on_longProbeDistanceInput_editingFinished();

    void on_longProbeDistanceInput_textChanged(const QString &arg1);

    void on_shortProbeBarrierDistanceUpButton_clicked();

    void on_shortProbeBarrierDistanceUpButton_pressed();

    void on_shortProbeBarrierDistanceUpButton_released();

    void on_shortProbeBarrierDistanceDownButton_clicked();

    void on_shortProbeBarrierDistanceDownButton_pressed();

    void on_shortProbeBarrierDistanceDownButton_released();

    void on_shortProbeBarrierDistanceInput_editingFinished();

    void on_shortProbeBarrierDistanceInput_textChanged(const QString &arg1);

    void on_signalSensorRadiusUpButton_clicked();

    void on_signalSensorRadiusUpButton_pressed();

    void on_signalSensorRadiusUpButton_released();

    void on_signalSensorRadiusDownButton_clicked();

    void on_signalSensorRadiusDownButton_pressed();

    void on_signalSensorRadiusDownButton_released();

    void on_signalSensorRadiusInput_editingFinished();

    void on_signalSensorRadiusInput_textChanged(const QString &arg1);

    void on_imageDirButton_clicked();

    void on_logDirButton_clicked();

    void on_displayScaleUpButton_clicked();

    void on_displayScaleUpButton_pressed();

    void on_displayScaleUpButton_released();

    void on_displayScaleDownButton_clicked();

    void on_displayScaleDownButton_pressed();

    void on_displayScaleDownButton_released();

    void on_displayScaleInput_editingFinished();

    void on_displayScaleInput_textChanged(const QString &arg1);

    void on_agentSizeUpButton_clicked();

    void on_agentSizeUpButton_pressed();

    void on_agentSizeUpButton_released();

    void on_agentSizeDownButton_clicked();

    void on_agentSizeDownButton_pressed();

    void on_agentSizeDownButton_released();

    void on_agentSizeInput_editingFinished();

    void on_agentSizeInput_textChanged(const QString &arg1);

    void on_videoSaveFirstFramesUpButton_clicked();

    void on_videoSaveFirstFramesUpButton_pressed();

    void on_videoSaveFirstFramesUpButton_released();

    void on_videoSaveFirstFramesDownButton_clicked();

    void on_videoSaveFirstFramesDownButton_pressed();

    void on_videoSaveFirstFramesDownButton_released();

    void on_videoSaveFirstFramesInput_editingFinished();

    void on_videoSaveFirstFramesInput_textChanged(const QString &arg1);

    void on_updateGraphLogCheckBox_stateChanged(int arg1);

    void on_saveVideoCheckBox_stateChanged(int arg1);

    void on_genomeComparisonMethodComboBox_currentIndexChanged(int index);

    void on_videoStrideUpButton_clicked();

    void on_videoStrideUpButton_pressed();

    void on_videoStrideUpButton_released();

    void on_videoStrideDownButton_clicked();

    void on_videoStrideDownButton_pressed();

    void on_videoStrideDownButton_released();

    void on_videoStrideInput_editingFinished();

    void on_videoStrideInput_textChanged(const QString &arg1);

    void on_displaySampleGenomesUpButton_clicked();

    void on_displaySampleGenomesUpButton_pressed();

    void on_displaySampleGenomesUpButton_released();

    void on_displaySampleGenomesDownButton_clicked();

    void on_displaySampleGenomesDownButton_pressed();

    void on_displaySampleGenomesDownButton_released();

    void on_displaySampleGenomesInput_editingFinished();

    void on_displaySampleGenomesInput_textChanged(const QString &arg1);

    void on_challengeComboBox_currentIndexChanged(int index);

    void on_barrierTypeComboBox_currentIndexChanged(int index);

    void on_deterministicCheckBox_stateChanged(int arg1);

    void on_RNGSeedUpButton_clicked();

    void on_RNGSeedUpButton_pressed();

    void on_RNGSeedUpButton_released();

    void on_RNGSeedDownButton_clicked();

    void on_RNGSeedDownButton_released();

    void on_RNGSeedDownButton_pressed();

    void on_RNGSeedInput_editingFinished();

    void on_RNGSeedInput_textChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_saveConfigButton_clicked();
    void on_actionSave_Config_triggered();
};
#endif // MAINWINDOW_H
