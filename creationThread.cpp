#include <QDebug>
#include <QIntValidator>
#include <QFile>
#include <QFileInfo>
#include <QCoreApplication>
#include "creationThread.h"
#include "filecreator.h"

void creationThread::startCreation(){  //Start file creation.
    createFile();
}

void creationThread::stopCreation(){ //Stop creation when button is clicked.
    stopFlag = true;
}

void creationThread::createFile(){

    QIntValidator *validator = new QIntValidator();
    validator->setBottom(0);
    emit(toggleStart());



    //QString size = ui->sizeInput->text();
    //QString name = ui->nameInput->text();
    //QString name = "C:\\Users\\user\\Desktop\\test.txt";
    //int bytes = size.toInt();





    qDebug()<<"Name Entered: "<<name<<endl;
    qDebug()<<"Size Entered: "<<size<<endl;


    //name = "C:\\Users\\user\\Desktop\\test.txt";
    QFile file(name);
    QFileInfo fi(file);
    qDebug()<<fi.absoluteFilePath();




    // qDebug()<<endl<<endl<<"File Name: "<<fileName;
    if(file.open(QIODevice::ReadWrite)){

        QTextStream stream(&file);



        emit updateStatus("Running");
        for(int i = 0; i < size; i++){
            if(stopFlag){
                break;
            }


            if(size % 10 == 0){
                emit updateProgress((i*100)/size);
            }

            stream<<getRandChar();
            QCoreApplication::processEvents();

        }

        if(!stopFlag){
            emit updateProgress(100);
        }

        emit (toggleStart());
        emit (disableStop());
        emit updateStatus("Idle");
        emit(finished());

    }
    else{
        qDebug()<<"Could not open file !!!";
    }

}

void creationThread::setParameters(QString userName, int userSize){
    name = userName;
    size = userSize;
}

char creationThread::getRandChar(){
    int characterSet = 0;
    int characterNumber = rand()%26;
    int calculatedCharacter;

    if(characterSet == 0){
        calculatedCharacter = UPPERCASE + characterNumber;
    }
    else{
        calculatedCharacter = LOWERCASE + characterNumber;
    }

    return (char)(calculatedCharacter);

}
