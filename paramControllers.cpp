#include "mainwindow.h"
#include "ui_mainwindow.h"
//numThreads
void MainWindow::updateNumThreads()
{
    updateParam("numThreads",numThreadsAmount,1,512,ui->numThreadsInput);
}
//down
void MainWindow::on_numThreadsDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("numThreads",-1,1,512,ui->numThreadsInput);
}

void MainWindow::on_numThreadsDownButton_pressed()
{
    onButtonDownPressed(&numThreadsAmount);
}

void MainWindow::on_numThreadsDownButton_released()
{
    onButtonDownReleased(&numThreadsAmount);
}

//up
void MainWindow::on_numThreadsUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("numThreads",1,1,512,ui->numThreadsInput);
}

void MainWindow::on_numThreadsUpButton_pressed()
{
    onButtonUpPressed(&numThreadsAmount);
}

void MainWindow::on_numThreadsUpButton_released()
{
    onButtonUpReleased(&numThreadsAmount);
}

//input
void MainWindow::numThreadsInputEditingFinished(){
    // qDebug()<<"numThread: "<<ui->numThreadsInput->text();
    QString numThreadsQString = parameters.value("numThreads");
    QString tempNumThreads = ui->numThreadsInput->text();

    if(numThreadsQString == tempNumThreads){
        return;
    }

    parameterModified = true;

    bool ok;
    ushort numThreads = 0;
    numThreads = tempNumThreads.toUShort(&ok,10);

    //qDebug()<<numThreads;

    if(ok && (numThreads>=1 && numThreads <= 512)){
        parameters["numThreads"] = QString::number(numThreads);
        ui->numThreadsInput->setText(QString::number(numThreads));
    }else{
        ui->numThreadsInput->setText(numThreadsQString); //last time valid
        qDebug()<<"numThread: Invalide";
    }
}

void MainWindow::on_numThreadsInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        ui->numThreadsInput->setText(text);
        return;
    }

    int number = text.toInt(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        if(text == ""){
            return;
        }
        ui->numThreadsInput->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->numThreadsInput->setText("0");
        }
        if(number>512){
            parameters["numThreads"] = "512";
            ui->numThreadsInput->setText("512");
        }
        return;
    }

    if(isNumber){
        if(number==text.toUShort()){
            //no overflow
            if(number>512){
                parameters["numThreads"] = "512";
                ui->numThreadsInput->setText("512");
            }else if(number==0){
                parameters["numThreads"] = "1";
                ui->numThreadsInput->setText("1");
            }else{
                text=QString::number(number);
                parameters["numThreads"] = text;
                ui->numThreadsInput->setText(text);
            }
        }else{
            //with overflow
            //return to default
            parameters["numThreads"] = "16";
            ui->numThreadsInput->setText("16");
        }
        parameterModified = true;
    }
}

//sizeX
void MainWindow::updateSizeX()
{
    updateParam("sizeX",sizeXAmount,16,32767,ui->sizeXInput);
}
//up
void MainWindow::on_sizeXUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("sizeX",1,16,32767,ui->sizeXInput);
}

void MainWindow::on_sizeXUpButton_pressed()
{
    onButtonUpPressed(&sizeXAmount);
}

void MainWindow::on_sizeXUpButton_released()
{
    onButtonUpReleased(&sizeXAmount);
}

//down
void MainWindow::on_sizeXDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("sizeX",-1,16,32767,ui->sizeXInput);
}

void MainWindow::on_sizeXDownButton_pressed()
{
    onButtonDownPressed(&sizeXAmount);
}

void MainWindow::on_sizeXDownButton_released()
{
    onButtonDownReleased(&sizeXAmount);
}

//input
void MainWindow::on_sizeXInput_editingFinished()
{
    QString sizeXQString = parameters.value("sizeX");
    QString sizeYQString = parameters.value("sizeY");
    QString tempSizeX = ui->sizeXInput->text();
    if (tempSizeX.size()==0 || tempSizeX =="0"){
        ui->sizeXInput->setText(sizeXQString);
        ui->sizeYInput->setText(sizeYQString);
        return;
    }

    if(sizeXQString == tempSizeX){
        return;
    }

    bool ok;
    int sizeX = 0;
    sizeX = tempSizeX.toInt(&ok,10);

    //qDebug()<<sizeX;

    if(ok && (sizeX>=16 && sizeX <= 32767)){
        tempSizeX = QString::number(sizeX); //remove begin 0

        parameters["sizeX"] = tempSizeX;
        ui->sizeXInput->setText(tempSizeX);

        parameters["sizeY"] = tempSizeX;
        ui->sizeYInput->setText(tempSizeX);

        parameterModified = true;
    }else if(sizeX>32767){
        parameters["sizeX"] = "32767";
        ui->sizeXInput->setText("32767");

        parameters["sizeY"] = "32767";
        ui->sizeYInput->setText("32767");

        parameterModified = true;
    }else if(sizeX<16){
        parameters["sizeX"] = "16";
        ui->sizeXInput->setText("16");

        parameters["sizeY"] = "16";
        ui->sizeYInput->setText("16");

        parameterModified = true;
    }else{
        ui->sizeXInput->setText(sizeXQString); //last time valid
        qDebug()<<"sizeX: Invalide";

        ui->sizeYInput->setText(sizeYQString); //last time valid
        qDebug()<<"sizeY: Invalide";
    }
}

void MainWindow::on_sizeXInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;
    text.toInt(&isNumber,10);
    //qDebug()<<tempChangeText;
    if(text == "" || text.size()==0){
        ui->sizeYInput->setText(ui->sizeXInput->text());
        return;
    }
    if (text.startsWith("-") || !isNumber){
        ui->sizeXInput->setText(ui->sizeYInput->text());
        return;
    }
    ui->sizeYInput->setText(ui->sizeXInput->text());
    return;
}

//sizeY
void MainWindow::updateSizeY()
{
    updateParam("sizeY",sizeYAmount,16,32767,ui->sizeYInput);
}
//up
void MainWindow::on_sizeYUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("sizeY",1,16,32767,ui->sizeYInput);
}

void MainWindow::on_sizeYUpButton_pressed()
{
    onButtonUpPressed(&sizeYAmount);
}

void MainWindow::on_sizeYUpButton_released()
{
    // first release event then clicked event
    onButtonUpReleased(&sizeYAmount);
}

//down
void MainWindow::on_sizeYDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("sizeY",-1,16,32767,ui->sizeYInput);
}

void MainWindow::on_sizeYDownButton_pressed()
{
    onButtonDownPressed(&sizeYAmount);
}

void MainWindow::on_sizeYDownButton_released()
{
    onButtonDownReleased(&sizeYAmount);
}

