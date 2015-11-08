#ifndef PMUENTERPAGE_H
#define PMUENTERPAGE_H

#include <QWidget>
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

#include "pmuMainPage.h"


class pmuEnterPage : public QWidget
{
    Q_OBJECT

public:
    pmuEnterPage(QWidget *parent = 0);
    ~pmuEnterPage();
    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();
    void display();

private:
    pmuMainPage * mainPage;
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

    int width;
    int height;

private slots:
    void signInHomePage();
};

#endif // PMUENTERPAGE_H
