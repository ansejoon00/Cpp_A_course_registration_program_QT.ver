#include <QtWidgets/QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QStandardItemModel>

#include "Student_Menu.h"
#include "ui_Student_Menu.h"

#include "Login.h"

#include "Change_PW.h"
#include "ui_Change_PW.h"

extern QSqlDatabase db;

Student_Menu::Student_Menu(QWidget* parent)
    : QDialog(parent), ui(new Ui::Student_Menu())
{
    ui->setupUi(this);

    this->setWindowTitle("학생 메뉴");

    // ListView에 사용할 모델 초기화
    courseListModel = new QStandardItemModel(this);
    ui->listView_1->setModel(courseListModel);

    enrollListModel = new QStandardItemModel(this);
    ui->listView_2->setModel(enrollListModel);

    connect(ui->pushButton_Search, SIGNAL(clicked()), this, SLOT(pushButton_Search()));
    connect(ui->pushButton_Add, SIGNAL(clicked()), this, SLOT(pushButton_Add()));
    connect(ui->pushButton_Delete, SIGNAL(clicked()), this, SLOT(pushButton_Delete()));
    connect(ui->pushButton_Change, SIGNAL(clicked()), this, SLOT(pushButton_ChangePW()));
    connect(ui->pushButton_LogOut, SIGNAL(clicked()), this, SLOT(pushButton_LogOut()));
    connect(ui->pushButton_Exit, SIGNAL(clicked()), this, SLOT(pushButton_Exit()));
}

Student_Menu::~Student_Menu()
{
    delete ui;
}

void Student_Menu::pushButton_Search()
{
    QSqlQuery query(db);

    QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

    QString all_Courses_Query = QString("SELECT * FROM course_table WHERE course_id NOT IN (SELECT course_id FROM enroll_table WHERE student_id = '%1')")
        .arg(student_Id);

    if (query.exec(all_Courses_Query))
    {
        // 결과가 있는 경우
        if (query.size() > 0)
        {
            qDebug() << "[ 현재 개설된 모든 강의 목록 ]";

            // 모든 강의 정보 출력 및 모델에 추가
            courseListModel->clear();
            while (query.next())
            {
                QString course_Id = query.value(0).toString();
                QString course_Name = query.value(1).toString();
                int credits = query.value(2).toInt();
                int enrollment = query.value(3).toInt();

                qDebug() << "강의 코드: " << course_Id << "\t, 강의 이름: " << course_Name << "\t, 학점: " << credits << "\t, 등록 인원: " << enrollment;

                // 모델에 강의 정보 추가
                QStandardItem* item = new QStandardItem(QString("강의 코드: %1, 강의 이름: %2, 학점: %3, 등록 인원: %4")
                    .arg(course_Id)
                    .arg(course_Name)
                    .arg(credits)
                    .arg(enrollment));
                courseListModel->appendRow(item);
            }
        }
        else
        {
            qDebug() << "< 현재 개설된 강의가 없거나 모든 강의를 이미 신청했습니다. >";
            courseListModel->clear();
        }
    }
    else
    {
        qDebug() << "!!! 강의 목록을 조회하는 데 실패했습니다. 오류: " << query.lastError().text();
    }

    QString student_Enroll_Query = QString("SELECT * FROM enroll_table WHERE student_id = '%1'")
        .arg(student_Id);

    if (query.exec(student_Enroll_Query))
    {
        // 결과가 있는 경우
        if (query.size() > 0)
        {
            qDebug() << "[ 현재 신청된 모든 강의 목록 ]";

            // 신청된 강의 정보 출력 및 모델에 추가
            enrollListModel->clear();
            while (query.next())
            {
                QString enroll_Code = query.value(1).toString();

                // 강의 정보를 가져오는 쿼리 실행
                QString studnet_Enroll_Search_Query = QString("SELECT * FROM course_table WHERE course_id = '%1'")
                    .arg(enroll_Code);

                QSqlQuery courseQuery(db);
                if (courseQuery.exec(studnet_Enroll_Search_Query) && courseQuery.size() > 0)
                {
                    courseQuery.next();
                    QString course_Id = courseQuery.value(0).toString();
                    QString course_Name = courseQuery.value(1).toString();
                    int credits = courseQuery.value(2).toInt();
                    int enrollment = courseQuery.value(3).toInt();

                    qDebug() << "강의 코드: " << course_Id << "\t, 강의 이름: " << course_Name << "\t, 학점: " << credits << "\t, 등록 인원: " << enrollment;

                    // 모델에 강의 정보 추가
                    QStandardItem* item = new QStandardItem(QString("강의 코드: %1, 강의 이름: %2, 학점: %3, 등록 인원: %4")
                        .arg(course_Id)
                        .arg(course_Name)
                        .arg(credits)
                        .arg(enrollment));
                    enrollListModel->appendRow(item);
                }
            }
        }
        else
        {
            qDebug() << "< 현재 신청된 강의가 없습니다. >";
            enrollListModel->clear();
        }
    }
    else
    {
        qDebug() << "!!! 강의 목록을 조회하는 데 실패했습니다. 오류: " << query.lastError().text();
    }
}

