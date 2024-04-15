//
// Created by igor on 4/8/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminWindow.h" resolved

#include "adminwindow.h"


AdminWindow::AdminWindow()
{




    this->database = new QSqlDatabase;
    *this->database = QSqlDatabase::addDatabase("QPSQL","contact_db");
    this->database->setHostName("localhost");
    this->database->setDatabaseName("stringinstruments");
    this->database->setUserName("igor");
    this->database->setPassword("hfccrfpxbrjd!!!");
    this->database->setPort(5432);
    if (!this->database->open())
    {
        qDebug()<< this->database->lastError();

    }
    else
    {
        qDebug()<<"Database connection established!";
    }



    this->mainWidget = new QWidget;
    this->mainLayout = new QGridLayout;
    this->setCentralWidget(this->mainWidget);
    this->mainWidget->setLayout(this->mainLayout);
    this->usersPushButton = new QPushButton("Users");
    this->instrumentsPushButton = new QPushButton("Instruments");
    this->chooseTableLayout = new QVBoxLayout;
    this->chooseTableLayout->addWidget(this->usersPushButton);
    this->chooseTableLayout->addWidget(this->instrumentsPushButton);
    this->mainLayout->addLayout(this->chooseTableLayout,0,0);

    this->usersTable = new QTableWidget;
    this->usersTable->setColumnCount(5);
    QStringList usersTableHeader = {"Login","Email","Name","Password","Role"};
    this->usersTable->setHorizontalHeaderLabels(usersTableHeader);

    this->editUserLayout = new QGridLayout;
    this->editUserLoginLabel = new QLabel("Login");
    this->editUserLoginLineEdit = new QLineEdit;
    this->editUserEmailLabel = new QLabel("Email");
    this->editUserEmailLineEdit = new QLineEdit;
    this->editUserNameLabel = new QLabel("Name");
    this->editUserNameLineEdit = new QLineEdit;
    this->editUserPasswordLabel = new QLabel("Password");
    this->editUserPasswordLineEdit = new QLineEdit;
    this->editUserRoleLabel = new QLabel("Role");
    this->editUserRoleComboBox = new QComboBox;
    this->editUserAddUserPushButton = new QPushButton("Add user");
    this->editUserDeleteUserPushButton = new QPushButton("Delete user");
    this->editUserEditUserPushButton = new QPushButton("Edit user");

    this->editUserLayout->addWidget(this->editUserLoginLabel,0,0);
    this->editUserLayout->addWidget(this->editUserLoginLineEdit,1,0);
    this->editUserLayout->addWidget(this->editUserEmailLabel,0,1);
    this->editUserLayout->addWidget(this->editUserEmailLineEdit,1,1);
    this->editUserLayout->addWidget(this->editUserNameLabel,0,2);
    this->editUserLayout->addWidget(this->editUserNameLineEdit,1,2);
    this->editUserLayout->addWidget(this->editUserPasswordLabel,0,3);
    this->editUserLayout->addWidget(this->editUserPasswordLineEdit,1,3);
    this->editUserLayout->addWidget(this->editUserRoleLabel,0,4);
    this->editUserLayout->addWidget(this->editUserRoleComboBox,1,4);
    this->editUserLayout->addWidget(this->editUserAddUserPushButton,2,4);

    //this->usersTableLayout = new QGridLayout;
    //this->usersTableLayout->addWidget(usersTable);

    connect(this->usersPushButton, SIGNAL(pressed()),this,SLOT(changeToEditUsers()));
    connect(this->instrumentsPushButton,SIGNAL(pressed()),this,SLOT(changeToEditInstruments()));


    this->instrumentsTable = new QTableWidget;
    this->instrumentsTable->setColumnCount(6);
    QStringList instrumentsTableHeader;
    instrumentsTableHeader<<"SerialNumber"<<"Model"<<"Fabricator"<<"Kind"<<"Class"<<"Type"<<"Price";
    this->instrumentsTable->setHorizontalHeaderLabels(instrumentsTableHeader);

    this->editInstrumentLayout = new QGridLayout;
    this->editInstrumentModelLabel = new QLabel("Model");
    this->editInstrumentModelComboBox = new QComboBox;
    this->editInstrumentFabricatorLabel = new QLabel("Fabricator");
    this->editInstrumentFabricatorComboBox = new QComboBox;
    this->editInstrumentKindLabel = new QLabel("Kind");
    this->editInstrumentKindComboBox = new QComboBox;
    this->editInstrumentClassLabel = new QLabel("Class");
    this->editInstrumentClassComboBox = new QComboBox;
    this->editInstrumentTypeLabel = new QLabel("Type");
    this->editInstrumentTypeComboBox = new QComboBox;
    this->editInstrumentSerialNumberLabel = new QLabel("Serial number");
    this->editInstrumentSerialNumberLineEdit = new QLineEdit;
    this->editInstrumentAddInstrumentPushButton = new QPushButton("Add instrument");
    this->editInstrumentDeleteInstrumentPushButton = new QPushButton("Delete instrument");
    this->editInstrumentEditInstrumentPushButton = new QPushButton("Edit instrument");

    this->editInstrumentLayout->addWidget(this->editInstrumentSerialNumberLabel,0,0);
    this->editInstrumentLayout->addWidget(this->editInstrumentSerialNumberLineEdit,1,0);
    this->editInstrumentLayout->addWidget(this->editInstrumentTypeLabel,0,1);
    this->editInstrumentLayout->addWidget(this->editInstrumentTypeComboBox,1,1);
    this->editInstrumentLayout->addWidget(this->editInstrumentClassLabel,0,2);
    this->editInstrumentLayout->addWidget(this->editInstrumentClassComboBox,1,2);
    this->editInstrumentLayout->addWidget(this->editInstrumentKindLabel,0,3);
    this->editInstrumentLayout->addWidget(this->editInstrumentKindComboBox,1,3);
    this->editInstrumentLayout->addWidget(this->editInstrumentFabricatorLabel, 0,4);
    this->editInstrumentLayout->addWidget(this->editInstrumentFabricatorComboBox,1,4);
    this->editInstrumentLayout->addWidget(this->editInstrumentModelLabel,0,5);
    this->editInstrumentLayout->addWidget(this->editInstrumentModelComboBox,1,5);
    this->editInstrumentLayout->addWidget(this->editInstrumentAddInstrumentPushButton,2,5);


    this->editUserWidget = new QWidget;
    this->editInstrumentWidget = new QWidget;
    this->editUserWidget->setLayout(this->editUserLayout);
    this->editInstrumentWidget->setLayout(this->editInstrumentLayout);
    //this->tableWidget = new QWidget;
    //this->instrumentsTableLayout = new QGridLayout;
    //this->instrumentsTableLayout->addWidget(instrumentsTable);



    this->editStackedWidget = new QStackedWidget;
    this->tableStackedWidget = new QStackedWidget;
    this->deletePushButtonStackedWidget = new QStackedWidget;
    this->editPushButtonStackedWidget = new QStackedWidget;
    this->tableStackedWidget->addWidget(this->usersTable);
    this->tableStackedWidget->addWidget(this->instrumentsTable);
    this->editStackedWidget->addWidget(this->editInstrumentWidget);
    this->editStackedWidget->addWidget(this->editUserWidget);
    this->deletePushButtonStackedWidget->addWidget(this->editUserDeleteUserPushButton);
    this->deletePushButtonStackedWidget->addWidget(this->editInstrumentDeleteInstrumentPushButton);
    this->editPushButtonStackedWidget->addWidget(this->editUserEditUserPushButton);
    this->editPushButtonStackedWidget->addWidget(this->editInstrumentEditInstrumentPushButton);


    this->mainLayout->addWidget(this->tableStackedWidget,0,1);
    this->mainLayout->addWidget(this->editPushButtonStackedWidget,1,1);
    this->mainLayout->addWidget(this->deletePushButtonStackedWidget,2,1);
    this->mainLayout->addWidget(this->editStackedWidget,3,1);

    this->tableStackedWidget->setCurrentWidget(this->usersTable);
    this->editStackedWidget->setCurrentWidget(this->editUserWidget);
    this->editPushButtonStackedWidget->setCurrentWidget(this->editUserEditUserPushButton);
    this->deletePushButtonStackedWidget->setCurrentWidget(this->editUserDeleteUserPushButton);
}

