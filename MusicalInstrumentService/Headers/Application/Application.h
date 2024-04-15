//
// Created by igor on 4/8/24.
//

#ifndef QTTEST2_APPLICATION_H
#define QTTEST2_APPLICATION_H

#include "../LoginWindow/loginwindow.h"
#include "../AdminWindow/adminwindow.h"
#include "../UserWindow/userwindow.h"


class Application : public QObject{
    Q_OBJECT
    LoginWindow* loginWindow;
    AdminWindow* adminWindow;
    UserWindow* userWindow;

public slots:
    void openWindow(EnterType enterType);
public:
    Application();
};


#endif //QTTEST2_APPLICATION_H
