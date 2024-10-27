
#ifndef LOGININFOSQLITEDAO_H
#define LOGININFOSQLITEDAO_H

#include "bend/service/db/logininfo.h"
#include "helper/dbsqlite.h"

class LoginInfoSqliteDao : public LoginInfoDao
{
public:
    LoginInfoSqliteDao();

    bool exists(const QString& secretId, int platform);
    void insert(const LoginInfoEntity& info);
    void update(const LoginInfoEntity& info);
    void remove(const QString& secretId, int platform);
    QList<LoginInfoEntity> select();


    void connect();
    void createLoginInfoTable();

private:
    DbSqlite db;


};

#endif // LOGININFOSQLITEDAO_H
