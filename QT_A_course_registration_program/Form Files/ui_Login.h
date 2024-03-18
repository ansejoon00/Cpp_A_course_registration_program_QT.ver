/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget* centralWidget;
    QGroupBox* groupBox;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QHBoxLayout* horizontalLayout;
    QLineEdit* lineEdit_ID;
    QHBoxLayout* horizontalLayout_2;
    QLineEdit* lineEdit_Password;
    QPushButton* pushButton_Login;
    QWidget* layoutWidget;
    QHBoxLayout* horizontalLayout_1;
    QRadioButton* radioButton_Student;
    QRadioButton* radioButton_Admin;
    QPushButton* pushButton_Exit;
    QPushButton* pushButton_Signup;
    QStatusBar* statusBar;

    void setupUi(QMainWindow* LoginClass)
    {
        if (LoginClass->objectName().isEmpty())
            LoginClass->setObjectName("LoginClass");
        LoginClass->resize(595, 400);
        centralWidget = new QWidget(LoginClass);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(130, 70, 331, 161));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(90, 60, 151, 84));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_ID = new QLineEdit(verticalLayoutWidget);
        lineEdit_ID->setObjectName("lineEdit_ID");

        horizontalLayout->addWidget(lineEdit_ID);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_Password = new QLineEdit(verticalLayoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);

        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_Login = new QPushButton(verticalLayoutWidget);
        pushButton_Login->setObjectName("pushButton_Login");

        verticalLayout->addWidget(pushButton_Login);

        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 31, 171, 22));
        horizontalLayout_1 = new QHBoxLayout(layoutWidget);
        horizontalLayout_1->setSpacing(6);
        horizontalLayout_1->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        radioButton_Student = new QRadioButton(layoutWidget);
        radioButton_Student->setObjectName("radioButton_Student");

        horizontalLayout_1->addWidget(radioButton_Student);

        radioButton_Admin = new QRadioButton(layoutWidget);
        radioButton_Admin->setObjectName("radioButton_Admin");

        horizontalLayout_1->addWidget(radioButton_Admin);

        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName("pushButton_Exit");
        pushButton_Exit->setGeometry(QRect(130, 280, 75, 24));
        pushButton_Signup = new QPushButton(centralWidget);
        pushButton_Signup->setObjectName("pushButton_Signup");
        pushButton_Signup->setGeometry(QRect(390, 280, 75, 24));
        LoginClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LoginClass);
        statusBar->setObjectName("statusBar");
        LoginClass->setStatusBar(statusBar);

        retranslateUi(LoginClass);

        QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QMainWindow* LoginClass)
    {
        LoginClass->setWindowTitle(QCoreApplication::translate("LoginClass", "Login", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginClass", "\353\241\234\352\267\270\354\235\270", nullptr));
        lineEdit_ID->setPlaceholderText(QCoreApplication::translate("LoginClass", "\354\225\204\354\235\264\353\224\224", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("LoginClass", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("LoginClass", "\353\241\234\352\267\270\354\235\270", nullptr));
        radioButton_Student->setText(QCoreApplication::translate("LoginClass", "\355\225\231\354\203\235", nullptr));
        radioButton_Admin->setText(QCoreApplication::translate("LoginClass", "\352\264\200\353\246\254\354\236\220", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("LoginClass", "\354\242\205\353\243\214", nullptr));
        pushButton_Signup->setText(QCoreApplication::translate("LoginClass", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
    } // retranslateUi
};

namespace Ui
{
    class Login : public Ui_Login
    {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
