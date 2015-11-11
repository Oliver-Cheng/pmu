#include "PmuEnterPage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PmuEnterPage w;
    w.show();

    return a.exec();
}
