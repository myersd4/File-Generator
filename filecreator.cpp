#include "filecreator.h"
#include "ui_filecreator.h"
#include <QDebug>
#include <QFile>


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
    QIntValidator *validator = new QIntValidator();
    validator->setBottom(0);
    ui->sizeInput->setValidator(validator);


    QString size = ui->sizeInput->text();
    QString name = ui->nameInput->text();

    int bytes = size.toInt();

    qDebug()<<"Name Entered: "<<name<<endl;
    qDebug()<<"Size Entered: "<<size<<endl;
    qDebug()<<"Converted Size: "<<bytes<<endl;

    QString fileName = name;
    QFile file(fileName);

    qDebug()<<endl<<endl<<"File Name: "<<fileName;
    if(file.open(QIODevice::ReadWrite)){

        QTextStream stream(&file);

        for(int i = 0; i < bytes; i++){
            qDebug()<<"Loop "<<i<<endl;

            stream<<"a";
        }
    }

}

