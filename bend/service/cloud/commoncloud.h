
#ifndef COMMONCLOUD_H
#define COMMONCLOUD_H


#include "middle/model/cloudmodel.h"
#include <QObject>
#include <QWidget>

// func of files transfering progress callback
using TransProgressCallback = std::function<void(uint64_t transferred_size,
                                                 uint64_t total_size,
                                                 void*)>;

/**
 * @brief The CommonCloud class
 * it's a base cloud operation class.
 */
class CommonCloud : public QObject
{
    Q_OBJECT
public:
    explicit CommonCloud(QObject *parent = nullptr);

    virtual QList<MyBucket> login(const QString& secretId, const QString& secretKey) = 0;

    // bucket operations
    virtual QList<MyBucket> buckets() = 0;
    virtual bool isBUcketExists(const QString& bucketName) = 0;
    virtual QString getBucketLocation(const QString& bucketName) = 0;
    virtual void createBucket(QString& bucketName, const QString& location) = 0;
    virtual void deleteBucket(const QString& bucketName, const QString& localtion) = 0;

    // objects operations
    virtual void getObjects(const QString& bucketName, const QString& key, const QString& location, const TransProgressCallback& callback) = 0;
    virtual void putObject(const QString& bucketName, const QString& key, const QString& location, const TransProgressCallback& callback) = 0;

signals:

};

#endif // COMMONCLOUD_H
