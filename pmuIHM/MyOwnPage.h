#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScreen>
#include <QFont>

class MyOwnPage : public QWidget
{
    Q_OBJECT

public:
    MyOwnPage(int width, int height);
    ~MyOwnPage();

    void initial();
    void constructIHM();
    void setConnections();

private:
    QWidget* idWidget;
    QLabel* idLabel;

    QWidget* courseInfoWidget;
    QWidget* fWidget;
    QWidget* sWidget;
    QWidget* tWidget;
    QWidget* foWidget;

    QPushButton* fButton;
    QPushButton* sButton;
    QPushButton* tButton;
    QPushButton* foButton;

    QVBoxLayout* mainLayout;
    QVBoxLayout* idLayout;
    QVBoxLayout* fLayout;
    QVBoxLayout* sLayout;
    QVBoxLayout* tLayout;
    QVBoxLayout* foLayout;
    QGridLayout* coursesLayout;

    QFont *caracterStyle;
    int width;
    int height;
    QScreen* screen;

private slots:
   void lks();

};

#endif // PERSONALINFORMATION_H
