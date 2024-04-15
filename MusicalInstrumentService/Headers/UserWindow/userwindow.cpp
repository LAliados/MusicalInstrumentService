//
// Created by igor on 4/8/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserWindow.h" resolved

#include "userwindow.h"


UserWindow::UserWindow()
{
    this->database = QSqlDatabase::addDatabase("QPSQL","contact_db");
    this->database.setHostName("localhost");
    this->database.setDatabaseName("stringinstruments");
    this->database.setUserName("igor");
    this->database.setPassword("hfccrfpxbrjd!!!");
    this->database.setPort(5432);
    if (!this->database.open())
    {
        qDebug()<< this->database.lastError();

    }
    else
    {
        qDebug()<<"Database connection established!";
    }

    QSqlQuery rightTableStatement("SELECT model.id, model.model model, fabricator.name fabricator, kind.name kind, class.name class, type.name type, model.price FROM (model LEFT JOIN (kind LEFT JOIN (class LEFT JOIN type ON class.typeid = type.id) ON kind.classid = class.id) ON model.kindid = kind.id) LEFT JOIN fabricator ON model.fabricatorid = fabricator.id;",database);
    QSqlRecord record = rightTableStatement.record();
    this->rightTable = new QTableWidget();
    this->rightTable->setColumnCount(6);

    QStringList rightTableHeader;
    rightTableHeader<<"Model"<<"Fabricator"<<"Kind"<<"Class"<<"Type"<<"Price";
    this->rightTable->setHorizontalHeaderLabels(rightTableHeader);
    int rightTableItemCount = rightTableStatement.size();
    this->rightTable->setRowCount(rightTableItemCount);
    for (int i = 0; rightTableStatement.next(); i++)
    {

        this->rightTable->setItem(i,0,new QTableWidgetItem(rightTableStatement.value(record.indexOf("model")).toString()));
        this->rightTable->setItem(i,1,new QTableWidgetItem(rightTableStatement.value(record.indexOf("fabricator")).toString()));
        this->rightTable->setItem(i,2,new QTableWidgetItem(rightTableStatement.value(record.indexOf("kind")).toString()));
        this->rightTable->setItem(i,3,new QTableWidgetItem(rightTableStatement.value(record.indexOf("class")).toString()));
        this->rightTable->setItem(i,4,new QTableWidgetItem(rightTableStatement.value(record.indexOf("type")).toString()));
        this->rightTable->setItem(i,5,new QTableWidgetItem(rightTableStatement.value(record.indexOf("price")).toString()));

    }
    rightTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    rightTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    rightTable->resizeColumnsToContents();
    rightTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    rightTable->setSelectionMode(QAbstractItemView::SingleSelection);
    rightTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    rightTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    this->mainLayout = new QGridLayout();

    this->leftLayout = new QGridLayout();


    //scrollArea->setLayout(rightLayout);
    this->mainLayout->addLayout(this->leftLayout, 0,0);
    this->mainLayout->addWidget(this->rightTable, 0,1);

    //LEFT LAYOUT***
    QLabel* modelLabel = new QLabel("Model:");
    this->leftLayout->addWidget(modelLabel,4,0);
    this->modelBox = new QComboBox();
    this->leftLayout->addWidget(this->modelBox,4,1);
    QList<QString> modelStrings;
    {
        QSqlQuery modelQuery ("SELECT * FROM model ORDER BY model.id ASC",this->database);
        record = modelQuery.record();
        for (int i = 0; modelQuery.next(); i++) {
            modelStrings.push_back(modelQuery.value(record.indexOf("model")).toString());
        }
        modelBox->addItems(modelStrings);
    }

    QLabel* fabricatorLabel = new QLabel("Fabricator:");
    this->leftLayout->addWidget(fabricatorLabel,3,0);
    this->fabricatorBox = new QComboBox();
    this->leftLayout->addWidget(this->fabricatorBox,3,1);
    QList<QString> fabricatorStrings;
    {
        QSqlQuery fabricatorQuery("SELECT * FROM fabricator ORDER BY fabricator.id ASC",this->database);
        record = fabricatorQuery.record();
        for (int i = 0; fabricatorQuery.next(); i++) {
            fabricatorStrings.push_back(fabricatorQuery.value(record.indexOf("name")).toString());
        }
        this->fabricatorBox->addItems(fabricatorStrings);
    }

    QLabel* kindLabel = new QLabel("Kind:");
    this->leftLayout->addWidget(kindLabel,2,0);
    this->kindBox = new QComboBox();
    this->leftLayout->addWidget(this->kindBox,2,1);
    QList<QString> kindStrings;
    {
        QSqlQuery kindQuery("SELECT * FROM kind ORDER BY kind.id ASC",this->database);
        record = kindQuery.record();
        for (int i = 0; kindQuery.next(); i++) {
            kindStrings.push_back(kindQuery.value(record.indexOf("name")).toString());
        }
        this->kindBox->addItems(kindStrings);
    }

    QLabel* classLabel = new QLabel("Class:");
    this->leftLayout->addWidget(classLabel,1,0);
    this->classBox = new QComboBox();
    this->leftLayout->addWidget(this->classBox,1,1);
    QList<QString> classStrings;
    {
        QSqlQuery classQuery("SELECT * FROM class ORDER BY class.id ASC",this->database);
        record = classQuery.record();
        for (int i = 0; classQuery.next(); i++) {
            classStrings.push_back(classQuery.value(record.indexOf("name")).toString());
        }
        this->classBox->addItems(classStrings);
    }

    QLabel* typeLabel = new QLabel("Type:");
    this->leftLayout->addWidget(typeLabel,0,0);
    this->typeBox = new QComboBox();
    this->leftLayout->addWidget(this->typeBox, 0,1);
    QList<QString> typeStrings;
    {
        QSqlQuery typeQuery("SELECT * FROM type ORDER BY type.id ASC",this->database);
        record = typeQuery.record();
        for (int i = 0; typeQuery.next(); i++) {
            typeStrings.push_back(typeQuery.value(record.indexOf("name")).toString());
        }
        this->typeBox->addItems(typeStrings);
    }


    QLabel* priceLabel = new QLabel("Price:");
    this->leftLayout->addWidget(priceLabel,5,0);
    this->priceWidget = new QWidget();
    this->priceLayout = new QGridLayout();
    this->priceWidget->setLayout(this->priceLayout);
    this->leftPriceLineEdit = new QLineEdit();
    this->rightPriceLineEdit = new QLineEdit();
    this->priceLayout->addWidget(this->leftPriceLineEdit,0,0);
    this->priceLayout->addWidget(this->rightPriceLineEdit,0,1);
    this->leftLayout->addWidget(this->priceWidget, 5,1);


    this->okFilterPushButton = new QPushButton();
    this->okFilterPushButton->setText("Apply filters");
    this->leftLayout->addWidget(this->okFilterPushButton, 6,1);


    this->leftLayout->addWidget(new QLabel, 7,0);

    this->buyPushButton = new QPushButton();
    this->buyPushButton->setText("Buy");
    this->leftLayout->addWidget(this->buyPushButton, 8,1);
    //LEFT LAYOUT


    //RIGHT LAYOUT***

    //RIGHT LAYOUT

    this->mainWidget = new QWidget;
    this->mainWidget->setLayout(this->mainLayout);
    this->setCentralWidget(mainWidget);
}

UserWindow::~UserWindow() {

}
