/********************************************************************************
** Form generated from reading UI file 'Signup.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QPushButton *pushButton_SignUP;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QRadioButton *radioButton_Student;
    QRadioButton *radioButton_Admin;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Year;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Code;
    QPushButton *pushButton_Check;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_Name;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_ID;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_Password_1;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_Password_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_Department;
    QPushButton *pushButton_Back;

    void setupUi(QDialog *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(533, 390);
        pushButton_SignUP = new QPushButton(Signup);
        pushButton_SignUP->setObjectName("pushButton_SignUP");
        pushButton_SignUP->setGeometry(QRect(320, 320, 81, 24));
        verticalLayoutWidget = new QWidget(Signup);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 40, 191, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        radioButton_Student = new QRadioButton(verticalLayoutWidget);
        radioButton_Student->setObjectName("radioButton_Student");

        horizontalLayout_1->addWidget(radioButton_Student);

        radioButton_Admin = new QRadioButton(verticalLayoutWidget);
        radioButton_Admin->setObjectName("radioButton_Admin");

        horizontalLayout_1->addWidget(radioButton_Admin);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_Year = new QLineEdit(verticalLayoutWidget);
        lineEdit_Year->setObjectName("lineEdit_Year");

        horizontalLayout_2->addWidget(lineEdit_Year);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_Code = new QLineEdit(verticalLayoutWidget);
        lineEdit_Code->setObjectName("lineEdit_Code");

        horizontalLayout_3->addWidget(lineEdit_Code);

        pushButton_Check = new QPushButton(verticalLayoutWidget);
        pushButton_Check->setObjectName("pushButton_Check");

        horizontalLayout_3->addWidget(pushButton_Check);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_Name = new QLineEdit(verticalLayoutWidget);
        lineEdit_Name->setObjectName("lineEdit_Name");

        horizontalLayout_4->addWidget(lineEdit_Name);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit_ID = new QLineEdit(verticalLayoutWidget);
        lineEdit_ID->setObjectName("lineEdit_ID");

        horizontalLayout_5->addWidget(lineEdit_ID);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_Password_1 = new QLineEdit(verticalLayoutWidget);
        lineEdit_Password_1->setObjectName("lineEdit_Password_1");
        lineEdit_Password_1->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_Password_1);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lineEdit_Password_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_Password_2->setObjectName("lineEdit_Password_2");
        lineEdit_Password_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(lineEdit_Password_2);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        lineEdit_Department = new QLineEdit(verticalLayoutWidget);
        lineEdit_Department->setObjectName("lineEdit_Department");

        horizontalLayout_8->addWidget(lineEdit_Department);


        verticalLayout->addLayout(horizontalLayout_8);

        pushButton_Back = new QPushButton(Signup);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setGeometry(QRect(130, 320, 81, 24));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QDialog *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Dialog", nullptr));
        pushButton_SignUP->setText(QCoreApplication::translate("Signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        radioButton_Student->setText(QCoreApplication::translate("Signup", "\355\225\231\354\203\235", nullptr));
        radioButton_Admin->setText(QCoreApplication::translate("Signup", "\352\264\200\353\246\254\354\236\220", nullptr));
        lineEdit_Year->setPlaceholderText(QCoreApplication::translate("Signup", "\353\205\204\353\217\204", nullptr));
        lineEdit_Code->setPlaceholderText(QCoreApplication::translate("Signup", "\354\275\224\353\223\234", nullptr));
        pushButton_Check->setText(QCoreApplication::translate("Signup", "\355\231\225\354\235\270", nullptr));
        lineEdit_Name->setPlaceholderText(QCoreApplication::translate("Signup", "\354\235\264\353\246\204(\354\230\201\354\226\264)", nullptr));
        lineEdit_ID->setPlaceholderText(QCoreApplication::translate("Signup", "\354\225\204\354\235\264\353\224\224(\354\210\253\354\236\220 4\352\260\234)", nullptr));
        lineEdit_Password_1->setPlaceholderText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        lineEdit_Password_2->setPlaceholderText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        lineEdit_Department->setPlaceholderText(QCoreApplication::translate("Signup", "\354\240\204\352\263\265(\354\230\201\354\226\264)", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("Signup", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
