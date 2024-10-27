
#include "logininfosqlite.h"
#include "config/global.h"
#include <QDebug>

LoginInfoSqliteDao::LoginInfoSqliteDao()
{

}

bool LoginInfoSqliteDao::exists(const QString &secretId, int platform)
{
    QString sql = QString(
            "select id from %1 where secret_id = '%2' and platform = %3;"
    ).arg(CONF::TABLES::LOGIN_INFO, secretId, QString::number(platform));

    return db.exist(sql);
}

void LoginInfoSqliteDao::insert(const LoginInfoEntity &info)
{
    QString sql = QString(
            "insert into %1 (name, secret_id, secret_key, remark, timestamp) values (?, ?, ?, ?, ?)"
    ).arg(CONF::TABLES::LOGIN_INFO);

    QVariantList fieldsValues;
    fieldsValues.append(info.name);
    fieldsValues.append(info.secretId);
    fieldsValues.append(info.secretKey);
    fieldsValues.append(info.remark);
    fieldsValues.append(info.timestamp);
    db.exec(sql, fieldsValues);
}

void LoginInfoSqliteDao::update(const LoginInfoEntity &info)
{
    QString sql = QString(
            "update %1 "
            "set name= ?, "
            "secret_key = ?, "
            "remark = ?, "
            "timestamp = ? "
            "where secret_id = ? and platform = ?;"
    ).arg(CONF::TABLES::LOGIN_INFO);

    QVariantList variantList;
    variantList << info.name
                << info.secretKey
                << info.remark
                << info.timestamp
                << info.secretId
                << QString::number(info.platform);

    db.exec(sql, variantList);
}

void LoginInfoSqliteDao::remove(const QString &secretId, int platform)
{
    QString sql = QString(
            "delete from %1 where secret_id = ?"
    ).arg(CONF::TABLES::LOGIN_INFO);

    QVariantList variantList;
    variantList << secretId << QString::number(platform);

    db.exec(sql, variantList);
}

QList<LoginInfoEntity> LoginInfoSqliteDao::select()
{
    QList<LoginInfoEntity> result;
    QString sql = QString(
            "select name, secret_id, secret_key, remark from %1 order by timestamp desc;"
    ).arg(
            CONF::TABLES::LOGIN_INFO
    );

    QList<RECORD> records = db.select(sql);
    foreach (const auto& record, records)
    {
        LoginInfoEntity info;
        info.name = record["name"].toString();
        info.secretId = record["secret_id"].toString();
        info.secretKey = record["secret_key"].toString();
        info.remark = record["remark"].toString();
        info.platform = record["platform"].toInt();

        result.append(info);
    }

    return result;
}

void LoginInfoSqliteDao::connect()
{
    db.connect(CONF::SQLITE::NAME);
    qDebug() << "[DaoLoginInfoSqlite::connect] connect successfully.";
}

void LoginInfoSqliteDao::createLoginInfoTable()
{
    qDebug() << "[DaoLoginInfoSqlite::createLoginInfoTable] create login info table.";
    QString sql = FileHelper::readAllText(CONF::SQL::LOGIN_INFO_TABLE);
    try {
        db.exec(sql);
        qDebug() << "[DaoLoginInfoSqlite::createLoginInfoTable] create login info table successfully.";
    } catch (...) {
        qDebug() << "[DaoLoginInfoSqlite::createLoginInfoTable] create login info table failed.";
    }
}

