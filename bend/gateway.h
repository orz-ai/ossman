
#ifndef GATEWAY_H
#define GATEWAY_H


#include <QObject>
#include <QJsonValue>


class Gateway : public QObject
{
    Q_OBJECT
public:
    explicit Gateway(QObject *parent = nullptr);
    ~Gateway();

    void send(int api, const QJsonValue& params=QJsonValue());

private:
    void dispatch(int api, const QJsonValue& params);
    void apiLogin(const QJsonValue& params);

    // bucket ops
    void apiGetBucketList(const QJsonValue& params);
    void apiPutBucket(const QJsonValue& params);
    void apiDeleteBucket(const QJsonValue& params);

    // object ops
    void apiGetObjectList(const QJsonValue& params);
    void apiGetObject(const QJsonValue& params);
    void apiPutObject(const QJsonValue& params);

signals:

};

#endif // GATEWAY_H
