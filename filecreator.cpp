#include "filecreator.h"
#include "ui_filecreator.h"
#include "creationThread.h"
#include <QDebug>
#include <QFile>
#include <QChar>
#include <QFileInfo>


filecreator::filecreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::filecreator)
{
    ui->setupUi(this);
}

filecreator::~filecreator()
{
    delete ui;
}

void filecreator::on_quitButton_clicked()
{
    qApp->quit();
}

void filecreator::on_startButton_clicked()
{

   creationThread t1;
   t1.start();

   t1.wait();


    /*QIntValidator *validator = new QIntValidator();
    validator->setBottom(0);
    ui->sizeInput->setValidator(validator);


    QString size = ui->sizeInput->text();
    //QString name = ui->nameInput->text();
    QString name = "C:\\Users\\user\\Desktop\\test.txt";
    int bytes = size.toInt();

    qDebug()<<"Name Entered: "<<name<<endl;
    qDebug()<<"Size Entered: "<<size<<endl;
    qDebug()<<"Converted Size: "<<bytes<<endl;


    QFile file(name);
    QFileInfo fi(file);
    qDebug()<<fi.absoluteFilePath();


   // qDebug()<<endl<<endl<<"File Name: "<<fileName;
    if(file.open(QIODevice::ReadWrite)){

        QTextStream stream(&file);
        QString fileContent = NULL;
        QChar newCharacter;

        ui->statusLabel->setText("Running");
        ui->fileProgress->setRange(0, bytes);
        ui->fileProgress->setValue(0);
        for(int i = 0; i < bytes; i++){
            qDebug()<<"Loop "<<i;
            newCharacter = getRandChar();
            qDebug()<<newCharacter;
            fileContent.append(newCharacter);
            double progress = (i/bytes)* 10;

            ui->fileProgress->setValue(progress);

        }

        //qDebug()<<"Final String: "<<fileContent;
        stream<<fileContent;

        //ui->statusLabel->setText("Idle");
    }
    else{
        qDebug()<<"Could not open file !!!";
    }*/

}

char filecreator::getRandChar(){
    int characterSet = 0;
    int characterNumber = rand()%26;
    int calculatedCharacter;

    if(characterSet == 0){
        calculatedCharacter = UPPERCASE + characterNumber;
    }
    else{
        calculatedCharacter = LOWERCASE + characterNumber;
    }

    return (char)(characterNumber + 65);

}

