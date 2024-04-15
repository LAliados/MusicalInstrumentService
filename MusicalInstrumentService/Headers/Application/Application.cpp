//
// Created by igor on 4/8/24.
//

#include "Application.h"

Application::Application()
{
    loginWindow = new LoginWindow();
    connect(loginWindow, SIGNAL(entered(EnterType)), this, SLOT(openWindow(EnterType)));
    loginWindow->show();
}

void Application::openWindow(EnterType enterType)
{
    loginWindow->close();
    delete loginWindow;
    switch (enterType)
    {
        case EnterType::Admin: adminWindow = new AdminWindow; adminWindow->show(); break;
        case EnterType::User: userWindow = new UserWindow; userWindow->show(); break;
    }
}