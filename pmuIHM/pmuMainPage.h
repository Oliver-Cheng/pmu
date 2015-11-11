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

#include "LanguageWidget.h"
#include "HottipsWidget.h"
#include "PrivilegeWidget.h"
#include "InstitutionWidget.h"
#include "GuessULikeWidget.h"
#include <QStandardItemModel>
#include <QStandardItem>

class PmuMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit PmuMainPage(int width, int height);
    ~PmuMainPage();

    void initial();
    void constructMainWidget();
    void setConnections();
private:
    LanguageWidget *languageWidget;

    QPixmap* pixmap;
    QVBoxLayout* mainLayout;
    QHBoxLayout* listWidgetLayout;
    QPalette palette;

    QFrame *titleBar;
    QHBoxLayout *searchingBarLayout;
    QLineEdit *searchingLineEdit;

    QPushButton *searchingButton;
    QPushButton* somethingElseButton1;

    QListView* optionListWidget;
    QTabWidget* choosenTableWidget;
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
