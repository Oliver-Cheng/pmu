#include "PmuMainPage.h"

PmuMainPage::PmuMainPage(int width, int height)
    : QWidget(){
    this->width = width;
    this->height = height;

    this->initial();
    this->constructMainWidget();
    this->setConnections();
}

PmuMainPage::~PmuMainPage()
{

}

void PmuMainPage::initial(){
    languageWidget = new LanguageWidget();

}

void PmuMainPage::constructMainWidget(){

    this->setStyleSheet("background-color:rgb(135,209,199)");

    //! create seraching bar area
    cityLabel = new QLabel("城市 :");
    cityLabel->setFixedHeight(height*0.05);
    //cityLabel->setAlignment(Qt::AlignCenter);
    cityLabel->setFont(QFont("Segoe UI",17,QFont::Normal,false));
    cityLabel->setStyleSheet("QLabel{background-color:transparent;color:aliceblue; border:0px solid Gray;}");
    citySwitchComoBox = new QComboBox();
    citySwitchComoBox->setStyleSheet("QComboBox{color:gray;background-color:transparent;border:0px solid black;border-radius:5px;padding:1px;}"
                                      //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                      "QComboBox::drop-down{width: 50px;border: 0px;border-color:transparent;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                      "QComboBox::down-arrow{image: url(:/images/down.png);width: 60px; height: 60px;}");
    citySwitchComoBox->setFixedSize(width*0.145,height*0.05);
    citySwitchComoBox->setFont(QFont("Segoe UI",16,QFont::Normal,false));
    citySwitchComoBox->addItem("珠海");
    citySwitchComoBox->addItem("澳門");

    searchingLineEdit = new QLineEdit();
    searchingLineEdit->setFixedSize(width*0.36,height*0.05);
    searchingLineEdit->setStyleSheet("QLineEdit { color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure; } "
                                               "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");
    //searchingLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 5px solid blue;border-radius: 10px;padding: 5px; selection-background-color:Blue;");
    searchingButton = new QPushButton("搜索");
    searchingButton->setFixedHeight(height*0.05);
    searchingLineEdit->setPlaceholderText("輸入个蛋");
    searchingButton->setStyleSheet("QPushButton{background-color:transparent;color:aliceblue;border:0px;}");
    somethingElseButton1 = new QPushButton("購物車");
    somethingElseButton1->setFixedHeight(height*0.05);
    somethingElseButton1->setStyleSheet("QPushButton{background-color:transparent;color:aliceblue;border:0px solid Gray; }");
    titleBar = new QFrame();
    titleBar->setFixedHeight(height*0.08);
    titleBar->setStyleSheet("background-color:transparent");
    searchingBarLayout = new QHBoxLayout(titleBar);
    searchingBarLayout->addWidget(cityLabel);
    searchingBarLayout->addWidget(citySwitchComoBox);
    searchingBarLayout->addWidget(searchingLineEdit);
    searchingBarLayout->addWidget(searchingButton);
    searchingBarLayout->addWidget(somethingElseButton1);
    searchingBarLayout->setSpacing(3);
    searchingBarLayout->setMargin(0);

    //!create list widget


//    optionsWidget->setFixedHeight(height*0.3);

    optionListWidget = new QListView();
    optionListWidget->setFixedHeight(height*0.37);
    //optionListWidget->setMovement(QListView::Static);
    //optionListWidget->setResizeMode(QListView::Fixed);
    optionListWidget->setViewMode(QListView::IconMode);
    optionListWidget->setSpacing(width*0.09);
    optionListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    optionListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    model = new QStandardItemModel();

    optionListWidget->setStyleSheet("background-color:transparent");
    optionListWidget->setViewMode(QListView::IconMode);
    languageItem = new QStandardItem(QIcon(":/images/lala.png"), tr("語言"));
    sportItem = new QStandardItem(QIcon(":/images/lala.png"), tr("運動"));
    informationTechItem = new QStandardItem(QIcon(":/images/lala.png"), tr("IT"));
    danceItem = new QStandardItem(QIcon(":/images/lala.png"), tr("舞蹈"));
    babyeducationItem = new QStandardItem(QIcon(":/images/lala.png"), tr("幼儿"));
    primaryschoolItem = new QStandardItem(QIcon(":/images/lala.png"), tr("小学"));
    middleschoolItem = new QStandardItem(QIcon(":/images/lala.png"), tr("中学"));
    collegeItem =new QStandardItem(QIcon(":/images/lala.png"), tr("大学"));
    mathItem = new QStandardItem(QIcon(":/images/lala.png"), tr("数学"));
    accountingItem = new QStandardItem(QIcon(":/images/lala.png"), tr("会计"));

    model->appendRow(languageItem);
    model->appendRow(sportItem);
    model->appendRow(informationTechItem);
    model->appendRow(danceItem);
    model->appendRow(babyeducationItem);
    model->appendRow(primaryschoolItem);
    model->appendRow(mathItem);
    model->appendRow(accountingItem);

    optionListWidget->setModel(model);
    optionListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    optionListWidget->setFlow(QListWidget::LeftToRight);
    optionListWidget->setLayoutMode(QListView::SinglePass);
    optionListWidget->setIconSize(QSize(width*0.5,height*0.072));
    optionListWidget->setDragEnabled(false);
    optionListWidget->setMovement(QListView::Static);
    optionListWidget->setResizeMode(QListView::Adjust);

    model = new QStandardItemModel();

    //!create tab widget-------------------------------------------------------------------------------
    choosenTableWidget = new QTabWidget();

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

    //!create main window
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(optionListWidget);
    mainLayout->addWidget(choosenTableWidget);
}
void PmuMainPage::setConnections(){

    this->connect(this->optionListWidget,SIGNAL(clicked(QModelIndex)),languageWidget,SLOT(show()));
}
