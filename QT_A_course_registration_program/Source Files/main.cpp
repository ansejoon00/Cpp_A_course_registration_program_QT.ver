#include "Login.h"
#include <QtWidgets/QApplication>

#include <QtSql>

// 전역으로 데이터베이스 연결 선언
QSqlDatabase db;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // MySQL 드라이버 로드
    db = QSqlDatabase::addDatabase("QMYSQL");

    // 데이터베이스 연결 설정
    db.setHostName("175.116.213.89");
    db.setDatabaseName("A_course_registration_program");
    db.setUserName("sejoon");
    db.setPassword("dkstpwns1!");
    db.setPort(33060);

    // 데이터베이스 연결 시도
    if (db.open())
        // if (1)
    {
        qDebug() << "Connected to database";

        // MainWindow 생성
        Login w;
        w.show();

        // 애플리케이션 이벤트 루프 시작
        return a.exec();
    }

    else
    {
        qDebug() << "Failed to connect to database";
        qDebug() << db.lastError().text();

        return 0;
    }
}