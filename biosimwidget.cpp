#include "biosimwidget.h"
#include "biosim4/simulator.h"
#include "biosim4/imageWriter.h"

#include <QPainter>

BiosimWidget::BiosimWidget(QObject *parent)
    : QGraphicsScene(parent)
{
    setBackgroundBrush(Qt::white);
}

void BiosimWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter, rect);
    // Call more drawing functions as needed
}
