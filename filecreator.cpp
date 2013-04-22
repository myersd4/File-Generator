#include "filecreator.h"
#include "ui_filecreator.h"
#include <QDebug>

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
    QIntValidator *validator = new QIntValidator;
    ui->sizeInput->setValidator(validator);
    QString size = ui->sizeInput->text();
    QString name = ui->nameInput->text();

    qDebug()<<size;


}

