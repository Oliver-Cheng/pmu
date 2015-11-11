#ifndef PMUENTERPAGE_H
#define PMUENTERPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QApplication>
#include <QScreen>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>
#include <QFont>
#include <QComboBox>

#include "PmuHomeTabPage.h"
#include "RegAndSignPage.h"

class PmuEnterPage : public QWidget
{
    Q_OBJECT

public:
    PmuEnterPage(QWidget *parent = 0);
    ~PmuEnterPage();
    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();

private:
    int width;
    int height;

    PmuHomeTabPage * pmuHomeTabPage;
    RegAndSignPage *regAndSignPage;
    QScreen *screen;
    QPixmap* pixmap;
    QFont *caracterStyle;

    QComboBox *optionCombox;

    QVBoxLayout* mainLayout;
    QHBoxLayout *searchingBarLayout;
    QHBoxLayout *titleBarLayout;
    QHBoxLayout *mainPlantformLayout;
    QVBoxLayout *centerPlantformLayout;
    QHBoxLayout *enterHomePageWidgetLayout;
    QHBoxLayout *searchingButtonLayout;
    QHBoxLayout *searchingLineEditLayout;

    QFrame *searchingBar;

    QSpacerItem *titleBarItem;

    QWidget *titleBar;
    QWidget *mainPlantform;
    QWidget *centerPlantform;
    QWidget *enterHomePageWidget;

    QLineEdit *searchingLineEdit;

    QLabel *welcomLabel;
    QLabel *searchingLabel;

    QPushButton *coursePublishButton;
    QPushButton *helpButton;
    QPushButton *signInButton;
    QPushButton *signUpButton;
    QPushButton *searchingButton;
    QPushButton *enterHomePageButton;

private slots:

};

#endif // PMUENTERPAGE_H
