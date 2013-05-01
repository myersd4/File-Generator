/*creationThread.h -  Header file for the thread that will create the file.
 *Dan Myers
 *CSC 402
 */
#ifndef CREATIONTHREAD_H
#define CREATIONTHREAD_H

#include <QThread>

#define UPPERCASE 65
#define LOWERCASE 97


class creationThread : public QThread{

    Q_OBJECT

protected:
    void run();

signals:
    void updateProgress(int value); //Update the progress bar.
    void updateStatus(QString status); //Update the status displayed above the progess bar.

private:
    int size;   //Size of the file to be created.
    QString name;   //Name of the file being created.
    char getRandChar(); //Returns a random character to be placed in the file.

public:
    void setParameters(QString name, int size);

};

#endif
