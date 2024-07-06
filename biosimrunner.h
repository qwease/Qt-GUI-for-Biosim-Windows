#ifndef BIOSIMRUNNER_H
#define BIOSIMRUNNER_H

#include <QObject>
#include <QMap>
#include <QImage>
#include <QString>

class BiosimRunner : public QObject
{
    Q_OBJECT

public:
    BiosimRunner(QObject *parent = nullptr);
    void initialize(const QMap<QString, QString> &parameters);
    void run(QString filenmae);
    void pause();
    void resume();
    void reset();
    void exit();

signals:
    void simulationUpdated(QImage lastFrame);
    void stepUpdated(int step);
    void generationUpdated(int generation);
    void agentImageUpdated(QString fileName);
    void plotsUpdated();
    void survivorsUpdated(QString survivorsInfo);
    void loggerUpdated(QString log);

private:
         // Add necessary member variables and methods for biosim4 integration
};

#endif // BIOSIMRUNNER_H
