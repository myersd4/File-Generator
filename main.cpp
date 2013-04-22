#include "filecreator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    filecreator w;
    w.show();
    
    return a.exec();
}
