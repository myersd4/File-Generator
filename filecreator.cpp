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

   connect(&t1, SIGNAL(updateProgress(int)), SLOT(setProgress(int)));
   connect(&t1, SIGNAL(updateStatus(QString)), SLOT(setStatus(QString)));
   t1.start();

   t1.wait();


}

void filecreator::setProgress(int value){

    ui->fileProgress->setValue(value);
}

void filecreator::setStatus(QString status){

    ui->statusLabel->setText(status);
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

