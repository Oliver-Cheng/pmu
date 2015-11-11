#ifndef PMUHOMETABPAGE_H
#define PMUHOMETABPAGE_H

#include <QWidget>
#include <QTabWidget>
#include "PmuMainPage.h"

class PmuHomeTabPage : public QTabWidget
{
    Q_OBJECT
public:
    PmuHomeTabPage(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnections();

private:
    int width;
    int height;

    PmuMainPage *pmumainPage;
    QWidget *neighborPage;
    QWidget *selectionPage;
    QWidget *myOwnPage;
signals:

public slots:
};

#endif // PMUHOMETABPAGE_H
