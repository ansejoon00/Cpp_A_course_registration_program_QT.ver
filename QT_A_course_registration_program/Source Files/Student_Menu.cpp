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

    // TableView에 사용할 모델 초기화
    courseListModel = new QStandardItemModel(this);
    ui->tableView_1->setModel(courseListModel);

    // 각 열의 헤더 라벨 설정
    courseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");

    enrollListModel = new QStandardItemModel(this);
    ui->tableView_2->setModel(enrollListModel);

    enrollListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");

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
    QSqlQuery DB_Course_Query(db);
    QSqlQuery DB_Enroll_Query(db);

    QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

    QString course_Query = QString("SELECT * FROM course_table WHERE course_id NOT IN (SELECT course_id FROM enroll_table WHERE student_id = '%1')")
        .arg(student_Id);

    if (DB_Course_Query.exec(course_Query))
    {
        // 결과가 있는 경우
        if (DB_Course_Query.size() > 0)
        {
            qDebug() << "[ 현재 개설된 모든 강의 목록 ]";

            // 모든 강의 정보 출력 및 모델에 추가
            courseListModel->clear();
            courseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");

            while (DB_Course_Query.next())
            {
                QString course_ID = DB_Course_Query.value(0).toString();
                QString course_Name = DB_Course_Query.value(1).toString();
                int credits = DB_Course_Query.value(2).toInt();
                int enrollment = DB_Course_Query.value(3).toInt();

                qDebug() << "강의 코드: " << course_ID << "\t, 강의 이름: " << course_Name << "\t, 학점: " << credits << "\t, 등록 인원: " << enrollment;

                // 모델에 강의 정보 추가
                QList<QStandardItem*> course_Items;
                course_Items.append(new QStandardItem(course_ID));
                course_Items.append(new QStandardItem(course_Name));
                course_Items.append(new QStandardItem(QString::number(credits)));
                course_Items.append(new QStandardItem(QString::number(enrollment)));
                courseListModel->appendRow(course_Items);
            }
        }
        else
        {
            qDebug() << "< 현재 개설된 강의가 없거나 모든 강의를 이미 신청했습니다. >";
            courseListModel->clear();
            courseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");
        }
    }
    else
    {
        qDebug() << "!!! 강의 목록을 조회하는 데 실패했습니다. 오류: " << DB_Course_Query.lastError().text();
    }

    QString enroll_Query = QString("SELECT * FROM enroll_table WHERE student_id = '%1'")
        .arg(student_Id);

    if (DB_Course_Query.exec(enroll_Query))
    {
        // 결과가 있는 경우
        if (DB_Course_Query.size() > 0)
        {
            qDebug() << "[ 현재 신청된 모든 강의 목록 ]";

            // 신청된 강의 정보 출력 및 모델에 추가
            enrollListModel->clear();
            enrollListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");

            while (DB_Course_Query.next())
            {
                QString enroll_Code = DB_Course_Query.value(1).toString();

                // 강의 정보를 가져오는 쿼리 실행
                QString enroll_Search_Query = QString("SELECT * FROM course_table WHERE course_id = '%1'")
                    .arg(enroll_Code);

                if (DB_Enroll_Query.exec(enroll_Search_Query) && DB_Enroll_Query.size() > 0)
                {
                    DB_Enroll_Query.next();
                    QString course_ID = DB_Enroll_Query.value(0).toString();
                    QString course_Name = DB_Enroll_Query.value(1).toString();
                    int credits = DB_Enroll_Query.value(2).toInt();
                    int enrollment = DB_Enroll_Query.value(3).toInt();

                    qDebug() << "강의 코드: " << course_ID << "\t, 강의 이름: " << course_Name << "\t, 학점: " << credits << "\t, 등록 인원: " << enrollment;

                    // 모델에 강의 정보 추가
                    QList<QStandardItem*> enroll_Items;
                    enroll_Items.append(new QStandardItem(course_ID));
                    enroll_Items.append(new QStandardItem(course_Name));
                    enroll_Items.append(new QStandardItem(QString::number(credits)));
                    enroll_Items.append(new QStandardItem(QString::number(enrollment)));
                    enrollListModel->appendRow(enroll_Items);
                }
            }
        }
        else
        {
            qDebug() << "< 현재 신청된 강의가 없습니다. >";
            enrollListModel->clear();
            enrollListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드" << "강의 이름" << "학점" << "등록 인원");
        }
    }
    else
    {
        qDebug() << "!!! 강의 목록을 조회하는 데 실패했습니다. 오류: " << DB_Course_Query.lastError().text();
    }
}

