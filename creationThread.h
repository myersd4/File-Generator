#ifndef CREATIONTHREAD_H
#define CREATIONTHREAD_H

#include <QThread>


class creationThread : public QThread{

    Q_OBJECT

protected:
    void run();

signals:
    void updateProgress(int value);
    void updateStatus(QString status);

};

#endif
