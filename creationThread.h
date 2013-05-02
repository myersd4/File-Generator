/*creationThread.h -  Header file for the thread that will create the file.
 *Dan Myers
 *CSC 402
 */
#ifndef CREATIONTHREAD_H
#define CREATIONTHREAD_H

#include <QThread>

#define UPPERCASE 65
#define LOWERCASE 97


class creationThread : public QObject{

    Q_OBJECT

signals:
    void updateProgress(int value); //Update the progress bar.
    void updateStatus(QString status); //Update the status displayed above the progess bar.
    void finished();
    void disableStop();
    void toggleStart();

private:
    int size;   //Size of the file to be created.
    QString name;   //Name of the file being created.
    bool stopFlag;
    char getRandChar(); //Returns a random character to be placed in the file.


private slots:

    void startCreation();   //Start creation of the file.
    void stopCreation();    //Stop creation of the file.

public:
    void createFile();      //Create the file.
    void setParameters(QString name, int size);     //Set the name and size of the file.

};

#endif
