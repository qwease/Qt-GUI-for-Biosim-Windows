#include "SimulationGraphicsView.h"


#include "qlabel.h"
#include "qpushbutton.h"
#include "qslider.h"



void SimulationGraphicsView::setStep(int step){
    this->step = step;
}

void SimulationGraphicsView::setGeneration(int generation){
    this->generation = generation;
}

void SimulationGraphicsView::setCurrentPixmap(QPixmap pixmap){
    this->currentPixmap = pixmap;
}

void SimulationGraphicsView::openSimulationWindow(int step, int generation) {
    if (window != nullptr) {
        window->raise();  // Brings the window to the foreground
        window->activateWindow();  // Focus the window
        return;
    }

    window = new QWidget;
    windowLayout = new QVBoxLayout(window);
    //window->setStyleSheet(window->styleSheet()+"; background-color: #f0f0f0;");  // Window styling

    QString viewStyle = R"(
        QGraphicsView {
            background-color: { background-color:  #f2f2f2 };
            border-style: inset;
            border-width: 2px;
            border-color: gray;
        }
    )";

    QString labelCSS="QLabel {margin-left:5px; font-size: 20px;color: #333333;} QToolTip { background-color: #e6e6e6; font-size: 13pt; padding: 2px; opacity: 200; border:none;}";
    QString buttonCSS="QPushButton {font-size: 17px;}";

    //current--------------------------------------------------
    currentLayout = new QVBoxLayout();
    currentInfoLayout = new QHBoxLayout();
    currentLabel = new QLabel("Main View");
    currentGenerationLabel = new QLabel("Generation: "+QString::number(generation));
    currentStepLabel = new QLabel("Step: "+QString::number(step));

    currentLabel->setStyleSheet(labelCSS);
    currentGenerationLabel->setStyleSheet(labelCSS);
    currentStepLabel->setStyleSheet(labelCSS);

    currentView = new NewWindowGraphicsView();

    currentView->setAndScalePixmap(currentPixmap);

    currentSlider = new QSlider(Qt::Horizontal);
    currentControlsLayout = new QHBoxLayout();
    currentPlayButton = new QPushButton("Play");
    currentPauseButton = new QPushButton("Pause");
    currentSpeedX1Button = new QPushButton("x1");
    currentSpeedX2Button = new QPushButton("x2");
    currentSpeedX4Button = new QPushButton("x4");
    currentPlayButton->setStyleSheet(buttonCSS);
    currentPauseButton->setStyleSheet(buttonCSS);
    currentSpeedX1Button->setStyleSheet(buttonCSS);
    currentSpeedX2Button->setStyleSheet(buttonCSS);
    currentSpeedX4Button->setStyleSheet(buttonCSS);

    currentInfoLayout->addWidget(currentLabel);
    currentInfoLayout->addWidget(currentGenerationLabel);
    currentInfoLayout->addWidget(currentStepLabel);

    currentControlsLayout->addWidget(currentPlayButton);
    currentControlsLayout->addWidget(currentPauseButton);
    currentControlsLayout->addWidget(currentSpeedX1Button);
    currentControlsLayout->addWidget(currentSpeedX2Button);
    currentControlsLayout->addWidget(currentSpeedX4Button);

    currentLayout->addLayout(currentInfoLayout);
    currentLayout->addWidget(currentView);
    currentLayout->addWidget(currentSlider);
    currentLayout->addLayout(currentControlsLayout);
    //---------------------------------------------------------

    //previous-------------------------------------------------
    previousLayout = new QVBoxLayout();
    previousInfoLayout = new QHBoxLayout();
    previousLabel = new QLabel("Secondary View");
    previousGenerationLabel = new QLabel("Generation: ");
    previousStepLabel = new QLabel("Step: ");

    previousLabel->setStyleSheet(labelCSS);
    previousGenerationLabel->setStyleSheet(labelCSS);
    previousStepLabel->setStyleSheet(labelCSS);

    previousView = new NewWindowGraphicsView();
    previousSlider = new QSlider(Qt::Horizontal);
    previousControlsLayout = new QHBoxLayout();
    previousPlayButton = new QPushButton("Play");
    previousPauseButton = new QPushButton("Pause");
    previousSpeedX1Button = new QPushButton("x1");
    previousSpeedX2Button = new QPushButton("x2");
    previousSpeedX4Button = new QPushButton("x4");

    previousPlayButton->setStyleSheet(buttonCSS);
    previousPauseButton->setStyleSheet(buttonCSS);
    previousSpeedX1Button->setStyleSheet(buttonCSS);
    previousSpeedX2Button->setStyleSheet(buttonCSS);
    previousSpeedX4Button->setStyleSheet(buttonCSS);

    previousInfoLayout->addWidget(previousLabel);
    previousInfoLayout->addWidget(previousGenerationLabel);
    previousInfoLayout->addWidget(previousStepLabel);

    previousControlsLayout->addWidget(previousPlayButton);
    previousControlsLayout->addWidget(previousPauseButton);
    previousControlsLayout->addWidget(previousSpeedX1Button);
    previousControlsLayout->addWidget(previousSpeedX2Button);
    previousControlsLayout->addWidget(previousSpeedX4Button);

    previousLayout->addLayout(previousInfoLayout);
    previousLayout->addWidget(previousView);
    previousLayout->addWidget(previousSlider);
    previousLayout->addLayout(previousControlsLayout);
    //---------------------------------------------------------

    // Setup current view
    currentView->setStyleSheet(viewStyle);

    // Setup previous view
    previousView->setStyleSheet(viewStyle);

    mainLayout = new QHBoxLayout();
    mainLayout->addLayout(previousLayout);
    mainLayout->addLayout(currentLayout);

    globalSlider = new QSlider(Qt::Horizontal);
    globalPlayButton = new QPushButton("Play");
    globalPauseButton = new QPushButton("Pause");
    globalSpeedX1Button = new QPushButton("x1");
    globalSpeedX2Button = new QPushButton("x2");
    globalSpeedX4Button = new QPushButton("x4");

    globalPlayButton->setStyleSheet(buttonCSS);
    globalPauseButton->setStyleSheet(buttonCSS);
    globalSpeedX1Button->setStyleSheet(buttonCSS);
    globalSpeedX2Button->setStyleSheet(buttonCSS);
    globalSpeedX4Button->setStyleSheet(buttonCSS);

    globalControlsLayout = new QHBoxLayout();
    globalControlsLayout->addWidget(globalPlayButton);
    globalControlsLayout->addWidget(globalPauseButton);
    globalControlsLayout->addWidget(globalSpeedX1Button);
    globalControlsLayout->addWidget(globalSpeedX2Button);
    globalControlsLayout->addWidget(globalSpeedX4Button);

    bottomLayout = new QVBoxLayout();
    bottomLayout->addWidget(globalSlider);
    bottomLayout->addLayout(globalControlsLayout);

    windowLayout->addLayout(mainLayout);
    windowLayout->addLayout(bottomLayout);


    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setLayout(windowLayout);
    window->resize(1800, 1100);
    window->show();

    // Ensure the window is deleted properly when closed
    connect(window, &QWidget::destroyed, this, &SimulationGraphicsView::newWindowDestroyed);

    //----connection
    // Connect the play button to the play slot
    connect(currentPlayButton, &QPushButton::clicked, this, &SimulationGraphicsView::playCurrentVideo);
    connect(previousPlayButton, &QPushButton::clicked, this, &SimulationGraphicsView::playPreviousVideo);
    connect(globalPlayButton, &QPushButton::clicked, this, &SimulationGraphicsView::playGlobalVideo);

    // Connect the pause button to the pause slot
    connect(currentPauseButton, &QPushButton::clicked, this, &SimulationGraphicsView::pauseCurrentVideo);
    connect(previousPauseButton, &QPushButton::clicked, this, &SimulationGraphicsView::pausePreviousVideo);

    // Connect the x1 button to the setPlaybackRate slot with a rate of 1.0
    connect(currentSpeedX1Button, &QPushButton::clicked, this, [this]() { setCurrentPlaybackRate(1.0); });
    connect(previousSpeedX1Button, &QPushButton::clicked, this, [this]() { setPreviousPlaybackRate(1.0); });

    // Connect the x2 button to the setPlaybackRate slot with a rate of 2.0
    connect(currentSpeedX2Button, &QPushButton::clicked, this, [this]() { setCurrentPlaybackRate(2.0); });
    connect(previousSpeedX2Button, &QPushButton::clicked, this, [this]() { setPreviousPlaybackRate(2.0); });

    // Connect the x4 button to the setPlaybackRate slot with a rate of 4.0
    connect(currentSpeedX4Button, &QPushButton::clicked, this, [this]() { setCurrentPlaybackRate(4.0); });
    connect(previousSpeedX4Button, &QPushButton::clicked, this, [this]() { setPreviousPlaybackRate(4.0); });

    // Connect the slider valueChanged signal to the setPosition slot
    connect(currentSlider, &QSlider::sliderMoved, this, &SimulationGraphicsView::setCurrentPosition);
    connect(previousSlider, &QSlider::sliderMoved, this, &SimulationGraphicsView::setPreviousPosition);

    connect(currentSlider, &QSlider::sliderPressed, this, &SimulationGraphicsView::pauseCurrentVideo);
    connect(previousSlider, &QSlider::sliderPressed, this, &SimulationGraphicsView::pausePreviousVideo);

    connect(currentView, &NewWindowGraphicsView::mediaPlayerPositionChanged, this, &SimulationGraphicsView::updateCurrentSliderPosition);
    connect(previousView, &NewWindowGraphicsView::mediaPlayerPositionChanged, this, &SimulationGraphicsView::updatePreviousSliderPosition);

    connect(currentView, &NewWindowGraphicsView::simulationStepChanged, this, &SimulationGraphicsView::updateCurrentSimulationStep);
    connect(previousView, &NewWindowGraphicsView::simulationStepChanged, this, &SimulationGraphicsView::updatePreviousSimulationStep);

    connect(currentView, &NewWindowGraphicsView::videoGenerationChanged, this, &SimulationGraphicsView::updateCurrentVideoGeneration);
    connect(previousView, &NewWindowGraphicsView::videoGenerationChanged, this, &SimulationGraphicsView::updatePreviousVideoGeneration);

    connect(currentView, &NewWindowGraphicsView::videoCleared, this, &SimulationGraphicsView::updateCurrentVideoControls);
    connect(previousView, &NewWindowGraphicsView::videoCleared, this, &SimulationGraphicsView::updatePreviousVideoControls);

    // Connect the slider sliderPressed signal to pause the video
    connect(currentSlider, &QSlider::sliderPressed, this, &SimulationGraphicsView::pauseCurrentVideo);
    connect(previousSlider, &QSlider::sliderPressed, this, &SimulationGraphicsView::pausePreviousVideo);

    // Connect the global slider sliderMoved signal to the setPosition slot of both players
    connect(globalSlider, &QSlider::sliderMoved, this, &SimulationGraphicsView::setGlobalPosition);

    connect(globalPlayButton, &QPushButton::clicked, this, &SimulationGraphicsView::playGlobalVideo);
    connect(globalPauseButton, &QPushButton::clicked, this, &SimulationGraphicsView::pauseGlobalVideo);
    connect(globalSpeedX1Button, &QPushButton::clicked, this, [this]() { setGlobalPlaybackRate(1.0); });
    connect(globalSpeedX2Button, &QPushButton::clicked, this, [this]() { setGlobalPlaybackRate(2.0); });
    connect(globalSpeedX4Button, &QPushButton::clicked, this, [this]() { setGlobalPlaybackRate(4.0); });
}

