
#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QObject>
#include "middle/model/dbmodel.h"
#include "bend/service/db/sqlite/logininfosqlite.h"


class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);
    ~DbManager();

    DbManager *instance();
    void init();

    void saveLoginInfo(const QString &username, const QString &secretId, const QString &secretKey, const QString &remark, int platform);
    void removeLoginInfo(const QString &secretId, int platform);
    int indexOfLoginInfo(const QString &secretId, int platform);
    QStringList loginNameList();
    LoginInfoEntity loginInfoByName(const QString &name, int platform);

private:
    LoginInfoSqliteDao loginInfoSqliteDao;
    QList<LoginInfoEntity> loginInfoList;

signals:

};

#endif // DBMANAGER_H
