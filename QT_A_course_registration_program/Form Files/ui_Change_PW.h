/********************************************************************************
** Form generated from reading UI file 'Change_PW.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_PW_H
#define UI_CHANGE_PW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Change_PW
{
public:
    QLineEdit *lineEdit_oldPW;
    QLineEdit *lineEdit_newPW1;
    QLineEdit *lineEdit_newPW2;
    QPushButton *pushButton_change;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(195, 202);
        lineEdit_oldPW = new QLineEdit(Dialog);
        lineEdit_oldPW->setObjectName("lineEdit_oldPW");
        lineEdit_oldPW->setGeometry(QRect(40, 40, 113, 21));
        lineEdit_oldPW->setEchoMode(QLineEdit::Password);
        lineEdit_newPW1 = new QLineEdit(Dialog);
        lineEdit_newPW1->setObjectName("lineEdit_newPW1");
        lineEdit_newPW1->setGeometry(QRect(40, 70, 113, 21));
        lineEdit_newPW1->setEchoMode(QLineEdit::Password);
        lineEdit_newPW2 = new QLineEdit(Dialog);
        lineEdit_newPW2->setObjectName("lineEdit_newPW2");
        lineEdit_newPW2->setGeometry(QRect(40, 100, 113, 21));
        lineEdit_newPW2->setEchoMode(QLineEdit::Password);
        pushButton_change = new QPushButton(Dialog);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(110, 130, 61, 24));
        pushButton_cancel = new QPushButton(Dialog);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(20, 130, 61, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEdit_oldPW->setPlaceholderText(QCoreApplication::translate("Dialog", "\355\230\204\354\236\254 \353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        lineEdit_newPW1->setPlaceholderText(QCoreApplication::translate("Dialog", "\354\203\210 \353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        lineEdit_newPW2->setPlaceholderText(QCoreApplication::translate("Dialog", "\354\203\210 \353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        pushButton_change->setText(QCoreApplication::translate("Dialog", "\353\263\200\352\262\275", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog", "\354\267\250\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Change_PW : public Ui_Change_PW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_PW_H