//input
void MainWindow::on_sizeYInput_editingFinished()
{
    QString sizeXQString = parameters.value("sizeX");
    QString sizeYQString = parameters.value("sizeY");
    QString tempSizeY = ui->sizeYInput->text();
    if (tempSizeY.size()==0 || tempSizeY =="0"){
        ui->sizeXInput->setText(sizeXQString);
        ui->sizeYInput->setText(sizeYQString);
        return;
    }

    if(sizeYQString == tempSizeY){
        return;
    }

    bool ok;
    int sizeY = 0;
    sizeY = tempSizeY.toInt(&ok,10);

    // qDebug()<<sizeY;

    if(ok && (sizeY>=16 && sizeY <= 32767)){
        tempSizeY = QString::number(sizeY); //remove begin 0
        parameters["sizeX"] = tempSizeY;
        ui->sizeXInput->setText(tempSizeY);

        parameters["sizeY"] = tempSizeY;
        ui->sizeYInput->setText(tempSizeY);

        parameterModified = true;
    }else if(sizeY>32767){
        parameters["sizeX"] = "32767";
        ui->sizeXInput->setText("32767");

        parameters["sizeY"] = "32767";
        ui->sizeYInput->setText("32767");

        parameterModified = true;
    }else if(sizeY<16){
        parameters["sizeX"] = "16";
        ui->sizeXInput->setText("16");

        parameters["sizeY"] = "16";
        ui->sizeYInput->setText("16");

        parameterModified = true;
    }else{
        ui->sizeXInput->setText(sizeXQString); //last time valid
        qDebug()<<"sizeX: Invalide";

        ui->sizeYInput->setText(sizeYQString); //last time valid
        qDebug()<<"sizeY: Invalide";
    }
}

void MainWindow::on_sizeYInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;
    int number = text.toInt(&isNumber,10);
    if(text == "" || text.size()==0){
        ui->sizeXInput->setText(ui->sizeYInput->text());
        return;
    }
    if (text.startsWith("-") || !isNumber){
        ui->sizeYInput->setText(ui->sizeXInput->text());
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->sizeXInput->setText("0");
            ui->sizeYInput->setText("0");
        }
        ui->sizeXInput->setText("0");
        ui->sizeYInput->setText("0");
        if(number>32767){
            parameters["sizeX"] = "32767";
            ui->sizeXInput->setText("32767");
            parameters["sizeY"] = "32767";
            ui->sizeYInput->setText("32767");
        }
        return;
    }
    ui->sizeXInput->setText(ui->sizeYInput->text());


    if(isNumber){
        if(number==text.toUShort()){
            //no overflow
            if(number>32767){
                parameters["sizeX"] = "32767";
                ui->sizeXInput->setText("32767");

                // parameters["sizeY"] = "32767";
                // ui->sizeYInput->setText("32767");
            }else{
                parameters["sizeX"] = tempChangeText;
                ui->sizeXInput->setText(tempChangeText);
            }
        }else{
            //with overflow
            //return to default
            if(number>32767){
                parameters["sizeX"] = "32767";
                ui->sizeXInput->setText("32767");

                parameters["sizeY"] = "32767";
                ui->sizeYInput->setText("32767");
            }else{
                parameters["sizeX"] = tempChangeText;
                ui->sizeXInput->setText(tempChangeText);
            }
        }
    }
}

//population
void MainWindow::updatePopulation()
{
    this->updateParam("population",populationAmount,1,32766,ui->populationInput);
}
//down
void MainWindow::on_populationDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("population",-1,1,32766,ui->populationInput);
}

void MainWindow::on_populationDownButton_pressed()
{
    onButtonDownPressed(&populationAmount);
}

void MainWindow::on_populationDownButton_released()
{
    onButtonDownReleased(&populationAmount);
}

//up
void MainWindow::on_populationUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("population",1,1,32766,ui->populationInput);
}

void MainWindow::on_populationUpButton_pressed()
{
    onButtonUpPressed(&populationAmount);
}

void MainWindow::on_populationUpButton_released()
{
    onButtonUpReleased(&populationAmount);
}

//input
void MainWindow::on_populationInput_editingFinished(){
    // qDebug()<<"population: "<<ui->populationInput->text();
    QString paramQString = parameters.value("population");
    QString tempParamQString = ui->populationInput->text();

    if(paramQString == tempParamQString){
        return;
    }

    bool ok;
    ushort paramValue = 0;
    paramValue = tempParamQString.toUShort(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=1 && paramValue <= 32766)){
        parameters["population"] = tempParamQString;
        ui->populationInput->setText(tempParamQString);

        parameterModified = true;
    }else{
        ui->populationInput->setText(paramQString); //last time valid
        qDebug()<<"population: Invalide";
    }
}

void MainWindow::on_populationInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        ui->populationInput->setText(text);
        return;
    }

    int number = text.toInt(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        if(text == ""){
            return;
        }
        ui->populationInput->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->populationInput->setText("0");
        }
        if(number>32766){
            parameters["numThreads"] = "32766";
            ui->populationInput->setText("32766");
        }
        return;
    }

    if(isNumber){
        if(number==text.toUShort()){
            //no overflow
            if(number>32766){
                parameters["population"] = "32766";
                ui->populationInput->setText("32766");
            }else if(number==0){
                parameters["population"] = "1";
                ui->populationInput->setText("1");
            }else{
                parameters["population"] = text;
                ui->populationInput->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            if(number>32767){
                parameters["population"] = "32766";
                ui->populationInput->setText("32766");
            }else{
                parameters["population"] = tempChangeText;
                ui->populationInput->setText(tempChangeText);
            }

            parameterModified = true;
        }
    }
}

//stepsPerGeneration
void MainWindow::updateStepsPerGeneration()
{
    updateParam("stepsPerGeneration", stepsPerGenerationAmount, 1, INT_MAX, ui->stepsPerGenerationInput);
}

//down
void MainWindow::on_stepsPerGenerationDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("stepsPerGeneration",-1,1,INT_MAX,ui->stepsPerGenerationInput);
}

void MainWindow::on_stepsPerGenerationDownButton_pressed()
{
    onButtonDownPressed(&stepsPerGenerationAmount);
}

void MainWindow::on_stepsPerGenerationDownButton_released()
{
    onButtonDownReleased(&stepsPerGenerationAmount);
}

//up
void MainWindow::on_stepsPerGenerationUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("stepsPerGeneration",1,1,INT_MAX,ui->stepsPerGenerationInput);
}

void MainWindow::on_stepsPerGenerationUpButton_pressed()
{
    onButtonUpPressed(&stepsPerGenerationAmount);
}

void MainWindow::on_stepsPerGenerationUpButton_released()
{
    onButtonUpReleased(&stepsPerGenerationAmount);
}

//input
void MainWindow::on_stepsPerGenerationInput_editingFinished(){
    // qDebug()<<"stepsPerGeneration: "<<ui->stepsPerGenerationInput->text();
    QString paramQString = parameters.value("stepsPerGeneration");
    QString tempParamQString = ui->stepsPerGenerationInput->text();

    if(paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=1 && paramValue <= INT_MAX)){
        parameters["stepsPerGeneration"] = tempParamQString;
        ui->stepsPerGenerationInput->setText(tempParamQString);

        parameterModified = true;
    }else{
        ui->stepsPerGenerationInput->setText(paramQString); //last time valid
        qDebug()<<"stepsPerGeneration: Invalide";
    }
}

