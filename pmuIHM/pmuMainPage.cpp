#include "pmuMainPage.h"

pmuMainPage::pmuMainPage(QWidget *parent)
    : QWidget(parent){

    this->initial();
    this->constructMainWidget();


}

pmuMainPage::~pmuMainPage()
{

}

void pmuMainPage::initial(){

    screen =QApplication::screens().at(0);
    height = screen->availableSize().height();
    width = screen->availableSize().width();
}

void pmuMainPage::constructMainWidget(){

    this->setStyleSheet("background-color:rgb(135,209,199)");

    //! create seraching bar area
    cityLabel = new QLabel("城市:");
    cityLabel->setFixedSize(width*0.18,height*0.05);
    //cityLabel->setAlignment(Qt::AlignCenter);
    cityLabel->setFont(QFont("Segoe UI",15,QFont::Normal,false));
    cityLabel->setStyleSheet("QLabel{background-color:transparent;color:aliceblue; border:0px solid Gray;}");
    citySwitchComoBox = new QComboBox();
    citySwitchComoBox->setStyleSheet("QComboBox{color:gray;background-color:cyan;border:1px solid black;border-radius:5px;padding:1px;}"
                                      "QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                      "QComboBox::drop-down{width: 20px;border: 1px;border-color:white;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                      "QComboBox::down-arrow{image: url(:/images/triangle.png);width: 180px; height: 180px;}");
    citySwitchComoBox->setFixedSize(width*0.18,height*0.05);
    citySwitchComoBox->setFont(QFont("Segoe UI",15,QFont::Normal,false));
    citySwitchComoBox->addItem("珠海");
    citySwitchComoBox->addItem("澳門");

    searchingLineEdit = new QLineEdit();
    searchingLineEdit->setFixedSize(width*0.28,height*0.05);
    searchingLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 5px solid blue;border-radius: 10px;padding: 5px; selection-background-color:Blue;");
    searchingButton = new QPushButton("搜索");
    searchingButton->setFixedSize(width*0.125,height*0.05);
    searchingButton->setStyleSheet("QPushButton{background-color:transparent;color:aliceblue;border:0px solid blue;}");
    somethingElseButton1 = new QPushButton("購物車");
    somethingElseButton1->setFixedSize(width*0.125,height*0.05);
    somethingElseButton1->setStyleSheet("QPushButton{background-color:transparent;color:aliceblue;border:0px solid Gray; }");
    titleBar = new QFrame();
    titleBar->setFixedHeight(height*0.1);
    titleBar->setStyleSheet("background-color:transparent");
    searchingBarLayout = new QHBoxLayout(titleBar);
    searchingBarLayout->addWidget(cityLabel);
    searchingBarLayout->addWidget(citySwitchComoBox);
    searchingBarLayout->addWidget(searchingLineEdit);
    searchingBarLayout->addWidget(searchingButton);
    searchingBarLayout->addWidget( somethingElseButton1);
    searchingBarLayout->setSpacing(3);
    searchingBarLayout->setMargin(0);

    //!create list widget


//    optionsWidget->setFixedHeight(height*0.3);

    optionListWidget = new QListView();
    optionListWidget->setFixedHeight(height*0.3);

    optionListWidget->setViewMode(QListView::IconMode);
    optionListWidget->setSpacing(width*0.01);

    model = new QStandardItemModel();

//    optionListWidget->setStyleSheet("background-color:transparent");
//    //optionListWidget->setStyleSheet("QListWidget::item{padding: 25px; color: aliceblue; border: 0px; margin:0px; }");
//    languageItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("語言"));
//   // languageItem->setFlags(languageItem->flags() & ~Qt::ItemIsSelectable);
//    sportItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("運動"));
//    //sportItem->setFlags(sportItem->flags() & ~Qt::ItemIsSelectable);
//    informationTechItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("IT"));
//   // informationTechItem->setFlags(informationTechItem->flags() & ~Qt::ItemIsSelectable);
//    danceItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("舞蹈"));
//   //danceItem->setFlags(danceItem->flags() & ~Qt::ItemIsSelectable);
//    babyeducationItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("幼儿"));
//   // babyeducationItem->setFlags(babyeducationItem->flags() & ~Qt::ItemIsSelectable);
//    primaryschoolItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("小学"));
//   // primaryschoolItem->setFlags(primaryschoolItem->flags() & ~Qt::ItemIsSelectable);
//    middleschoolItem = new QStandardItem(QIcon(":/images/dancers.jpg"), tr("中学"));
//   // middleschoolItem->setFlags(middleschoolItem->flags() & ~Qt::ItemIsSelectable);
//    collegeItem =new QStandardItem(QIcon(":/images/dancers.jpg"), tr("大学"));
   // collegeItem->setFlags(collegeItem->flags() & ~Qt::ItemIsSelectable);
//    model->insertRow(0,languageItem);
//    model->insertRow(0,sportItem);
//    model->insertRow(0,informationTechItem);
//    model->insertRow(1,danceItem);
//    model->insertRow(1,babyeducationItem);
//    model->insertRow(1,primaryschoolItem);
//    optionListWidget->setModel(model);


//    optionListWidget->setFlow(QListWidget::LeftToRight);
//    optionListWidget->setLayoutMode(QListWidget::Batched);

//    optionListWidget->setIconSize(QSize(width*0.3,height*0.075));
//    optionListWidget->setDragEnabled(false);
    //optionListWidget->setResizeMode();


//    accountingItem = new QStandardItem(QIcon(":images/dancers.jpg"),tr("會計"));
//    //accountingItem->setFlags(accountingItem->flags() & ~Qt::ItemIsSelectable);
//    mathItem = new QStandardItem(QIcon(":images/dancers.jpg"),tr("數學"));


    //!create tab widget-------------------------------------------------------------------------------
    choosenTableWidget = new QTabWidget();
    choosenTableWidget->setFixedHeight(height*0.5);
    choosenTableWidget->setStyleSheet("QTabWidget::pane {border-top: 2px solid #C2C7CB;position: absolute; top: -0.5em;}"
                                      "QTabWidget::tab-bar { alignment: center;}"
                                      "QTabBar::tab {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
                                      "border: 2px solid #C4C4C3;border-bottom-color: #C2C7CB; /* same as the pane color */border-top-left-radius: 4px; border-top-right-radius: 4px;min-width: 8ex;padding: 10px;color:aliceblue}"
                                      "QTabBar::tab:selected, QTabBar::tab:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fafafa, stop: 0.4 #f4f4f4, stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);}"
                                      "QTabBar::tab:selected {border-color: #9B9B9B; border-bottom-color: #C2C7CB; /* same as pane color */ }"
                                      "QTabBar::tab:!selected {margin-top: 1px; /* make non-selected tabs look smaller */}"\
                                      "QTabBar::close-button{border-image: url(:/no.png)}");
    hottipsWidget = new HottipsWidget();
    hottipsWidget->setFocusPolicy(Qt::NoFocus);
    privilegeWidget = new PrivilegeWidget();
    privilegeWidget->setFocusPolicy(Qt::NoFocus);
    institutionWidget = new InstitutionWidget();
    institutionWidget->setFocusPolicy(Qt::NoFocus);
    guessULikeWidget = new GuessULikeWidget();
    institutionWidget->setFocusPolicy(Qt::NoFocus);
    choosenTableWidget->insertTab(0,hottipsWidget,"熱 門");
    choosenTableWidget->insertTab(1,privilegeWidget,"優 惠");
    choosenTableWidget->insertTab(2,institutionWidget,"機 構");
    choosenTableWidget->insertTab(3,guessULikeWidget,"猜妳喜歡");
    choosenTableWidget->setFont(QFont("Segoe UI",15,QFont::Normal,false));


    //!create personnal information widget
    personnalWidget = new QWidget();
    personnalWidget->setStyleSheet("background-color:transparent");
    personnalWidget->setFixedHeight(height*0.1);
    homepagePushBtn = new QPushButton("首頁");
    homepagePushBtn->setFixedHeight(height*0.05);
    homepagePushBtn->setStyleSheet("background-color:transparent;color:aliceblue; border:0px aliceblue;");
    nearByPushBtn = new QPushButton("附近") ;
    nearByPushBtn->setFixedHeight(height*0.05);
    nearByPushBtn->setStyleSheet("background-color:transparent;color:aliceblue;border:0px aliceblue;");

    essentialOptionPushBtn = new QPushButton("精選");
    essentialOptionPushBtn->setFixedHeight(height*0.05);
    essentialOptionPushBtn->setStyleSheet("background-color:transparent;color:aliceblue;border:0px;QPushButton{border:none}");
    privateHomePushBtn = new QPushButton("我的");
    privateHomePushBtn->setFixedHeight(height*0.05);
    privateHomePushBtn->setStyleSheet("background-color:transparent;color:aliceblue;border:0px aliceblue;");
    personnalBarLayout = new QHBoxLayout(personnalWidget);
    personnalBarLayout->addWidget(homepagePushBtn);
    personnalBarLayout->addWidget(nearByPushBtn);
    personnalBarLayout->addWidget(essentialOptionPushBtn);
    personnalBarLayout->addWidget(privateHomePushBtn);


    //!create main window
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(optionListWidget);
    mainLayout->addWidget(choosenTableWidget);
    mainLayout->addWidget(personnalWidget);
}



