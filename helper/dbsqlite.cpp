#include "dbsqlite.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include "config/common.h"

DbSqlite::DbSqlite()
{
//    db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug() << "[DbSqlite] add database";
}

DbSqlite::~DbSqlite()
{
    if(db.isOpen()){
        qDebug() << "[DbSqlite] ready to close the db.";
        db.close();
        qDebug() << "[DbSqlite] db closed successfully.";
    }
}

void DbSqlite::connect(const QString &dbPath)
{
    db.setDatabaseName(dbPath);

    if(!db.open()){
        qDebug() << "[DbSqlite] db open failed.";
        throw STR("db open failed£º%1 %2").arg(dbPath, db.lastError().text());
    }

    qDebug() << "[DbSqlite] db open success.";
}

QSqlQuery DbSqlite::exec(const QString &sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        qDebug() << "[DbSqlite] exec failed. " << query.lastError().text();
        throw STR("exec failed£º%1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

QSqlQuery DbSqlite::exec(const QString &sql, const QVariantList &list)
{
    QSqlQuery query;
    if(!query.prepare(sql)){
        qDebug() << "[DbSqlite] prepare failed. " << query.lastError().text();
        throw STR("prepare failed£º%1 %2").arg(sql, query.lastError().text());
    }

    for(int i = 0; i < list.size(); i++){
        query.bindValue(i, list.at(i));
    }

    if(!query.exec()){
        qDebug() << "[DbSqlite] exec failed. " << query.lastError().text();
        throw STR("exec failed:%1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

bool DbSqlite::exist(const QString &sql)
{
    QSqlQuery query = exec(sql);
    return query.next();
}

QList<RECORD> DbSqlite::select(const QString &sql)
{
    QList<RECORD> retList;
    QSqlQuery query = exec(sql);
    while(query.next()){
        RECORD ret;

        QSqlRecord record = query.record();
        for(int i = 0; i < record.count(); ++i){
            QString name = record.fieldName(i);
            QVariant value = record.value(i);
            ret[name] = value;
        }
        retList.append(ret);
    }

    return retList;
}
