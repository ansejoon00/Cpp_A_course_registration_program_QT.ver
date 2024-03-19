#pragma once
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QtWidgets/QMainWindow>

#include "ui_Signup.h"

class Signup : public QDialog
{
    Q_OBJECT

public:
    Signup(QWidget* parent = nullptr);
    ~Signup();

private:
    Ui::Signup* ui;
    QButtonGroup* radioButtonGroup;
    bool signupClicked;

private slots:
    void pushButton_Check();
    void pushButton_Back();
    void pushButton_SignUP();
};

#endif // SIGNUP_H