
#ifndef DBMODEL_H
#define DBMODEL_H

#include <QString>


struct LoginInfoEntity
{
    QString name;
    QString secretId;
    QString secretKey;
    QString remark;
    int platform;
    uint timestamp;
};

#endif // DBMODEL_H
