//
// Created by igor on 4/8/24.
//

#ifndef QTTEST2_USERWINDOW_H
#define QTTEST2_USERWINDOW_H

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
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QMainWindow {
Q_OBJECT

    QSqlDatabase database;

    QWidget* mainWidget;

    QTableWidget* rightTable;
    QGridLayout* mainLayout;
    QGridLayout* leftLayout;

    QComboBox* modelBox;
    QComboBox* fabricatorBox;
    QComboBox* kindBox;
    QComboBox* classBox;
    QComboBox* typeBox;

    QComboBox* priceBox;
    QWidget* priceWidget;
    QGridLayout* priceLayout;
    QLineEdit* leftPriceLineEdit;
    QLineEdit* rightPriceLineEdit;

    QPushButton* okFilterPushButton;
    QPushButton* buyPushButton;

public:
    explicit UserWindow();

    ~UserWindow() override;


};


#endif //QTTEST2_USERWINDOW_H
