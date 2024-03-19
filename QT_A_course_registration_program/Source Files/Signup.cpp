#include <QtWidgets/QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QButtonGroup>

#include "Signup.h"
#include "ui_Signup.h"

extern QSqlDatabase db;

Signup::Signup(QWidget* parent)
    : QDialog(parent), ui(new Ui::Signup())
{
    ui->setupUi(this);

    this->setWindowTitle("회원가입");

    // QButtonGroup 객체 생성
    radioButtonGroup = new QButtonGroup(this);

    // 라디오 버튼들을 그룹에 추가
    radioButtonGroup->addButton(ui->radioButton_Student);
    radioButtonGroup->addButton(ui->radioButton_Admin);

    // 그룹 내에서 하나만 선택할 수 있도록 설정
    radioButtonGroup->setExclusive(true);

    signupClicked = false;

    connect(ui->pushButton_Check, SIGNAL(clicked()), this, SLOT(pushButton_Check()));
    connect(ui->pushButton_Back, SIGNAL(clicked()), this, SLOT(pushButton_Back()));
    connect(ui->pushButton_SignUP, SIGNAL(clicked()), this, SLOT(pushButton_SignUP()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::pushButton_Check()
{
    QString yearString = ui->lineEdit_Year->text();
    int year = yearString.toInt();
    QString codeString = ui->lineEdit_Code->text();

    qDebug() << "Year: " << year << " Code: " << codeString;

    // 선택된 라디오 버튼 확인
    QAbstractButton* selectedRadioButton = radioButtonGroup->checkedButton();

    if (!selectedRadioButton)
    {
        QMessageBox::warning(this, "회원가입", "학생인지 관리자인지 체크해주세요.");
    }

    else
    {
        if (yearString.length() != 4 || QString::number(year) != yearString)
        {
            QMessageBox::warning(this, "회원가입", "년도를 정확하게 입력해주세요(4 자리).");
        }

        else
        {
            // 선택된 라디오 버튼에 따라 다른 인증 코드 계산
            QString authCode;
            if (ui->radioButton_Student->isChecked())
            {
                authCode = yearString + "12345678";
            }
            else if (ui->radioButton_Admin->isChecked())
            {
                authCode = yearString + "87654321";
            }

            qDebug() << "Calculated Auth Code: " << authCode;

            if (codeString.length() == 0)
            {
                QMessageBox::warning(this, "회원가입", "코드를 입력해 주세요.");
            }
            else if (codeString == authCode)
            {
                QMessageBox::information(this, "회원가입", "계속 진행해주세요!");

                ui->radioButton_Student->setEnabled(false); // true가 활성화 / false가 비활성화
                ui->radioButton_Admin->setEnabled(0);
                ui->lineEdit_Year->setEnabled(false);
                ui->lineEdit_Code->setEnabled(0);
                ui->pushButton_Check->setEnabled(false);

                signupClicked = true;
            }
            else
            {
                QMessageBox::warning(this, "회원가입", "코드가 올바르지 않습니다.");
            }
        }
    }
}

void Signup::pushButton_Back()
{
    // 사용자에게 종료 여부 묻기
    QMessageBox::StandardButton reply = QMessageBox::question(this, "뒤로가기", "뒤로 돌아가시겠습니까?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        close();
    }
}

void Signup::pushButton_SignUP()
{
    QSqlQuery query("MYSQL");

    QString year = ui->lineEdit_Year->text();
    QString name = ui->lineEdit_Name->text();
    QString numString = ui->lineEdit_ID->text();
    int num = numString.toInt();
    QString password1 = ui->lineEdit_Password_1->text();
    QString password2 = ui->lineEdit_Password_2->text();
    QString department = ui->lineEdit_Department->text();

    if (year.isEmpty() || name.isEmpty() || numString.isEmpty() || password1.isEmpty() || password2.isEmpty() || department.isEmpty())
    {
        QMessageBox::warning(this, "회원가입", "모든 항목을 입력해주세요.");
    }
    else
    {
        if (!signupClicked)
        {
            QMessageBox::warning(this, "회원가입", "\"확인\" 버튼을 통해 코드를 인증하세요.");
        }
        else if (numString.length() != 4 || QString::number(num) != numString)
        {
            QMessageBox::warning(this, "회원가입", "아이디로 사용될 숫자 4자리를 정확하게 입력해주세요");
        }
        else if (password1 != password2)
        {
            QMessageBox::warning(this, "회원가입", "비밀번호가 일치하지 않습니다.");
        }
        else
        {
            // 데이터베이스에 데이터 삽입

            // 선택된 라디오 버튼에 따라 다른 테이블에 데이터 삽입
            if (ui->radioButton_Student->isChecked())
            {
                query.prepare("INSERT INTO student_table (student_id, username, password, department) "
                    "VALUES (:student_id, :username, :password, :department)");
            }
            else if (ui->radioButton_Admin->isChecked())
            {
                query.prepare("INSERT INTO admin_table (professor_id, username, password, department) "
                    "VALUES (:professor_id, :username, :password, :department)");
            }

            year = year.append("A") + QString::number(num);

            // 바인딩
            query.bindValue(":student_id", year);
            query.bindValue(":professor_id", year);
            query.bindValue(":username", name);
            query.bindValue(":password", password1);
            query.bindValue(":department", department);

            // 쿼리 실행
            if (query.exec())
            {
                QMessageBox::information(this, "회원가입", "회원가입 성공!");
            }
            else
            {
                QMessageBox::warning(this, "회원가입", "Error: " + query.lastError().text());
            }
        }
    }
}