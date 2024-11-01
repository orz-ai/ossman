
#ifndef SIGNHELPER_H
#define SIGNHELPER_H


#include <QObject>
#include <QString>
#include <QMap>
#include <QUrl>
#include <QDateTime>
#include <QCryptographicHash>
#include <QByteArray>


class SignHelper : public QObject
{
    Q_OBJECT
public:
    explicit SignHelper(QObject *parent = nullptr);
    static QString generateSignature(const QString &secretId,
                                     const QString &secretKey,
                                     const QString &httpMethod,
                                     const QString &uriPath,
                                     const QMap<QString, QString> &httpParams,
                                     const QMap<QString, QString> &httpHeaders,
                                     int expiresIn = 3600);  // 签名有效期，默认为1小时
    static QString generateAliSignature(const QString &secretId,
                                     const QString &secretKey,
                                     const QString &httpMethod,
                                     const QString &bucketName,
                                     const QString &objectKey,
                                     QMap<QString, QString> &httpParams,
                                     QMap<QString, QString> &httpHeaders);

private:
    static QByteArray filterHeaders(const QMap<QString, QString> &headers);
    static QByteArray formatString(const QString &method, const QString &path, const QByteArray &headers, const QMap<QString, QString> &params);
    static QString canonicalizeHeaders(const QMap<QString, QString> &headerss);
    static QString canonicalizeResource(const QString &bucket, const QString &objectKey);
};

#endif // SIGNHELPER_H