void SimulationGraphicsView::playCurrentVideo() {
    currentMediaPlayer = currentView->getMediaPlayer();
    if (currentMediaPlayer != nullptr) {
        currentMediaPlayer->play();
    }
}

void SimulationGraphicsView::playPreviousVideo() {
    previousMediaPlayer = previousView->getMediaPlayer();
    if (previousMediaPlayer != nullptr) {
        previousMediaPlayer->play();
    }
}

void SimulationGraphicsView::pauseCurrentVideo() {
    currentMediaPlayer = currentView->getMediaPlayer();
    if (currentMediaPlayer != nullptr) {
        currentMediaPlayer->pause();
    }
}

void SimulationGraphicsView::pausePreviousVideo() {
    previousMediaPlayer = previousView->getMediaPlayer();
    if (previousMediaPlayer != nullptr) {
        previousMediaPlayer->pause();
    }
}

void SimulationGraphicsView::setCurrentPlaybackRate(qreal rate) {
    currentMediaPlayer = currentView->getMediaPlayer();

    if (currentMediaPlayer != nullptr) {
        if(!currentMediaPlayer->isPlaying()){
            currentMediaPlayer->play();
        }
        currentMediaPlayer->setPlaybackRate(rate);
    }
}

void SimulationGraphicsView::setPreviousPlaybackRate(qreal rate) {
    previousMediaPlayer = previousView->getMediaPlayer();

    if (previousMediaPlayer != nullptr) {
        if(!previousMediaPlayer->isPlaying()){
            previousMediaPlayer->play();
        }
        previousMediaPlayer->setPlaybackRate(rate);
    }
}

