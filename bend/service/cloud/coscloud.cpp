
#include "coscloud.h"
#include "src/config/exception.h"
#include "src/config/errorcode.h"
#include <QDebug>

// 此头文件要放到最后，否则可能会报错
#include "cos_api.h"

using  namespace qcloud_cos;


CosCloud::CosCloud()
{
}

CosCloud::~CosCloud()
{
}

QList<MyBucket> CosCloud::login(const QString &secretId, const QString &secretKey)
{

}

QList<MyBucket> CosCloud::buckets()
{

}

bool CosCloud::isBucketExists(const QString &bucketName)
{
    return true;
}

void CosCloud::putBucket(const QString &bucketName, const QString &location)
{

}

void CosCloud::deleteBucket(const QString &bucketName)
{

}

QList<MyObject> CosCloud::getObjects(const QString &bucketName, const QString &dir)
{

}

void CosCloud::putObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}

void CosCloud::getObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}

bool CosCloud::isObjectExists(const QString &bucketName, const QString &key)
{

}

QList<MyObject> CosCloud::getDirList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{

}

QList<MyObject> CosCloud::getFileList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{

}

MyBucket CosCloud::getBucketByName(const QString &bucketName)
{

}

void CosCloud::throwError(const QString &code, qcloud_cos::CosResult &result)
{

}


