#include "pmuEnterPage.h"

pmuEnterPage::pmuEnterPage(QWidget *parent)
    : QWidget(parent)
{
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
    //this->drawBackground();
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
    this->searchingButton->setFixedSize(width*0.092,height*0.053);
    this->searchingButton->setIconSize(QSize(width*0.092,height*0.053));
    searchingButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton0.png); background-color:transparent;border: 0px solid Gray; border-radius: 0px;}"
                                   "QPushButton:pressed{border-image: url(:/images/searchButton2.png);}");

    this->optionCombox = new QComboBox();
    this->optionCombox->setStyleSheet("QComboBox { border: 0px solid gray; border-radius: 3px; padding: 1px 1px 1px 3px; min-width: 3em; background-color: transparent; color: gainsboro}"
                                      "QComboBox:editable { background: white; }"
                                      "QComboBox:!editable, QComboBox::drop-down:editable { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); } /* QComboBox gets the on state when the popup is open */ "
                                      "QComboBox:!editable:on, QComboBox::drop-down:editable:on { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #D3D3D3, stop: 0.4 #D8D8D8, stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);  }"
                                      "QComboBox:on { /* shift the text when the popup opens */ padding-top: 0px; padding-left: 0px;  }"
                                      "QComboBox::drop-down {  subcontrol-origin: padding;  subcontrol-position: top right;width: 15px;border-left-width: 1px; border-left-color: darkgray; border-left-style: solid; /* just a single line */ border-top-right-radius: 3px; /* same radius as the QComboBox */border-bottom-right-radius: 3px; } "
                                      "QComboBox::down-arrow {image: url(/usr/share/icons/crystalsvg/16x16/actions/1downarrow.png); }QComboBox::down-arrow:on { /* shift the arrow when popup is open */ top: 1px;left: 1px;}");

    this->optionCombox->setFixedSize(width*0.2, height*0.053);
    this->optionCombox->addItem("語言");
    this->optionCombox->addItem("音樂");
    this->optionCombox->addItem("舞蹈");

    this->searchingBar = new QFrame();
    this->searchingBar->setStyleSheet("background-color:transparent; color:AliceBlue; border: 1px solid aliceblue; ");
    this->searchingBar->setFixedSize(width*0.75, height*0.053);
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

}
