
#ifndef COSCLOUD_H
#define COSCLOUD_H


#include "commoncloud.h"
#include <QObject>
#include <QWidget>





namespace qcloud_cos{
    class CosConfig;
    class CosResult;
    class GetBucketResp;
}

class CosCloud : public CommonCloud
{
public:
    CosCloud();

    ~CosCloud();

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

    // bucket operations
    QList<MyBucket> buckets() override;
    bool isBucketExists(const QString& bucketName) override;
    QString getBucketLocation(const QString& bucketName) override;
    void createBucket(QString& bucketName, const QString& location) override;
    void deleteBucket(const QString& bucketName, const QString& location) override;

    // object operations
    QList<MyObject> getObjects(const QString& bucketName, const QString& dir) override;
    void putObject(const QString& bucketName,const QString& key,const QString& localPath,const TransProgressCallback& callback) override;
    void getObject(const QString& bucketName,const QString& key,const QString& localPath,const TransProgressCallback& callback) override;
    bool isObjectExists(const QString& bucketName, const QString& key);

private:
    QList<MyObject> getDirList(qcloud_cos::GetBucketResp& resp, const QString& dir);
    QList<MyObject> getFileList(qcloud_cos::GetBucketResp& resp, const QString& dir);
    MyBucket getBucketByName(const QString& bucketName);

    void throwError(const QString& code, qcloud_cos::CosResult& result);


private:
    qcloud_cos::CosConfig* config = nullptr;
};


#endif // COSCLOUD_H