void AdminWindow::changeToEditUsers()
{
    QSqlQuery statement("SELECT userdata.login login, userdata.email email, userdata.name name, userdata.passwordhash passwordhash, role.name role  FROM userdata left join role on userdata.roleid = role.id ORDER BY userdata.id ASC;",*database);
    QSqlRecord record = statement.record();
    this->usersTable->setRowCount(statement.size());

    for (int i = 0; statement.next(); i++)
    {

        this->usersTable->setItem(i,0,new QTableWidgetItem(statement.value(record.indexOf("login")).toString()));
        this->usersTable->setItem(i,1,new QTableWidgetItem(statement.value(record.indexOf("email")).toString()));
        this->usersTable->setItem(i,2,new QTableWidgetItem(statement.value(record.indexOf("name")).toString()));
        this->usersTable->setItem(i,3,new QTableWidgetItem(statement.value(record.indexOf("passwordhash")).toString()));
        this->usersTable->setItem(i,4,new QTableWidgetItem(statement.value(record.indexOf("role")).toString()));

    }
    this->usersTable->resizeColumnsToContents();
    this->usersTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);


    this->tableStackedWidget->setCurrentWidget(this->usersTable);
    this->editStackedWidget->setCurrentWidget(this->editUserWidget);
    this->deletePushButtonStackedWidget->setCurrentWidget(this->editUserDeleteUserPushButton);
    this->editPushButtonStackedWidget->setCurrentWidget(this->editUserEditUserPushButton);

}
void AdminWindow::changeToEditInstruments()
{

    this->tableStackedWidget->setCurrentWidget(this->instrumentsTable);
    this->editStackedWidget->setCurrentWidget(this->editInstrumentWidget);
    this->deletePushButtonStackedWidget->setCurrentWidget(this->editInstrumentDeleteInstrumentPushButton);
    this->editPushButtonStackedWidget->setCurrentWidget(this->editInstrumentEditInstrumentPushButton);
}

AdminWindow::~AdminWindow() {
}
