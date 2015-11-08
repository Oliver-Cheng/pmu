#ifndef PMUMAINPAGE_H
#define PMUMAINPAGE_H

#include <QWidget>
#include <QWidget>
#include <QPixmap>
#include <QScreen>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QTabWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QRect>
#include <QDesktopWidget>
#include <QListView>

#include "HottipsWidget.h"
#include "PrivilegeWidget.h"
#include "InstitutionWidget.h"
#include "GuessULikeWidget.h"
#include <QStandardItemModel>
#include <QStandardItem>

class pmuMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit pmuMainPage(QWidget *parent = 0);
    ~pmuMainPage();

    void initial();
    void constructMainWidget();

private:
    QPixmap* pixmap;
    QVBoxLayout* mainLayout;
    QHBoxLayout* listWidgetLayout;
    QPalette palette;
    QScreen *screen;


    QFrame *titleBar;
    QHBoxLayout *searchingBarLayout;
    QLineEdit *searchingLineEdit;

    QPushButton *searchingButton;
    QPushButton* somethingElseButton1;


    QListView* optionListWidget;
    QTabWidget* choosenTableWidget;
    QWidget* personnalWidget;
    QComboBox* citySwitchComoBox;
    QLabel* cityLabel;

    QStandardItem* languageItem;
    QStandardItem* sportItem;
    QStandardItem* informationTechItem;
    QStandardItem* danceItem;
    QStandardItem* accountingItem;
    QStandardItem* mathItem;
    QStandardItem* collegeItem;
    QStandardItem* babyeducationItem;
    QStandardItem* middleschoolItem;
    QStandardItem* primaryschoolItem;

    QPushButton* homepagePushBtn;
    QPushButton* nearByPushBtn;
    QPushButton* essentialOptionPushBtn;
    QPushButton* privateHomePushBtn;
    QHBoxLayout *personnalBarLayout;

    HottipsWidget* hottipsWidget;
    PrivilegeWidget* privilegeWidget;
    InstitutionWidget* institutionWidget;
    GuessULikeWidget* guessULikeWidget;


    QWidget* optionsWidget;


    QStandardItemModel* model;


    int width;
    int height;


signals:

public slots:
};

#endif // PMUMAINPAGE_H
