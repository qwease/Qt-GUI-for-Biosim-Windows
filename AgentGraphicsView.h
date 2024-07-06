#ifndef AGENTGRAPHICSVIEW_H
#define AGENTGRAPHICSVIEW_H

#include <QGraphicsView>

class AgentGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    AgentGraphicsView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QPointF lastMousePos;
    bool isPanning;
};

#endif // AGENTGRAPHICSVIEW_H