void SimulationGraphicsView::setCurrentPosition(int sliderPosition) {
    currentMediaPlayer = currentView->getMediaPlayer();
    if (currentMediaPlayer != nullptr) {
        qint64 duration = currentMediaPlayer->duration();
        qint64 position = (duration * sliderPosition) / 99;
        currentMediaPlayer->setPosition(position);
    }
}

void SimulationGraphicsView::setPreviousPosition(int sliderPosition) {
    previousMediaPlayer = previousView->getMediaPlayer();
    if (previousMediaPlayer != nullptr) {
        qint64 duration = previousMediaPlayer->duration();
        qint64 position = (duration * sliderPosition) / 99;
        previousMediaPlayer->setPosition(position);
    }
}

void SimulationGraphicsView::updateCurrentSliderPosition(qint64 position) {
    currentMediaPlayer = currentView->getMediaPlayer();
    if (currentMediaPlayer != nullptr && currentMediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        currentSlider->setSliderPosition(position);
    }
}

void SimulationGraphicsView::updatePreviousSliderPosition(qint64 position) {
    previousMediaPlayer = previousView->getMediaPlayer();
    if (previousMediaPlayer != nullptr && previousMediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        previousSlider->setSliderPosition(position);
    }
}

void SimulationGraphicsView::updateCurrentSimulationStep(int step){
    currentStepLabel->setText(QString("Step: ")+QString::number(step));
}

