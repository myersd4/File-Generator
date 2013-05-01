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
   int size = ui->sizeInput->text().toInt(); //Get the size of the file.

   creationThread t1;

   t1.setParameters(ui->nameInput->text(), size); //Get the name of the file.'

   //Connect creationThread signals to the appropriate slots.
   connect(&t1, SIGNAL(updateProgress(int)), SLOT(setProgress(int)));
   connect(&t1, SIGNAL(updateStatus(QString)), SLOT(setStatus(QString)));

   t1.start();//Start the thread.

   t1.wait();



}

void filecreator::setProgress(int value){

    ui->fileProgress->setValue(value);
}

void filecreator::setStatus(QString status){

    ui->statusLabel->setText(status);
}

void filecreator::on_stopButton_clicked()
{
    //t1.stop();
}
