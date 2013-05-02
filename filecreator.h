#ifndef FILECREATOR_H
#define FILECREATOR_H

/*filecreator.h - Header file for filecreator.cpp
 *Dan Myers
 *CSC 402
 */

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

signals:
    void stopNow();
    
private slots:

    void on_quitButton_clicked();
    void on_startButton_clicked();
    void setProgress(int value);
    void setStatus(QString status);
    void on_stopButton_clicked();
    void on_nameInput_textEdited(const QString &name);
    void on_sizeInput_textEdited(const QString &sizeStr);
    void toggleStop();
    void toggleStart();

private:
    Ui::filecreator *ui;
    bool stopBool;
    bool acceptableName;
    bool acceptableSize;
    QThread *thread;
    void checkInput();
};

#endif // FILECREATOR_H