void Student_Menu::pushButton_Add()
{
    // 현재 선택된 강의의 정보를 가져오기
    QModelIndex selected_Index = ui->tableView_1->selectionModel()->currentIndex();
    if (selected_Index.isValid())
    {
        // 선택된 행에서 강의 코드를 가져옴
        QVariant course_id = ui->tableView_1->model()->data(selected_Index.siblingAtColumn(0));
        QString course_Id = course_id.toString();

        // 현재 로그인한 학생의 ID 가져오기
        QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

        // 이미 수강 중인지 확인하는 쿼리
        QString check_Existing_Query = QString("SELECT * FROM enroll_table WHERE student_id = '%1' AND course_id = '%2'")
            .arg(student_Id)
            .arg(course_Id);

        qDebug() << "Check Existing Query: " << check_Existing_Query;

        QSqlQuery query(db);

        if (query.exec(check_Existing_Query))
        {
            if (query.size() > 0)
            {
                // 이미 수강 중인 강의인 경우
                QMessageBox::warning(this, "알림", "이미 수강 중인 강의입니다.");
            }
            else
            {
                // 수강 신청 쿼리 실행
                QString add_Course_To_Student_Query = QString("INSERT INTO enroll_table (student_id, course_id) VALUES ('%1', '%2')")
                    .arg(student_Id)
                    .arg(course_Id);

                if (query.exec(add_Course_To_Student_Query))
                {
                    QMessageBox::information(this, "알림", "강의가 성공적으로 수강 신청되었습니다.");
                    // 수강 신청 후 강의 목록 업데이트
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
    QModelIndex selected_Index = ui->tableView_2->selectionModel()->currentIndex();
    if (selected_Index.isValid())
    {
        // 선택된 행에서 강의 코드를 가져옴
        QVariant course_id = ui->tableView_2->model()->data(selected_Index.siblingAtColumn(0));
        QString course_Id = course_id.toString();

        // 현재 로그인한 학생의 ID 가져오기
        QString student_Id = dynamic_cast<Login*>(parent())->getLoggedInUserId();

        // 취소할 강의를 수강 목록에서 삭제하는 쿼리
        QString cancel_Enrollment_Query = QString("DELETE FROM enroll_table WHERE student_id = '%1' AND course_id = '%2'")
            .arg(student_Id)
            .arg(course_Id);

        qDebug() << "Cancel Enrollment Query: " << cancel_Enrollment_Query;

        QSqlQuery query(db);

        if (query.exec(cancel_Enrollment_Query))
        {
            QMessageBox::information(this, "알림", "강의가 성공적으로 취소되었습니다.");
            // 취소 후 강의 목록 업데이트
            pushButton_Search();
        }
        else
        {
            qDebug() << "!!! 강의 취소 중 오류가 발생했습니다. 에러 메시지: " << query.lastError().text();
            QMessageBox::critical(this, "에러", "강의 취소 중 오류가 발생했습니다.");
        }
    }
    else
    {
        QMessageBox::warning(this, "알림", "수강 취소할 강의를 선택하세요.");
    }
}

void Student_Menu::pushButton_ChangePW()
{
    qDebug() << "ChangePW button clicked!";
    // 부모 윈도우를 직접 전달
    Change_PW* change_pw = new Change_PW(dynamic_cast<QWidget*>(this->parent())); 
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
