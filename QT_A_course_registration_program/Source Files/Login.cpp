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
    : QMainWindow(parent), ui(new Ui::Login())
{
    ui->setupUi(this);

    this->setWindowTitle("로그인");

    // QButtonGroup 객체 생성
    radioButtonGroup = new QButtonGroup(this);

    // 라디오 버튼들을 그룹에 추가
    radioButtonGroup->addButton(ui->radioButton_Student);
    radioButtonGroup->addButton(ui->radioButton_Admin);

    // 그룹 내에서 하나만 선택할 수 있도록 설정
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

void Login::pushButton_Login()
{
    QAbstractButton* selectedRadioButton = radioButtonGroup->checkedButton();

    QSqlQuery query("MYSQL");

    QString id = ui->lineEdit_ID->text();
    QString password = ui->lineEdit_Password->text();

    qDebug() << "[ ID: " << id << "Password: " << password << " ]";

    if (!selectedRadioButton)
    {
        QMessageBox::warning(this, "로그인", "학생인지 관리자인지 체크해주세요.");
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

        if (query.exec() && query.next())
        {
            qDebug() << "Login successful";
            QMessageBox::information(this, "로그인", "로그인 성공!");
            if (ui->radioButton_Student->isChecked())
            {
                qDebug() << "[Student Login!]";
                loggedInUserId = id;
                Student_Menu* student_menu = new Student_Menu(this);
                student_menu->exec();
            }
            else if (ui->radioButton_Admin->isChecked())
            {
                qDebug() << "[Admin Login!]";
                loggedInUserId = id;
                Admin_Menu* admin_menu = new Admin_Menu(this);
                admin_menu->exec();
            }
        }
        else
        {
            qDebug() << "Login failed. Please check your credentials.";
            qDebug() << "Query error:" << query.lastError().text();
            qDebug() << "Query executed: " << query.lastQuery();
            QMessageBox::warning(this, "로그인", "로그인 실패. 다시 시도해 주세요.");
        }
    }
}

void Login::pushButton_Exit()
{
    // 사용자에게 종료 여부 묻기
    QMessageBox::StandardButton reply = QMessageBox::question(this, "종료", "프로그램을 종료하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        // 종료 버튼이 눌렸을 때 데이터베이스 연결 해제
        db.close();
        qApp->exit();
    }
}

QString Login::getLoggedInUserId() const
{
    return loggedInUserId;
}
