//
// Created by igor on 4/8/24.
//

#ifndef QTTEST2_LOGINWINDOW_H
#define QTTEST2_LOGINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QDebug>
#include <iostream>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDial>
#include <QList>
#include <QtSql>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QTableWidget>
#include <QTableWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

enum class EnterType
{
    Admin,
    User,
};
class LoginWindow : public QMainWindow {
Q_OBJECT
    QGridLayout* mainLayout;
    QLabel* loginLabel;
    QLabel* passwordLabel;
    QLineEdit* loginLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* enterPushButton;
    QPushButton* registerPushButton;
    QWidget* mainWidget;
public:
    explicit LoginWindow();

public slots:
    void enter();
signals:
    void entered(EnterType enterType);
public:
    ~LoginWindow() override;

};


#endif //QTTEST2_LOGINWINDOW_H
