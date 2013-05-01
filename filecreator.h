#ifndef FILECREATOR_H
#define FILECREATOR_H



#include <QMainWindow>
#include "creationThread.h"

namespace Ui {
class filecreator;
}

class filecreator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit filecreator(QWidget *parent = 0);
    ~filecreator();
    
private slots:

    void on_quitButton_clicked();

    void on_startButton_clicked();

    void setProgress(int value);

    void setStatus(QString status);

    void on_stopButton_clicked();

private:
    Ui::filecreator *ui;
    bool stopBool;
    //creationThread t1;
};

#endif // FILECREATOR_H
