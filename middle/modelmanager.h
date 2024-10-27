
#ifndef MODELMANAGER_H
#define MODELMANAGER_H


#include <QObject>
#include <QStandardItemModel>
#include <middle/model/cloudmodel.h>


class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);
    ~ModelManager();

    QStandardItemModel *modelBuckets() const;
    QStandardItemModel *modelObjects() const;

private:
    void initBucketsTable();
    void initObjectsTable();

private slots:
    void setBuckets(const QList<MyBucket>& buckets);
    void setObjects(const QList<MyObject>& objects);

};

#endif // MODELMANAGER_H
