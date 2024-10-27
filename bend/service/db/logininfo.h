
#ifndef LOGININFO_H
#define LOGININFO_H


#include <QObject>
#include <middle/model/dbmodel.h>


class LoginInfoDao : public QObject
{
    Q_OBJECT
public:
    explicit LoginInfoDao(QObject *parent = nullptr);

    virtual bool exists(const QString &secretId, int platform)=0;
    virtual void insert(const LoginInfoEntity &loginInfo)=0;
    virtual void update(const LoginInfoEntity &loginInfo)=0;
    virtual void remove(const QString &secretId, int platform)=0;
    virtual QList<LoginInfoEntity> select()=0;

    virtual void connect()=0;
    virtual void createLoginInfoTable()=0;

};

#endif // LOGININFO_H
