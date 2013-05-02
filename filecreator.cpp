/*filecreator.cpp - Creates a thread and runs it to create the file.
 *Dan Myers
 *CSC 402
 */
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
    ui->stopButton->setEnabled(true);

    creationThread *t1 = new creationThread();  //Get instance of class that actually creates the file.
    thread = new QThread();     //Get instance of QThread.
    t1->moveToThread(thread);   //Move the file creating class into the thread.


    //Get file name and size and set the values in the thread.
    t1->setParameters(ui->nameInput->text(), ui->sizeInput->text().toInt());


    connect(thread, SIGNAL(started()), t1, SLOT(startCreation()));  //Start the file creation.
    connect(t1, SIGNAL(finished()), thread, SLOT(quit()));          //Signal when finished.
    connect(t1, SIGNAL(updateProgress(int)), SLOT(setProgress(int)));   //Update progress bar.
    connect(t1, SIGNAL(updateStatus(QString)), SLOT(setStatus(QString)));   //Update status.
    connect(this, SIGNAL(stopNow()), t1, SLOT(stopCreation())); //Stop the program.
    connect(t1, SIGNAL(disableStop()), SLOT(toggleStop()));
    connect(t1, SIGNAL(toggleStart()), SLOT(toggleStart()));

    thread->start(); //Start the thread.



}

/*Update file creation progress.*/
void filecreator::setProgress(int value){

    ui->fileProgress->setValue(value);
}

/*Set the status of the file creation.*/
void filecreator::setStatus(QString status){

    ui->statusLabel->setText(status);
}

/*Stop the file creation*/
void filecreator::on_stopButton_clicked()
{
    emit(stopNow());
}

/*Validator for name input*/
void filecreator::on_nameInput_textEdited(const QString &name)
{

    if(name.isEmpty()){ //Empty string is not valid
        acceptableName = false;
        checkInput();
        return;
    }

    for(int i = 0; i < name.size(); i++){
        if(!name[i].isLetter()){    //Only letters are valid.
            acceptableName = false;
            checkInput();
            return;
        }
    }

    acceptableName = true;
    checkInput();
}

/*Validator for size input*/
void filecreator::on_sizeInput_textEdited(const QString &sizeStr)
{
    if(sizeStr.isEmpty()){  //Empty field is not valid.
        acceptableSize = false;
        checkInput();
        return;
    }

    for(int i = 0; i < sizeStr.size(); i++){
        if(!sizeStr[i].isDigit() || sizeStr.size() > 9){    //Number has to be all digits and shorter than 9 digits.
            acceptableSize = false;
            checkInput();
            return;
        }

        int first = sizeStr[0].digitValue();
        if(first != 1){     //First number must be a 1
            acceptableSize = false;
            checkInput();
            return;
        }

        acceptableSize = true;
        checkInput();
    }

    acceptableSize = true;
    checkInput();
}

void filecreator::checkInput(){

    if(acceptableName && acceptableSize){
        ui->startButton->setEnabled(true);
    }
    else{
        ui->startButton->setEnabled(false);
    }
}

void filecreator::toggleStop(){
    ui->stopButton->setEnabled(false);
}

void filecreator::toggleStart(){
    if(ui->startButton->isEnabled()){
        ui->startButton->setEnabled(false);
    }
    else{
        ui->startButton->setEnabled(true);
    }
}