void Student_Menu::pushButton_Add()
{
    // 현재 선택된 강의의 정보를 가져오기
    QModelIndex selected_Index = ui->listView_1->currentIndex();
    if (selected_Index.isValid())
    {
        QString selected_Course_Info = selected_Index.data().toString();
        qDebug() << "Selected Course: " << selected_Course_Info;

        // 수강신청 로직: 선택한 강의를 학생의 수강 목록에 추가
        QSqlQuery query(db);

        QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

        // 강의 정보에서 강의 코드를 추출
        QStringList course_InfoParts = selected_Course_Info.split(", ");
        QString course_CodePart = course_InfoParts[0];
        QString course_Id = course_CodePart.mid(7);

        // 이미 수강 중인지 확인
        QString check_Existing_Query = QString("SELECT * FROM enroll_table WHERE student_id = '%1' AND course_id = '%2'")
            .arg(student_Id)
            .arg(course_Id);

        qDebug() << check_Existing_Query;

        if (query.exec(check_Existing_Query))
        {
            if (query.size() > 0)
            {
                // 이미 수강 중인 강의인 경우
                QMessageBox::warning(this, "알림", "이미 수강 중인 강의입니다.");
            }
            else
            {
                // 새로운 강의를 수강 목록에 추가
                QString add_Course_To_Student_Query = QString("INSERT INTO enroll_table (student_id, course_id) VALUES ('%1', '%2')")
                    .arg(student_Id)
                    .arg(course_Id);

                if (query.exec(add_Course_To_Student_Query))
                {
                    QMessageBox::information(this, "알림", "강의가 성공적으로 수강 신청되었습니다.");
                    pushButton_Search();
                }
                else
                {
                    qDebug() << "!!! 강의 수강 신청 중 오류가 발생했습니다. 에러 메시지: " << query.lastError().text();
                    QMessageBox::critical(this, "에러", "강의 수강 신청 중 오류가 발생했습니다.");
                }
            }
        }
        else
        {
            qDebug() << "!!! 이미 수강 중인 강의를 확인하는 데 실패했습니다. 오류: " << query.lastError().text();
        }
    }
    else
    {
        QMessageBox::warning(this, "알림", "수강 신청할 강의를 선택하세요.");
    }
}

void Student_Menu::pushButton_Delete()
{
    // 현재 선택된 강의의 정보를 가져오기
    QModelIndex selected_Index = ui->listView_2->currentIndex();
    if (selected_Index.isValid())
    {
        QString selected_Course_Info = selected_Index.data().toString();
        qDebug() << "Selected Course: " << selected_Course_Info;

        // 수강신청 로직: 선택한 강의를 학생의 수강 목록에 추가
        QSqlQuery query(db);

        QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

        // 강의 정보에서 강의 코드를 추출
        QStringList course_InfoParts = selected_Course_Info.split(", ");
        QString course_CodePart = course_InfoParts[0];
        QString course_Id = course_CodePart.mid(7);

        // 이미 수강 중인지 확인
        QString check_Existing_Query = QString("DELETE FROM enroll_table WHERE student_id = '%1' AND course_id = '%2'")
            .arg(student_Id)
            .arg(course_Id);

        qDebug() << check_Existing_Query;

        if (query.exec(check_Existing_Query))
        {
            QMessageBox::information(this, "알림", "강의가 성공적으로 삭제되었습니다.");
            pushButton_Search();
        }

    }
    else 
    {
        QMessageBox::warning(this, "알림", "수강 신청 취소할 강의를 선택하세요.");
    }
}

void Student_Menu::pushButton_ChangePW()
{
    qDebug() << "ChangePW button clicked!";
    Change_PW* change_pw = new Change_PW(this);
    change_pw->exec();
}

void Student_Menu::pushButton_LogOut()
{
    // 사용자에게 로그아웃 여부 묻기
    QMessageBox::StandardButton reply = QMessageBox::question(this, "로그아웃", "로그아웃 하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        close();
    }
}

void Student_Menu::pushButton_Exit()
{
    // 사용자에게 종료 여부 묻기
    QMessageBox::StandardButton reply = QMessageBox::question(this, "종료", "프로그램을 종료하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        db.close();
        qApp->exit();
    }
}
