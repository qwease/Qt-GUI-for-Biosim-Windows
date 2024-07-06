#include "AgentGraphicsView.h"
#include <QWheelEvent>

AgentGraphicsView::AgentGraphicsView(QWidget *parent)
    : QGraphicsView(parent), isPanning(false)
{
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
    setOptimizationFlag(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

void AgentGraphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    double currentScale = transform().m11();
    if (event->angleDelta().y() > 0 && currentScale < 10.0) {
        scale(scaleFactor, scaleFactor);
    } else if (event->angleDelta().y() < 0 && currentScale > 0.1){
        scale(1 / scaleFactor, 1 / scaleFactor);
    }

    event->accept();
}
