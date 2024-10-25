
#ifndef CLOUDMANAGER_H
#define CLOUDMANAGER_H


#include <QObject>
#include <QWidget>

#include <middle/model/cloudmodel.h>


class CloudManager : public QObject
{
    Q_OBJECT
public:
    explicit CloudManager(QObject *parent = nullptr);
    ~CloudManager();

    void login(QString secretId, QString secretKey);

    // bucket operations
    void getBuckets();
    void createBucket(const QString& bucketName);
    void deleteBucket(const QString& bucketName);

    // object operations
    void getObjects(const QString& bucketName, const QString& dir="");
    void getObject(const QString& jobId, const QString& bucketName, const QString& key, const QString& localPath);
    void putObject(const QString& jobId, const QString& bucketName, const QString& key, const QString& localPath);

    QString currentBucketName() const;
    QString currentDir() const;

private:
    QString mCurrentBucketName;
    QString mCurrentDir;

    void bucketsAlready(const QList<MyBucket>& buckets);


signals:

};

#endif // CLOUDMANAGER_H