void MainWindow::on_stepsPerGenerationInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        ui->stepsPerGenerationInput->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        ui->stepsPerGenerationInput->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->stepsPerGenerationInput->setText("0");
        }
        if(number>2147483647){
            parameters["stepsPerGeneration"] = "2147483647";
            ui->stepsPerGenerationInput->setText("2147483647");
        }
        return;
    }

    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>INT_MAX){
                parameters["stepsPerGeneration"] = "2147483647";
                ui->stepsPerGenerationInput->setText("2147483647");
            }else if(number==0){
                parameters["stepsPerGeneration"] = "1";
                ui->stepsPerGenerationInput->setText("1");
            }else{
                parameters["stepsPerGeneration"] = text;
                ui->stepsPerGenerationInput->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            //qDebug()<<number;
            parameters["stepsPerGeneration"] = "2147483647";
            ui->stepsPerGenerationInput->setText("2147483647");

            parameterModified = true;
        }
    }
}

//maxGenerations
void MainWindow::updateMaxGenerations()
{
    updateParam("maxGenerations", maxGenerationsAmount, 1, INT_MAX, ui->maxGenerationsInput);
}

//Down
void MainWindow::on_maxGenerationsDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("maxGenerations",-1,1,INT_MAX,ui->maxGenerationsInput);
}

void MainWindow::on_maxGenerationsDownButton_pressed()
{
    onButtonDownPressed(&maxGenerationsAmount);
}

void MainWindow::on_maxGenerationsDownButton_released()
{
    onButtonDownReleased(&maxGenerationsAmount);
}

//Up
void MainWindow::on_maxGenerationsUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("maxGenerations",1,1,INT_MAX,ui->maxGenerationsInput);
}

void MainWindow::on_maxGenerationsUpButton_pressed()
{
    onButtonUpPressed(&maxGenerationsAmount);
}

void MainWindow::on_maxGenerationsUpButton_released()
{
    onButtonUpReleased(&maxGenerationsAmount);
}

//Input
void MainWindow::on_maxGenerationsInput_editingFinished(){
    // qDebug()<<"maxGenerations: "<<ui->maxGenerationsInput->text();
    QString paramName = "maxGenerations";
    QLineEdit * inputPtr = ui->maxGenerationsInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if(paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    // qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_maxGenerationsInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "maxGenerations";
    QLineEdit * inputPtr = ui->maxGenerationsInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();

    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }


    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            // qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}


//genomeInitialLengthMin
void MainWindow::updateGenomeInitialLengthMin()
{
    updateParam("genomeInitialLengthMin", genomeInitialLengthMinAmount, 1, INT_MAX, ui->genomeInitialLengthMinInput);
}

//Down
void MainWindow::on_genomeInitialLengthMinDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeInitialLengthMin",-1,1,INT_MAX,ui->genomeInitialLengthMinInput);
}

void MainWindow::on_genomeInitialLengthMinDownButton_pressed()
{
    onButtonDownPressed(&genomeInitialLengthMinAmount);
}

void MainWindow::on_genomeInitialLengthMinDownButton_released()
{
    onButtonDownReleased(&genomeInitialLengthMinAmount);
}

//Up
void MainWindow::on_genomeInitialLengthMinUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeInitialLengthMin",1,1,INT_MAX,ui->genomeInitialLengthMinInput);
}

void MainWindow::on_genomeInitialLengthMinUpButton_pressed()
{
    onButtonUpPressed(&genomeInitialLengthMinAmount);
}

void MainWindow::on_genomeInitialLengthMinUpButton_released()
{
    onButtonUpReleased(&genomeInitialLengthMinAmount);
}

//Input
void MainWindow::on_genomeInitialLengthMinInput_editingFinished()
{
    // qDebug()<<"genomeInitialLengthMin: "<<ui->genomeInitialLengthMinInput->text();
    QString lengthMinQString = parameters.value("genomeInitialLengthMin");
    QString lengthMaxQString = parameters.value("genomeInitialLengthMax");
    QString tempLengthMinQString = ui->genomeInitialLengthMinInput->text();
    QString tempLengthMaxQString = ui->genomeInitialLengthMaxInput->text();

    if(lengthMinQString == tempLengthMinQString){
        return;
    }

    bool ok;
    unsigned long long lengthMinValue = 0;
    unsigned long long lengthMaxValue = 0;
    lengthMinValue = tempLengthMinQString.toULongLong(&ok,10);
    lengthMaxValue = tempLengthMaxQString.toULongLong(&ok,10);
    // qDebug()<<lengthMinValue;
    // qDebug()<<lengthMaxValue;

    if(ok && (lengthMinValue>=1 && lengthMinValue <= parameters["genomeMaxLength"].toInt())){
        parameters["genomeInitialLengthMin"] = tempLengthMinQString;
        ui->genomeInitialLengthMinInput->setText(tempLengthMinQString);

        parameters["genomeInitialLengthMax"] = tempLengthMinQString;
        ui->genomeInitialLengthMaxInput->setText(tempLengthMinQString);

        parameters["genomeInitialLengthMax"] = QString::number(lengthMinValue);
        ui->genomeInitialLengthMaxInput->setText(QString::number(lengthMinValue));
        parameters["genomeInitialLengthMin"] = QString::number(lengthMinValue);
        ui->genomeInitialLengthMinInput->setText(QString::number(lengthMinValue));

        parameterModified = true;
    }else{
        ui->genomeInitialLengthMinInput->setText(lengthMinQString); //last time valid
        ui->genomeInitialLengthMaxInput->setText(lengthMaxQString);
        qDebug()<<"genomeInitialLengthMin: Invalide";
    }
}


void MainWindow::on_genomeInitialLengthMinInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        ui->genomeInitialLengthMinInput->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        ui->genomeInitialLengthMinInput->setText("");
        ui->genomeInitialLengthMaxInput->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->genomeInitialLengthMinInput->setText("0");
            ui->genomeInitialLengthMaxInput->setText("0");
        }
        // ui->genomeInitialLengthMinInput->setText("0");
        // ui->genomeInitialLengthMaxInput->setText("0");
        if(number>parameters["genomeMaxLength"].toInt()){
            parameters["genomeInitialLengthMin"] = QString::number(parameters["genomeMaxLength"].toInt());
            ui->genomeInitialLengthMinInput->setText(QString::number(parameters["genomeMaxLength"].toInt()));
            parameters["genomeInitialLengthMax"] = QString::number(parameters["genomeMaxLength"].toInt());
            ui->genomeInitialLengthMaxInput->setText(QString::number(parameters["genomeMaxLength"].toInt()));
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>parameters["genomeMaxLength"].toInt()){
                parameters["genomeInitialLengthMin"] = parameters["genomeMaxLength"];
                ui->genomeInitialLengthMinInput->setText(parameters["genomeMaxLength"]);

                parameters["genomeInitialLengthMax"] = parameters["genomeMaxLength"];
                ui->genomeInitialLengthMaxInput->setText(parameters["genomeMaxLength"]);
            }else if(number==0){
                parameters["genomeInitialLengthMin"] = "1";
                ui->genomeInitialLengthMinInput->setText("1");

                parameters["genomeInitialLengthMax"] = "1";
                ui->genomeInitialLengthMaxInput->setText("1");
            }else{
                parameters["genomeInitialLengthMin"] = text;
                ui->genomeInitialLengthMinInput->setText(text);

                parameters["genomeInitialLengthMax"] = text;
                ui->genomeInitialLengthMaxInput->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            //qDebug()<<number;
            parameters["genomeInitialLengthMin"] = parameters["genomeInitialLengthMax"];
            ui->genomeInitialLengthMinInput->setText(parameters["genomeInitialLengthMax"]);
            parameters["genomeInitialLengthMax"] = parameters["genomeInitialLengthMin"];
            ui->genomeInitialLengthMaxInput->setText(parameters["genomeInitialLengthMin"]);
        }
    }
}

