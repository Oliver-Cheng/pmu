#ifndef WIDGET_H
#define WIDGET_H

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
#include <QToolButton>
#include <QSpacerItem>
#include <QLabel>
#include <QIcon>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QGridLayout>
#include <QFont>

#include "SearchWidget.h"

class LanguageWidget : public QWidget
{
    Q_OBJECT

public:
    LanguageWidget(QWidget *parent = 0);
    ~LanguageWidget();

    void initial();
    void drawBackground();
    void constructIHM();
    void setConnections();
    void adjustScrollBar(QScrollBar *scrollBar);
private:
    QPixmap* pixmap;

    QScreen* screen;

    QFrame *tileBar;
    //QScrollArea *contentWidget;
    QWidget *contentWidget;
    QWidget *adsWidget;
    QWidget *contentInfoChWidget;
    QWidget *contentInfoEnWidget;
    QWidget *contentInfoFrWidget;
    QWidget *contentInfoGeWidget;

    QWidget *contentChineseWidget;
    QWidget *contentEnglishWidget;
    QWidget *contentFrenchWidget;
    QWidget *contentDeutschWidget;
    QWidget *contentJapaneseWidget;
    QWidget *contentKoreanWidget;

//    QListWidget *contentListWindow;

    QVBoxLayout* mainWidgetLayout;
    QHBoxLayout* tileBarLayout;
    QVBoxLayout* contentWidgetLayout;
    QHBoxLayout* chineseWidgetLayout;
    QHBoxLayout* englishWidgetLayout;
    QHBoxLayout* frenchWidgetLayout;
    QHBoxLayout* deutschWidgetLayout;

    QGridLayout* chineseGridLayout;
    QGridLayout* englishGridLayout;
    QGridLayout* frenchGridLayout;
    QGridLayout* deutschGridLayout;
//    QGridLayout* testGridLayout;

//    QSpacerItem* tileBarSpacer;

    QPushButton* tileBarReturnButton;
    QPushButton* tileBarSearchButton;
    QPushButton* chineseGridButtonone;
    QPushButton* chineseGridButtontwo;
    QPushButton* chineseGridButtonthree;
    QPushButton* chineseGridButtonfour;
    QPushButton* chineseGridButtonfive;
    QPushButton* chineseGridButtonsix;
    QPushButton* englishGridButtonone;
    QPushButton* englishGridButtontwo;
    QPushButton* englishGridButtonthree;
    QPushButton* englishGridButtonfour;
    QPushButton* englishGridButtonfive;
    QPushButton* englishGridButtonsix;
    QPushButton* frenchGridButtonone;
    QPushButton* frenchGridButtontwo;
    QPushButton* frenchGridButtonthree;
    QPushButton* frenchGridButtonfour;
    QPushButton* frenchGridButtonfive;
    QPushButton* frenchGridButtonsix;
    QPushButton* deutschGridButtonone;
    QPushButton* deutschGridButtontwo;
    QPushButton* deutschGridButtonthree;
    QPushButton* deutschGridButtonfour;
    QPushButton* deutschGridButtonfive;
    QPushButton* deutschGridButtonsix;

    QFont *caracterStyle;

    QLabel* tileBarLabel;
    QLabel* chineseLabel;
    QLabel* englishLabel;
    QLabel* frenchLabel;
    QLabel* deutchLabel;

    QScrollArea* contentWidgetScrollArea;

    SearchWidget *searchPage;
    int height;
    int width;
    int buttonWidth;
    int buttonHeight;



signals:


public slots:
    void signSearchPage();
};

#endif // WIDGET_H