void SimulationGraphicsView::updatePreviousSimulationStep(int step){
    previousStepLabel->setText(QString("Step: ")+QString::number(step));
}

void SimulationGraphicsView::updateCurrentVideoGeneration(QString generation){
    currentGenerationLabel->setText(QString("Generation: ")+generation);
}

void SimulationGraphicsView::updatePreviousVideoGeneration(QString generation){
    previousGenerationLabel->setText(QString("Generation: ")+generation);
}

void SimulationGraphicsView::updateCurrentVideoControls(){
    currentGenerationLabel->setText("Generation: ");
    currentStepLabel->setText("Step: ");
    currentSlider->setSliderPosition(0);
}

void SimulationGraphicsView::updatePreviousVideoControls(){
    previousGenerationLabel->setText("Generation: ");
    previousStepLabel->setText("Step: ");
    previousSlider->setSliderPosition(0);
}

void SimulationGraphicsView::playGlobalVideo() {
    currentMediaPlayer = currentView->getMediaPlayer();
    previousMediaPlayer = previousView->getMediaPlayer();

    if (currentMediaPlayer != nullptr && currentMediaPlayer->playbackState() == QMediaPlayer::PausedState) {
        currentMediaPlayer->play();
    }
    if (previousMediaPlayer != nullptr && previousMediaPlayer->playbackState() == QMediaPlayer::PausedState) {
        previousMediaPlayer->play();
    }
}

void SimulationGraphicsView::pauseGlobalVideo() {
    currentMediaPlayer = currentView->getMediaPlayer();
    previousMediaPlayer = previousView->getMediaPlayer();

    if (currentMediaPlayer != nullptr && currentMediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        currentMediaPlayer->pause();
    }
    if (previousMediaPlayer != nullptr && previousMediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        previousMediaPlayer->pause();
    }
}

void SimulationGraphicsView::setGlobalPlaybackRate(qreal rate) {
    currentMediaPlayer = currentView->getMediaPlayer();
    previousMediaPlayer = previousView->getMediaPlayer();

    if (currentMediaPlayer != nullptr) {
        if(!currentMediaPlayer->isPlaying()){
            currentMediaPlayer->play();
        }
        currentMediaPlayer->setPlaybackRate(rate);
    }
    if (previousMediaPlayer != nullptr) {
        if(!previousMediaPlayer->isPlaying()){
            previousMediaPlayer->play();
        }
        previousMediaPlayer->setPlaybackRate(rate);
    }
}

void SimulationGraphicsView::setGlobalPosition(int sliderPosition) {
    currentMediaPlayer = currentView->getMediaPlayer();
    previousMediaPlayer = previousView->getMediaPlayer();

    if (currentMediaPlayer != nullptr) {
        currentMediaPlayer->pause();
        qint64 duration = currentMediaPlayer->duration();
        qint64 position = (duration * sliderPosition) / 99;
        currentSlider->setSliderPosition(sliderPosition);
        currentMediaPlayer->setPosition(position);
    }


    if (previousMediaPlayer != nullptr) {
        previousMediaPlayer->pause();
        qint64 duration = previousMediaPlayer->duration();
        qint64 position = (duration * sliderPosition) / 99;
        previousSlider->setSliderPosition(sliderPosition);
        previousMediaPlayer->setPosition(position);
    }
}

void SimulationGraphicsView::newWindowDestroyed(){
    window = nullptr;
}
