
#include "signalmanager.h"

#include <middle/model/cloudmodel.h>

SignalManager::SignalManager(QObject *parent)
    : QObject{parent}
{
    qRegisterMetaType<QList<MyBucket> >("QList<MyBucket>");
    qRegisterMetaType<QList<MyObject> >("QList<MyObject>");
}

SignalManager::~SignalManager()
{
    qDebug("delete SignalManager");
}
