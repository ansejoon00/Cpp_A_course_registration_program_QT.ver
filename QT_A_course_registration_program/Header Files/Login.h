#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets/QMainWindow>
#include <QtSql>

#include "ui_Login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; };
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget* parent = nullptr);
    ~Login();

    QString getLoggedInUserId() const;

private:
    Ui::Login* ui;
    QButtonGroup* radioButtonGroup;

    QString loggedInUserId;

private slots:
    void pushButton_Signup();
    void pushButton_Login();
    void pushButton_Exit();
};
#endif // LOGIN_H
