/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "DoubleClickableGraphicsView.h"
#include "SimulationGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionRun;
    QAction *actionPause;
    QAction *actionReset;
    QAction *actionLoad_Button;
    QAction *actionRunSimulation_Button;
    QAction *actionPauseSimulation_Button;
    QAction *actionResetSimulation_Button;
    QAction *actionExitSimulation_Button;
    QAction *actionSave_Config;
    QWidget *centralwidget;
    SimulationGraphicsView *graphicsViewSimulation;
    QTabWidget *tabWidget;
    QWidget *Parameters;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *numThreadsLayout;
    QLineEdit *numThreadsInput;
    QPushButton *numThreadsDownButton;
    QPushButton *numThreadsUpButton;
    QLabel *numThreadsLabel;
    QHBoxLayout *populationLayout;
    QLineEdit *populationInput;
    QPushButton *populationDownButton;
    QPushButton *populationUpButton;
    QLabel *populationLabel;
    QHBoxLayout *sizeXLayout;
    QLineEdit *sizeXInput;
    QPushButton *sizeXDownButton;
    QPushButton *sizeXUpButton;
    QLabel *sizeXLabel;
    QHBoxLayout *sizeYLayout;
    QLineEdit *sizeYInput;
    QPushButton *sizeYDownButton;
    QPushButton *sizeYUpButton;
    QLabel *sizeYLabel;
    QHBoxLayout *stepsPerGenerationLayout;
    QLineEdit *stepsPerGenerationInput;
    QPushButton *stepsPerGenerationDownButton;
    QPushButton *stepsPerGenerationUpButton;
    QLabel *stepsPerGenerationLabel;
    QHBoxLayout *maxGenerationsLayout;
    QLineEdit *maxGenerationsInput;
    QPushButton *maxGenerationsDownButton;
    QPushButton *maxGenerationsUpButton;
    QLabel *maxGenerationsLabel;
    QHBoxLayout *genomeInitialLengthMinLayout;
    QLineEdit *genomeInitialLengthMinInput;
    QPushButton *genomeInitialLengthMinDownButton;
    QPushButton *genomeInitialLengthMinUpButton;
    QLabel *genomeInitialLengthMinLabel;
    QHBoxLayout *genomeInitialLengthMaxLayout;
    QLineEdit *genomeInitialLengthMaxInput;
    QPushButton *genomeInitialLengthMaxDownButton;
    QPushButton *genomeInitialLengthMaxUpButton;
    QLabel *genomeInitialLengthMaxLabel;
    QHBoxLayout *genomeMaxLengthLayout;
    QLineEdit *genomeMaxLengthInput;
    QPushButton *genomeMaxLengthDownButton;
    QPushButton *genomeMaxLengthUpButton;
    QLabel *genomeMaxLengthLabel;
    QHBoxLayout *maxNumberNeuronsLayout;
    QLineEdit *maxNumberNeuronsInput;
    QPushButton *maxNumberNeuronsDownButton;
    QPushButton *maxNumberNeuronsUpButton;
    QLabel *maxNumberNeuronsLabel;
    QHBoxLayout *killableLayout;
    QCheckBox *killEnableCheckBox;
    QHBoxLayout *sexualReproductionLayout;
    QCheckBox *sexualReproductionCheckBox;
    QHBoxLayout *chooseParentsByFitnessLayout;
    QCheckBox *chooseParentsByFitnessCheckBox;
    QHBoxLayout *pointMutationRateLayout;
    QLineEdit *pointMutationRateInput;
    QPushButton *pointMutationRateDownButton;
    QPushButton *pointMutationRateUpButton;
    QLabel *pointMutationRateLabel;
    QHBoxLayout *geneInsertionDeletionRateLayout;
    QLineEdit *geneInsertionDeletionRateInput;
    QPushButton *geneInsertionDeletionRateDownButton;
    QPushButton *geneInsertionDeletionRateUpButton;
    QLabel *geneInsertionDeletionRateLabel;
    QHBoxLayout *deletionRatioLayout;
    QLineEdit *deletionRatioInput;
    QPushButton *deletionRatioDownButton;
    QPushButton *deletionRatioUpButton;
    QLabel *deletionRatioLabel;
    QHBoxLayout *responsivenessCurveKFactorLayout;
    QLineEdit *responsivenessCurveKFactorInput;
    QPushButton *responsivenessCurveKFactorDownButton;
    QPushButton *responsivenessCurveKFactorUpButton;
    QLabel *responsivenessCurveKFactorLabel;
    QHBoxLayout *populationSensorRadiusLayout;
    QLineEdit *populationSensorRadiusInput;
    QPushButton *populationSensorRadiusDownButton;
    QPushButton *populationSensorRadiusUpButton;
    QLabel *populationSensorRadiusLabel;
    QHBoxLayout *longProbeDistanceLayout;
    QLineEdit *longProbeDistanceInput;
    QPushButton *longProbeDistanceDownButton;
    QPushButton *longProbeDistanceUpButton;
    QLabel *longProbeDistanceLabel;
    QHBoxLayout *shortProbeBarrierDistanceLayout;
    QLineEdit *shortProbeBarrierDistanceInput;
    QPushButton *shortProbeBarrierDistanceDownButton;
    QPushButton *shortProbeBarrierDistanceUpButton;
    QLabel *shortProbeBarrierDistanceLabel;
    QHBoxLayout *signalSensorRadiusLayout;
    QLineEdit *signalSensorRadiusInput;
    QPushButton *signalSensorRadiusDownButton;
    QPushButton *signalSensorRadiusUpButton;
    QLabel *signalSensorRadiusLabel;
    QHBoxLayout *signalLayersLayout;
    QLineEdit *signalLayersInput;
    QPushButton *signalLayersDownButton;
    QPushButton *signalLayersUpButton;
    QLabel *signalLayersLabel;
    QHBoxLayout *imageDirLayout;
    QLineEdit *imageDirInput;
    QPushButton *imageDirButton;
    QLabel *imageDirLabel;
    QHBoxLayout *logDirLayout;
    QLineEdit *logDirInput;
    QPushButton *logDirButton;
    QLabel *logDirLabel;
    QHBoxLayout *displayScaleLayout;
    QLineEdit *displayScaleInput;
    QPushButton *displayScaleDownButton;
    QPushButton *displayScaleUpButton;
    QLabel *displayScaleLabel;
    QHBoxLayout *agentSizeLayout;
    QLineEdit *agentSizeInput;
    QPushButton *agentSizeDownButton;
    QPushButton *agentSizeUpButton;
    QLabel *agentSizeLabel;
    QHBoxLayout *videoSaveFirstFramesLayout;
    QLineEdit *videoSaveFirstFramesInput;
    QPushButton *videoSaveFirstFramesDownButton;
    QPushButton *videoSaveFirstFramesUpButton;
    QLabel *videoSaveFirstFramesLabel;
    QHBoxLayout *updateGraphLogLayout;
    QCheckBox *updateGraphLogCheckBox;
    QHBoxLayout *saveVideoLayout;
    QCheckBox *saveVideoCheckBox;
    QHBoxLayout *videoStrideLayout;
    QLineEdit *videoStrideInput;
    QPushButton *videoStrideDownButton;
    QPushButton *videoStrideUpButton;
    QLabel *videoStrideLabel;
    QHBoxLayout *genomeComparisonMethodLayout;
    QComboBox *genomeComparisonMethodComboBox;
    QLabel *genomeComparisonMethodLabel;
    QHBoxLayout *displaySampleGenomesLayout;
    QLineEdit *displaySampleGenomesInput;
    QPushButton *displaySampleGenomesDownButton;
    QPushButton *displaySampleGenomesUpButton;
    QLabel *displaySampleGenomesLabel;
    QHBoxLayout *challengeLayout;
    QComboBox *challengeComboBox;
    QLabel *challengeLabel;
    QHBoxLayout *barrierTypeLayout;
    QComboBox *barrierTypeComboBox;
    QLabel *barrierTypeLabel;
    QHBoxLayout *deterministicLayout;
    QCheckBox *deterministicCheckBox;
    QHBoxLayout *RNGSeedLayout;
    QLineEdit *RNGSeedInput;
    QPushButton *RNGSeedDownButton;
    QPushButton *RNGSeedUpButton;
    QLabel *RNGSeedLabel;
    QWidget *Graphs;
    DoubleClickableGraphicsView *survivalView;
    QLabel *survivalLabel;
    QLabel *diversityLabel;
    DoubleClickableGraphicsView *diversityView;
    QWidget *Agent;
    QGraphicsView *graphicsViewAgent;
    QLabel *generationLabel;
    QFrame *line;
    QLabel *quickInfo;
    QLabel *stepLabel;
    QPushButton *saveConfigButton;
    QLabel *lastGenSurvivorsLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSimulation;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2500, 1400);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f0f0f0;\n"
"}"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName("actionRun");
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName("actionPause");
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName("actionReset");
        actionLoad_Button = new QAction(MainWindow);
        actionLoad_Button->setObjectName("actionLoad_Button");
        actionLoad_Button->setMenuRole(QAction::NoRole);
        actionRunSimulation_Button = new QAction(MainWindow);
        actionRunSimulation_Button->setObjectName("actionRunSimulation_Button");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playback-start")));
        actionRunSimulation_Button->setIcon(icon);
        actionRunSimulation_Button->setMenuRole(QAction::NoRole);
        actionPauseSimulation_Button = new QAction(MainWindow);
        actionPauseSimulation_Button->setObjectName("actionPauseSimulation_Button");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("media-playback-pause")));
        actionPauseSimulation_Button->setIcon(icon1);
        actionPauseSimulation_Button->setMenuRole(QAction::NoRole);
        actionResetSimulation_Button = new QAction(MainWindow);
        actionResetSimulation_Button->setObjectName("actionResetSimulation_Button");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("view-refresh")));
        actionResetSimulation_Button->setIcon(icon2);
        actionResetSimulation_Button->setMenuRole(QAction::NoRole);
        actionExitSimulation_Button = new QAction(MainWindow);
        actionExitSimulation_Button->setObjectName("actionExitSimulation_Button");
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("process-stop")));
        actionExitSimulation_Button->setIcon(icon3);
        actionExitSimulation_Button->setMenuRole(QAction::NoRole);
        actionSave_Config = new QAction(MainWindow);
        actionSave_Config->setObjectName("actionSave_Config");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        graphicsViewSimulation = new SimulationGraphicsView(centralwidget);
        graphicsViewSimulation->setObjectName("graphicsViewSimulation");
        graphicsViewSimulation->setGeometry(QRect(869, 119, 1600, 1153));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsViewSimulation->sizePolicy().hasHeightForWidth());
        graphicsViewSimulation->setSizePolicy(sizePolicy1);
        graphicsViewSimulation->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    border: 1px solid #c0c0c0;\n"
"}"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 90, 811, 1181));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #c0c0c0;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #c0c0c0;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom-color: white;\n"
"}"));
        Parameters = new QWidget();
        Parameters->setObjectName("Parameters");
        scrollArea = new QScrollArea(Parameters);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 811, 1141));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: white;\n"
