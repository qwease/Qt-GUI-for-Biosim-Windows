#ifndef BIOSIMWIDGET_H
#define BIOSIMWIDGET_H

#include <QGraphicsScene>

class BiosimWidget : public QGraphicsScene
{
    Q_OBJECT

public:
    BiosimWidget(QObject *parent = nullptr);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:

};

#endif // BIOSIMWIDGET_H
