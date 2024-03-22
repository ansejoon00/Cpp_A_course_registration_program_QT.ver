/********************************************************************************
** Form generated from reading UI file 'Student_Menu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_MENU_H
#define UI_STUDENT_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Student_Menu
{
public:
    QPushButton *pushButton_LogOut;
    QPushButton *pushButton_Exit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_Change;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_1;
    QHBoxLayout *horizontalLayout_1;
    QSpacerItem *horizontalSpacer_1;
    QLabel *label_1;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView_1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Search;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(658, 446);
        pushButton_LogOut = new QPushButton(Dialog);
        pushButton_LogOut->setObjectName("pushButton_LogOut");
        pushButton_LogOut->setGeometry(QRect(470, 410, 75, 24));
        pushButton_Exit = new QPushButton(Dialog);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setGeometry(QRect(570, 410, 75, 21));
        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 200, 641, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tableView_2 = new QTableView(verticalLayoutWidget_2);
        tableView_2->setObjectName("tableView_2");

        verticalLayout_2->addWidget(tableView_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_Delete = new QPushButton(verticalLayoutWidget_2);
        pushButton_Delete->setObjectName("pushButton_Delete");

        horizontalLayout_4->addWidget(pushButton_Delete);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pushButton_Change = new QPushButton(Dialog);
        pushButton_Change->setObjectName("pushButton_Change");
        pushButton_Change->setGeometry(QRect(20, 410, 111, 24));
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 639, 171));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setObjectName("verticalLayout_1");
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_1);

        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName("label_1");

        horizontalLayout_1->addWidget(label_1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_2);


        verticalLayout_1->addLayout(horizontalLayout_1);

        tableView_1 = new QTableView(verticalLayoutWidget);
        tableView_1->setObjectName("tableView_1");

        verticalLayout_1->addWidget(tableView_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_Add = new QPushButton(verticalLayoutWidget);
        pushButton_Add->setObjectName("pushButton_Add");

        horizontalLayout_2->addWidget(pushButton_Add);


        verticalLayout_1->addLayout(horizontalLayout_2);

        pushButton_Search = new QPushButton(Dialog);
        pushButton_Search->setObjectName("pushButton_Search");
        pushButton_Search->setGeometry(QRect(20, 380, 111, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_LogOut->setText(QCoreApplication::translate("Dialog", "\353\241\234\352\267\270\354\225\204\354\233\203", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Dialog", "\354\242\205\353\243\214", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "< \355\230\204\354\236\254 \354\210\230\352\260\225\354\213\240\354\262\255\355\225\234 \353\252\251\353\241\235 >", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("Dialog", "\354\202\255\354\240\234", nullptr));
        pushButton_Change->setText(QCoreApplication::translate("Dialog", "\353\271\204\353\260\200\353\262\210\355\230\270 \353\263\200\352\262\275", nullptr));
        label_1->setText(QCoreApplication::translate("Dialog", "< \355\230\204\354\236\254 \354\210\230\352\260\225\354\213\240\354\262\255 \352\260\200\353\212\245\355\225\234 \353\252\251\353\241\235 >", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("Dialog", "\354\266\224\352\260\200", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("Dialog", "\354\241\260\355\232\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_Menu : public Ui_Student_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_MENU_H
