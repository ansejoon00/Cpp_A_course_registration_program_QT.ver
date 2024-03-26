/********************************************************************************
** Form generated from reading UI file 'Admin_Menu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_MENU_H
#define UI_ADMIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin_Menu
{
public:
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_LogOut;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_1;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_1;
    QLineEdit *lineEdit_course_ID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_course_Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_credits;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_enrollment;
    QPushButton *pushButton_Add;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView_1;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_Search;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(665, 256);
        pushButton_Exit = new QPushButton(Dialog);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setGeometry(QRect(560, 210, 75, 24));
        pushButton_LogOut = new QPushButton(Dialog);
        pushButton_LogOut->setObjectName("pushButton_LogOut");
        pushButton_LogOut->setGeometry(QRect(460, 210, 75, 24));
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 160, 170));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName("label_1");

        horizontalLayout_1->addWidget(label_1);

        lineEdit_course_ID = new QLineEdit(verticalLayoutWidget);
        lineEdit_course_ID->setObjectName("lineEdit_course_ID");

        horizontalLayout_1->addWidget(lineEdit_course_ID);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit_course_Name = new QLineEdit(verticalLayoutWidget);
        lineEdit_course_Name->setObjectName("lineEdit_course_Name");

        horizontalLayout_2->addWidget(lineEdit_course_Name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEdit_credits = new QLineEdit(verticalLayoutWidget);
        lineEdit_credits->setObjectName("lineEdit_credits");

        horizontalLayout_3->addWidget(lineEdit_credits);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        lineEdit_enrollment = new QLineEdit(verticalLayoutWidget);
        lineEdit_enrollment->setObjectName("lineEdit_enrollment");

        horizontalLayout_4->addWidget(lineEdit_enrollment);


        verticalLayout->addLayout(horizontalLayout_4);

        pushButton_Add = new QPushButton(verticalLayoutWidget);
        pushButton_Add->setObjectName("pushButton_Add");

        verticalLayout->addWidget(pushButton_Add);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(190, 20, 451, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tableView_1 = new QTableView(verticalLayoutWidget_2);
        tableView_1->setObjectName("tableView_1");

        verticalLayout_2->addWidget(tableView_1);

        pushButton_Delete = new QPushButton(verticalLayoutWidget_2);
        pushButton_Delete->setObjectName("pushButton_Delete");

        verticalLayout_2->addWidget(pushButton_Delete);

        pushButton_Search = new QPushButton(Dialog);
        pushButton_Search->setObjectName("pushButton_Search");
        pushButton_Search->setGeometry(QRect(30, 210, 75, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Dialog", "\354\242\205\353\243\214", nullptr));
        pushButton_LogOut->setText(QCoreApplication::translate("Dialog", "\353\241\234\352\267\270\354\225\204\354\233\203", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\352\260\225\354\235\230 \352\260\234\354\204\244", nullptr));
        label_1->setText(QCoreApplication::translate("Dialog", "\352\263\274\353\252\251 \354\275\224\353\223\234", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", " \352\263\274\353\252\251 \353\252\205  ", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\354\210\230\352\260\225 \355\225\231\354\240\220", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\354\210\230\352\260\225 \354\235\270\354\233\220", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("Dialog", "\352\260\234\354\204\244", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "< \352\260\234\354\204\244\353\220\234 \352\263\274\353\252\251 >", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("Dialog", "\354\202\255\354\240\234", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("Dialog", "\354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_Menu : public Ui_Admin_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_MENU_H
