#include "dagmainwindow.h"
#include "databasemanager.h"
#include <QApplication>
#include <QtSql/QtSql>
#include <QSqlDriver>
#include <sqlite3.h>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DAGMainWindow w;

    QSqlDatabase db;
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( QDir::homePath() + QDir::separator() + "inoveDB.db3");
    if (db.open()) {
        QSqlQuery query(db);
        if (query.exec("CREATE TABLE users ( INTEGER id PRIMARY KEY);")) {
            qDebug() << "table créée";
        } else {
            qDebug() << "erreur" << query.lastError();
        }
    } else {
        qDebug() << "DB Nao aberto.";
    }
    if (db.open()) {
        QSqlQuery add(db);
        add.exec("INSERT INTO users VALUES(18)");
        add.exec("INSERT INTO users VALUES(42)");
        add.exec("INSERT INTO users VALUES(1337)");
    } else {
        qDebug() << "DB Nao aberto.";
    }
    int i;
    if (db.open()) {
        QSqlQuery get(db);
        if (get.exec("select * from users")) {
            qDebug() << "table créée";
            while (get.next()) {
                QVariant id = get.value(0);
                //id.setValue(QVariant::Int);
                if ( id.canConvert(QVariant::Int)){
                    i = id.toInt();
                    std::cout<<i<<std::endl;
                }
            }

        } else {
            qDebug() << "erreur" << get.lastError();
        }
    } else {
        qDebug() << "DB Nao aberto.";
    }
    db.close();
    w.show();

    return a.exec();
}
