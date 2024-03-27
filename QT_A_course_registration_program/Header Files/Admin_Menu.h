#pragma once
#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>

#include "ui_Admin_Menu.h"

class Admin_Menu : public QDialog
{
    Q_OBJECT

public:
    Admin_Menu(QWidget* parent = nullptr);
    ~Admin_Menu();

private:
    Ui::Admin_Menu* ui;
    QStandardItemModel* allCourseListModel;

private slots:
    void pushButton_Search();
    void pushButton_Add();
    void pushButton_Delete();
    void pushButton_LogOut();
    void pushButton_Exit();
};
#endif // ADMIN_MENU_H