//genomeInitialLengthMax
void MainWindow::updateGenomeInitialLengthMax()
{
    updateParam("genomeInitialLengthMax", genomeInitialLengthMaxAmount, 1, INT_MAX, ui->genomeInitialLengthMaxInput);
}

//Down
void MainWindow::on_genomeInitialLengthMaxDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeInitialLengthMax",-1,1, INT_MAX,ui->genomeInitialLengthMaxInput);
    //INT_MAX
    //ui->genomeMaxLengthInput->text().toInt()
}

void MainWindow::on_genomeInitialLengthMaxDownButton_pressed()
{
    onButtonDownPressed(&genomeInitialLengthMaxAmount);
}

void MainWindow::on_genomeInitialLengthMaxDownButton_released()
{
    onButtonDownReleased(&genomeInitialLengthMaxAmount);
}

//Up
void MainWindow::on_genomeInitialLengthMaxUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeInitialLengthMax",1,1,INT_MAX,ui->genomeInitialLengthMaxInput);
}

void MainWindow::on_genomeInitialLengthMaxUpButton_pressed()
{
    onButtonUpPressed(&genomeInitialLengthMaxAmount);
}

void MainWindow::on_genomeInitialLengthMaxUpButton_released()
{
    onButtonUpReleased(&genomeInitialLengthMaxAmount);
}

//Input
void MainWindow::on_genomeInitialLengthMaxInput_editingFinished()
{
    // qDebug()<<"genomeInitialLengthMax: "<<ui->genomeInitialLengthMaxInput->text();
    QString paramQString = parameters.value("genomeInitialLengthMax");
    QString tempParamQString = ui->genomeInitialLengthMaxInput->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    // qDebug()<<paramValue;

    if(ok && (paramValue>=1 && paramValue <= parameters["genomeMaxLength"].toInt())){
        if(paramValue<parameters["genomeInitialLengthMin"].toInt()){
            parameters["genomeInitialLengthMax"] = parameters["genomeInitialLengthMin"];
            ui->genomeInitialLengthMaxInput->setText(parameters["genomeInitialLengthMin"]);
        }else{

            parameters["genomeInitialLengthMax"] = QString::number(paramValue);
            ui->genomeInitialLengthMaxInput->setText(QString::number(paramValue));
            parameters["genomeInitialLengthMin"] = QString::number(paramValue);
            ui->genomeInitialLengthMinInput->setText(QString::number(paramValue));
        }

        parameterModified = true;
    }else{
        ui->genomeInitialLengthMaxInput->setText(paramQString); //last time valid
        qDebug()<<"genomeInitialLengthMin: Invalide";
    }
}


void MainWindow::on_genomeInitialLengthMaxInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        ui->genomeInitialLengthMaxInput->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        ui->genomeInitialLengthMinInput->setText("");

        ui->genomeInitialLengthMaxInput->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            ui->genomeInitialLengthMinInput->setText("0");
            ui->genomeInitialLengthMaxInput->setText("0");
        }
        // ui->genomeInitialLengthMinInput->setText("0");
        // ui->genomeInitialLengthMaxInput->setText("0");
        if(number>parameters["genomeMaxLength"].toInt()){
            parameters["genomeInitialLengthMin"] = QString::number(ui->genomeMaxLengthInput->text().toInt());
            ui->genomeInitialLengthMinInput->setText(QString::number(ui->genomeMaxLengthInput->text().toInt()));

            parameters["genomeInitialLengthMax"] = QString::number(ui->genomeMaxLengthInput->text().toInt());
            ui->genomeInitialLengthMaxInput->setText(QString::number(ui->genomeMaxLengthInput->text().toInt()));
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>parameters["genomeMaxLength"].toInt()){
                parameters["genomeInitialLengthMin"] = ui->genomeMaxLengthInput->text();
                ui->genomeInitialLengthMinInput->setText(ui->genomeMaxLengthInput->text());

                parameters["genomeInitialLengthMax"] = ui->genomeMaxLengthInput->text();
                ui->genomeInitialLengthMaxInput->setText(ui->genomeMaxLengthInput->text());
            }else if(number==0){
                parameters["genomeInitialLengthMin"] = "1";
                ui->genomeInitialLengthMinInput->setText("1");

                parameters["genomeInitialLengthMax"] = "1";
                ui->genomeInitialLengthMaxInput->setText("1");
            }else{
                parameters["genomeInitialLengthMin"] = text;
                ui->genomeInitialLengthMinInput->setText(text);

                parameters["genomeInitialLengthMax"] = text;
                ui->genomeInitialLengthMaxInput->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters["genomeInitialLengthMin"] = parameters["genomeMaxLength"];
            ui->genomeInitialLengthMinInput->setText(parameters["genomeMaxLength"]);

            parameters["genomeInitialLengthMax"] = parameters["genomeMaxLength"];
            ui->genomeInitialLengthMaxInput->setText(parameters["genomeMaxLength"]);
        }
    }
}

//genomeMaxLength
void MainWindow::updateGenomeMaxLength()
{
    updateParam("genomeMaxLength", genomeMaxLengthAmount, 1, INT_MAX, ui->genomeMaxLengthInput);
}

void MainWindow::genomeMaxLengthCheckCap(){
    //cap
    if (parameters["genomeMaxLength"].toInt()<parameters["genomeInitialLengthMax"].toInt()){
        parameters["genomeInitialLengthMin"] = parameters["genomeMaxLength"];
        ui->genomeInitialLengthMinInput->setText(parameters["genomeMaxLength"]);

        parameters["genomeInitialLengthMax"] = parameters["genomeMaxLength"];
        ui->genomeInitialLengthMaxInput->setText(parameters["genomeMaxLength"]);
    }
}

//Down
void MainWindow::on_genomeMaxLengthDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeMaxLength",-1,1,INT_MAX,ui->genomeMaxLengthInput);
}

void MainWindow::on_genomeMaxLengthDownButton_pressed()
{
    onButtonDownPressed(&genomeMaxLengthAmount);
}

void MainWindow::on_genomeMaxLengthDownButton_released()
{
    onButtonDownReleased(&genomeMaxLengthAmount);
}

//Up
void MainWindow::on_genomeMaxLengthUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("genomeMaxLength",1,1,INT_MAX,ui->genomeMaxLengthInput);
}

void MainWindow::on_genomeMaxLengthUpButton_pressed()
{
    onButtonUpPressed(&genomeMaxLengthAmount);
}

void MainWindow::on_genomeMaxLengthUpButton_released()
{
    onButtonUpReleased(&genomeMaxLengthAmount);
}

