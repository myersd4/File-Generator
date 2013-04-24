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
    void updateProgress(int value);
    void updateStatus(QString status);

private:
    int size;
    QString name;
    char getRandChar();

public:
    void setParameters(QString name, int size);

};

#endif
