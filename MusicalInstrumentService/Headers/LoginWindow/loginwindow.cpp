//
// Created by igor on 4/8/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginWindow.h" resolved

#include "loginwindow.h"


LoginWindow::LoginWindow()
{
    this->mainLayout = new QGridLayout;
    this->loginLabel = new QLabel("Login or Email");
    this->passwordLabel = new QLabel("Password");
    this->registerPushButton = new QPushButton("Register");
    this->enterPushButton = new QPushButton("Enter");
    this->loginLineEdit = new QLineEdit;
    this->loginLineEdit->setPlaceholderText("Login / email@example.com");
    this->passwordLineEdit = new QLineEdit;
    this->passwordLineEdit->setPlaceholderText("Enter Password...");
    this->passwordLineEdit->setEchoMode(QLineEdit::Password);


    this->mainWidget = new QWidget;
    this->mainWidget->setLayout(this->mainLayout);

    this->mainLayout->addWidget(this->loginLabel,0,0);
    this->mainLayout->addWidget(this->loginLineEdit,0,1);
    this->mainLayout->addWidget(this->passwordLabel,1,0);
    this->mainLayout->addWidget(this->passwordLineEdit,1,1);
    this->mainLayout->addWidget(this->registerPushButton,2,0);
    this->mainLayout->addWidget(this->enterPushButton,2,1);
    this->setCentralWidget(mainWidget);
    connect(enterPushButton,SIGNAL(pressed()),this,SLOT(enter()));
}

LoginWindow::~LoginWindow() {
    delete this->mainLayout;
    delete this->loginLabel;
    delete this->passwordLabel;
    delete this->registerPushButton;
    delete this->enterPushButton;
    delete this->loginLineEdit;
    delete this->passwordLineEdit;
    delete this->mainWidget;
}

void LoginWindow::enter()
{
    if (loginLineEdit->text()=="u")
    emit entered(EnterType::User);
    else
        emit entered(EnterType::Admin);
}