//Input
void MainWindow::on_genomeMaxLengthInput_editingFinished(){
    QString paramName = "genomeMaxLength";
    QLineEdit * inputPtr = ui->genomeMaxLengthInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);
        if (paramValue<parameters["genomeInitialLengthMax"].toInt()){
            parameters["genomeInitialLengthMin"] = tempParamQString;
            ui->genomeInitialLengthMinInput->setText(tempParamQString);

            parameters["genomeInitialLengthMax"] = tempParamQString;
            ui->genomeInitialLengthMaxInput->setText(tempParamQString);
        }

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<paramName<<": Invalide";
    }


}

void MainWindow::on_genomeMaxLengthInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "genomeMaxLength";
    QLineEdit * inputPtr = ui->genomeMaxLengthInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }
            genomeMaxLengthCheckCap();

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//maxNumberNeurons
void MainWindow::updateMaxNumberNeurons()
{
    updateParam("maxNumberNeurons", maxNumberNeuronsAmount, 1, INT_MAX, ui->maxNumberNeuronsInput);
}

//Up
void MainWindow::on_maxNumberNeuronsUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("maxNumberNeurons",1,1,INT_MAX,ui->maxNumberNeuronsInput);
}

void MainWindow::on_maxNumberNeuronsUpButton_pressed()
{
    onButtonUpPressed(&maxNumberNeuronsAmount);
}


void MainWindow::on_maxNumberNeuronsUpButton_released()
{
    onButtonUpReleased(&maxNumberNeuronsAmount);
}

//Down
void MainWindow::on_maxNumberNeuronsDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("maxNumberNeurons",-1,1,INT_MAX,ui->maxNumberNeuronsInput);
}

void MainWindow::on_maxNumberNeuronsDownButton_pressed()
{
    onButtonDownPressed(&maxNumberNeuronsAmount);
}


void MainWindow::on_maxNumberNeuronsDownButton_released()
{
    onButtonDownReleased(&maxNumberNeuronsAmount);
}

//Input
void MainWindow::on_maxNumberNeuronsInput_editingFinished(){
    // qDebug()<<"maxNumberNeurons: "<<ui->maxNumberNeuronsInput->text();
    QString paramName = "maxNumberNeurons";
    QLineEdit * inputPtr = ui->maxNumberNeuronsInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_maxNumberNeuronsInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "maxNumberNeurons";
    QLineEdit * inputPtr = ui->maxNumberNeuronsInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//killable
void MainWindow::on_killEnableCheckBox_stateChanged(int state)
{
    parameters["killEnable"] = (state == Qt::Checked) ? "true" : "false";
}

//sexualReproduction
void MainWindow::on_sexualReproductionCheckBox_stateChanged(int state)
{
    parameters["sexualReproduction"] = (state == Qt::Checked) ? "true" : "false";
}

//chooseParentsByFitness
void MainWindow::on_chooseParentsByFitnessCheckBox_stateChanged(int state)
{
    parameters["chooseParentsByFitness"] = (state == Qt::Checked) ? "true" : "false";
}

//pointMutationRate
void MainWindow::on_pointMutationRateUpButton_clicked()
{
    return;
}


void MainWindow::on_pointMutationRateUpButton_pressed()
{
    return;
}


void MainWindow::on_pointMutationRateUpButton_released()
{
    return;
}


void MainWindow::on_pointMutationRateDownButton_clicked()
{
    return;
}


void MainWindow::on_pointMutationRateDownButton_pressed()
{
    return;
}


void MainWindow::on_pointMutationRateDownButton_released()
{
    return;
}


void MainWindow::on_pointMutationRateInput_editingFinished()
{
    bool ok;
    double value = ui->pointMutationRateInput->text().toDouble(&ok);
    if (ok && value >= 0.0 && value <= 1.0) {
        parameters["pointMutationRate"] = QString::number(value);
        ui->pointMutationRateInput->setText(QString::number(value));

        parameterModified = true;
    } else {
        ui->pointMutationRateInput->setText(parameters["pointMutationRate"]);
    }
}


void MainWindow::on_pointMutationRateInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    double value;
    if (!(text.startsWith(".") || text.startsWith("0") || text.startsWith("1"))){
        ui->pointMutationRateInput->setText("");
        return;
    }
    bool isNumber;
    tempChangeText.right(1).toShort(&isNumber);
    if(!isNumber && tempChangeText.right(1)!=QString('.')){
        text.chop(1);
        ui->pointMutationRateInput->setText(text);
        return;
    }

    value=text.toDouble(&isNumber);
    if(std::find(tempChangeText.begin(), tempChangeText.end(), QString('.')) != tempChangeText.end()){
        //"." present
        //check if presented two times
        if(std::count(tempChangeText.begin(), tempChangeText.end(), QString('.')) >= 2){
            text.chop(1);
            ui->pointMutationRateInput->setText(text);
        }
        return;
    }
    if(value>1){
        parameters["pointMutationRate"] = QString::number(1.0);
        ui->pointMutationRateInput->setText(QString::number(1.0));
    }
}

//responsivenessCurveKFactor
void MainWindow::updateResponsivenessCurveKFactor(){
    updateParam("responsivenessCurveKFactor", responsivenessCurveKFactorAmount, 1, INT_MAX, ui->responsivenessCurveKFactorInput);
}

//Up
void MainWindow::on_responsivenessCurveKFactorUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("responsivenessCurveKFactor",1,1,INT_MAX,ui->responsivenessCurveKFactorInput);
}

void MainWindow::on_responsivenessCurveKFactorUpButton_pressed()
{
    onButtonUpPressed(&responsivenessCurveKFactorAmount);
}


void MainWindow::on_responsivenessCurveKFactorUpButton_released()
{
    onButtonUpReleased(&responsivenessCurveKFactorAmount);
}

//Down
void MainWindow::on_responsivenessCurveKFactorDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("responsivenessCurveKFactor",-1,1,INT_MAX,ui->responsivenessCurveKFactorInput);
}

void MainWindow::on_responsivenessCurveKFactorDownButton_pressed()
{
    onButtonDownPressed(&responsivenessCurveKFactorAmount);
}


void MainWindow::on_responsivenessCurveKFactorDownButton_released()
{
    onButtonDownReleased(&responsivenessCurveKFactorAmount);
}

//Input
void MainWindow::on_responsivenessCurveKFactorInput_editingFinished(){
    // qDebug()<<"responsivenessCurveKFactorNeurons: "<<ui->responsivenessCurveKFactorInput->text();
    QString paramName = "responsivenessCurveKFactor";
    QLineEdit * inputPtr = ui->responsivenessCurveKFactorInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"responsivenessCurveKFactor: Invalide";
    }
}

void MainWindow::on_responsivenessCurveKFactorInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "responsivenessCurveKFactor";
    QLineEdit * inputPtr = ui->responsivenessCurveKFactorInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//populationSensorRadius
