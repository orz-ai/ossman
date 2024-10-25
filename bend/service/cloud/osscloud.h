
#ifndef OSSCLOUD_H
#define OSSCLOUD_H


#include <QObject>


class OssCloud : public QObject
{
    Q_OBJECT
public:
    explicit OssCloud(QObject *parent = nullptr);

signals:

};

#endif // OSSCLOUD_H
