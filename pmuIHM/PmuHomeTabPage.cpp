#include "PmuHomeTabPage.h"

PmuHomeTabPage::PmuHomeTabPage(int width, int height) : QTabWidget()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    //this->setConnections();
}

void PmuHomeTabPage::initVariable(){
    this->pmumainPage = new PmuMainPage(width,height);
    this->neighborPage = new QWidget();
    this->selectionPage = new QWidget();
    this->myOwnPage = new QWidget();

    this->setStyleSheet("QTabWidget::pane {border-top: 2px solid #C2C7CB;position: absolute; top: -0.5em;}"
                        "QTabWidget::tab-bar { alignment: center;}"
                        "QTabBar::tab {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
                        "border: 2px solid #C4C4C3;border-bottom-color: #C2C7CB; /* same as the pane color */border-top-left-radius: 4px; border-top-right-radius: 4px;min-width: 8ex;padding: 10px;color:aliceblue}"
                        "QTabBar::tab:selected, QTabBar::tab:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fafafa, stop: 0.4 #f4f4f4, stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);}"
                        "QTabBar::tab:selected {border-color: #9B9B9B; border-bottom-color: #C2C7CB; /* same as pane color */ }"
                        "QTabBar::tab:!selected {margin-top: 1px; /* make non-selected tabs look smaller */}"\
                        "QTabBar::close-button{border-image: url(:/no.png)}");
}

void PmuHomeTabPage::constructIHM(){
    this->insertTab(0,this->pmumainPage,"首頁");
    this->insertTab(1,this->neighborPage,"附近");
    this->insertTab(2,this->selectionPage,"精選");
    this->insertTab(3,this->myOwnPage,"我的");
    this->setTabPosition(South);
}

