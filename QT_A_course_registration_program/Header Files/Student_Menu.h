#pragma once
#ifndef STUDENT_MENE_H
#define STUDENT_MENE_H

#include <QtWidgets/QMainWindow>
#include <QtSql>
#include <QStandardItemModel>

#include "ui_Student_Menu.h"

class Student_Menu : public QDialog
{
    Q_OBJECT

public:
    Student_Menu(QWidget* parent = nullptr);
    ~Student_Menu();

private:
    Ui::Student_Menu* ui;
    QStandardItemModel* courseListModel;
    QStandardItemModel* enrollListModel;

private slots:
    void pushButton_Search();
    void pushButton_Add();
    void pushButton_Delete();
    void pushButton_ChangePW();
    void pushButton_LogOut();
    void pushButton_Exit();
};
#endif // STUDENT_MENE_H