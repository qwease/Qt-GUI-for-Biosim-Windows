#include "biosimparser.h"
#include <QFile>
#include <QTextStream>


BiosimParser::BiosimParser() {}



void BiosimParser::parseIniFile(const QString &filePath)
{
    QFile file(filePath);
    this->isFileOpened=false;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        this->isFileOpened=true;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty() && !line.startsWith("#")) {
                QStringList parts = line.split("=");
                if (parts.size() == 2) {
                    QString key = parts[0].trimmed();
                    QString value = parts[1].trimmed();
                    parameters[key] = value;
                }
            }
        }
        file.close();

    }else{
        // for any reason open failed
        //
    }
}

bool BiosimParser::getIsFileOpened() const {
    return this->isFileOpened;
}

QMap<QString, QString> BiosimParser::getParameters() const
{
    return parameters;
}