void MainWindow::on_populationSensorRadiusInput_editingFinished()
{
    bool ok;
    if(ui->populationSensorRadiusInput->text() == ""){
        ui->populationSensorRadiusInput->setText(parameters["populationSensorRadius"]);
        return;
    }
    double value = ui->populationSensorRadiusInput->text().toDouble(&ok);
    double sizeX = parameters["sizeX"].toDouble(&ok);

    if (ok){
        if (value >= 0.5 && value <= sizeX) {
            parameters["populationSensorRadius"] = QString::number(value);
            ui->populationSensorRadiusInput->setText(QString::number(value));
        } else if (value>sizeX){
            parameters["populationSensorRadius"] = QString::number(sizeX);
            ui->populationSensorRadiusInput->setText(QString::number(sizeX));
        } else{
            //less then 0.5
            parameters["populationSensorRadius"] = QString::number(0.5);
            ui->populationSensorRadiusInput->setText(QString::number(0.5));
        }

        parameterModified = true;
    }else{
        ui->populationSensorRadiusInput->setText(parameters["populationSensorRadius"]);
    }
}


void MainWindow::on_populationSensorRadiusInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    double sizeX = parameters["sizeX"].toDouble();
    bool startWithNumber;
    text.left(1).toShort(&startWithNumber);
    if (!(text.startsWith(".") || startWithNumber)){
        ui->populationSensorRadiusInput->setText("");
        return;
    }
    bool isNumber;
    tempChangeText.right(1).toShort(&isNumber);
    if(!isNumber && tempChangeText.right(1)!=QString('.')){
        text.chop(1);
        ui->populationSensorRadiusInput->setText(text);
        return;
    }

    double number = text.toDouble(&isNumber);
    if(std::find(tempChangeText.begin(), tempChangeText.end(), QString('.')) != tempChangeText.end()){
        //"." present
        //check if presented two times
        if(std::count(tempChangeText.begin(), tempChangeText.end(), QString('.')) >= 2){
            text.chop(1);
            ui->populationSensorRadiusInput->setText(text);
        }
        if (text.toDouble()>=128){
            text.chop(1);
            ui->populationSensorRadiusInput->setText(text);
        }
        return;
    }
    QLineEdit * inputPtr = ui->populationSensorRadiusInput;
    QString paramName = "populationSensorRadius";
    QString maxString = parameters["sizeX"];
    if(isNumber){
        //no overflow
        if(number>sizeX){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);

            parameterModified = true;
        }else{
            parameters[paramName] = text;
            inputPtr->setText(text);
        }
    }
}

//longProbeDistance
void MainWindow::updateLongProbeDistance()
{
    updateParam("longProbeDistance", longProbeDistanceAmount, 1, INT_MAX, ui->longProbeDistanceInput);
}

//Up
void MainWindow::on_longProbeDistanceUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("longProbeDistance",1,1,INT_MAX,ui->longProbeDistanceInput);
}

void MainWindow::on_longProbeDistanceUpButton_pressed()
{
    onButtonUpPressed(&longProbeDistanceAmount);
}


void MainWindow::on_longProbeDistanceUpButton_released()
{
    onButtonUpReleased(&longProbeDistanceAmount);
}

//Down
void MainWindow::on_longProbeDistanceDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("longProbeDistance",-1,1,INT_MAX,ui->longProbeDistanceInput);
}

void MainWindow::on_longProbeDistanceDownButton_pressed()
{
    onButtonDownPressed(&longProbeDistanceAmount);
}


void MainWindow::on_longProbeDistanceDownButton_released()
{
    onButtonDownReleased(&longProbeDistanceAmount);
}

//Input
void MainWindow::on_longProbeDistanceInput_editingFinished(){
    // qDebug()<<"longProbeDistance: "<<ui->longProbeDistanceInput->text();
    QString paramName = "longProbeDistance";
    QLineEdit * inputPtr = ui->longProbeDistanceInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    // qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_longProbeDistanceInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "longProbeDistance";
    QLineEdit * inputPtr = ui->longProbeDistanceInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//shortProbeBarrierDistance
void MainWindow::updateShortProbeBarrierDistance()
{
    updateParam("shortProbeBarrierDistance", shortProbeBarrierDistanceAmount, 1, INT_MAX, ui->shortProbeBarrierDistanceInput);
}

//Up
void MainWindow::on_shortProbeBarrierDistanceUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("shortProbeBarrierDistance",1,1,INT_MAX,ui->shortProbeBarrierDistanceInput);
}

void MainWindow::on_shortProbeBarrierDistanceUpButton_pressed()
{
    onButtonUpPressed(&shortProbeBarrierDistanceAmount);
}


void MainWindow::on_shortProbeBarrierDistanceUpButton_released()
{
    onButtonUpReleased(&shortProbeBarrierDistanceAmount);
}

//Down
void MainWindow::on_shortProbeBarrierDistanceDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("shortProbeBarrierDistance",-1,1,INT_MAX,ui->shortProbeBarrierDistanceInput);
}

void MainWindow::on_shortProbeBarrierDistanceDownButton_pressed()
{
    onButtonDownPressed(&shortProbeBarrierDistanceAmount);
}


void MainWindow::on_shortProbeBarrierDistanceDownButton_released()
{
    onButtonDownReleased(&shortProbeBarrierDistanceAmount);
}

//Input
void MainWindow::on_shortProbeBarrierDistanceInput_editingFinished(){
    // qDebug()<<"shortProbeBarrierDistance: "<<ui->shortProbeBarrierDistanceInput->text();
    QString paramName = "shortProbeBarrierDistance";
    QLineEdit * inputPtr = ui->shortProbeBarrierDistanceInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_shortProbeBarrierDistanceInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "shortProbeBarrierDistance";
    QLineEdit * inputPtr = ui->shortProbeBarrierDistanceInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//signalSensorRadius
//Up
void MainWindow::on_signalSensorRadiusUpButton_clicked()
{
    return;
}

void MainWindow::on_signalSensorRadiusUpButton_pressed()
{
    return;
}


void MainWindow::on_signalSensorRadiusUpButton_released()
{
    return;
}

//Down
void MainWindow::on_signalSensorRadiusDownButton_clicked()
{
    return;
}

void MainWindow::on_signalSensorRadiusDownButton_pressed()
{
    return;
}


void MainWindow::on_signalSensorRadiusDownButton_released()
{
    return;
}

//Input
void MainWindow::on_signalSensorRadiusInput_editingFinished()
{
    bool ok;
    if(ui->signalSensorRadiusInput->text() == ""){
        ui->signalSensorRadiusInput->setText(parameters["signalSensorRadius"]);
        return;
    }
    double value = ui->signalSensorRadiusInput->text().toDouble(&ok);
    double sizeX = parameters["sizeX"].toDouble(&ok);

    if (ok){
        if (value >= 0.5 && value <= sizeX) {
            parameters["signalSensorRadius"] = QString::number(value);
            ui->signalSensorRadiusInput->setText(QString::number(value));
        } else if (value>sizeX){
            parameters["signalSensorRadius"] = QString::number(sizeX);
            ui->signalSensorRadiusInput->setText(QString::number(sizeX));
        } else{
            //less then 0.5
            parameters["signalSensorRadius"] = QString::number(0.5);
            ui->signalSensorRadiusInput->setText(QString::number(0.5));
        }

        parameterModified = true;
    }else{

    }
}


void MainWindow::on_signalSensorRadiusInput_textChanged(const QString &tempChangeText)
{
    QString text = tempChangeText.toLower();
    double sizeX = parameters["sizeX"].toDouble();
    bool startWithNumber;
    text.left(1).toShort(&startWithNumber);
    if (!(text.startsWith(".") || startWithNumber)){
        ui->signalSensorRadiusInput->setText("");
        return;
    }
    bool isNumber;
    tempChangeText.right(1).toShort(&isNumber);
    if(!isNumber && tempChangeText.right(1)!=QString('.')){
        text.chop(1);
        ui->signalSensorRadiusInput->setText(text);
        return;
    }

    double number = text.toDouble(&isNumber);
    if(std::find(tempChangeText.begin(), tempChangeText.end(), QString('.')) != tempChangeText.end()){
        //"." present
        //check if presented two times
        if(std::count(tempChangeText.begin(), tempChangeText.end(), QString('.')) >= 2){
            text.chop(1);
            ui->signalSensorRadiusInput->setText(text);
        }
        if (text.toDouble()>=128){
            text.chop(1);
            ui->signalSensorRadiusInput->setText(text);
        }
        return;
    }
    QLineEdit * inputPtr = ui->signalSensorRadiusInput;
    QString paramName = "signalSensorRadius";
    QString maxString = parameters["sizeX"];
    if(isNumber){
        //no overflow
        if(number>sizeX){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);

            parameterModified = true;
        }else{
            parameters[paramName] = text;
            inputPtr->setText(text);
        }
    }
}

