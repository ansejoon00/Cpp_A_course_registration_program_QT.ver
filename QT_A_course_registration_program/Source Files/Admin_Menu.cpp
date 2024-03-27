#include <QtWidgets/QMessageBox>
#include <QSqlQuery>
#include <QtSql>

#include "Admin_Menu.h"
#include "ui_Admin_Menu.h"

#include "Login.h"

extern QSqlDatabase db;

Admin_Menu::Admin_Menu(QWidget* parent)
    : QDialog(parent), ui(new Ui::Admin_Menu())
{
    ui->setupUi(this);

    this->setWindowTitle("관리자 메뉴");

    // TableView에 사용할 모델 초기화
    allCourseListModel = new QStandardItemModel(this);
    ui->tableView_1->setModel(allCourseListModel);

    // 각 열의 헤더 라벨 설정
    allCourseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드"
        << "강의 이름"
        << "학점"
        << "등록 인원");

    connect(ui->pushButton_Search, SIGNAL(clicked()), this, SLOT(pushButton_Search()));
    connect(ui->pushButton_Add, SIGNAL(clicked()), this, SLOT(pushButton_Add()));
    connect(ui->pushButton_Delete, SIGNAL(clicked()), this, SLOT(pushButton_Delete()));
    connect(ui->pushButton_LogOut, SIGNAL(clicked()), this, SLOT(pushButton_LogOut()));
    connect(ui->pushButton_Exit, SIGNAL(clicked()), this, SLOT(pushButton_Exit()));
}

Admin_Menu::~Admin_Menu()
{
    delete ui;
}

void Admin_Menu::pushButton_Search()
{
    QSqlQuery query(db);

    QString course_Query = QString("SELECT * from course_table;");

    if (query.exec(course_Query))
    {
        if (query.size() > 0)
        {
            qDebug() << "[ 현재 개설된 모든 강의 목록 ]";

            allCourseListModel->clear();
            allCourseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드"
                << "강의 이름"
                << "학점"
                << "등록 인원");

            while (query.next())
            {
                QString course_ID = query.value(0).toString();
                QString course_Name = query.value(1).toString();
                int credits = query.value(2).toInt();
                int enrollment = query.value(3).toInt();

                qDebug() << "강의 코드: " << course_ID << "\t, 강의 이름: " << course_Name << "\t, 학점: " << credits << "\t, 등록 인원: " << enrollment;

                // 모델에 강의 정보 추가
                QList<QStandardItem*> course_Items;
                course_Items.append(new QStandardItem(course_ID));
                course_Items.append(new QStandardItem(course_Name));
                course_Items.append(new QStandardItem(QString::number(credits)));
                course_Items.append(new QStandardItem(QString::number(enrollment)));
                allCourseListModel->appendRow(course_Items);
            }
        }
        else
        {
            qDebug() << "< 현재 개설된 강의가 없습니다. >";
            allCourseListModel->clear();
            allCourseListModel->setHorizontalHeaderLabels(QStringList() << "강의 코드"
                << "강의 이름"
                << "학점"
                << "등록 인원");
        }
    }
    else
    {
        qDebug() << "!!! 강의 목록을 조회하는 데 실패했습니다. 오류: " << query.lastError().text();
    }
}

void Admin_Menu::pushButton_Add()
{
    QString course_ID = ui->lineEdit_course_ID->text();
    QString course_Name = ui->lineEdit_course_Name->text();
    QString credits = ui->lineEdit_credits->text();
    QString enrollment = ui->lineEdit_enrollment->text();

    if (course_ID.isEmpty() || course_Name.isEmpty() || credits.isEmpty() || enrollment.isEmpty())
    {
        QMessageBox::warning(this, "강의 개설", "모든 항목을 입력해주세요.");
    }
    else
    {
        QSqlQuery checkQuery(db);
        checkQuery.prepare("SELECT * FROM course_table WHERE course_id = :course_id");
        checkQuery.bindValue(":course_id", course_ID);

        if (checkQuery.exec() && checkQuery.next())
        {
            // 이미 존재하는 과목 코드일 경우
            QMessageBox::critical(this, "에러", "이미 존재하는 강의 코드입니다.");
        }
        else
        {
            QSqlQuery query(db);

            // 강의 추가를 위한 쿼리 생성
            QString course_Add_Query = QString("INSERT INTO course_table (course_id, course_name, credit, enrollment_limit) "
                "VALUES (:course_id, :course_name, :credits, :enrollment)");

            // 쿼리에 바인딩할 값 설정
            query.prepare(course_Add_Query);
            query.bindValue(":course_id", course_ID);
            query.bindValue(":course_name", course_Name);
            query.bindValue(":credits", credits.toInt());
            query.bindValue(":enrollment", enrollment.toInt());

            // 쿼리 실행
            if (query.exec())
            {
                QMessageBox::information(this, "알림", "강의가 성공적으로 추가되었습니다.");
                // 추가 후 강의 목록 업데이트
                pushButton_Search();
            }
            else
            {
                qDebug() << "!!! 강의 추가 중 오류가 발생했습니다. 에러 메시지: " << query.lastError().text();
                QMessageBox::critical(this, "에러", "강의 추가 중 오류가 발생했습니다.");
            }
        }
    }
}

void Admin_Menu::pushButton_Delete()
{
    QSqlQuery query(db);

    // 현재 선택된 강의의 정보를 가져오기
    QModelIndex selected_Index = ui->tableView_1->selectionModel()->currentIndex();
    if (selected_Index.isValid())
    {
        // 선택된 행에서 강의 코드를 가져옴
        QVariant course_id = ui->tableView_1->model()->data(selected_Index.siblingAtColumn(0));
        QString course_Id = course_id.toString();

        // 취소할 강의를 수강 목록에서 삭제하는 쿼리
        QString cancel_Enrollment_Query = QString("DELETE FROM course_table WHERE course_id = '%1'")
            .arg(course_Id);

        qDebug() << "Cancel Enrollment Query: " << cancel_Enrollment_Query;

        if (query.exec(cancel_Enrollment_Query))
        {
            QMessageBox::information(this, "알림", "강의가 성공적으로 폐강되었습니다.");
            // 취소 후 강의 목록 업데이트
            pushButton_Search();
        }
        else
        {
            qDebug() << "!!! 강의 취소 중 오류가 발생했습니다. 에러 메시지: " << query.lastError().text();
            QMessageBox::critical(this, "에러", "강의 폐강 중 오류가 발생했습니다.");
        }
    }
    else
    {
        QMessageBox::warning(this, "알림", "폐강할 강의를 선택하세요.");
    }
}

void Admin_Menu::pushButton_LogOut()
{
    // 사용자에게 로그아웃 여부 묻기
    QMessageBox::StandardButton reply = QMessageBox::question(this, "로그아웃", "로그아웃 하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        close();
    }
}

void Admin_Menu::pushButton_Exit()
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