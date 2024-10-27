
#include "dbmanager.h"
#include "config/common.h"
#include <QDebug>
#include <QDateTime>

DbManager::DbManager(QObject *parent)
        : QObject{parent}
{

}

void DbManager::init()
{
    loginInfoSqliteDao.connect();
    loginInfoSqliteDao.createLoginInfoTable();
    loginInfoList = loginInfoSqliteDao.select();
}

void DbManager::saveLoginInfo(const QString &name, const QString &secretId, const QString &secretKey,
                              const QString &remark, int platform)
{
    LoginInfoEntity info;
    info.name = (name == "" ? secretId : name);
    info.secretId = secretId.trimmed();
    info.secretKey = secretKey.trimmed();
    info.remark = remark.trimmed();
    info.platform = platform;
    info.timestamp = QDateTime::currentDateTimeUtc().toTime_t();

    // check if exists
    if (loginInfoSqliteDao.exists(info.secretId, info.platform))
    {
        loginInfoSqliteDao.update(info);
        loginInfoList[indexOfLoginInfo(info.secretId, info.platform)] = info;
    } else
    {
        loginInfoSqliteDao.insert(info);
        // cache login info
        loginInfoList.append(info);
    }
}

void DbManager::removeLoginInfo(const QString &secretId, int platform)
{
    if (loginInfoSqliteDao.exists(secretId, platform))
    {
        loginInfoSqliteDao.remove(secretId, platform);
        loginInfoList.removeAt(indexOfLoginInfo(secretId, platform));
    }
}

int DbManager::indexOfLoginInfo(const QString &secretId, const int type)
{
    for (int i = 0; i < loginInfoList.size(); ++i)
    {
        if (loginInfoList[i].secretId == secretId)
        {
            return i;
        }
    }
    throw STR("can't find login info %1").arg(secretId);
}

QStringList DbManager::loginNameList()
{
    QStringList words;
    for (auto & i : loginInfoList)
    {
        words.append(i.name);
    }
    return words;
}

LoginInfoEntity DbManager::loginInfoByName(const QString &name, const int type)
{
    for (auto & i : loginInfoList)
    {
        if (i.name == name)
        {
            return i;
        }
    }
    throw STR("can't find login info by name %1").arg(name);
}

DbManager::~DbManager()
{

}

