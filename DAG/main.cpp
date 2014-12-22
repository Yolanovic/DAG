#include "dagmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DAGMainWindow w;
    w.show();

    return a.exec();
}
