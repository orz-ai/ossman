
#include <config/errorcode.h>
#include "gateway.h"
#include "config/baseexception.h"
#include "middle/globalmanager.h"
#include "middle/signal/signalmanager.h"
#include "config/common.h"
#include "config/api.h"
#include <QtConcurrent/QtConcurrent>
#include <bend/mgr/cloudmanager.h>

Gateway::Gateway(QObject *parent)
        : QObject{parent}
{

}

Gateway::~Gateway()
{

}

void Gateway::send(int api, const QJsonValue &params)
{
    QtConcurrent::run([=]()
                      {
                          try
                          {
                              this->dispatch(api, params);
                          } catch (BaseException &e)
                          {
                              mError(e.msg());
                              emit GM->signalMgr->error(api, e.msg(), params);
                          } catch (...)
                          {
                              BaseException e = BaseException(EC_100000, STR("unknown error"));
                              mError(e.msg());
                              emit GM->signalMgr->error(api, e.msg(), params);
                          }
                      }
    );
}

void Gateway::dispatch(int api, const QJsonValue &params)
{
    switch (api)
    {
        case API::LOGIN::NORMAL:
            apiLogin(params);
            break;
        case API::BUCKET::LIST:
            apiGetBucketList(params);
            break;
        case API::BUCKET::PUT:
            apiPutBucket(params);
            break;
        case API::BUCKET::DELETE:
            apiDeleteBucket(params);
            break;
        case API::OBJECT::LIST:
            apiGetObjectList(params);
            break;
        case API::OBJECT::GET:
            apiGetObject(params);
            break;
        case API::OBJECT::PUT:
            apiPutObject(params);
            break;
        case API::OBJECT::DELETE:
            break;
        default:
            throw BaseException(EC_100000, STR("unknown api"));
    }
}

void Gateway::apiLogin(const QJsonValue &params)
{
    QString secretId = params["secretId"].toString();
    QString secretKey = params["secretKey"].toString();

    qDebug() << "[apiLogin]secretId: " << secretId;
    qDebug() << "[apiLogin]secretKey: " << secretKey;

    GM->cloudMgr->login(secretId, secretKey);
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

