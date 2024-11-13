#include "manager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    Manager mng;
    mng.run();

    return a.exec();
}
