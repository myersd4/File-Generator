#ifndef FILECREATOR_H
#define FILECREATOR_H

#define UPPERCASE 65
#define LOWERCASE 97

#include <QMainWindow>

namespace Ui {
class filecreator;
}

class filecreator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit filecreator(QWidget *parent = 0);
    char getRandChar();
    ~filecreator();
    
private slots:

    void on_quitButton_clicked();

    void on_startButton_clicked();


private:
    Ui::filecreator *ui;
};

#endif // FILECREATOR_H
