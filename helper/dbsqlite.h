
#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QString>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>

typedef QMap<QString, QVariant> RECORD;

class DbSqlite
{
public:
    DbSqlite();
    ~DbSqlite();

    void connect(const QString &dbPath);
    QSqlQuery exec(const QString &sql);
    QSqlQuery exec(const QString &sql, const QVariantList &list);
    bool exist(const QString &sql);
    QList<RECORD> select(const QString &sql);

private:
    QSqlDatabase db;

};

#endif // DBSQLITE_H
