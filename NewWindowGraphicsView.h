#pragma once

#include "qevent.h"
#include "qgraphicsitem.h"
#include <QGraphicsView>
#include <QMenu>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsVideoItem>
#include <QMediaMetaData>

#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QDebug>

class NewWindowGraphicsView : public QGraphicsView {
    Q_OBJECT
private:
    QMediaPlayer *mediaPlayer;
    QGraphicsVideoItem *videoItem;

public:
    explicit NewWindowGraphicsView(QWidget *parent = nullptr) : QGraphicsView(parent) {
        // Ensure the view scales contents automatically
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setScene(new QGraphicsScene(this));
        setAlignment(Qt::AlignCenter);

        mediaPlayer = nullptr;

    }

    // Method to set and scale pixmap
    void setAndScalePixmap(const QPixmap &pixmap) {
        scene()->clear();  // Clear the previous content
        auto item = scene()->addPixmap(pixmap);
        fitInView(item, Qt::KeepAspectRatio);  // Scale the pixmap to fit the view
    }

    QMediaPlayer* getMediaPlayer() const {
        if (mediaPlayer != nullptr) {
            return mediaPlayer;
        }
        return nullptr;
    }

protected:
    void resizeEvent(QResizeEvent *event) override {
        QGraphicsView::resizeEvent(event);
        if (!scene()->items().isEmpty()) {
            //fitInView(scene()->items().first(), Qt::KeepAspectRatio);
            fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
        }
    }

    void contextMenuEvent(QContextMenuEvent *event) override {
        QString menuStyle = R"(
            QMenu::item {
                font-size: 14pt;
                color: #333333;
                padding: 4px 12px; /* Vertical padding of 4px and horizontal padding of 12px */
                margin: 2px; /* Margin around items */
            }
            QMenu::item:selected {
                background-color: #b0c4de; /* Light blue background for selected item */
            }
        )";
        QMenu menu;
        menu.setStyleSheet(menuStyle);

        QAction *loadImageAction = menu.addAction("Load Image");
        QAction *loadVideoAction = menu.addAction("Load Video");
        QAction *clearAction = menu.addAction("Clear");

        QAction *selectedAction = menu.exec(event->globalPos());
        if (selectedAction == loadImageAction) {
            loadImage();
        } else if (selectedAction == loadVideoAction) {
            loadVideo();
        } else if (selectedAction == clearAction) {
            clear();
        }
    }

private:
    void makeMediaPlayerNullptr(){
        if(mediaPlayer!=nullptr){
            if(mediaPlayer->hasVideo()){
                mediaPlayer->pause();
                mediaPlayer->setPosition(0);
                delete mediaPlayer;
                mediaPlayer = nullptr;
            }
        }
    }
    void loadImage() {
        clear();
        makeMediaPlayerNullptr();
        QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
        if (!fileName.isEmpty()) {
            // Stop the video if it's currently playing
            if (mediaPlayer && mediaPlayer->isPlaying()) {
                mediaPlayer->stop();
                scene()->removeItem(videoItem);
                delete videoItem;
                videoItem = nullptr;
            }

            QGraphicsScene *scene = new QGraphicsScene(this);
            QPixmap pixmap(fileName);
            scene->addPixmap(pixmap);
            setScene(scene);
            fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        }
    }

    void loadVideo() {
        clear();
        makeMediaPlayerNullptr();
        QString fileName = QFileDialog::getOpenFileName(this, "Open Video", "", "Video Files (*.mp4 *.avi)");
        if (!fileName.isEmpty()) {
            mediaPlayer = new QMediaPlayer(this);
            videoItem = new QGraphicsVideoItem;
            QGraphicsScene *scene = new QGraphicsScene(this);
            setScene(scene);
            scene->addItem(videoItem);

            mediaPlayer ->setSource(QUrl::fromLocalFile(fileName));
            mediaPlayer->setVideoOutput(videoItem);

            // Set the size of the video item to match the view size
            videoItem->setSize(size());

            // Scale the video item to fill the view while maintaining aspect ratio
            videoItem->setAspectRatioMode(Qt::KeepAspectRatio);
            fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

            // Connect the positionChanged signal to the handlePlayerPositionChanged slot
            connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &NewWindowGraphicsView::handlePlayerPositionChanged);
            connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &NewWindowGraphicsView::handleSimulationStep);

            emit videoGenerationChanged(fileName.split("/").last().split("-").last().split(".").first());
            mediaPlayer->play();
        }
    }

    void clear() {
        makeMediaPlayerNullptr();
        QGraphicsScene *scene = new QGraphicsScene(this);
        setScene(scene);
        emit videoCleared();
    }

    int mapPositionToFrameStep(int position, double totalDurationMs) {
        double frameDurationPositionScale = (10000.0 / totalDurationMs) * 33.33;
        return static_cast<int>((position / frameDurationPositionScale) + 0.5); // rounding
    }
private slots:
    void handlePlayerPositionChanged(qint64 position) {
        if (position >= mediaPlayer->duration() - 40) {
            // Seek to the end of the video when playback is about to stop
            mediaPlayer->setPosition(mediaPlayer->duration());
            mediaPlayer->pause();
        }
        if (mediaPlayer != nullptr) {
            qint64 duration = mediaPlayer->duration();
            int sliderPosition = (position * 99) / duration;
            emit mediaPlayerPositionChanged(sliderPosition);
        }
    }

    void handleSimulationStep(qint64 position){
        //fps 30
        int frameStep = mapPositionToFrameStep(static_cast<int>(position), mediaPlayer->duration());
        emit simulationStepChanged(frameStep);
    }

signals:
    void videoGenerationChanged(QString generation);
    void mediaPlayerPositionChanged(int position);
    void playbackPositionChanged(qint64 position);
    void simulationStepChanged(int step);
    void videoCleared();
};
