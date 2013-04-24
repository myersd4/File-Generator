#include <QDebug>
#include <QIntValidator>
#include <QFile>
#include <QFileInfo>
#include "creationThread.h"

void creationThread::run(){

    QIntValidator *validator = new QIntValidator();
    validator->setBottom(0);



    //QString size = ui->sizeInput->text();
    //QString name = ui->nameInput->text();
    //QString name = "C:\\Users\\user\\Desktop\\test.txt";
    //int bytes = size.toInt();


    QString name = "C:\\Users\\user\\Desktop\\test.txt";
    int bytes = 200000;

    qDebug()<<"Name Entered: "<<name<<endl;
    //qDebug()<<"Size Entered: "<<size<<endl;
    qDebug()<<"Converted Size: "<<bytes<<endl;


    QFile file(name);
    QFileInfo fi(file);
    qDebug()<<fi.absoluteFilePath();


   // qDebug()<<endl<<endl<<"File Name: "<<fileName;
    if(file.open(QIODevice::ReadWrite)){

        QTextStream stream(&file);
        QString fileContent = NULL;
        QChar newCharacter;



        emit updateStatus("Running");
        for(int i = 0; i < bytes; i++){
            qDebug()<<"Loop "<<i;
            emit updateProgress((i*100)/bytes);
           // newCharacter = getRandChar();
            newCharacter = 'A';
            qDebug()<<newCharacter;
            fileContent.append(newCharacter);
            double progress = (i/bytes)* 10;

            //ui->fileProgress->setValue(progress);

        }
        emit updateStatus("Idle");

        //qDebug()<<"Final String: "<<fileContent;
        stream<<fileContent;

        //ui->statusLabel->setText("Idle");
    }
    else{
        qDebug()<<"Could not open file !!!";
    }

}