//signalLayers

//imageDir
void MainWindow::on_imageDirButton_clicked()
{
    QString dirName=QFileDialog::getExistingDirectory(this, tr("Select Image Directory"),
                                                        "./",
                                                        QFileDialog::ShowDirsOnly
                                                            | QFileDialog::DontResolveSymlinks);

    if(dirName!=""){
        ui->imageDirInput->setText(dirName);
        parameters["imageDir"]=dirName;

        parameterModified = true;
    }
}

//logDir
void MainWindow::on_logDirButton_clicked()
{
    QString dirName=QFileDialog::getExistingDirectory(this, tr("Select Log Directory"),
                                                        "./",
                                                        QFileDialog::ShowDirsOnly
                                                            | QFileDialog::DontResolveSymlinks);

    if(dirName!=""){
        ui->logDirInput->setText(dirName);
        parameters["logDir"]=dirName;

        parameterModified = true;
    }
}

//displayScale
void MainWindow::updateDisplayScale()
{
    updateParam("displayScale", displayScaleAmount, 1, UINT_MAX, ui->displayScaleInput);
}

//Up
void MainWindow::on_displayScaleUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("displayScale",1,1,INT_MAX,ui->displayScaleInput);
}


void MainWindow::on_displayScaleUpButton_pressed()
{
    onButtonUpPressed(&displayScaleAmount);
}


void MainWindow::on_displayScaleUpButton_released()
{
    onButtonUpReleased(&displayScaleAmount);
}

//Down
void MainWindow::on_displayScaleDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("displayScale",-1,1,INT_MAX,ui->displayScaleInput);
}

void MainWindow::on_displayScaleDownButton_pressed()
{
    onButtonDownPressed(&displayScaleAmount);
}


void MainWindow::on_displayScaleDownButton_released()
{
    onButtonDownReleased(&displayScaleAmount);
}

//Input
void MainWindow::on_displayScaleInput_editingFinished(){
    // qDebug()<<"displayScale: "<<ui->displayScaleInput->text();
    QString paramName = "displayScale";
    QLineEdit * inputPtr = ui->displayScaleInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_displayScaleInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "displayScale";
    QLineEdit * inputPtr = ui->displayScaleInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//agentSize
void MainWindow::updateAgentSize()
{
    updateParam("agentSize", agentSizeAmount, 1, UINT_MAX, ui->agentSizeInput);
}

//Up
void MainWindow::on_agentSizeUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("agentSize",1,1,INT_MAX,ui->agentSizeInput);
}


void MainWindow::on_agentSizeUpButton_pressed()
{
    onButtonUpPressed(&agentSizeAmount);
}


void MainWindow::on_agentSizeUpButton_released()
{
    onButtonUpReleased(&agentSizeAmount);
}

//Down
void MainWindow::on_agentSizeDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("agentSize",-1,1,INT_MAX,ui->agentSizeInput);
}

void MainWindow::on_agentSizeDownButton_pressed()
{
    onButtonDownPressed(&agentSizeAmount);
}


void MainWindow::on_agentSizeDownButton_released()
{
    onButtonDownReleased(&agentSizeAmount);
}

//Input
void MainWindow::on_agentSizeInput_editingFinished(){
    // qDebug()<<"agentSize: "<<ui->agentSizeInput->text();
    QString paramName = "agentSize";
    QLineEdit * inputPtr = ui->agentSizeInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_agentSizeInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "agentSize";
    QLineEdit * inputPtr = ui->agentSizeInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//videoSaveFirstFrames
void MainWindow::updateVideoSaveFirstFrames()
{
    updateParam("videoSaveFirstFrames", videoSaveFirstFramesAmount, 1, INT_MAX, ui->videoSaveFirstFramesInput);
}

//Up
void MainWindow::on_videoSaveFirstFramesUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("videoSaveFirstFrames",1,1,INT_MAX,ui->videoSaveFirstFramesInput);
}


void MainWindow::on_videoSaveFirstFramesUpButton_pressed()
{
    onButtonUpPressed(&videoSaveFirstFramesAmount);
}


void MainWindow::on_videoSaveFirstFramesUpButton_released()
{
    onButtonUpReleased(&videoSaveFirstFramesAmount);
}

//Down
void MainWindow::on_videoSaveFirstFramesDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("videoSaveFirstFrames",-1,1,INT_MAX,ui->videoSaveFirstFramesInput);
}

void MainWindow::on_videoSaveFirstFramesDownButton_pressed()
{
    onButtonDownPressed(&videoSaveFirstFramesAmount);
}


void MainWindow::on_videoSaveFirstFramesDownButton_released()
{
    onButtonDownReleased(&videoSaveFirstFramesAmount);
}

//Input
void MainWindow::on_videoSaveFirstFramesInput_editingFinished(){
    // qDebug()<<"videoSaveFirstFrames: "<<ui->videoSaveFirstFramesInput->text();
    QString paramName = "videoSaveFirstFrames";
    QLineEdit * inputPtr = ui->videoSaveFirstFramesInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_videoSaveFirstFramesInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "videoSaveFirstFrames";
    QLineEdit * inputPtr = ui->videoSaveFirstFramesInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//updateGraphLog
void MainWindow::on_updateGraphLogCheckBox_stateChanged(int state)
{
    parameters["updateGraphLog"] = (state == Qt::Checked) ? "true" : "false";
}

//saveVideo
void MainWindow::on_saveVideoCheckBox_stateChanged(int state)
{
    parameters["saveVideo"] = (state == Qt::Checked) ? "true" : "false";
}

//videoStride
void MainWindow::updateVideoStride()
{
    updateParam("videoStride", videoStrideAmount, 1, INT_MAX, ui->videoStrideInput);
}

//Up
void MainWindow::on_videoStrideUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("videoStride",1,1,INT_MAX,ui->videoStrideInput);
}


