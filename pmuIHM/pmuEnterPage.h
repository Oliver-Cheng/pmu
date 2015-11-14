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
#include <QDialog>

#include "PmuHomeTabPage.h"
#include "RegAndSignPage.h"
#include "CoursePublishPage.h"

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
    void creatDialogWidget();

private:
    int width;
    int height;
    bool flag;

    PmuHomeTabPage * pmuHomeTabPage;
    RegAndSignPage *regAndSignPage;
    CoursePublishPage *coursePublishPage;
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
    QVBoxLayout *dialogLayout;
    QHBoxLayout *optionWidgetLayout;

    QFrame *searchingBar;

    QSpacerItem *titleBarItem;

    QWidget *titleBar;
    QWidget *mainPlantform;
    QWidget *centerPlantform;
    QWidget *enterHomePageWidget;
    QWidget *optionWidget;

    QLineEdit *searchingLineEdit;

    QLabel *welcomLabel;
    QLabel *searchingLabel;
    QLabel *optionInfoLabel;

    QPushButton *coursePublishButton;
    QPushButton *helpButton;
    QPushButton *signInButton;
    QPushButton *signUpButton;
    QPushButton *searchingButton;
    QPushButton *enterHomePageButton;
    QPushButton *individualButton;
    QPushButton *organizationButton;
    QPushButton *cancelButton;

    QDialog *individualOrOrgDialog;

private slots:
    void showSignUpPage();
    void showSignIpPage();
    void showDialog();
    void showCoursePublishPage();
};

#endif // PMUENTERPAGE_H
