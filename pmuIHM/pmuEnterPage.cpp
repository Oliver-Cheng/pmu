#include "pmuEnterPage.h"

pmuEnterPage::pmuEnterPage(QWidget *parent)
    : QWidget(parent)
{
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

pmuEnterPage::~pmuEnterPage()
{

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::initVariable
//!
void pmuEnterPage::initVariable(){
    this->screen = QApplication::screens().at(0);
    this->height = screen->availableSize().height();
    this->width = screen->availableSize().width();
    this->caracterStyle = new QFont("Segoe UI", 15, QFont::AnyStyle, false);
    mainPage = new pmuMainPage();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::setConnections
//!
void pmuEnterPage::setConnections(){
    this->connect(enterHomePageButton, SIGNAL(clicked()), this, SLOT(signInHomePage()));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::constructIHM
//!
void pmuEnterPage::constructIHM(){
    //--------------------------------------------------------------------------------------
    //titleBar layout
    //--------------------------------------------------------------------------------------
    this->titleBarItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->coursePublishButton = new QPushButton("發布課程");
    this->coursePublishButton->setFont(QFont("Segoe UI", 17, QFont::AnyStyle, false));
    this->coursePublishButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->helpButton = new QPushButton("幫助");
    this->helpButton->setFont(*caracterStyle);
    this->helpButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->signInButton = new QPushButton("登錄");
    this->signInButton->setFont(*caracterStyle);
    this->signInButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->signUpButton = new QPushButton("註冊");
    this->signUpButton->setFont(*caracterStyle);
    this->signUpButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->titleBar = new QWidget();
    this->titleBar->setStyleSheet("background-color:transparent");
    this->titleBar->setFixedHeight(height*0.08);
    this->titleBarLayout = new QHBoxLayout(titleBar);
    this->titleBarLayout->addItem(titleBarItem);
    this->titleBarLayout->addWidget(coursePublishButton);
    this->titleBarLayout->addWidget(helpButton);
    this->titleBarLayout->addWidget(signInButton);
    this->titleBarLayout->addWidget(signUpButton);
    this->titleBarLayout->setSpacing(0);
    this->titleBarLayout->setMargin(0);

    //--------------------------------------------------------------------------------------
    //centerplantform layout
    //--------------------------------------------------------------------------------------
    this->welcomLabel = new QLabel("學  滴  野");
    this->welcomLabel->setFont(QFont("Helvetica [Cronyx]", 50, QFont::Bold, false));
    this->welcomLabel->setStyleSheet("background-color:transparent; color: aliceblue");
    this->welcomLabel->setAlignment(Qt::AlignCenter);

    this->searchingLineEdit = new QLineEdit();
    this->searchingLineEdit->setFixedHeight(height*0.053);
    this->searchingLineEdit->setPlaceholderText("輸入學科、汾類");
    this->searchingLineEdit->setStyleSheet("QLineEdit { color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure; } "
                                           "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");

    this->searchingButton = new QPushButton();
    this->searchingButton->setIcon(QIcon(":/images/searchButton.png"));
    this->searchingButton->setFixedSize(width*0.092,height*0.053);
    this->searchingButton->setIconSize(QSize(width*0.092,height*0.053));
    /*this->searchingButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton0.png); background-color:transparent;border: 0px solid Gray; border-radius: 0px;}"
                                   "QPushButton:pressed{border-image: url(:/images/searchButton2.png);}");*/

    this->optionCombox = new QComboBox();
    this->optionCombox->setFixedSize(width*0.15, height*0.053);
    this->optionCombox->addItem("語言");
    this->optionCombox->addItem("音樂");
    this->optionCombox->addItem("舞蹈");
    this->optionCombox->setStyleSheet( "QComboBox{color:gray;background-color:cyan;border:1px solid black;border-radius:5px;padding:1px;}"
                                      // "QComboBox{color:white;background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));border-color: rgba(255,255,255,200);border-width: 1px;border-style: solid; }"
                                       "QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                       "QComboBox::drop-down{width: 20px;border: 1px;border-color:white;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                       "QComboBox::down-arrow{image: url(:/images/triangle.png);width: 180px; height: 180px;}");

//    this->optionCombox->setStyleSheet("QComboBox:editable { background-color: pink; }"
//                                      "QComboBox:!editable"
//                                      "QComboBox::drop-down:editable { background-color : transparent } /* QComboBox gets the on state when the popup is open */ "
//                                      "QComboBox:!editable:on"
//                                      "QComboBox::drop-down:editable:on { background-color : transparent  }"
//                                      "QComboBox:on { /* shift the text when the popup opens */ padding-top: 0px; padding-left: 0px;  }"
//                                      "QComboBox::drop-down {  subcontrol-origin: padding;  subcontrol-position: top right;width: 15px;border-left-width: 1px; border-left-color: darkgray; border-left-style: solid; /* just a single line */ border-top-right-radius: 3px; /* same radius as the QComboBox */border-bottom-right-radius: 3px; } "
//                                      "QComboBox::down-arrow { image: url(:/images/triangle.png); width : 10px; height : 10px; }"
//                                      "QComboBox::down-arrow:on { top: 0px;left: 0px;}");
    this->searchingBar = new QFrame();
    this->searchingBar->setStyleSheet("background-color:transparent; color:AliceBlue; border: 1px solid aliceblue; ");
    this->searchingBar->setFixedHeight(height*0.053);
    this->searchingBarLayout = new QHBoxLayout(this->searchingBar);
    this->searchingBarLayout->addWidget(this->searchingLineEdit);
    this->searchingBarLayout->addWidget(this->searchingButton);
    this->searchingBarLayout->addWidget(this->optionCombox);
    this->searchingBarLayout->setSpacing(0);
    this->searchingBarLayout->setMargin(0);

    this->enterHomePageButton = new QPushButton("進入主頁");
    this->enterHomePageButton->setStyleSheet("background-color:transparent; color: aliceblue; border: 3px solid white; border-radius:16px");
    this->enterHomePageButton->setFixedSize(width*0.28,height*0.053);

    this->enterHomePageWidget =new QWidget();
    this->enterHomePageWidget->setStyleSheet("background-color:transparent;");
    this->enterHomePageWidgetLayout = new QHBoxLayout(this->enterHomePageWidget);
    this->enterHomePageWidgetLayout->addWidget(this->enterHomePageButton);

    this->centerPlantform = new QWidget();
    this->centerPlantform->setStyleSheet("background-color:transparent");
    this->centerPlantform->setFixedSize(width*0.74, height*0.53);
    this->centerPlantformLayout = new QVBoxLayout(centerPlantform);
    this->centerPlantformLayout->addWidget(this->welcomLabel);
    this->centerPlantformLayout->addWidget(this->searchingBar);
    this->centerPlantformLayout->addWidget(this->enterHomePageWidget);
    this->centerPlantformLayout->setSpacing(0);
    this->centerPlantformLayout->setMargin(0);

    //--------------------------------------------------------------------------------------
    //mainplantform layout
    //--------------------------------------------------------------------------------------
    this->mainPlantform = new QWidget();
    this->mainPlantform->setStyleSheet("background-color:transparent");
    this->mainPlantformLayout = new QHBoxLayout(this->mainPlantform);
    this->mainPlantformLayout->addWidget(this->centerPlantform);
    //--------------------------------------------------------------------------------------
    //main layout
    //--------------------------------------------------------------------------------------
    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(this->titleBar);
    this->mainLayout->addWidget(this->mainPlantform);
    this->mainLayout->setSpacing(0);
    this->mainLayout->setMargin(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::drawBackground
//!
void pmuEnterPage::drawBackground(){
    pixmap = new QPixmap(":/images/smallgu.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief Widget::signInHomePage
//!
void pmuEnterPage::signInHomePage(){
    mainPage->show();
}
