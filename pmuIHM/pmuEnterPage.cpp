#include "PmuEnterPage.h"

PmuEnterPage::PmuEnterPage(QWidget *parent)
    : QWidget(parent)
{
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

PmuEnterPage::~PmuEnterPage()
{

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::initVariable
//!
void PmuEnterPage::initVariable(){
    this->screen = QApplication::screens().at(0);
    this->height = screen->availableSize().height();
    this->width = screen->availableSize().width();
    this->caracterStyle = new QFont("Segoe UI", 15, QFont::AnyStyle, false);
    this->pmuHomeTabPage = new PmuHomeTabPage(width,height);
    this->regAndSignPage = new RegAndSignPage(width,height);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::setConnections
//!
void PmuEnterPage::setConnections(){
    this->connect(this->enterHomePageButton, SIGNAL(clicked()), pmuHomeTabPage, SLOT(show()));
    this->connect(this->signUpButton, SIGNAL(clicked()), regAndSignPage, SLOT(show()));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::constructIHM
//!
void PmuEnterPage::constructIHM(){
    //--------------------------------------------------------------------------------------
    //titleBar layout
    //--------------------------------------------------------------------------------------
    this->titleBarItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->coursePublishButton = new QPushButton("發布課程");
    this->coursePublishButton->setFont(*caracterStyle);
    this->coursePublishButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 1px solid white; border-radius:16px");

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
    this->welcomLabel->setFont(QFont("华文行楷", 50, QFont::Bold, false));
    this->welcomLabel->setStyleSheet("background-color:transparent; color: aliceblue");
    this->welcomLabel->setAlignment(Qt::AlignCenter);

    this->searchingLineEdit = new QLineEdit();
    this->searchingLineEdit->setFixedHeight(height*0.053);
    this->searchingLineEdit->setPlaceholderText("輸入學科、汾類");
    this->searchingLineEdit->setStyleSheet("QLineEdit { color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure; } "
                                           "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");

    this->searchingButton = new QPushButton();
    //this->searchingButton->setIcon(QIcon(":/images/searchButton.png"));
    this->searchingButton->setFixedSize(width*0.092,height*0.053);
    this->searchingButton->setIconSize(QSize(width*0.092,height*0.053));
    this->searchingButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton.png); background-color:AliceBlue;border: 0px;}"
                                   "QPushButton:pressed{border-image: url(:/images/searchButton1.png);background-color:AliceBlue;border: 0px;}");

    this->optionCombox = new QComboBox();
    this->optionCombox->setFixedSize(width*0.18, height*0.053);
    this->optionCombox->insertItem(0,"語言");
    this->optionCombox->insertItem(1,"音樂");
    this->optionCombox->insertItem(2,"舞蹈");
    this->optionCombox->setStyleSheet( "QComboBox{color:gray;background-color:transparent;border:0px;border-radius:0px;padding:0px;}"
                                       //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                       "QComboBox::drop-down{width: 88px;border: 0px;border-color:trantransparent;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                       "QComboBox::down-arrow{image: url(:/images/down.png);}"
                                       "QComboBox::down-arrow{width:72; height:72}"
                                       "QComboBox::down-arrow:on { top: 1px;left: 1px;}");
    this->searchingBar = new QFrame();
    this->searchingBar->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px ; ");
    this->searchingBar->setFixedHeight(height*0.053);
    this->searchingBarLayout = new QHBoxLayout(this->searchingBar);
    this->searchingBarLayout->addWidget(this->searchingLineEdit);
    this->searchingBarLayout->addWidget(this->searchingButton);
    this->searchingBarLayout->addStretch();
    this->searchingBarLayout->addWidget(this->optionCombox);
    this->searchingBarLayout->setSpacing(0);
    this->searchingBarLayout->setMargin(0);

    this->enterHomePageButton = new QPushButton("進入主頁");
    this->enterHomePageButton->setStyleSheet("background-color:transparent; color: aliceblue; border: 1px solid white; border-radius:16px");
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
void PmuEnterPage::drawBackground(){
    pixmap = new QPixmap(":/images/smallgu.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}