"}"));
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 11, 800, 1130));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(4, 0, 0, 0);
        numThreadsLayout = new QHBoxLayout();
        numThreadsLayout->setSpacing(3);
        numThreadsLayout->setObjectName("numThreadsLayout");
        numThreadsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        numThreadsInput = new QLineEdit(scrollAreaWidgetContents);
        numThreadsInput->setObjectName("numThreadsInput");
        numThreadsInput->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(15);
        numThreadsInput->setFont(font1);

        numThreadsLayout->addWidget(numThreadsInput);

        numThreadsDownButton = new QPushButton(scrollAreaWidgetContents);
        numThreadsDownButton->setObjectName("numThreadsDownButton");
        sizePolicy1.setHeightForWidth(numThreadsDownButton->sizePolicy().hasHeightForWidth());
        numThreadsDownButton->setSizePolicy(sizePolicy1);
        numThreadsDownButton->setMinimumSize(QSize(10, 10));
        numThreadsDownButton->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Ubuntu")});
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setItalic(false);
        numThreadsDownButton->setFont(font2);

        numThreadsLayout->addWidget(numThreadsDownButton);

        numThreadsUpButton = new QPushButton(scrollAreaWidgetContents);
        numThreadsUpButton->setObjectName("numThreadsUpButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(numThreadsUpButton->sizePolicy().hasHeightForWidth());
        numThreadsUpButton->setSizePolicy(sizePolicy2);
        numThreadsUpButton->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setPointSize(17);
        font3.setBold(false);
        font3.setItalic(false);
        numThreadsUpButton->setFont(font3);

        numThreadsLayout->addWidget(numThreadsUpButton);

        numThreadsLabel = new QLabel(scrollAreaWidgetContents);
        numThreadsLabel->setObjectName("numThreadsLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(numThreadsLabel->sizePolicy().hasHeightForWidth());
        numThreadsLabel->setSizePolicy(sizePolicy3);
        numThreadsLabel->setMaximumSize(QSize(16777215, 30));
        numThreadsLabel->setFont(font2);

        numThreadsLayout->addWidget(numThreadsLabel);

        numThreadsLayout->setStretch(0, 4);
        numThreadsLayout->setStretch(3, 3);

        verticalLayout->addLayout(numThreadsLayout);

        populationLayout = new QHBoxLayout();
        populationLayout->setSpacing(3);
        populationLayout->setObjectName("populationLayout");
        populationLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        populationInput = new QLineEdit(scrollAreaWidgetContents);
        populationInput->setObjectName("populationInput");
        populationInput->setMaximumSize(QSize(16777215, 30));
        populationInput->setFont(font1);

        populationLayout->addWidget(populationInput);

        populationDownButton = new QPushButton(scrollAreaWidgetContents);
        populationDownButton->setObjectName("populationDownButton");
        sizePolicy1.setHeightForWidth(populationDownButton->sizePolicy().hasHeightForWidth());
        populationDownButton->setSizePolicy(sizePolicy1);
        populationDownButton->setMinimumSize(QSize(10, 10));
        populationDownButton->setMaximumSize(QSize(30, 30));
        populationDownButton->setFont(font2);

        populationLayout->addWidget(populationDownButton);

        populationUpButton = new QPushButton(scrollAreaWidgetContents);
        populationUpButton->setObjectName("populationUpButton");
        sizePolicy2.setHeightForWidth(populationUpButton->sizePolicy().hasHeightForWidth());
        populationUpButton->setSizePolicy(sizePolicy2);
        populationUpButton->setMaximumSize(QSize(30, 30));
        populationUpButton->setFont(font3);

        populationLayout->addWidget(populationUpButton);

        populationLabel = new QLabel(scrollAreaWidgetContents);
        populationLabel->setObjectName("populationLabel");
        sizePolicy3.setHeightForWidth(populationLabel->sizePolicy().hasHeightForWidth());
        populationLabel->setSizePolicy(sizePolicy3);
        populationLabel->setMaximumSize(QSize(16777215, 30));
        populationLabel->setFont(font2);

        populationLayout->addWidget(populationLabel);

        populationLayout->setStretch(0, 4);
        populationLayout->setStretch(3, 3);

        verticalLayout->addLayout(populationLayout);

        sizeXLayout = new QHBoxLayout();
        sizeXLayout->setSpacing(3);
        sizeXLayout->setObjectName("sizeXLayout");
        sizeXLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        sizeXInput = new QLineEdit(scrollAreaWidgetContents);
        sizeXInput->setObjectName("sizeXInput");
        sizeXInput->setMaximumSize(QSize(16777215, 30));
        sizeXInput->setFont(font1);

        sizeXLayout->addWidget(sizeXInput);

        sizeXDownButton = new QPushButton(scrollAreaWidgetContents);
        sizeXDownButton->setObjectName("sizeXDownButton");
        sizePolicy1.setHeightForWidth(sizeXDownButton->sizePolicy().hasHeightForWidth());
        sizeXDownButton->setSizePolicy(sizePolicy1);
        sizeXDownButton->setMinimumSize(QSize(10, 10));
        sizeXDownButton->setMaximumSize(QSize(30, 30));
        sizeXDownButton->setFont(font2);

        sizeXLayout->addWidget(sizeXDownButton);

        sizeXUpButton = new QPushButton(scrollAreaWidgetContents);
        sizeXUpButton->setObjectName("sizeXUpButton");
        sizePolicy2.setHeightForWidth(sizeXUpButton->sizePolicy().hasHeightForWidth());
        sizeXUpButton->setSizePolicy(sizePolicy2);
        sizeXUpButton->setMaximumSize(QSize(30, 30));
        sizeXUpButton->setFont(font3);

        sizeXLayout->addWidget(sizeXUpButton);

        sizeXLabel = new QLabel(scrollAreaWidgetContents);
        sizeXLabel->setObjectName("sizeXLabel");
        sizePolicy3.setHeightForWidth(sizeXLabel->sizePolicy().hasHeightForWidth());
        sizeXLabel->setSizePolicy(sizePolicy3);
        sizeXLabel->setMaximumSize(QSize(16777215, 30));
        sizeXLabel->setFont(font2);

        sizeXLayout->addWidget(sizeXLabel);

        sizeXLayout->setStretch(0, 4);
        sizeXLayout->setStretch(3, 3);

        verticalLayout->addLayout(sizeXLayout);

        sizeYLayout = new QHBoxLayout();
        sizeYLayout->setSpacing(3);
        sizeYLayout->setObjectName("sizeYLayout");
        sizeYLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        sizeYInput = new QLineEdit(scrollAreaWidgetContents);
        sizeYInput->setObjectName("sizeYInput");
        sizeYInput->setMaximumSize(QSize(16777215, 30));
        sizeYInput->setFont(font1);

        sizeYLayout->addWidget(sizeYInput);

        sizeYDownButton = new QPushButton(scrollAreaWidgetContents);
        sizeYDownButton->setObjectName("sizeYDownButton");
        sizePolicy1.setHeightForWidth(sizeYDownButton->sizePolicy().hasHeightForWidth());
        sizeYDownButton->setSizePolicy(sizePolicy1);
        sizeYDownButton->setMinimumSize(QSize(10, 10));
        sizeYDownButton->setMaximumSize(QSize(30, 30));
        sizeYDownButton->setFont(font2);

        sizeYLayout->addWidget(sizeYDownButton);

        sizeYUpButton = new QPushButton(scrollAreaWidgetContents);
        sizeYUpButton->setObjectName("sizeYUpButton");
        sizePolicy2.setHeightForWidth(sizeYUpButton->sizePolicy().hasHeightForWidth());
        sizeYUpButton->setSizePolicy(sizePolicy2);
        sizeYUpButton->setMaximumSize(QSize(30, 30));
        sizeYUpButton->setFont(font3);

        sizeYLayout->addWidget(sizeYUpButton);

        sizeYLabel = new QLabel(scrollAreaWidgetContents);
        sizeYLabel->setObjectName("sizeYLabel");
        sizePolicy3.setHeightForWidth(sizeYLabel->sizePolicy().hasHeightForWidth());
        sizeYLabel->setSizePolicy(sizePolicy3);
        sizeYLabel->setMaximumSize(QSize(16777215, 30));
        sizeYLabel->setFont(font2);

        sizeYLayout->addWidget(sizeYLabel);

        sizeYLayout->setStretch(0, 4);
        sizeYLayout->setStretch(3, 3);

        verticalLayout->addLayout(sizeYLayout);

        stepsPerGenerationLayout = new QHBoxLayout();
        stepsPerGenerationLayout->setSpacing(3);
        stepsPerGenerationLayout->setObjectName("stepsPerGenerationLayout");
        stepsPerGenerationLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        stepsPerGenerationInput = new QLineEdit(scrollAreaWidgetContents);
        stepsPerGenerationInput->setObjectName("stepsPerGenerationInput");
        stepsPerGenerationInput->setMaximumSize(QSize(16777215, 30));
        stepsPerGenerationInput->setFont(font1);

        stepsPerGenerationLayout->addWidget(stepsPerGenerationInput);

        stepsPerGenerationDownButton = new QPushButton(scrollAreaWidgetContents);
        stepsPerGenerationDownButton->setObjectName("stepsPerGenerationDownButton");
        sizePolicy1.setHeightForWidth(stepsPerGenerationDownButton->sizePolicy().hasHeightForWidth());
        stepsPerGenerationDownButton->setSizePolicy(sizePolicy1);
        stepsPerGenerationDownButton->setMinimumSize(QSize(10, 10));
        stepsPerGenerationDownButton->setMaximumSize(QSize(30, 30));
        stepsPerGenerationDownButton->setFont(font2);

        stepsPerGenerationLayout->addWidget(stepsPerGenerationDownButton);

        stepsPerGenerationUpButton = new QPushButton(scrollAreaWidgetContents);
        stepsPerGenerationUpButton->setObjectName("stepsPerGenerationUpButton");
        sizePolicy2.setHeightForWidth(stepsPerGenerationUpButton->sizePolicy().hasHeightForWidth());
        stepsPerGenerationUpButton->setSizePolicy(sizePolicy2);
        stepsPerGenerationUpButton->setMaximumSize(QSize(30, 30));
        stepsPerGenerationUpButton->setFont(font3);

        stepsPerGenerationLayout->addWidget(stepsPerGenerationUpButton);

        stepsPerGenerationLabel = new QLabel(scrollAreaWidgetContents);
        stepsPerGenerationLabel->setObjectName("stepsPerGenerationLabel");
        sizePolicy3.setHeightForWidth(stepsPerGenerationLabel->sizePolicy().hasHeightForWidth());
        stepsPerGenerationLabel->setSizePolicy(sizePolicy3);
        stepsPerGenerationLabel->setMaximumSize(QSize(16777215, 30));
        stepsPerGenerationLabel->setFont(font2);

        stepsPerGenerationLayout->addWidget(stepsPerGenerationLabel);

        stepsPerGenerationLayout->setStretch(0, 4);
        stepsPerGenerationLayout->setStretch(3, 3);

        verticalLayout->addLayout(stepsPerGenerationLayout);

        maxGenerationsLayout = new QHBoxLayout();
        maxGenerationsLayout->setSpacing(3);
        maxGenerationsLayout->setObjectName("maxGenerationsLayout");
        maxGenerationsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        maxGenerationsInput = new QLineEdit(scrollAreaWidgetContents);
        maxGenerationsInput->setObjectName("maxGenerationsInput");
        maxGenerationsInput->setMaximumSize(QSize(16777215, 30));
        maxGenerationsInput->setFont(font1);

        maxGenerationsLayout->addWidget(maxGenerationsInput);

        maxGenerationsDownButton = new QPushButton(scrollAreaWidgetContents);
        maxGenerationsDownButton->setObjectName("maxGenerationsDownButton");
        sizePolicy1.setHeightForWidth(maxGenerationsDownButton->sizePolicy().hasHeightForWidth());
        maxGenerationsDownButton->setSizePolicy(sizePolicy1);
        maxGenerationsDownButton->setMinimumSize(QSize(10, 10));
        maxGenerationsDownButton->setMaximumSize(QSize(30, 30));
        maxGenerationsDownButton->setFont(font2);

        maxGenerationsLayout->addWidget(maxGenerationsDownButton);

        maxGenerationsUpButton = new QPushButton(scrollAreaWidgetContents);
        maxGenerationsUpButton->setObjectName("maxGenerationsUpButton");
        sizePolicy2.setHeightForWidth(maxGenerationsUpButton->sizePolicy().hasHeightForWidth());
        maxGenerationsUpButton->setSizePolicy(sizePolicy2);
        maxGenerationsUpButton->setMaximumSize(QSize(30, 30));
        maxGenerationsUpButton->setFont(font3);

        maxGenerationsLayout->addWidget(maxGenerationsUpButton);

        maxGenerationsLabel = new QLabel(scrollAreaWidgetContents);
        maxGenerationsLabel->setObjectName("maxGenerationsLabel");
        sizePolicy3.setHeightForWidth(maxGenerationsLabel->sizePolicy().hasHeightForWidth());
        maxGenerationsLabel->setSizePolicy(sizePolicy3);
        maxGenerationsLabel->setMaximumSize(QSize(16777215, 30));
        maxGenerationsLabel->setFont(font2);

        maxGenerationsLayout->addWidget(maxGenerationsLabel);

        maxGenerationsLayout->setStretch(0, 4);
        maxGenerationsLayout->setStretch(3, 3);

        verticalLayout->addLayout(maxGenerationsLayout);

        genomeInitialLengthMinLayout = new QHBoxLayout();
        genomeInitialLengthMinLayout->setSpacing(3);
        genomeInitialLengthMinLayout->setObjectName("genomeInitialLengthMinLayout");
        genomeInitialLengthMinLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        genomeInitialLengthMinInput = new QLineEdit(scrollAreaWidgetContents);
        genomeInitialLengthMinInput->setObjectName("genomeInitialLengthMinInput");
        genomeInitialLengthMinInput->setMaximumSize(QSize(16777215, 30));
        genomeInitialLengthMinInput->setFont(font1);

        genomeInitialLengthMinLayout->addWidget(genomeInitialLengthMinInput);

        genomeInitialLengthMinDownButton = new QPushButton(scrollAreaWidgetContents);
        genomeInitialLengthMinDownButton->setObjectName("genomeInitialLengthMinDownButton");
        sizePolicy1.setHeightForWidth(genomeInitialLengthMinDownButton->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMinDownButton->setSizePolicy(sizePolicy1);
        genomeInitialLengthMinDownButton->setMinimumSize(QSize(10, 10));
        genomeInitialLengthMinDownButton->setMaximumSize(QSize(30, 30));
        genomeInitialLengthMinDownButton->setFont(font2);

        genomeInitialLengthMinLayout->addWidget(genomeInitialLengthMinDownButton);

        genomeInitialLengthMinUpButton = new QPushButton(scrollAreaWidgetContents);
        genomeInitialLengthMinUpButton->setObjectName("genomeInitialLengthMinUpButton");
        sizePolicy2.setHeightForWidth(genomeInitialLengthMinUpButton->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMinUpButton->setSizePolicy(sizePolicy2);
        genomeInitialLengthMinUpButton->setMaximumSize(QSize(30, 30));
        genomeInitialLengthMinUpButton->setFont(font3);

        genomeInitialLengthMinLayout->addWidget(genomeInitialLengthMinUpButton);

        genomeInitialLengthMinLabel = new QLabel(scrollAreaWidgetContents);
        genomeInitialLengthMinLabel->setObjectName("genomeInitialLengthMinLabel");
        sizePolicy3.setHeightForWidth(genomeInitialLengthMinLabel->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMinLabel->setSizePolicy(sizePolicy3);
        genomeInitialLengthMinLabel->setMaximumSize(QSize(16777215, 30));
        genomeInitialLengthMinLabel->setFont(font2);

        genomeInitialLengthMinLayout->addWidget(genomeInitialLengthMinLabel);

        genomeInitialLengthMinLayout->setStretch(0, 4);
        genomeInitialLengthMinLayout->setStretch(3, 3);

        verticalLayout->addLayout(genomeInitialLengthMinLayout);

        genomeInitialLengthMaxLayout = new QHBoxLayout();
        genomeInitialLengthMaxLayout->setSpacing(3);
        genomeInitialLengthMaxLayout->setObjectName("genomeInitialLengthMaxLayout");
        genomeInitialLengthMaxLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        genomeInitialLengthMaxInput = new QLineEdit(scrollAreaWidgetContents);
        genomeInitialLengthMaxInput->setObjectName("genomeInitialLengthMaxInput");
        genomeInitialLengthMaxInput->setMaximumSize(QSize(16777215, 30));
        genomeInitialLengthMaxInput->setFont(font1);

        genomeInitialLengthMaxLayout->addWidget(genomeInitialLengthMaxInput);

        genomeInitialLengthMaxDownButton = new QPushButton(scrollAreaWidgetContents);
        genomeInitialLengthMaxDownButton->setObjectName("genomeInitialLengthMaxDownButton");
        sizePolicy1.setHeightForWidth(genomeInitialLengthMaxDownButton->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMaxDownButton->setSizePolicy(sizePolicy1);
        genomeInitialLengthMaxDownButton->setMinimumSize(QSize(10, 10));
        genomeInitialLengthMaxDownButton->setMaximumSize(QSize(30, 30));
        genomeInitialLengthMaxDownButton->setFont(font2);

        genomeInitialLengthMaxLayout->addWidget(genomeInitialLengthMaxDownButton);

        genomeInitialLengthMaxUpButton = new QPushButton(scrollAreaWidgetContents);
        genomeInitialLengthMaxUpButton->setObjectName("genomeInitialLengthMaxUpButton");
        sizePolicy2.setHeightForWidth(genomeInitialLengthMaxUpButton->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMaxUpButton->setSizePolicy(sizePolicy2);
        genomeInitialLengthMaxUpButton->setMaximumSize(QSize(30, 30));
        genomeInitialLengthMaxUpButton->setFont(font3);

        genomeInitialLengthMaxLayout->addWidget(genomeInitialLengthMaxUpButton);

        genomeInitialLengthMaxLabel = new QLabel(scrollAreaWidgetContents);
        genomeInitialLengthMaxLabel->setObjectName("genomeInitialLengthMaxLabel");
        sizePolicy3.setHeightForWidth(genomeInitialLengthMaxLabel->sizePolicy().hasHeightForWidth());
        genomeInitialLengthMaxLabel->setSizePolicy(sizePolicy3);
        genomeInitialLengthMaxLabel->setMaximumSize(QSize(16777215, 30));
        genomeInitialLengthMaxLabel->setFont(font2);

        genomeInitialLengthMaxLayout->addWidget(genomeInitialLengthMaxLabel);

        genomeInitialLengthMaxLayout->setStretch(0, 4);
        genomeInitialLengthMaxLayout->setStretch(3, 3);

        verticalLayout->addLayout(genomeInitialLengthMaxLayout);

        genomeMaxLengthLayout = new QHBoxLayout();
        genomeMaxLengthLayout->setSpacing(3);
        genomeMaxLengthLayout->setObjectName("genomeMaxLengthLayout");
        genomeMaxLengthLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        genomeMaxLengthInput = new QLineEdit(scrollAreaWidgetContents);
        genomeMaxLengthInput->setObjectName("genomeMaxLengthInput");
        genomeMaxLengthInput->setMaximumSize(QSize(16777215, 30));
        genomeMaxLengthInput->setFont(font1);

        genomeMaxLengthLayout->addWidget(genomeMaxLengthInput);

        genomeMaxLengthDownButton = new QPushButton(scrollAreaWidgetContents);
        genomeMaxLengthDownButton->setObjectName("genomeMaxLengthDownButton");
        sizePolicy1.setHeightForWidth(genomeMaxLengthDownButton->sizePolicy().hasHeightForWidth());
        genomeMaxLengthDownButton->setSizePolicy(sizePolicy1);
        genomeMaxLengthDownButton->setMinimumSize(QSize(10, 10));
        genomeMaxLengthDownButton->setMaximumSize(QSize(30, 30));
        genomeMaxLengthDownButton->setFont(font2);

        genomeMaxLengthLayout->addWidget(genomeMaxLengthDownButton);

        genomeMaxLengthUpButton = new QPushButton(scrollAreaWidgetContents);
        genomeMaxLengthUpButton->setObjectName("genomeMaxLengthUpButton");
        sizePolicy2.setHeightForWidth(genomeMaxLengthUpButton->sizePolicy().hasHeightForWidth());
        genomeMaxLengthUpButton->setSizePolicy(sizePolicy2);
        genomeMaxLengthUpButton->setMaximumSize(QSize(30, 30));
        genomeMaxLengthUpButton->setFont(font3);

        genomeMaxLengthLayout->addWidget(genomeMaxLengthUpButton);

        genomeMaxLengthLabel = new QLabel(scrollAreaWidgetContents);
        genomeMaxLengthLabel->setObjectName("genomeMaxLengthLabel");
        sizePolicy3.setHeightForWidth(genomeMaxLengthLabel->sizePolicy().hasHeightForWidth());
        genomeMaxLengthLabel->setSizePolicy(sizePolicy3);
        genomeMaxLengthLabel->setMaximumSize(QSize(16777215, 30));
        genomeMaxLengthLabel->setFont(font2);

        genomeMaxLengthLayout->addWidget(genomeMaxLengthLabel);

        genomeMaxLengthLayout->setStretch(0, 4);
        genomeMaxLengthLayout->setStretch(3, 3);

        verticalLayout->addLayout(genomeMaxLengthLayout);

        maxNumberNeuronsLayout = new QHBoxLayout();
        maxNumberNeuronsLayout->setSpacing(3);
        maxNumberNeuronsLayout->setObjectName("maxNumberNeuronsLayout");
        maxNumberNeuronsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        maxNumberNeuronsInput = new QLineEdit(scrollAreaWidgetContents);
        maxNumberNeuronsInput->setObjectName("maxNumberNeuronsInput");
        maxNumberNeuronsInput->setMaximumSize(QSize(16777215, 30));
        maxNumberNeuronsInput->setFont(font1);

        maxNumberNeuronsLayout->addWidget(maxNumberNeuronsInput);

        maxNumberNeuronsDownButton = new QPushButton(scrollAreaWidgetContents);
        maxNumberNeuronsDownButton->setObjectName("maxNumberNeuronsDownButton");
        sizePolicy1.setHeightForWidth(maxNumberNeuronsDownButton->sizePolicy().hasHeightForWidth());
        maxNumberNeuronsDownButton->setSizePolicy(sizePolicy1);
        maxNumberNeuronsDownButton->setMinimumSize(QSize(10, 10));
        maxNumberNeuronsDownButton->setMaximumSize(QSize(30, 30));
        maxNumberNeuronsDownButton->setFont(font2);

        maxNumberNeuronsLayout->addWidget(maxNumberNeuronsDownButton);

        maxNumberNeuronsUpButton = new QPushButton(scrollAreaWidgetContents);
        maxNumberNeuronsUpButton->setObjectName("maxNumberNeuronsUpButton");
        sizePolicy2.setHeightForWidth(maxNumberNeuronsUpButton->sizePolicy().hasHeightForWidth());
        maxNumberNeuronsUpButton->setSizePolicy(sizePolicy2);
        maxNumberNeuronsUpButton->setMaximumSize(QSize(30, 30));
        maxNumberNeuronsUpButton->setFont(font3);

        maxNumberNeuronsLayout->addWidget(maxNumberNeuronsUpButton);

        maxNumberNeuronsLabel = new QLabel(scrollAreaWidgetContents);
        maxNumberNeuronsLabel->setObjectName("maxNumberNeuronsLabel");
        sizePolicy3.setHeightForWidth(maxNumberNeuronsLabel->sizePolicy().hasHeightForWidth());
        maxNumberNeuronsLabel->setSizePolicy(sizePolicy3);
        maxNumberNeuronsLabel->setMaximumSize(QSize(16777215, 30));
        maxNumberNeuronsLabel->setFont(font2);

        maxNumberNeuronsLayout->addWidget(maxNumberNeuronsLabel);

        maxNumberNeuronsLayout->setStretch(0, 4);
        maxNumberNeuronsLayout->setStretch(3, 3);

        verticalLayout->addLayout(maxNumberNeuronsLayout);

        killableLayout = new QHBoxLayout();
        killableLayout->setSpacing(3);
        killableLayout->setObjectName("killableLayout");
        killableLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        killEnableCheckBox = new QCheckBox(scrollAreaWidgetContents);
        killEnableCheckBox->setObjectName("killEnableCheckBox");
        QFont font4;
        font4.setPointSize(17);
        killEnableCheckBox->setFont(font4);
        killEnableCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: black; }QCheckBox:checked{ color: black; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        killEnableCheckBox->setIconSize(QSize(20, 20));
        killEnableCheckBox->setChecked(false);
        killEnableCheckBox->setTristate(false);

        killableLayout->addWidget(killEnableCheckBox);


        verticalLayout->addLayout(killableLayout);

        sexualReproductionLayout = new QHBoxLayout();
        sexualReproductionLayout->setSpacing(3);
        sexualReproductionLayout->setObjectName("sexualReproductionLayout");
        sexualReproductionLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        sexualReproductionCheckBox = new QCheckBox(scrollAreaWidgetContents);
        sexualReproductionCheckBox->setObjectName("sexualReproductionCheckBox");
        sexualReproductionCheckBox->setFont(font4);
        sexualReproductionCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: white; }QCheckBox:checked{ color: white; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        sexualReproductionCheckBox->setIconSize(QSize(20, 20));
        sexualReproductionCheckBox->setChecked(false);
        sexualReproductionCheckBox->setTristate(false);

        sexualReproductionLayout->addWidget(sexualReproductionCheckBox);


        verticalLayout->addLayout(sexualReproductionLayout);

        chooseParentsByFitnessLayout = new QHBoxLayout();
        chooseParentsByFitnessLayout->setSpacing(3);
        chooseParentsByFitnessLayout->setObjectName("chooseParentsByFitnessLayout");
        chooseParentsByFitnessLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        chooseParentsByFitnessCheckBox = new QCheckBox(scrollAreaWidgetContents);
        chooseParentsByFitnessCheckBox->setObjectName("chooseParentsByFitnessCheckBox");
        chooseParentsByFitnessCheckBox->setFont(font4);
        chooseParentsByFitnessCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: white; }QCheckBox:checked{ color: white; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        chooseParentsByFitnessCheckBox->setIconSize(QSize(20, 20));
        chooseParentsByFitnessCheckBox->setChecked(false);
        chooseParentsByFitnessCheckBox->setTristate(false);

        chooseParentsByFitnessLayout->addWidget(chooseParentsByFitnessCheckBox);


        verticalLayout->addLayout(chooseParentsByFitnessLayout);

        pointMutationRateLayout = new QHBoxLayout();
        pointMutationRateLayout->setSpacing(3);
        pointMutationRateLayout->setObjectName("pointMutationRateLayout");
        pointMutationRateLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pointMutationRateInput = new QLineEdit(scrollAreaWidgetContents);
        pointMutationRateInput->setObjectName("pointMutationRateInput");
        pointMutationRateInput->setMaximumSize(QSize(16777215, 30));
        pointMutationRateInput->setFont(font4);

        pointMutationRateLayout->addWidget(pointMutationRateInput);

        pointMutationRateDownButton = new QPushButton(scrollAreaWidgetContents);
        pointMutationRateDownButton->setObjectName("pointMutationRateDownButton");
        sizePolicy1.setHeightForWidth(pointMutationRateDownButton->sizePolicy().hasHeightForWidth());
        pointMutationRateDownButton->setSizePolicy(sizePolicy1);
        pointMutationRateDownButton->setMinimumSize(QSize(10, 10));
        pointMutationRateDownButton->setMaximumSize(QSize(30, 30));
        pointMutationRateDownButton->setFont(font2);
        pointMutationRateDownButton->setStyleSheet(QString::fromUtf8(""));

        pointMutationRateLayout->addWidget(pointMutationRateDownButton);

        pointMutationRateUpButton = new QPushButton(scrollAreaWidgetContents);
        pointMutationRateUpButton->setObjectName("pointMutationRateUpButton");
        sizePolicy2.setHeightForWidth(pointMutationRateUpButton->sizePolicy().hasHeightForWidth());
        pointMutationRateUpButton->setSizePolicy(sizePolicy2);
        pointMutationRateUpButton->setMaximumSize(QSize(30, 30));
        pointMutationRateUpButton->setFont(font3);
        pointMutationRateUpButton->setStyleSheet(QString::fromUtf8(""));
        pointMutationRateUpButton->setCheckable(false);

        pointMutationRateLayout->addWidget(pointMutationRateUpButton);

        pointMutationRateLabel = new QLabel(scrollAreaWidgetContents);
        pointMutationRateLabel->setObjectName("pointMutationRateLabel");
        sizePolicy3.setHeightForWidth(pointMutationRateLabel->sizePolicy().hasHeightForWidth());
        pointMutationRateLabel->setSizePolicy(sizePolicy3);
        pointMutationRateLabel->setMaximumSize(QSize(16777215, 30));
        pointMutationRateLabel->setFont(font2);

        pointMutationRateLayout->addWidget(pointMutationRateLabel);

        pointMutationRateLayout->setStretch(0, 4);
        pointMutationRateLayout->setStretch(3, 3);

        verticalLayout->addLayout(pointMutationRateLayout);

        geneInsertionDeletionRateLayout = new QHBoxLayout();
        geneInsertionDeletionRateLayout->setSpacing(3);
        geneInsertionDeletionRateLayout->setObjectName("geneInsertionDeletionRateLayout");
        geneInsertionDeletionRateLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        geneInsertionDeletionRateInput = new QLineEdit(scrollAreaWidgetContents);
        geneInsertionDeletionRateInput->setObjectName("geneInsertionDeletionRateInput");
        geneInsertionDeletionRateInput->setMaximumSize(QSize(16777215, 30));
        geneInsertionDeletionRateInput->setFont(font4);

        geneInsertionDeletionRateLayout->addWidget(geneInsertionDeletionRateInput);

        geneInsertionDeletionRateDownButton = new QPushButton(scrollAreaWidgetContents);
        geneInsertionDeletionRateDownButton->setObjectName("geneInsertionDeletionRateDownButton");
        sizePolicy1.setHeightForWidth(geneInsertionDeletionRateDownButton->sizePolicy().hasHeightForWidth());
        geneInsertionDeletionRateDownButton->setSizePolicy(sizePolicy1);
        geneInsertionDeletionRateDownButton->setMinimumSize(QSize(10, 10));
        geneInsertionDeletionRateDownButton->setMaximumSize(QSize(30, 30));
        geneInsertionDeletionRateDownButton->setFont(font2);
        geneInsertionDeletionRateDownButton->setStyleSheet(QString::fromUtf8(""));

        geneInsertionDeletionRateLayout->addWidget(geneInsertionDeletionRateDownButton);

        geneInsertionDeletionRateUpButton = new QPushButton(scrollAreaWidgetContents);
        geneInsertionDeletionRateUpButton->setObjectName("geneInsertionDeletionRateUpButton");
        sizePolicy2.setHeightForWidth(geneInsertionDeletionRateUpButton->sizePolicy().hasHeightForWidth());
        geneInsertionDeletionRateUpButton->setSizePolicy(sizePolicy2);
        geneInsertionDeletionRateUpButton->setMaximumSize(QSize(30, 30));
        geneInsertionDeletionRateUpButton->setFont(font3);
        geneInsertionDeletionRateUpButton->setStyleSheet(QString::fromUtf8(""));
        geneInsertionDeletionRateUpButton->setCheckable(false);

        geneInsertionDeletionRateLayout->addWidget(geneInsertionDeletionRateUpButton);

        geneInsertionDeletionRateLabel = new QLabel(scrollAreaWidgetContents);
        geneInsertionDeletionRateLabel->setObjectName("geneInsertionDeletionRateLabel");
        sizePolicy3.setHeightForWidth(geneInsertionDeletionRateLabel->sizePolicy().hasHeightForWidth());
        geneInsertionDeletionRateLabel->setSizePolicy(sizePolicy3);
        geneInsertionDeletionRateLabel->setMaximumSize(QSize(16777215, 30));
        geneInsertionDeletionRateLabel->setFont(font2);

        geneInsertionDeletionRateLayout->addWidget(geneInsertionDeletionRateLabel);

        geneInsertionDeletionRateLayout->setStretch(0, 4);
        geneInsertionDeletionRateLayout->setStretch(3, 3);

        verticalLayout->addLayout(geneInsertionDeletionRateLayout);

        deletionRatioLayout = new QHBoxLayout();
        deletionRatioLayout->setSpacing(3);
        deletionRatioLayout->setObjectName("deletionRatioLayout");
        deletionRatioLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        deletionRatioInput = new QLineEdit(scrollAreaWidgetContents);
        deletionRatioInput->setObjectName("deletionRatioInput");
        deletionRatioInput->setMaximumSize(QSize(16777215, 30));
        deletionRatioInput->setFont(font4);

        deletionRatioLayout->addWidget(deletionRatioInput);

        deletionRatioDownButton = new QPushButton(scrollAreaWidgetContents);
        deletionRatioDownButton->setObjectName("deletionRatioDownButton");
        sizePolicy1.setHeightForWidth(deletionRatioDownButton->sizePolicy().hasHeightForWidth());
        deletionRatioDownButton->setSizePolicy(sizePolicy1);
        deletionRatioDownButton->setMinimumSize(QSize(10, 10));
        deletionRatioDownButton->setMaximumSize(QSize(30, 30));
        deletionRatioDownButton->setFont(font2);
        deletionRatioDownButton->setStyleSheet(QString::fromUtf8(""));

        deletionRatioLayout->addWidget(deletionRatioDownButton);

        deletionRatioUpButton = new QPushButton(scrollAreaWidgetContents);
        deletionRatioUpButton->setObjectName("deletionRatioUpButton");
        sizePolicy2.setHeightForWidth(deletionRatioUpButton->sizePolicy().hasHeightForWidth());
        deletionRatioUpButton->setSizePolicy(sizePolicy2);
        deletionRatioUpButton->setMaximumSize(QSize(30, 30));
        deletionRatioUpButton->setFont(font3);
        deletionRatioUpButton->setStyleSheet(QString::fromUtf8(""));
        deletionRatioUpButton->setCheckable(false);

        deletionRatioLayout->addWidget(deletionRatioUpButton);

        deletionRatioLabel = new QLabel(scrollAreaWidgetContents);
        deletionRatioLabel->setObjectName("deletionRatioLabel");
        sizePolicy3.setHeightForWidth(deletionRatioLabel->sizePolicy().hasHeightForWidth());
        deletionRatioLabel->setSizePolicy(sizePolicy3);
        deletionRatioLabel->setMaximumSize(QSize(16777215, 30));
        deletionRatioLabel->setFont(font2);

        deletionRatioLayout->addWidget(deletionRatioLabel);

        deletionRatioLayout->setStretch(0, 4);
        deletionRatioLayout->setStretch(3, 3);

        verticalLayout->addLayout(deletionRatioLayout);

        responsivenessCurveKFactorLayout = new QHBoxLayout();
        responsivenessCurveKFactorLayout->setSpacing(3);
        responsivenessCurveKFactorLayout->setObjectName("responsivenessCurveKFactorLayout");
        responsivenessCurveKFactorLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        responsivenessCurveKFactorInput = new QLineEdit(scrollAreaWidgetContents);
        responsivenessCurveKFactorInput->setObjectName("responsivenessCurveKFactorInput");
        responsivenessCurveKFactorInput->setMaximumSize(QSize(16777215, 30));
        responsivenessCurveKFactorInput->setFont(font1);

        responsivenessCurveKFactorLayout->addWidget(responsivenessCurveKFactorInput);

        responsivenessCurveKFactorDownButton = new QPushButton(scrollAreaWidgetContents);
        responsivenessCurveKFactorDownButton->setObjectName("responsivenessCurveKFactorDownButton");
        sizePolicy1.setHeightForWidth(responsivenessCurveKFactorDownButton->sizePolicy().hasHeightForWidth());
        responsivenessCurveKFactorDownButton->setSizePolicy(sizePolicy1);
        responsivenessCurveKFactorDownButton->setMinimumSize(QSize(10, 10));
        responsivenessCurveKFactorDownButton->setMaximumSize(QSize(30, 30));
        responsivenessCurveKFactorDownButton->setFont(font2);

        responsivenessCurveKFactorLayout->addWidget(responsivenessCurveKFactorDownButton);

        responsivenessCurveKFactorUpButton = new QPushButton(scrollAreaWidgetContents);
        responsivenessCurveKFactorUpButton->setObjectName("responsivenessCurveKFactorUpButton");
        sizePolicy2.setHeightForWidth(responsivenessCurveKFactorUpButton->sizePolicy().hasHeightForWidth());
        responsivenessCurveKFactorUpButton->setSizePolicy(sizePolicy2);
        responsivenessCurveKFactorUpButton->setMaximumSize(QSize(30, 30));
        responsivenessCurveKFactorUpButton->setFont(font3);

        responsivenessCurveKFactorLayout->addWidget(responsivenessCurveKFactorUpButton);

        responsivenessCurveKFactorLabel = new QLabel(scrollAreaWidgetContents);
        responsivenessCurveKFactorLabel->setObjectName("responsivenessCurveKFactorLabel");
        sizePolicy3.setHeightForWidth(responsivenessCurveKFactorLabel->sizePolicy().hasHeightForWidth());
        responsivenessCurveKFactorLabel->setSizePolicy(sizePolicy3);
        responsivenessCurveKFactorLabel->setMaximumSize(QSize(16777215, 30));
        responsivenessCurveKFactorLabel->setFont(font2);

        responsivenessCurveKFactorLayout->addWidget(responsivenessCurveKFactorLabel);

        responsivenessCurveKFactorLayout->setStretch(0, 4);
        responsivenessCurveKFactorLayout->setStretch(3, 3);

        verticalLayout->addLayout(responsivenessCurveKFactorLayout);

        populationSensorRadiusLayout = new QHBoxLayout();
        populationSensorRadiusLayout->setSpacing(3);
        populationSensorRadiusLayout->setObjectName("populationSensorRadiusLayout");
        populationSensorRadiusLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        populationSensorRadiusInput = new QLineEdit(scrollAreaWidgetContents);
        populationSensorRadiusInput->setObjectName("populationSensorRadiusInput");
        populationSensorRadiusInput->setMaximumSize(QSize(16777215, 30));
        populationSensorRadiusInput->setFont(font1);

        populationSensorRadiusLayout->addWidget(populationSensorRadiusInput);

        populationSensorRadiusDownButton = new QPushButton(scrollAreaWidgetContents);
        populationSensorRadiusDownButton->setObjectName("populationSensorRadiusDownButton");
        sizePolicy1.setHeightForWidth(populationSensorRadiusDownButton->sizePolicy().hasHeightForWidth());
        populationSensorRadiusDownButton->setSizePolicy(sizePolicy1);
        populationSensorRadiusDownButton->setMinimumSize(QSize(10, 10));
        populationSensorRadiusDownButton->setMaximumSize(QSize(30, 30));
        populationSensorRadiusDownButton->setFont(font2);

        populationSensorRadiusLayout->addWidget(populationSensorRadiusDownButton);

        populationSensorRadiusUpButton = new QPushButton(scrollAreaWidgetContents);
        populationSensorRadiusUpButton->setObjectName("populationSensorRadiusUpButton");
        sizePolicy2.setHeightForWidth(populationSensorRadiusUpButton->sizePolicy().hasHeightForWidth());
        populationSensorRadiusUpButton->setSizePolicy(sizePolicy2);
        populationSensorRadiusUpButton->setMaximumSize(QSize(30, 30));
        populationSensorRadiusUpButton->setFont(font3);

        populationSensorRadiusLayout->addWidget(populationSensorRadiusUpButton);

        populationSensorRadiusLabel = new QLabel(scrollAreaWidgetContents);
        populationSensorRadiusLabel->setObjectName("populationSensorRadiusLabel");
        sizePolicy3.setHeightForWidth(populationSensorRadiusLabel->sizePolicy().hasHeightForWidth());
        populationSensorRadiusLabel->setSizePolicy(sizePolicy3);
        populationSensorRadiusLabel->setMaximumSize(QSize(16777215, 30));
        populationSensorRadiusLabel->setFont(font2);

        populationSensorRadiusLayout->addWidget(populationSensorRadiusLabel);

        populationSensorRadiusLayout->setStretch(0, 4);
        populationSensorRadiusLayout->setStretch(3, 3);

        verticalLayout->addLayout(populationSensorRadiusLayout);

        longProbeDistanceLayout = new QHBoxLayout();
        longProbeDistanceLayout->setSpacing(3);
        longProbeDistanceLayout->setObjectName("longProbeDistanceLayout");
        longProbeDistanceLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        longProbeDistanceInput = new QLineEdit(scrollAreaWidgetContents);
        longProbeDistanceInput->setObjectName("longProbeDistanceInput");
        longProbeDistanceInput->setMaximumSize(QSize(16777215, 30));
        longProbeDistanceInput->setFont(font1);

        longProbeDistanceLayout->addWidget(longProbeDistanceInput);

        longProbeDistanceDownButton = new QPushButton(scrollAreaWidgetContents);
        longProbeDistanceDownButton->setObjectName("longProbeDistanceDownButton");
        sizePolicy1.setHeightForWidth(longProbeDistanceDownButton->sizePolicy().hasHeightForWidth());
        longProbeDistanceDownButton->setSizePolicy(sizePolicy1);
        longProbeDistanceDownButton->setMinimumSize(QSize(10, 10));
        longProbeDistanceDownButton->setMaximumSize(QSize(30, 30));
        longProbeDistanceDownButton->setFont(font2);

        longProbeDistanceLayout->addWidget(longProbeDistanceDownButton);

        longProbeDistanceUpButton = new QPushButton(scrollAreaWidgetContents);
        longProbeDistanceUpButton->setObjectName("longProbeDistanceUpButton");
        sizePolicy2.setHeightForWidth(longProbeDistanceUpButton->sizePolicy().hasHeightForWidth());
        longProbeDistanceUpButton->setSizePolicy(sizePolicy2);
        longProbeDistanceUpButton->setMaximumSize(QSize(30, 30));
        longProbeDistanceUpButton->setFont(font3);

        longProbeDistanceLayout->addWidget(longProbeDistanceUpButton);

        longProbeDistanceLabel = new QLabel(scrollAreaWidgetContents);
        longProbeDistanceLabel->setObjectName("longProbeDistanceLabel");
        sizePolicy3.setHeightForWidth(longProbeDistanceLabel->sizePolicy().hasHeightForWidth());
        longProbeDistanceLabel->setSizePolicy(sizePolicy3);
        longProbeDistanceLabel->setMaximumSize(QSize(16777215, 30));
        longProbeDistanceLabel->setFont(font2);

        longProbeDistanceLayout->addWidget(longProbeDistanceLabel);

        longProbeDistanceLayout->setStretch(0, 4);
        longProbeDistanceLayout->setStretch(3, 3);

        verticalLayout->addLayout(longProbeDistanceLayout);

        shortProbeBarrierDistanceLayout = new QHBoxLayout();
        shortProbeBarrierDistanceLayout->setSpacing(3);
        shortProbeBarrierDistanceLayout->setObjectName("shortProbeBarrierDistanceLayout");
        shortProbeBarrierDistanceLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        shortProbeBarrierDistanceInput = new QLineEdit(scrollAreaWidgetContents);
        shortProbeBarrierDistanceInput->setObjectName("shortProbeBarrierDistanceInput");
        shortProbeBarrierDistanceInput->setMaximumSize(QSize(16777215, 30));
        shortProbeBarrierDistanceInput->setFont(font1);

        shortProbeBarrierDistanceLayout->addWidget(shortProbeBarrierDistanceInput);

        shortProbeBarrierDistanceDownButton = new QPushButton(scrollAreaWidgetContents);
        shortProbeBarrierDistanceDownButton->setObjectName("shortProbeBarrierDistanceDownButton");
        sizePolicy1.setHeightForWidth(shortProbeBarrierDistanceDownButton->sizePolicy().hasHeightForWidth());
        shortProbeBarrierDistanceDownButton->setSizePolicy(sizePolicy1);
        shortProbeBarrierDistanceDownButton->setMinimumSize(QSize(10, 10));
        shortProbeBarrierDistanceDownButton->setMaximumSize(QSize(30, 30));
        shortProbeBarrierDistanceDownButton->setFont(font2);

        shortProbeBarrierDistanceLayout->addWidget(shortProbeBarrierDistanceDownButton);

        shortProbeBarrierDistanceUpButton = new QPushButton(scrollAreaWidgetContents);
        shortProbeBarrierDistanceUpButton->setObjectName("shortProbeBarrierDistanceUpButton");
        sizePolicy2.setHeightForWidth(shortProbeBarrierDistanceUpButton->sizePolicy().hasHeightForWidth());
        shortProbeBarrierDistanceUpButton->setSizePolicy(sizePolicy2);
        shortProbeBarrierDistanceUpButton->setMaximumSize(QSize(30, 30));
        shortProbeBarrierDistanceUpButton->setFont(font3);

        shortProbeBarrierDistanceLayout->addWidget(shortProbeBarrierDistanceUpButton);

        shortProbeBarrierDistanceLabel = new QLabel(scrollAreaWidgetContents);
        shortProbeBarrierDistanceLabel->setObjectName("shortProbeBarrierDistanceLabel");
        sizePolicy3.setHeightForWidth(shortProbeBarrierDistanceLabel->sizePolicy().hasHeightForWidth());
        shortProbeBarrierDistanceLabel->setSizePolicy(sizePolicy3);
        shortProbeBarrierDistanceLabel->setMaximumSize(QSize(16777215, 30));
        shortProbeBarrierDistanceLabel->setFont(font2);

        shortProbeBarrierDistanceLayout->addWidget(shortProbeBarrierDistanceLabel);

        shortProbeBarrierDistanceLayout->setStretch(0, 4);
        shortProbeBarrierDistanceLayout->setStretch(3, 3);

        verticalLayout->addLayout(shortProbeBarrierDistanceLayout);

        signalSensorRadiusLayout = new QHBoxLayout();
        signalSensorRadiusLayout->setSpacing(3);
        signalSensorRadiusLayout->setObjectName("signalSensorRadiusLayout");
        signalSensorRadiusLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        signalSensorRadiusInput = new QLineEdit(scrollAreaWidgetContents);
        signalSensorRadiusInput->setObjectName("signalSensorRadiusInput");
        signalSensorRadiusInput->setMaximumSize(QSize(16777215, 30));
        signalSensorRadiusInput->setFont(font1);

        signalSensorRadiusLayout->addWidget(signalSensorRadiusInput);

        signalSensorRadiusDownButton = new QPushButton(scrollAreaWidgetContents);
        signalSensorRadiusDownButton->setObjectName("signalSensorRadiusDownButton");
        sizePolicy1.setHeightForWidth(signalSensorRadiusDownButton->sizePolicy().hasHeightForWidth());
        signalSensorRadiusDownButton->setSizePolicy(sizePolicy1);
        signalSensorRadiusDownButton->setMinimumSize(QSize(10, 10));
        signalSensorRadiusDownButton->setMaximumSize(QSize(30, 30));
        signalSensorRadiusDownButton->setFont(font2);

        signalSensorRadiusLayout->addWidget(signalSensorRadiusDownButton);

        signalSensorRadiusUpButton = new QPushButton(scrollAreaWidgetContents);
        signalSensorRadiusUpButton->setObjectName("signalSensorRadiusUpButton");
        sizePolicy2.setHeightForWidth(signalSensorRadiusUpButton->sizePolicy().hasHeightForWidth());
        signalSensorRadiusUpButton->setSizePolicy(sizePolicy2);
        signalSensorRadiusUpButton->setMaximumSize(QSize(30, 30));
        signalSensorRadiusUpButton->setFont(font3);

        signalSensorRadiusLayout->addWidget(signalSensorRadiusUpButton);

        signalSensorRadiusLabel = new QLabel(scrollAreaWidgetContents);
        signalSensorRadiusLabel->setObjectName("signalSensorRadiusLabel");
        sizePolicy3.setHeightForWidth(signalSensorRadiusLabel->sizePolicy().hasHeightForWidth());
        signalSensorRadiusLabel->setSizePolicy(sizePolicy3);
        signalSensorRadiusLabel->setMaximumSize(QSize(16777215, 30));
        signalSensorRadiusLabel->setFont(font2);

        signalSensorRadiusLayout->addWidget(signalSensorRadiusLabel);

        signalSensorRadiusLayout->setStretch(0, 4);
        signalSensorRadiusLayout->setStretch(3, 3);

        verticalLayout->addLayout(signalSensorRadiusLayout);

        signalLayersLayout = new QHBoxLayout();
        signalLayersLayout->setSpacing(3);
        signalLayersLayout->setObjectName("signalLayersLayout");
        signalLayersLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        signalLayersInput = new QLineEdit(scrollAreaWidgetContents);
        signalLayersInput->setObjectName("signalLayersInput");
        signalLayersInput->setMaximumSize(QSize(16777215, 30));
        signalLayersInput->setFont(font1);

        signalLayersLayout->addWidget(signalLayersInput);

        signalLayersDownButton = new QPushButton(scrollAreaWidgetContents);
        signalLayersDownButton->setObjectName("signalLayersDownButton");
        sizePolicy1.setHeightForWidth(signalLayersDownButton->sizePolicy().hasHeightForWidth());
        signalLayersDownButton->setSizePolicy(sizePolicy1);
        signalLayersDownButton->setMinimumSize(QSize(10, 10));
        signalLayersDownButton->setMaximumSize(QSize(30, 30));
        signalLayersDownButton->setFont(font2);

        signalLayersLayout->addWidget(signalLayersDownButton);

        signalLayersUpButton = new QPushButton(scrollAreaWidgetContents);
        signalLayersUpButton->setObjectName("signalLayersUpButton");
        sizePolicy2.setHeightForWidth(signalLayersUpButton->sizePolicy().hasHeightForWidth());
        signalLayersUpButton->setSizePolicy(sizePolicy2);
        signalLayersUpButton->setMaximumSize(QSize(30, 30));
        signalLayersUpButton->setFont(font3);

        signalLayersLayout->addWidget(signalLayersUpButton);

        signalLayersLabel = new QLabel(scrollAreaWidgetContents);
        signalLayersLabel->setObjectName("signalLayersLabel");
        sizePolicy3.setHeightForWidth(signalLayersLabel->sizePolicy().hasHeightForWidth());
        signalLayersLabel->setSizePolicy(sizePolicy3);
        signalLayersLabel->setMaximumSize(QSize(16777215, 30));
        signalLayersLabel->setFont(font2);

        signalLayersLayout->addWidget(signalLayersLabel);

        signalLayersLayout->setStretch(0, 4);
        signalLayersLayout->setStretch(3, 3);

        verticalLayout->addLayout(signalLayersLayout);

        imageDirLayout = new QHBoxLayout();
        imageDirLayout->setSpacing(3);
        imageDirLayout->setObjectName("imageDirLayout");
        imageDirLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        imageDirInput = new QLineEdit(scrollAreaWidgetContents);
        imageDirInput->setObjectName("imageDirInput");
        imageDirInput->setMaximumSize(QSize(16777215, 30));
        imageDirInput->setFont(font1);

        imageDirLayout->addWidget(imageDirInput);

        imageDirButton = new QPushButton(scrollAreaWidgetContents);
        imageDirButton->setObjectName("imageDirButton");
        sizePolicy1.setHeightForWidth(imageDirButton->sizePolicy().hasHeightForWidth());
        imageDirButton->setSizePolicy(sizePolicy1);
        imageDirButton->setMinimumSize(QSize(10, 10));
        imageDirButton->setMaximumSize(QSize(30, 30));
        imageDirButton->setFont(font2);
        imageDirButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/assets/img/folder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        imageDirButton->setIcon(icon4);
        imageDirButton->setIconSize(QSize(30, 30));

        imageDirLayout->addWidget(imageDirButton);

        imageDirLabel = new QLabel(scrollAreaWidgetContents);
        imageDirLabel->setObjectName("imageDirLabel");
        sizePolicy3.setHeightForWidth(imageDirLabel->sizePolicy().hasHeightForWidth());
        imageDirLabel->setSizePolicy(sizePolicy3);
        imageDirLabel->setMaximumSize(QSize(16777215, 30));
        imageDirLabel->setFont(font2);

        imageDirLayout->addWidget(imageDirLabel);

        imageDirLayout->setStretch(0, 10);
        imageDirLayout->setStretch(2, 7);

        verticalLayout->addLayout(imageDirLayout);

        logDirLayout = new QHBoxLayout();
        logDirLayout->setSpacing(3);
        logDirLayout->setObjectName("logDirLayout");
        logDirLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        logDirInput = new QLineEdit(scrollAreaWidgetContents);
        logDirInput->setObjectName("logDirInput");
        logDirInput->setMaximumSize(QSize(16777215, 30));
        logDirInput->setFont(font1);

        logDirLayout->addWidget(logDirInput);

        logDirButton = new QPushButton(scrollAreaWidgetContents);
        logDirButton->setObjectName("logDirButton");
        sizePolicy1.setHeightForWidth(logDirButton->sizePolicy().hasHeightForWidth());
        logDirButton->setSizePolicy(sizePolicy1);
        logDirButton->setMinimumSize(QSize(10, 10));
        logDirButton->setMaximumSize(QSize(30, 30));
        logDirButton->setFont(font2);
        logDirButton->setStyleSheet(QString::fromUtf8(""));
        logDirButton->setIcon(icon4);
        logDirButton->setIconSize(QSize(30, 30));

        logDirLayout->addWidget(logDirButton);

        logDirLabel = new QLabel(scrollAreaWidgetContents);
        logDirLabel->setObjectName("logDirLabel");
        sizePolicy3.setHeightForWidth(logDirLabel->sizePolicy().hasHeightForWidth());
        logDirLabel->setSizePolicy(sizePolicy3);
        logDirLabel->setMaximumSize(QSize(16777215, 30));
        logDirLabel->setFont(font2);

        logDirLayout->addWidget(logDirLabel);

        logDirLayout->setStretch(0, 10);
        logDirLayout->setStretch(2, 7);

        verticalLayout->addLayout(logDirLayout);

        displayScaleLayout = new QHBoxLayout();
        displayScaleLayout->setSpacing(3);
        displayScaleLayout->setObjectName("displayScaleLayout");
        displayScaleLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        displayScaleInput = new QLineEdit(scrollAreaWidgetContents);
        displayScaleInput->setObjectName("displayScaleInput");
        displayScaleInput->setMaximumSize(QSize(16777215, 30));
        displayScaleInput->setFont(font1);

        displayScaleLayout->addWidget(displayScaleInput);

        displayScaleDownButton = new QPushButton(scrollAreaWidgetContents);
        displayScaleDownButton->setObjectName("displayScaleDownButton");
        sizePolicy1.setHeightForWidth(displayScaleDownButton->sizePolicy().hasHeightForWidth());
        displayScaleDownButton->setSizePolicy(sizePolicy1);
        displayScaleDownButton->setMinimumSize(QSize(10, 10));
        displayScaleDownButton->setMaximumSize(QSize(30, 30));
        displayScaleDownButton->setFont(font2);

        displayScaleLayout->addWidget(displayScaleDownButton);

        displayScaleUpButton = new QPushButton(scrollAreaWidgetContents);
        displayScaleUpButton->setObjectName("displayScaleUpButton");
        sizePolicy2.setHeightForWidth(displayScaleUpButton->sizePolicy().hasHeightForWidth());
        displayScaleUpButton->setSizePolicy(sizePolicy2);
        displayScaleUpButton->setMaximumSize(QSize(30, 30));
        displayScaleUpButton->setFont(font3);

        displayScaleLayout->addWidget(displayScaleUpButton);

        displayScaleLabel = new QLabel(scrollAreaWidgetContents);
        displayScaleLabel->setObjectName("displayScaleLabel");
        sizePolicy3.setHeightForWidth(displayScaleLabel->sizePolicy().hasHeightForWidth());
        displayScaleLabel->setSizePolicy(sizePolicy3);
        displayScaleLabel->setMaximumSize(QSize(16777215, 30));
        displayScaleLabel->setFont(font2);

        displayScaleLayout->addWidget(displayScaleLabel);

        displayScaleLayout->setStretch(0, 4);
        displayScaleLayout->setStretch(3, 3);

        verticalLayout->addLayout(displayScaleLayout);

        agentSizeLayout = new QHBoxLayout();
        agentSizeLayout->setSpacing(3);
        agentSizeLayout->setObjectName("agentSizeLayout");
        agentSizeLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        agentSizeInput = new QLineEdit(scrollAreaWidgetContents);
        agentSizeInput->setObjectName("agentSizeInput");
        agentSizeInput->setMaximumSize(QSize(16777215, 30));
        agentSizeInput->setFont(font1);

        agentSizeLayout->addWidget(agentSizeInput);

        agentSizeDownButton = new QPushButton(scrollAreaWidgetContents);
        agentSizeDownButton->setObjectName("agentSizeDownButton");
        sizePolicy1.setHeightForWidth(agentSizeDownButton->sizePolicy().hasHeightForWidth());
        agentSizeDownButton->setSizePolicy(sizePolicy1);
        agentSizeDownButton->setMinimumSize(QSize(10, 10));
        agentSizeDownButton->setMaximumSize(QSize(30, 30));
        agentSizeDownButton->setFont(font2);

        agentSizeLayout->addWidget(agentSizeDownButton);

        agentSizeUpButton = new QPushButton(scrollAreaWidgetContents);
        agentSizeUpButton->setObjectName("agentSizeUpButton");
        sizePolicy2.setHeightForWidth(agentSizeUpButton->sizePolicy().hasHeightForWidth());
        agentSizeUpButton->setSizePolicy(sizePolicy2);
        agentSizeUpButton->setMaximumSize(QSize(30, 30));
        agentSizeUpButton->setFont(font3);

        agentSizeLayout->addWidget(agentSizeUpButton);

        agentSizeLabel = new QLabel(scrollAreaWidgetContents);
        agentSizeLabel->setObjectName("agentSizeLabel");
        sizePolicy3.setHeightForWidth(agentSizeLabel->sizePolicy().hasHeightForWidth());
        agentSizeLabel->setSizePolicy(sizePolicy3);
        agentSizeLabel->setMaximumSize(QSize(16777215, 30));
        agentSizeLabel->setFont(font2);

        agentSizeLayout->addWidget(agentSizeLabel);

        agentSizeLayout->setStretch(0, 4);
        agentSizeLayout->setStretch(3, 3);

        verticalLayout->addLayout(agentSizeLayout);

        videoSaveFirstFramesLayout = new QHBoxLayout();
        videoSaveFirstFramesLayout->setSpacing(3);
        videoSaveFirstFramesLayout->setObjectName("videoSaveFirstFramesLayout");
        videoSaveFirstFramesLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        videoSaveFirstFramesInput = new QLineEdit(scrollAreaWidgetContents);
        videoSaveFirstFramesInput->setObjectName("videoSaveFirstFramesInput");
        videoSaveFirstFramesInput->setMaximumSize(QSize(16777215, 30));
        videoSaveFirstFramesInput->setFont(font1);

        videoSaveFirstFramesLayout->addWidget(videoSaveFirstFramesInput);

        videoSaveFirstFramesDownButton = new QPushButton(scrollAreaWidgetContents);
        videoSaveFirstFramesDownButton->setObjectName("videoSaveFirstFramesDownButton");
        sizePolicy1.setHeightForWidth(videoSaveFirstFramesDownButton->sizePolicy().hasHeightForWidth());
        videoSaveFirstFramesDownButton->setSizePolicy(sizePolicy1);
        videoSaveFirstFramesDownButton->setMinimumSize(QSize(10, 10));
        videoSaveFirstFramesDownButton->setMaximumSize(QSize(30, 30));
        videoSaveFirstFramesDownButton->setFont(font2);

        videoSaveFirstFramesLayout->addWidget(videoSaveFirstFramesDownButton);

        videoSaveFirstFramesUpButton = new QPushButton(scrollAreaWidgetContents);
        videoSaveFirstFramesUpButton->setObjectName("videoSaveFirstFramesUpButton");
        sizePolicy2.setHeightForWidth(videoSaveFirstFramesUpButton->sizePolicy().hasHeightForWidth());
        videoSaveFirstFramesUpButton->setSizePolicy(sizePolicy2);
        videoSaveFirstFramesUpButton->setMaximumSize(QSize(30, 30));
        videoSaveFirstFramesUpButton->setFont(font3);

        videoSaveFirstFramesLayout->addWidget(videoSaveFirstFramesUpButton);

        videoSaveFirstFramesLabel = new QLabel(scrollAreaWidgetContents);
        videoSaveFirstFramesLabel->setObjectName("videoSaveFirstFramesLabel");
        sizePolicy3.setHeightForWidth(videoSaveFirstFramesLabel->sizePolicy().hasHeightForWidth());
        videoSaveFirstFramesLabel->setSizePolicy(sizePolicy3);
        videoSaveFirstFramesLabel->setMaximumSize(QSize(16777215, 30));
        videoSaveFirstFramesLabel->setFont(font2);

        videoSaveFirstFramesLayout->addWidget(videoSaveFirstFramesLabel);

        videoSaveFirstFramesLayout->setStretch(0, 4);
        videoSaveFirstFramesLayout->setStretch(3, 3);

        verticalLayout->addLayout(videoSaveFirstFramesLayout);

        updateGraphLogLayout = new QHBoxLayout();
        updateGraphLogLayout->setSpacing(3);
        updateGraphLogLayout->setObjectName("updateGraphLogLayout");
        updateGraphLogLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        updateGraphLogCheckBox = new QCheckBox(scrollAreaWidgetContents);
        updateGraphLogCheckBox->setObjectName("updateGraphLogCheckBox");
        updateGraphLogCheckBox->setFont(font4);
        updateGraphLogCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: white; }QCheckBox:checked{ color: white; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        updateGraphLogCheckBox->setIconSize(QSize(20, 20));
        updateGraphLogCheckBox->setChecked(false);
        updateGraphLogCheckBox->setTristate(false);

        updateGraphLogLayout->addWidget(updateGraphLogCheckBox);


        verticalLayout->addLayout(updateGraphLogLayout);

        saveVideoLayout = new QHBoxLayout();
        saveVideoLayout->setSpacing(3);
        saveVideoLayout->setObjectName("saveVideoLayout");
        saveVideoLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        saveVideoCheckBox = new QCheckBox(scrollAreaWidgetContents);
        saveVideoCheckBox->setObjectName("saveVideoCheckBox");
        saveVideoCheckBox->setFont(font4);
        saveVideoCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: white; }QCheckBox:checked{ color: white; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        saveVideoCheckBox->setIconSize(QSize(20, 20));
        saveVideoCheckBox->setChecked(false);
        saveVideoCheckBox->setTristate(false);

        saveVideoLayout->addWidget(saveVideoCheckBox);


        verticalLayout->addLayout(saveVideoLayout);

        videoStrideLayout = new QHBoxLayout();
        videoStrideLayout->setSpacing(3);
        videoStrideLayout->setObjectName("videoStrideLayout");
        videoStrideLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        videoStrideInput = new QLineEdit(scrollAreaWidgetContents);
        videoStrideInput->setObjectName("videoStrideInput");
        videoStrideInput->setMaximumSize(QSize(16777215, 30));
        videoStrideInput->setFont(font1);

        videoStrideLayout->addWidget(videoStrideInput);

        videoStrideDownButton = new QPushButton(scrollAreaWidgetContents);
        videoStrideDownButton->setObjectName("videoStrideDownButton");
        sizePolicy1.setHeightForWidth(videoStrideDownButton->sizePolicy().hasHeightForWidth());
        videoStrideDownButton->setSizePolicy(sizePolicy1);
        videoStrideDownButton->setMinimumSize(QSize(10, 10));
        videoStrideDownButton->setMaximumSize(QSize(30, 30));
        videoStrideDownButton->setFont(font2);

        videoStrideLayout->addWidget(videoStrideDownButton);

        videoStrideUpButton = new QPushButton(scrollAreaWidgetContents);
        videoStrideUpButton->setObjectName("videoStrideUpButton");
        sizePolicy2.setHeightForWidth(videoStrideUpButton->sizePolicy().hasHeightForWidth());
        videoStrideUpButton->setSizePolicy(sizePolicy2);
        videoStrideUpButton->setMaximumSize(QSize(30, 30));
        videoStrideUpButton->setFont(font3);

        videoStrideLayout->addWidget(videoStrideUpButton);

        videoStrideLabel = new QLabel(scrollAreaWidgetContents);
        videoStrideLabel->setObjectName("videoStrideLabel");
        sizePolicy3.setHeightForWidth(videoStrideLabel->sizePolicy().hasHeightForWidth());
        videoStrideLabel->setSizePolicy(sizePolicy3);
        videoStrideLabel->setMaximumSize(QSize(16777215, 30));
        videoStrideLabel->setFont(font2);

        videoStrideLayout->addWidget(videoStrideLabel);

        videoStrideLayout->setStretch(0, 4);
        videoStrideLayout->setStretch(3, 3);

        verticalLayout->addLayout(videoStrideLayout);

        genomeComparisonMethodLayout = new QHBoxLayout();
        genomeComparisonMethodLayout->setSpacing(3);
        genomeComparisonMethodLayout->setObjectName("genomeComparisonMethodLayout");
        genomeComparisonMethodLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        genomeComparisonMethodComboBox = new QComboBox(scrollAreaWidgetContents);
        genomeComparisonMethodComboBox->setObjectName("genomeComparisonMethodComboBox");
        genomeComparisonMethodComboBox->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(genomeComparisonMethodComboBox->sizePolicy().hasHeightForWidth());
        genomeComparisonMethodComboBox->setSizePolicy(sizePolicy4);
        genomeComparisonMethodComboBox->setFont(font1);
        genomeComparisonMethodComboBox->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"font-size:24px;\n"
"height:30px;\n"
" border-radius:5px 5px 0px 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: white;\n"
"}\n"
"\n"
"  QComboBox QAbstractItemView{\n"
"background-color: #ededed;\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	font-size:20px;\n"
"    outline: 0px; \n"
"  }"));
        genomeComparisonMethodComboBox->setMaxVisibleItems(3);

        genomeComparisonMethodLayout->addWidget(genomeComparisonMethodComboBox);

        genomeComparisonMethodLabel = new QLabel(scrollAreaWidgetContents);
        genomeComparisonMethodLabel->setObjectName("genomeComparisonMethodLabel");
        sizePolicy3.setHeightForWidth(genomeComparisonMethodLabel->sizePolicy().hasHeightForWidth());
        genomeComparisonMethodLabel->setSizePolicy(sizePolicy3);
        genomeComparisonMethodLabel->setMaximumSize(QSize(16777215, 30));
        genomeComparisonMethodLabel->setFont(font2);

        genomeComparisonMethodLayout->addWidget(genomeComparisonMethodLabel);

        genomeComparisonMethodLayout->setStretch(0, 12);
        genomeComparisonMethodLayout->setStretch(1, 11);

        verticalLayout->addLayout(genomeComparisonMethodLayout);

        displaySampleGenomesLayout = new QHBoxLayout();
        displaySampleGenomesLayout->setSpacing(3);
        displaySampleGenomesLayout->setObjectName("displaySampleGenomesLayout");
        displaySampleGenomesLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        displaySampleGenomesInput = new QLineEdit(scrollAreaWidgetContents);
        displaySampleGenomesInput->setObjectName("displaySampleGenomesInput");
        displaySampleGenomesInput->setMaximumSize(QSize(16777215, 30));
        displaySampleGenomesInput->setFont(font1);

        displaySampleGenomesLayout->addWidget(displaySampleGenomesInput);

        displaySampleGenomesDownButton = new QPushButton(scrollAreaWidgetContents);
        displaySampleGenomesDownButton->setObjectName("displaySampleGenomesDownButton");
        sizePolicy1.setHeightForWidth(displaySampleGenomesDownButton->sizePolicy().hasHeightForWidth());
        displaySampleGenomesDownButton->setSizePolicy(sizePolicy1);
        displaySampleGenomesDownButton->setMinimumSize(QSize(10, 10));
        displaySampleGenomesDownButton->setMaximumSize(QSize(30, 30));
        displaySampleGenomesDownButton->setFont(font2);

        displaySampleGenomesLayout->addWidget(displaySampleGenomesDownButton);

        displaySampleGenomesUpButton = new QPushButton(scrollAreaWidgetContents);
        displaySampleGenomesUpButton->setObjectName("displaySampleGenomesUpButton");
        sizePolicy2.setHeightForWidth(displaySampleGenomesUpButton->sizePolicy().hasHeightForWidth());
        displaySampleGenomesUpButton->setSizePolicy(sizePolicy2);
        displaySampleGenomesUpButton->setMaximumSize(QSize(30, 30));
        displaySampleGenomesUpButton->setFont(font3);

        displaySampleGenomesLayout->addWidget(displaySampleGenomesUpButton);

        displaySampleGenomesLabel = new QLabel(scrollAreaWidgetContents);
        displaySampleGenomesLabel->setObjectName("displaySampleGenomesLabel");
        sizePolicy3.setHeightForWidth(displaySampleGenomesLabel->sizePolicy().hasHeightForWidth());
        displaySampleGenomesLabel->setSizePolicy(sizePolicy3);
        displaySampleGenomesLabel->setMaximumSize(QSize(16777215, 30));
        displaySampleGenomesLabel->setFont(font2);

        displaySampleGenomesLayout->addWidget(displaySampleGenomesLabel);

        displaySampleGenomesLayout->setStretch(0, 4);
        displaySampleGenomesLayout->setStretch(3, 3);

        verticalLayout->addLayout(displaySampleGenomesLayout);

        challengeLayout = new QHBoxLayout();
        challengeLayout->setSpacing(3);
        challengeLayout->setObjectName("challengeLayout");
        challengeLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        challengeComboBox = new QComboBox(scrollAreaWidgetContents);
        challengeComboBox->setObjectName("challengeComboBox");
        sizePolicy4.setHeightForWidth(challengeComboBox->sizePolicy().hasHeightForWidth());
        challengeComboBox->setSizePolicy(sizePolicy4);
        challengeComboBox->setFont(font1);
        challengeComboBox->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"font-size:24px;\n"
"height:30px;\n"
" border-radius:5px 5px 0px 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: white;\n"
"}\n"
"\n"
"  QComboBox QAbstractItemView{\n"
"background-color: #ededed;\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	font-size:20px;\n"
"    outline: 0px; \n"
"  }"));
        challengeComboBox->setMaxVisibleItems(3);

        challengeLayout->addWidget(challengeComboBox);

        challengeLabel = new QLabel(scrollAreaWidgetContents);
        challengeLabel->setObjectName("challengeLabel");
        sizePolicy3.setHeightForWidth(challengeLabel->sizePolicy().hasHeightForWidth());
        challengeLabel->setSizePolicy(sizePolicy3);
        challengeLabel->setMaximumSize(QSize(16777215, 30));
        challengeLabel->setFont(font2);

        challengeLayout->addWidget(challengeLabel);

        challengeLayout->setStretch(0, 12);
        challengeLayout->setStretch(1, 11);

        verticalLayout->addLayout(challengeLayout);

        barrierTypeLayout = new QHBoxLayout();
        barrierTypeLayout->setSpacing(3);
        barrierTypeLayout->setObjectName("barrierTypeLayout");
        barrierTypeLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        barrierTypeComboBox = new QComboBox(scrollAreaWidgetContents);
        barrierTypeComboBox->setObjectName("barrierTypeComboBox");
        sizePolicy4.setHeightForWidth(barrierTypeComboBox->sizePolicy().hasHeightForWidth());
        barrierTypeComboBox->setSizePolicy(sizePolicy4);
        barrierTypeComboBox->setFont(font1);
        barrierTypeComboBox->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"font-size:24px;\n"
"height:30px;\n"
" border-radius:5px 5px 0px 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: white;\n"
"}\n"
"\n"
"  QComboBox QAbstractItemView{\n"
"background-color: #ededed;\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	font-size:20px;\n"
"    outline: 0px; \n"
"  }"));
        barrierTypeComboBox->setMaxVisibleItems(3);

        barrierTypeLayout->addWidget(barrierTypeComboBox);

        barrierTypeLabel = new QLabel(scrollAreaWidgetContents);
        barrierTypeLabel->setObjectName("barrierTypeLabel");
        sizePolicy3.setHeightForWidth(barrierTypeLabel->sizePolicy().hasHeightForWidth());
        barrierTypeLabel->setSizePolicy(sizePolicy3);
        barrierTypeLabel->setMaximumSize(QSize(16777215, 30));
        barrierTypeLabel->setFont(font2);

        barrierTypeLayout->addWidget(barrierTypeLabel);

        barrierTypeLayout->setStretch(0, 12);
        barrierTypeLayout->setStretch(1, 11);

        verticalLayout->addLayout(barrierTypeLayout);

        deterministicLayout = new QHBoxLayout();
        deterministicLayout->setSpacing(3);
        deterministicLayout->setObjectName("deterministicLayout");
        deterministicLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        deterministicCheckBox = new QCheckBox(scrollAreaWidgetContents);
        deterministicCheckBox->setObjectName("deterministicCheckBox");
        deterministicCheckBox->setFont(font4);
        deterministicCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox:unchecked{ color: white; }QCheckBox:checked{ color: white; }\n"
"QCheckBox::indicator{\n"
"	width:30px;\n"
"	height:30px;\n"
"}\n"
"\n"
"QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}"));
        deterministicCheckBox->setIconSize(QSize(20, 20));
        deterministicCheckBox->setChecked(false);
        deterministicCheckBox->setTristate(false);

        deterministicLayout->addWidget(deterministicCheckBox);


        verticalLayout->addLayout(deterministicLayout);

        RNGSeedLayout = new QHBoxLayout();
        RNGSeedLayout->setSpacing(3);
        RNGSeedLayout->setObjectName("RNGSeedLayout");
        RNGSeedLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        RNGSeedInput = new QLineEdit(scrollAreaWidgetContents);
        RNGSeedInput->setObjectName("RNGSeedInput");
        RNGSeedInput->setMaximumSize(QSize(16777215, 30));
        RNGSeedInput->setFont(font1);

        RNGSeedLayout->addWidget(RNGSeedInput);

        RNGSeedDownButton = new QPushButton(scrollAreaWidgetContents);
        RNGSeedDownButton->setObjectName("RNGSeedDownButton");
        sizePolicy1.setHeightForWidth(RNGSeedDownButton->sizePolicy().hasHeightForWidth());
        RNGSeedDownButton->setSizePolicy(sizePolicy1);
        RNGSeedDownButton->setMinimumSize(QSize(10, 10));
        RNGSeedDownButton->setMaximumSize(QSize(30, 30));
        RNGSeedDownButton->setFont(font2);

        RNGSeedLayout->addWidget(RNGSeedDownButton);

        RNGSeedUpButton = new QPushButton(scrollAreaWidgetContents);
        RNGSeedUpButton->setObjectName("RNGSeedUpButton");
        sizePolicy2.setHeightForWidth(RNGSeedUpButton->sizePolicy().hasHeightForWidth());
        RNGSeedUpButton->setSizePolicy(sizePolicy2);
        RNGSeedUpButton->setMaximumSize(QSize(30, 30));
        RNGSeedUpButton->setFont(font3);

        RNGSeedLayout->addWidget(RNGSeedUpButton);

        RNGSeedLabel = new QLabel(scrollAreaWidgetContents);
        RNGSeedLabel->setObjectName("RNGSeedLabel");
        sizePolicy3.setHeightForWidth(RNGSeedLabel->sizePolicy().hasHeightForWidth());
        RNGSeedLabel->setSizePolicy(sizePolicy3);
        RNGSeedLabel->setMaximumSize(QSize(16777215, 30));
        RNGSeedLabel->setFont(font2);

        RNGSeedLayout->addWidget(RNGSeedLabel);

        RNGSeedLayout->setStretch(0, 4);
        RNGSeedLayout->setStretch(3, 3);

        verticalLayout->addLayout(RNGSeedLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(Parameters, QString());
        Graphs = new QWidget();
        Graphs->setObjectName("Graphs");
        survivalView = new DoubleClickableGraphicsView(Graphs);
        survivalView->setObjectName("survivalView");
        survivalView->setGeometry(QRect(0, 30, 800, 420));
        survivalLabel = new QLabel(Graphs);
        survivalLabel->setObjectName("survivalLabel");
        survivalLabel->setGeometry(QRect(0, 0, 531, 31));
        survivalLabel->setFont(font4);
        diversityLabel = new QLabel(Graphs);
        diversityLabel->setObjectName("diversityLabel");
        diversityLabel->setGeometry(QRect(0, 500, 531, 21));
        diversityLabel->setFont(font4);
        diversityView = new DoubleClickableGraphicsView(Graphs);
        diversityView->setObjectName("diversityView");
        diversityView->setGeometry(QRect(0, 540, 800, 420));
        tabWidget->addTab(Graphs, QString());
        Agent = new QWidget();
        Agent->setObjectName("Agent");
        graphicsViewAgent = new QGraphicsView(Agent);
        graphicsViewAgent->setObjectName("graphicsViewAgent");
        graphicsViewAgent->setGeometry(QRect(0, 0, 810, 1150));
        graphicsViewAgent->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(Agent, QString());
        generationLabel = new QLabel(centralwidget);
        generationLabel->setObjectName("generationLabel");
        generationLabel->setGeometry(QRect(10, 40, 291, 31));
        QFont font5;
        font5.setPointSize(14);
        generationLabel->setFont(font5);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 70, 811, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        quickInfo = new QLabel(centralwidget);
        quickInfo->setObjectName("quickInfo");
        quickInfo->setGeometry(QRect(10, 0, 811, 31));
        quickInfo->setFont(font5);
        stepLabel = new QLabel(centralwidget);
        stepLabel->setObjectName("stepLabel");
        stepLabel->setGeometry(QRect(370, 40, 211, 31));
        stepLabel->setFont(font5);
        saveConfigButton = new QPushButton(centralwidget);
        saveConfigButton->setObjectName("saveConfigButton");
        saveConfigButton->setGeometry(QRect(717, 90, 101, 24));
        saveConfigButton->setFont(font);
        saveConfigButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding:2px,0px;\n"
"\n"
"}"));
        lastGenSurvivorsLabel = new QLabel(centralwidget);
        lastGenSurvivorsLabel->setObjectName("lastGenSurvivorsLabel");
        lastGenSurvivorsLabel->setGeometry(QRect(610, 40, 211, 31));
        lastGenSurvivorsLabel->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 2500, 41));
        menubar->setFont(font5);
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"    background-color: #f0f0f0;\n"
"    border-bottom: 1px solid #c0c0c0;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 8px 10px;\n"
"    background-color: transparent;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: white;\n"
"    border: 1px solid #c0c0c0;\n"
"}\n"
"\n"
"QMenu::item {\n"
"font-size:20px;\n"
"    padding: 8px 10px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #c0c0c0;\n"
"    margin: 4px 0;\n"
"}"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName("menuSimulation");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave_Config);
        menuSimulation->addAction(actionRun);
        menuSimulation->addAction(actionPause);
        menuSimulation->addAction(actionReset);
        toolBar->addAction(actionLoad_Button);
        toolBar->addAction(actionRunSimulation_Button);
        toolBar->addAction(actionPauseSimulation_Button);
        toolBar->addAction(actionResetSimulation_Button);
        toolBar->addSeparator();
        toolBar->addAction(actionExitSimulation_Button);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        genomeComparisonMethodComboBox->setCurrentIndex(-1);
        challengeComboBox->setCurrentIndex(-1);
        barrierTypeComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BiosimQt", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionLoad_Button->setText(QCoreApplication::translate("MainWindow", "Load Ini File", nullptr));
