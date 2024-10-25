
#ifndef S3CLOUD_H
#define S3CLOUD_H


#include <QObject>


class S3Cloud : public QObject
{
    Q_OBJECT
public:
    explicit S3Cloud(QObject *parent = nullptr);

signals:

};

#endif // S3CLOUD_H
