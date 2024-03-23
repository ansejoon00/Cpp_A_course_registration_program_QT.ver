#pragma once
#ifndef CHANGE_PW_H
#define CHANGE_PW_H

#include <QtWidgets/QMainWindow>
#include <QtSql>

#include "ui_Change_PW.h"

class Change_PW : public QDialog
{
    Q_OBJECT

public:
    Change_PW(QWidget* parent = nullptr);
    ~Change_PW();

private:
    Ui::Change_PW* ui;

private slots:
    void pushButton_cancel();
    void pushButton_change();
};
#endif // SIGNUP_H