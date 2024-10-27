
#include "coscloud.h"
#include <QDebug>


using  namespace qcloud_cos;


CosCloud::CosCloud()
{
}

CosCloud::~CosCloud()
{
}

QList<MyBucket> CosCloud::login(const QString &secretId, const QString &secretKey)
{
    QList<MyBucket> buckets;

    return buckets;
}

QList<MyBucket> CosCloud::buckets()
{
    QList<MyBucket> buckets;

    return buckets;
}

bool CosCloud::isBucketExists(const QString &bucketName)
{
    return true;
}

QString CosCloud::getBucketLocation(const QString &bucketName)
{
    return "";
}

void CosCloud::createBucket(QString &bucketName, const QString &location)
{

}

void CosCloud::deleteBucket(const QString &bucketName, const QString& location)
{

}

QList<MyObject> CosCloud::getObjects(const QString &bucketName, const QString &dir)
{
    QList<MyObject> objects;

    return objects;
}


void CosCloud::putObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}

void CosCloud::getObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}

bool CosCloud::isObjectExists(const QString &bucketName, const QString &key)
{
    return false;
}

QList<MyObject> CosCloud::getDirList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{
    QList<MyObject> objects;

    return objects;
}

QList<MyObject> CosCloud::getFileList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{
    QList<MyObject> objects;

    return objects;
}

MyBucket CosCloud::getBucketByName(const QString &bucketName)
{
    MyBucket bucket;
    return bucket;
}

void CosCloud::throwError(const QString &code, qcloud_cos::CosResult &result)
{

}


