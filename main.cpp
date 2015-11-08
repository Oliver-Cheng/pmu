#include "pmuEnterPage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pmuEnterPage w;
    w.show();

    return a.exec();
}
