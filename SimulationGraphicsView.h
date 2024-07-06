#ifndef SIMULATIONGRAPHICSVIEW_H
#define SIMULATIONGRAPHICSVIEW_H

#include "qlabel.h"
#endif // SIMULATIONGRAPHICSVIEW_H
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QFileDialog>
#include <QSlider>
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qslider.h"
#include "NewWindowGraphicsView.h"

class SimulationGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    int step;
    int generation;
    void setStep(int step);
    void setGeneration(int generation);
    void setCurrentPixmap(QPixmap pixmap);

    //GUI Specific
    QWidget *window;
    QVBoxLayout *windowLayout;

    //current
    QVBoxLayout *currentLayout;
    QHBoxLayout *currentInfoLayout;
    QLabel *currentLabel;
    QLabel *currentGenerationLabel;
    QLabel *currentStepLabel;
    NewWindowGraphicsView *currentView;

    QSlider *currentSlider;
    QHBoxLayout *currentControlsLayout;
    QPushButton *currentPlayButton;
    QPushButton *currentPauseButton;
    QPushButton *currentSpeedX1Button;
    QPushButton *currentSpeedX2Button;
    QPushButton *currentSpeedX4Button;

    //previous
    QVBoxLayout *previousLayout;
    QHBoxLayout *previousInfoLayout;
    QLabel *previousLabel;
    QLabel *previousGenerationLabel;
    QLabel *previousStepLabel;
    NewWindowGraphicsView *previousView;
    QSlider *previousSlider;
    QHBoxLayout *previousControlsLayout;
    QPushButton *previousPlayButton;
    QPushButton *previousPauseButton;
    QPushButton *previousSpeedX1Button;
    QPushButton *previousSpeedX2Button;
    QPushButton *previousSpeedX4Button;

    QHBoxLayout *mainLayout;

    //global
    QSlider *globalSlider;
    QPushButton *globalPlayButton;
    QPushButton *globalPauseButton;
    QPushButton *globalSpeedX1Button;
    QPushButton *globalSpeedX2Button;
    QPushButton *globalSpeedX4Button;

    QHBoxLayout *globalControlsLayout;
    QVBoxLayout *bottomLayout;

    explicit SimulationGraphicsView(QWidget *parent = nullptr) : QGraphicsView(parent) {}
    SimulationGraphicsView(const SimulationGraphicsView&) = delete;
    SimulationGraphicsView& operator=(const SimulationGraphicsView&) = delete;

private:
    QPixmap currentPixmap;
    QMediaPlayer * currentMediaPlayer;
    QMediaPlayer * previousMediaPlayer;

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            openSimulationWindow(step,generation);
        }
    }

private:
    void openSimulationWindow(int step, int generation);

private slots:
    void newWindowDestroyed();

    void playCurrentVideo();
    void playPreviousVideo();
    void playGlobalVideo();

    void pauseCurrentVideo();
    void pausePreviousVideo();
    void pauseGlobalVideo();

    void setCurrentPlaybackRate(qreal rate);
    void setPreviousPlaybackRate(qreal rate);
    void setGlobalPlaybackRate(qreal rate);

    void setCurrentPosition(int position);
    void setPreviousPosition(int position);
    void updateCurrentSliderPosition(qint64 position);
    void updatePreviousSliderPosition(qint64 position);
    void updateCurrentSimulationStep(int step);
    void updatePreviousSimulationStep(int step);
    void updateCurrentVideoGeneration(QString generation);
    void updatePreviousVideoGeneration(QString generation);
    void updateCurrentVideoControls();
    void updatePreviousVideoControls();


    void setGlobalPosition(int position);
};