void MainWindow::on_videoStrideUpButton_pressed()
{
    onButtonUpPressed(&videoStrideAmount);
}


void MainWindow::on_videoStrideUpButton_released()
{
    onButtonUpReleased(&videoStrideAmount);
}

//Down
void MainWindow::on_videoStrideDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("videoStride",-1,1,INT_MAX,ui->videoStrideInput);
}

void MainWindow::on_videoStrideDownButton_pressed()
{
    onButtonDownPressed(&videoStrideAmount);
}


void MainWindow::on_videoStrideDownButton_released()
{
    onButtonDownReleased(&videoStrideAmount);
}

//Input
void MainWindow::on_videoStrideInput_editingFinished(){
    // qDebug()<<"videoStride: "<<ui->videoStrideInput->text();
    QString paramName = "videoStride";
    QLineEdit * inputPtr = ui->videoStrideInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified =true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_videoStrideInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "videoStride";
    QLineEdit * inputPtr = ui->videoStrideInput;
    int min = 1;
    int max = INT_MAX; //INT_MAX==2147483647
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}


//genomeComparisonMethod
void MainWindow::on_genomeComparisonMethodComboBox_currentIndexChanged(int index)
{
    //qDebug()<<index;
    parameters["genomeComparisonMethod"] = QString::number(index);
}

//displaySampleGenomes
void MainWindow::updateDisplaySampleGenomes()
{
    updateParam("displaySampleGenomes", displaySampleGenomesAmount, 1, INT_MAX, ui->displaySampleGenomesInput);
}

//Up
void MainWindow::on_displaySampleGenomesUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("displaySampleGenomes",1,1,INT_MAX,ui->displaySampleGenomesInput);
}

void MainWindow::on_displaySampleGenomesUpButton_pressed()
{
    onButtonUpPressed(&displaySampleGenomesAmount);
}


void MainWindow::on_displaySampleGenomesUpButton_released()
{
    onButtonUpReleased(&displaySampleGenomesAmount);
}

//Down
void MainWindow::on_displaySampleGenomesDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("displaySampleGenomes",-1,1,INT_MAX,ui->displaySampleGenomesInput);
}

void MainWindow::on_displaySampleGenomesDownButton_pressed()
{
    onButtonDownPressed(&displaySampleGenomesAmount);
}


void MainWindow::on_displaySampleGenomesDownButton_released()
{
    onButtonDownReleased(&displaySampleGenomesAmount);
}

//Input
void MainWindow::on_displaySampleGenomesInput_editingFinished(){
    // qDebug()<<"displaySampleGenomes: "<<ui->displaySampleGenomesInput->text();
    QString paramName = "displaySampleGenomes";
    QLineEdit * inputPtr = ui->displaySampleGenomesInput;
    int min = 1;
    int max = parameters["population"].toInt();
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified = true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_displaySampleGenomesInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "displaySampleGenomes";
    QLineEdit * inputPtr = ui->displaySampleGenomesInput;
    int min = 1;
    int max = parameters["population"].toInt();
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}

//challenge
void MainWindow::on_challengeComboBox_currentIndexChanged(int index)
{
    //qDebug()<<index;
    parameters["challenge"] = QString::number(index);

    parameterModified = true;
}

//barrierType
void MainWindow::on_barrierTypeComboBox_currentIndexChanged(int index)
{
    //qDebug()<<index;
    parameters["barrierType"] = QString::number(index);

    parameterModified = true;
}

//deterministic
void MainWindow::on_deterministicCheckBox_stateChanged(int state)
{
    parameters["deterministic"] = (state == Qt::Checked) ? "true" : "false";

    parameterModified = true;
}

//RNGSeed
void MainWindow::updateRNGSeed()
{
    updateParam("RNGSeed", RNGSeedAmount, 0, 4294967295, ui->RNGSeedInput);
}

//Up
void MainWindow::on_RNGSeedUpButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("RNGSeed",1,0,UINT_MAX,ui->RNGSeedInput);
}

void MainWindow::on_RNGSeedUpButton_pressed()
{
    onButtonUpPressed(&RNGSeedAmount);
}


void MainWindow::on_RNGSeedUpButton_released()
{
    onButtonUpReleased(&RNGSeedAmount);
}

//Down
void MainWindow::on_RNGSeedDownButton_clicked()
{
    if(hasTimerActived){
        hasTimerActived = false;
        return;
    }
    onButtonClicked("RNGSeed",-1,0,UINT_MAX,ui->RNGSeedInput);
}

void MainWindow::on_RNGSeedDownButton_pressed()
{
    onButtonDownPressed(&RNGSeedAmount);
}


void MainWindow::on_RNGSeedDownButton_released()
{
    onButtonDownReleased(&RNGSeedAmount);
}

//Input
void MainWindow::on_RNGSeedInput_editingFinished(){
    // qDebug()<<"RNGSeed: "<<ui->RNGSeedInput->text();
    QString paramName = "RNGSeed";
    QLineEdit * inputPtr = ui->RNGSeedInput;
    unsigned int min = 0;
    unsigned int max = UINT_MAX;
    // QString minString = QString::number(min);
    // QString maxString = QString::number(max);

    QString paramQString = parameters.value(paramName);
    QString tempParamQString = inputPtr->text();

    if (paramQString == tempParamQString){
        return;
    }

    bool ok;
    unsigned long long paramValue = 0;
    paramValue = tempParamQString.toULongLong(&ok,10);

    //qDebug()<<paramValue;

    if(ok && (paramValue>=min && paramValue <= max)){
        parameters[paramName] = tempParamQString;
        inputPtr->setText(tempParamQString);

        parameterModified =true;
    }else{
        inputPtr->setText(paramQString); //last time valid
        qDebug()<<"maxGenerations: Invalide";
    }
}

void MainWindow::on_RNGSeedInput_textChanged(const QString &tempChangeText)
{
    QString paramName = "RNGSeed";
    QLineEdit * inputPtr = ui->RNGSeedInput;
    unsigned int min = 0;
    unsigned int max = UINT_MAX;
    QString minString = QString::number(min);
    QString maxString = QString::number(max);

    QString text = tempChangeText.toLower();
    bool isNumber;

    text.right(1).toShort(&isNumber);
    if(!isNumber){
        text.chop(1);
        inputPtr->setText(text);
        return;
    }

    unsigned long long number = text.toULongLong(&isNumber,10);
    if (text.startsWith("-") || !isNumber){
        inputPtr->setText("");
        return;
    }
    if(tempChangeText.startsWith("0")){
        if(tempChangeText.size()>1 && tempChangeText.at(1)=='0'){
            inputPtr->setText("0");
        }
        if(number>max){
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
        return;
    }
    if(isNumber){
        if(number==text.toULongLong()){
            //no overflow
            if(number>max){
                parameters[paramName] = maxString;
                inputPtr->setText(maxString);
            }else if(number==0){
                parameters[paramName] = minString;
                inputPtr->setText(minString);
            }else{
                parameters[paramName] = text;
                inputPtr->setText(text);
            }

            parameterModified = true;
        }else{
            //with overflow
            //return to default
            qDebug()<<number;
            parameters[paramName] = maxString;
            inputPtr->setText(maxString);
        }
    }
}
