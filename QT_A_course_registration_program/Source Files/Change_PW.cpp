#include <QtWidgets/QMessageBox>
#include <QSqlQuery>
#include <QtSql>

#include "Change_PW.h"
#include "ui_Change_PW.h"

#include "Login.h"

extern QSqlDatabase db;

Change_PW::Change_PW(QWidget* parent)
    : QDialog(parent), ui(new Ui::Change_PW())
{
    ui->setupUi(this);

    this->setWindowTitle("비밀번호 변경");

    connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(pushButton_cancel()));
    connect(ui->pushButton_change, SIGNAL(clicked()), this, SLOT(pushButton_change()));
}

Change_PW::~Change_PW()
{
    delete ui;
}

void Change_PW::pushButton_cancel()
{
    close();
}

void Change_PW::pushButton_change()
{
    QSqlQuery query(db);

    // 사용자의 ID 가져오기
    QString id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

    // 입력된 현재 비밀번호, 새 비밀번호 1, 새 비밀번호 2 가져오기
    QString oldPass = ui->lineEdit_oldPW->text();
    QString newPass1 = ui->lineEdit_newPW1->text();
    QString newPass2 = ui->lineEdit_newPW2->text();

    // 현재 비밀번호를 가져오기 위한 쿼리 준비
    QString getPasswordQuery = "SELECT password FROM student_table WHERE student_id = :id";
    query.prepare(getPasswordQuery);
    query.bindValue(":id", id);

    // 디버깅 메시지 출력: 입력한 값 확인
    qDebug() << "ID: " << id << "OldPass: " << oldPass << "NewPass1: " << newPass1 << "NewPass2: " << newPass2;

    if (query.exec() && query.next())
    {
        QString currentPassword = query.value(0).toString();

        // 현재 비밀번호 확인
        if (currentPassword == oldPass)
        {
            // 새 비밀번호와 새 비밀번호 확인이 일치하는지 확인
            if (newPass1 == newPass2)
            {
                // 비밀번호 변경 쿼리 준비
                QString change_PW_Query = QString("UPDATE student_table SET password = '%1' WHERE student_id = '%2'")
                    .arg(newPass1)
                    .arg(id);

                // 디버깅 메시지 출력: 변경할 비밀번호 쿼리 확인
                qDebug() << "비밀번호 변경 쿼리: " << change_PW_Query;

                // 비밀번호 변경 쿼리 실행
                if (query.exec(change_PW_Query))
                {
                    QMessageBox::information(this, "성공", "비밀번호가 성공적으로 변경되었습니다.");
                    close();
                }
                else
                {
                    qDebug() << "비밀번호 변경 중 오류 발생: " << query.lastError().text();
                    QMessageBox::critical(this, "오류", "비밀번호 변경에 실패했습니다.");
                }
            }
            else
            {
                QMessageBox::critical(this, "경고", "새 비밀번호가 일치하지 않습니다.");
            }
        }
        else
        {
            QMessageBox::critical(this, "경고", "현재 비밀번호가 올바르지 않습니다.");
        }
    }
    else
    {
        qDebug() << "비밀번호 가져오기 중 오류 발생: " << query.lastError().text();
        QMessageBox::critical(this, "오류", "비밀번호 변경에 실패했습니다.");
    }
}