
#include "cloudmanager.h"
#include "middle/globalmanager.h"
#include "plugin/pluginmanager.h"

CloudManager::CloudManager(QObject *parent)
    : QObject{parent}
{

}

void CloudManager::login(QString secretId, QString secretKey)
{
    QList<MyBucket> buckets = GM->pluginMgr->clouds()->login(secretId, secretKey);
}

void CloudManager::getBuckets()
{

}

void CloudManager::createBucket(const QString &bucketName)
{

}

void CloudManager::deleteBucket(const QString &bucketName)
{

}

void CloudManager::getObjects(const QString &bucketName, const QString &dir)
{

}

void CloudManager::getObject(const QString &jobId, const QString &bucketName, const QString &key, const QString &localPath)
{

}

void CloudManager::putObject(const QString &jobId, const QString &bucketName, const QString &key, const QString &localPath)
{

}

QString CloudManager::currentBucketName() const
{
    return "";
}

QString CloudManager::currentDir() const
{
    return "";
}

void CloudManager::bucketsAlready(const QList<MyBucket> &buckets)
{

}

CloudManager::~CloudManager()
{

}
