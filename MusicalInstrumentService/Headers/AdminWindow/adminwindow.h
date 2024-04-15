//
// Created by igor on 4/8/24.
//

#ifndef QTTEST2_ADMINWINDOW_H
#define QTTEST2_ADMINWINDOW_H

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
#include <QStackedWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow : public QMainWindow {
Q_OBJECT

    QSqlDatabase* database;

    QWidget* mainWidget;
    QGridLayout* mainLayout;
    QPushButton* usersPushButton;
    QPushButton* instrumentsPushButton;
    QVBoxLayout* chooseTableLayout;
    QTableWidget* usersTable;
    QTableWidget* instrumentsTable;
    QWidget* editUserWidget;
    QWidget* editInstrumentWidget;
    QStackedWidget* editStackedWidget;
    QStackedWidget* tableStackedWidget;
    QStackedWidget* deletePushButtonStackedWidget;
    QStackedWidget* editPushButtonStackedWidget;

    enum class editWindow
    {
        User,
        Instrument,

    };
    //editWindow editWindowOpened;



    QGridLayout* editUserLayout;
    QLabel* editUserLoginLabel;
    QLineEdit* editUserLoginLineEdit;
    QLabel* editUserEmailLabel;
    QLineEdit* editUserEmailLineEdit;
    QLabel* editUserNameLabel;
    QLineEdit* editUserNameLineEdit;
    QLabel* editUserPasswordLabel;
    QLineEdit* editUserPasswordLineEdit;
    QLabel* editUserRoleLabel;
    QComboBox* editUserRoleComboBox;
    QPushButton* editUserAddUserPushButton;
    QPushButton* editUserDeleteUserPushButton;
    QPushButton* editUserEditUserPushButton;


    QGridLayout* editInstrumentLayout;
    QLabel* editInstrumentSerialNumberLabel;
    QLineEdit* editInstrumentSerialNumberLineEdit;
    QLabel* editInstrumentModelLabel;
    QComboBox* editInstrumentModelComboBox;
    QLabel* editInstrumentFabricatorLabel;
    QComboBox* editInstrumentFabricatorComboBox;
    QLabel* editInstrumentKindLabel;
    QComboBox* editInstrumentKindComboBox;
    QLabel* editInstrumentClassLabel;
    QComboBox* editInstrumentClassComboBox;
    QLabel* editInstrumentTypeLabel;
    QComboBox* editInstrumentTypeComboBox;
    QPushButton* editInstrumentAddInstrumentPushButton;
    QPushButton* editInstrumentDeleteInstrumentPushButton;
    QPushButton* editInstrumentEditInstrumentPushButton;








public:
    explicit AdminWindow();
protected slots:
    void changeToEditUsers();
    void changeToEditInstruments();

public:
    ~AdminWindow() override;

};


#endif //QTTEST2_ADMINWINDOW_H
