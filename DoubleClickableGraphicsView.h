#ifndef DOUBLECLICKABLEGRAPHICSVIEW_H
#define DOUBLECLICKABLEGRAPHICSVIEW_H
#include "qapplication.h"
#endif // DOUBLECLICKABLEGRAPHICSVIEW_H
#include "qevent.h"
#include "qgraphicsitem.h"

#include <QGraphicsView>
#include <QLabel>
// In your header file, declare a new subclass of QGraphicsView
class DoubleClickableGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    using QGraphicsView::QGraphicsView; // inherit constructors

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override {
        QGraphicsItem *item = itemAt(event->pos());
        if (!item)
            return;

        QGraphicsPixmapItem *pixmapItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        if (!pixmapItem)
            return;

        QPixmap pixmap = pixmapItem->pixmap();
        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(pixmap);
        imageLabel->setScaledContents(true);  // Optional: Scale image to fit window

        // Calculate the center position relative to the screen size
        QScreen *screen = QApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();

        int x = (screenGeometry.width() - pixmap.width()) / 2;
        int y = (screenGeometry.height() - pixmap.height()) / 2;
        // Move the window to the center of the screen
        imageLabel->move(x,y);

        // Show the label
        imageLabel->show();
    }
};
