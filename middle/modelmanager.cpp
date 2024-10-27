
#include "modelmanager.h"

ModelManager::ModelManager(QObject *parent)
    : QObject{parent}
{

}

QStandardItemModel *ModelManager::modelBuckets() const
{
    return nullptr;
}

QStandardItemModel *ModelManager::modelObjects() const
{
    return nullptr;
}

void ModelManager::initBucketsTable()
{

}

void ModelManager::initObjectsTable()
{

}

void ModelManager::setBuckets(const QList<MyBucket> &buckets)
{

}

void ModelManager::setObjects(const QList<MyObject> &objects)
{

}

ModelManager::~ModelManager()
{

}
