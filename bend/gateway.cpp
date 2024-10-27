
#include "gateway.h"

Gateway::Gateway(QObject *parent)
    : QObject{parent}
{

}

Gateway::~Gateway()
{

}

void Gateway::send(int api, const QJsonValue &params)
{

}

void Gateway::dispatch(int api, const QJsonValue &params)
{

}

void Gateway::apiLogin(const QJsonValue &params)
{

}

void Gateway::apiGetBucketList(const QJsonValue &params)
{

}

void Gateway::apiPutBucket(const QJsonValue &params)
{

}

void Gateway::apiDeleteBucket(const QJsonValue &params)
{

}

void Gateway::apiGetObjectList(const QJsonValue &params)
{

}

void Gateway::apiGetObject(const QJsonValue &params)
{

}

void Gateway::apiPutObject(const QJsonValue &params)
{

}

