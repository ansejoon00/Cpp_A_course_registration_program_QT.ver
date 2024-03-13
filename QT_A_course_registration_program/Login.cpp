#include <QtWidgets/QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QButtonGroup>

#include "Login.h"
#include "ui_Login.h"

#include "Signup.h"
#include "ui_Signup.h"

#include "Student_Menu.h"
#include "ui_Student_Menu.h"

#include "Admin_Menu.h"
#include "ui_Admin_Menu.h"

extern QSqlDatabase db;

Login::Login(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Login())
{
    ui->setupUi(this);

    // QButtonGroup ��ü ����
    radioButtonGroup = new QButtonGroup(this);

    // ���� ��ư���� �׷쿡 �߰�
    radioButtonGroup->addButton(ui->radioButton_Student);
    radioButtonGroup->addButton(ui->radioButton_Admin);

    // �׷� ������ �ϳ��� ������ �� �ֵ��� ����
    radioButtonGroup->setExclusive(true);

    connect(ui->pushButton_Signup, SIGNAL(clicked()), this, SLOT(pushButton_Signup()));
    connect(ui->pushButton_Login, SIGNAL(clicked()), this, SLOT(pushButton_Login()));
    connect(ui->pushButton_Exit, SIGNAL(clicked()), this, SLOT(pushButton_Exit()));
}


Login::~Login()
{
    delete ui;
}


void Login::pushButton_Signup()
{
    qDebug() << "Signup button clicked!";
    Signup* signup = new Signup(this);
    signup->exec();
}


// void Login::on_pushButton_Login_clicked()
void Login::pushButton_Login()
{
    QAbstractButton* selectedRadioButton = radioButtonGroup->checkedButton();

    QSqlQuery query("MYSQL");

    QString id = ui->lineEdit_ID->text();
    QString password = ui->lineEdit_Password->text();

    qDebug() << "[ ID: " << id << "Password: " << password << " ]";

    if (!selectedRadioButton)
    {
        QMessageBox::warning(this, "SignUP", "Please select either Admin or Student.");
    }
    else
    {
        if (ui->radioButton_Student->isChecked())
        {
            query.prepare("SELECT * FROM student_table WHERE student_id = :id AND password = :password");
        }
        else if (ui->radioButton_Admin->isChecked())
        {
            query.prepare("SELECT * FROM admin_table WHERE professor_id = :id AND password = :password");
        }
        query.bindValue(":id", id);
        query.bindValue(":password", password);

        qDebug() << "Query prepared: " << query.lastQuery();
        qDebug() << "Bound values: " << query.boundValues();

        if (query.exec() && query.next()) {
            qDebug() << "Login successful";
            QMessageBox::information(this, "Login", "Login successful");
            if (ui->radioButton_Student->isChecked())
            {
                qDebug() << "[Student Login!]";
                loggedInUserId = id;
                Student_Menu* student_menu = new Student_Menu(this);
                student_menu->exec();
                this->hide();
            }
            else if (ui->radioButton_Admin->isChecked())
            {
                qDebug() << "[Admin Login!]";
                loggedInUserId = id;
                Admin_Menu* admin_menu = new Admin_Menu(this);
                admin_menu->exec();
                this->hide();
            }
        }
        else {
            qDebug() << "Login failed. Please check your credentials.";
            qDebug() << "Query error:" << query.lastError().text();
            qDebug() << "Query executed: " << query.lastQuery();
            QMessageBox::warning(this, "Login", "Login failed. Please try again.");
        }
    }
}


void Login::pushButton_Exit()
{
    // ����ڿ��� ���� ���� ����
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // ���� ��ư�� ������ �� �����ͺ��̽� ���� ����
        db.close();
        qApp->exit();
    }
}


QString Login::getLoggedInUserId() const
{
    return loggedInUserId;
}