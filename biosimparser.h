#ifndef BIOSIMPARSER_H
#define BIOSIMPARSER_H

#include <QMap>
#include <QString>

class BiosimParser
{
public:
    BiosimParser();
    void parseIniFile(const QString &filePath);
    QMap<QString, QString> getParameters() const;
    bool getIsFileOpened() const;
private:
    QMap<QString, QString> parameters;
    bool isFileOpened;
};

#endif // BIOSIMPARSER_H