#if QT_CONFIG(tooltip)
        actionLoad_Button->setToolTip(QCoreApplication::translate("MainWindow", "Load Ini File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRunSimulation_Button->setText(QCoreApplication::translate("MainWindow", "Run Simulation", nullptr));
#if QT_CONFIG(tooltip)
        actionRunSimulation_Button->setToolTip(QCoreApplication::translate("MainWindow", "Run Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPauseSimulation_Button->setText(QCoreApplication::translate("MainWindow", "PauseSimulation Button", nullptr));
#if QT_CONFIG(tooltip)
        actionPauseSimulation_Button->setToolTip(QCoreApplication::translate("MainWindow", "Pause Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
        actionResetSimulation_Button->setText(QCoreApplication::translate("MainWindow", "ResetSimulation Button", nullptr));
#if QT_CONFIG(tooltip)
        actionResetSimulation_Button->setToolTip(QCoreApplication::translate("MainWindow", "Reset Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExitSimulation_Button->setText(QCoreApplication::translate("MainWindow", "ExitSimulation Button", nullptr));
#if QT_CONFIG(tooltip)
        actionExitSimulation_Button->setToolTip(QCoreApplication::translate("MainWindow", "Exit Simulation", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave_Config->setText(QCoreApplication::translate("MainWindow", "Save Config", nullptr));
        numThreadsInput->setStyleSheet(QString());
        numThreadsInput->setText(QString());
        numThreadsDownButton->setStyleSheet(QString());
        numThreadsDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        numThreadsUpButton->setStyleSheet(QString());
        numThreadsUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        numThreadsLabel->setStyleSheet(QString());
        numThreadsLabel->setText(QCoreApplication::translate("MainWindow", "numThreads", nullptr));
        populationInput->setStyleSheet(QString());
        populationInput->setText(QString());
        populationDownButton->setStyleSheet(QString());
        populationDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        populationUpButton->setStyleSheet(QString());
        populationUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        populationLabel->setStyleSheet(QString());
        populationLabel->setText(QCoreApplication::translate("MainWindow", "population", nullptr));
        sizeXInput->setStyleSheet(QString());
        sizeXInput->setText(QString());
        sizeXDownButton->setStyleSheet(QString());
        sizeXDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        sizeXUpButton->setStyleSheet(QString());
        sizeXUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        sizeXLabel->setStyleSheet(QString());
        sizeXLabel->setText(QCoreApplication::translate("MainWindow", "sizeX", nullptr));
        sizeYInput->setStyleSheet(QString());
        sizeYInput->setText(QString());
        sizeYDownButton->setStyleSheet(QString());
        sizeYDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        sizeYUpButton->setStyleSheet(QString());
        sizeYUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        sizeYLabel->setStyleSheet(QString());
        sizeYLabel->setText(QCoreApplication::translate("MainWindow", "sizeY", nullptr));
        stepsPerGenerationInput->setStyleSheet(QString());
        stepsPerGenerationInput->setText(QString());
        stepsPerGenerationDownButton->setStyleSheet(QString());
        stepsPerGenerationDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        stepsPerGenerationUpButton->setStyleSheet(QString());
        stepsPerGenerationUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        stepsPerGenerationLabel->setStyleSheet(QString());
        stepsPerGenerationLabel->setText(QCoreApplication::translate("MainWindow", "stepsPerGeneration", nullptr));
        maxGenerationsInput->setStyleSheet(QString());
        maxGenerationsInput->setText(QString());
        maxGenerationsDownButton->setStyleSheet(QString());
        maxGenerationsDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        maxGenerationsUpButton->setStyleSheet(QString());
        maxGenerationsUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        maxGenerationsLabel->setStyleSheet(QString());
        maxGenerationsLabel->setText(QCoreApplication::translate("MainWindow", "maxGenerations", nullptr));
        genomeInitialLengthMinInput->setStyleSheet(QString());
        genomeInitialLengthMinInput->setText(QString());
        genomeInitialLengthMinDownButton->setStyleSheet(QString());
        genomeInitialLengthMinDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        genomeInitialLengthMinUpButton->setStyleSheet(QString());
        genomeInitialLengthMinUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        genomeInitialLengthMinLabel->setStyleSheet(QString());
        genomeInitialLengthMinLabel->setText(QCoreApplication::translate("MainWindow", "genomeInitialLengthMin", nullptr));
        genomeInitialLengthMaxInput->setStyleSheet(QString());
        genomeInitialLengthMaxInput->setText(QString());
        genomeInitialLengthMaxDownButton->setStyleSheet(QString());
        genomeInitialLengthMaxDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        genomeInitialLengthMaxUpButton->setStyleSheet(QString());
        genomeInitialLengthMaxUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        genomeInitialLengthMaxLabel->setStyleSheet(QString());
        genomeInitialLengthMaxLabel->setText(QCoreApplication::translate("MainWindow", "genomeInitialLengthMax", nullptr));
        genomeMaxLengthInput->setStyleSheet(QString());
        genomeMaxLengthInput->setText(QString());
        genomeMaxLengthDownButton->setStyleSheet(QString());
        genomeMaxLengthDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        genomeMaxLengthUpButton->setStyleSheet(QString());
        genomeMaxLengthUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        genomeMaxLengthLabel->setStyleSheet(QString());
        genomeMaxLengthLabel->setText(QCoreApplication::translate("MainWindow", "genomeMaxLength", nullptr));
        maxNumberNeuronsInput->setStyleSheet(QString());
        maxNumberNeuronsInput->setText(QString());
        maxNumberNeuronsDownButton->setStyleSheet(QString());
        maxNumberNeuronsDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        maxNumberNeuronsUpButton->setStyleSheet(QString());
        maxNumberNeuronsUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        maxNumberNeuronsLabel->setStyleSheet(QString());
        maxNumberNeuronsLabel->setText(QCoreApplication::translate("MainWindow", "maxNumberNeurons", nullptr));
        killEnableCheckBox->setText(QCoreApplication::translate("MainWindow", "Killable", nullptr));
        sexualReproductionCheckBox->setText(QCoreApplication::translate("MainWindow", "sexualReproduction", nullptr));
        chooseParentsByFitnessCheckBox->setText(QCoreApplication::translate("MainWindow", "chooseParentsByFitness", nullptr));
        pointMutationRateInput->setStyleSheet(QString());
        pointMutationRateInput->setText(QString());
        pointMutationRateDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pointMutationRateUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pointMutationRateLabel->setStyleSheet(QString());
        pointMutationRateLabel->setText(QCoreApplication::translate("MainWindow", "pointMutationRate", nullptr));
        geneInsertionDeletionRateInput->setStyleSheet(QString());
        geneInsertionDeletionRateInput->setText(QString());
        geneInsertionDeletionRateDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        geneInsertionDeletionRateUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        geneInsertionDeletionRateLabel->setStyleSheet(QString());
        geneInsertionDeletionRateLabel->setText(QCoreApplication::translate("MainWindow", "geneInsertionDeletionRate", nullptr));
        deletionRatioInput->setStyleSheet(QString());
        deletionRatioInput->setText(QString());
        deletionRatioDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        deletionRatioUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        deletionRatioLabel->setStyleSheet(QString());
        deletionRatioLabel->setText(QCoreApplication::translate("MainWindow", "deletionRatio", nullptr));
        responsivenessCurveKFactorInput->setStyleSheet(QString());
        responsivenessCurveKFactorInput->setText(QString());
        responsivenessCurveKFactorDownButton->setStyleSheet(QString());
        responsivenessCurveKFactorDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        responsivenessCurveKFactorUpButton->setStyleSheet(QString());
        responsivenessCurveKFactorUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        responsivenessCurveKFactorLabel->setStyleSheet(QString());
        responsivenessCurveKFactorLabel->setText(QCoreApplication::translate("MainWindow", "responsivenessCurveKFactor", nullptr));
        populationSensorRadiusInput->setStyleSheet(QString());
        populationSensorRadiusInput->setText(QString());
        populationSensorRadiusDownButton->setStyleSheet(QString());
        populationSensorRadiusDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        populationSensorRadiusUpButton->setStyleSheet(QString());
        populationSensorRadiusUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        populationSensorRadiusLabel->setStyleSheet(QString());
        populationSensorRadiusLabel->setText(QCoreApplication::translate("MainWindow", "populationSensorRadius", nullptr));
        longProbeDistanceInput->setStyleSheet(QString());
        longProbeDistanceInput->setText(QString());
        longProbeDistanceDownButton->setStyleSheet(QString());
        longProbeDistanceDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        longProbeDistanceUpButton->setStyleSheet(QString());
        longProbeDistanceUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        longProbeDistanceLabel->setStyleSheet(QString());
        longProbeDistanceLabel->setText(QCoreApplication::translate("MainWindow", "longProbeDistance", nullptr));
        shortProbeBarrierDistanceInput->setStyleSheet(QString());
        shortProbeBarrierDistanceInput->setText(QString());
        shortProbeBarrierDistanceDownButton->setStyleSheet(QString());
        shortProbeBarrierDistanceDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        shortProbeBarrierDistanceUpButton->setStyleSheet(QString());
        shortProbeBarrierDistanceUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        shortProbeBarrierDistanceLabel->setStyleSheet(QString());
        shortProbeBarrierDistanceLabel->setText(QCoreApplication::translate("MainWindow", "shortProbeBarrierDistance", nullptr));
        signalSensorRadiusInput->setStyleSheet(QString());
        signalSensorRadiusInput->setText(QString());
        signalSensorRadiusDownButton->setStyleSheet(QString());
        signalSensorRadiusDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        signalSensorRadiusUpButton->setStyleSheet(QString());
        signalSensorRadiusUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        signalSensorRadiusLabel->setStyleSheet(QString());
        signalSensorRadiusLabel->setText(QCoreApplication::translate("MainWindow", "signalSensorRadius", nullptr));
        signalLayersInput->setStyleSheet(QString());
        signalLayersInput->setText(QString());
        signalLayersDownButton->setStyleSheet(QString());
        signalLayersDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        signalLayersUpButton->setStyleSheet(QString());
        signalLayersUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        signalLayersLabel->setStyleSheet(QString());
        signalLayersLabel->setText(QCoreApplication::translate("MainWindow", "signalLayers", nullptr));
        imageDirInput->setStyleSheet(QString());
        imageDirInput->setText(QString());
        imageDirButton->setText(QString());
        imageDirLabel->setStyleSheet(QString());
        imageDirLabel->setText(QCoreApplication::translate("MainWindow", "imageDir", nullptr));
        logDirInput->setStyleSheet(QString());
        logDirInput->setText(QString());
        logDirButton->setText(QString());
        logDirLabel->setStyleSheet(QString());
        logDirLabel->setText(QCoreApplication::translate("MainWindow", "logDir", nullptr));
        displayScaleInput->setStyleSheet(QString());
        displayScaleInput->setText(QString());
        displayScaleDownButton->setStyleSheet(QString());
        displayScaleDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        displayScaleUpButton->setStyleSheet(QString());
        displayScaleUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        displayScaleLabel->setStyleSheet(QString());
        displayScaleLabel->setText(QCoreApplication::translate("MainWindow", "displayScale", nullptr));
        agentSizeInput->setStyleSheet(QString());
        agentSizeInput->setText(QString());
        agentSizeDownButton->setStyleSheet(QString());
        agentSizeDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        agentSizeUpButton->setStyleSheet(QString());
        agentSizeUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        agentSizeLabel->setStyleSheet(QString());
        agentSizeLabel->setText(QCoreApplication::translate("MainWindow", "agentSize", nullptr));
        videoSaveFirstFramesInput->setStyleSheet(QString());
        videoSaveFirstFramesInput->setText(QString());
        videoSaveFirstFramesDownButton->setStyleSheet(QString());
        videoSaveFirstFramesDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        videoSaveFirstFramesUpButton->setStyleSheet(QString());
        videoSaveFirstFramesUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        videoSaveFirstFramesLabel->setStyleSheet(QString());
        videoSaveFirstFramesLabel->setText(QCoreApplication::translate("MainWindow", "videoSaveFirstFrames", nullptr));
        updateGraphLogCheckBox->setText(QCoreApplication::translate("MainWindow", "updateGraphLog", nullptr));
        saveVideoCheckBox->setText(QCoreApplication::translate("MainWindow", "saveVideo", nullptr));
        videoStrideInput->setStyleSheet(QString());
        videoStrideInput->setText(QString());
        videoStrideDownButton->setStyleSheet(QString());
        videoStrideDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        videoStrideUpButton->setStyleSheet(QString());
        videoStrideUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        videoStrideLabel->setStyleSheet(QString());
        videoStrideLabel->setText(QCoreApplication::translate("MainWindow", "videoStride", nullptr));
        genomeComparisonMethodLabel->setStyleSheet(QString());
        genomeComparisonMethodLabel->setText(QCoreApplication::translate("MainWindow", "genomeComparisonMethod", nullptr));
        displaySampleGenomesInput->setStyleSheet(QString());
        displaySampleGenomesInput->setText(QString());
        displaySampleGenomesDownButton->setStyleSheet(QString());
        displaySampleGenomesDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        displaySampleGenomesUpButton->setStyleSheet(QString());
        displaySampleGenomesUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        displaySampleGenomesLabel->setStyleSheet(QString());
        displaySampleGenomesLabel->setText(QCoreApplication::translate("MainWindow", "displaySampleGenomes", nullptr));
        challengeLabel->setStyleSheet(QString());
        challengeLabel->setText(QCoreApplication::translate("MainWindow", "challenge", nullptr));
        barrierTypeLabel->setStyleSheet(QString());
        barrierTypeLabel->setText(QCoreApplication::translate("MainWindow", "barrierType", nullptr));
        deterministicCheckBox->setText(QCoreApplication::translate("MainWindow", "deterministic", nullptr));
        RNGSeedInput->setStyleSheet(QString());
        RNGSeedInput->setText(QString());
        RNGSeedDownButton->setStyleSheet(QString());
        RNGSeedDownButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        RNGSeedUpButton->setStyleSheet(QString());
        RNGSeedUpButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        RNGSeedLabel->setStyleSheet(QString());
        RNGSeedLabel->setText(QCoreApplication::translate("MainWindow", "RNGSeed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Parameters), QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        survivalLabel->setText(QCoreApplication::translate("MainWindow", "Generation Survival Plot", nullptr));
        diversityLabel->setText(QCoreApplication::translate("MainWindow", "Population Diversity Plot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Graphs), QCoreApplication::translate("MainWindow", "Graphs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Agent), QCoreApplication::translate("MainWindow", "Agent", nullptr));
        generationLabel->setStyleSheet(QString());
        generationLabel->setText(QCoreApplication::translate("MainWindow", "Generation: 0", nullptr));
        line->setStyleSheet(QString());
        quickInfo->setStyleSheet(QString());
        quickInfo->setText(QString());
        stepLabel->setStyleSheet(QString());
        stepLabel->setText(QCoreApplication::translate("MainWindow", "Step: 0", nullptr));
        saveConfigButton->setText(QCoreApplication::translate("MainWindow", "Save Config", nullptr));
        lastGenSurvivorsLabel->setStyleSheet(QString());
        lastGenSurvivorsLabel->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
