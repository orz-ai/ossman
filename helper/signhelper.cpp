
#include "signhelper.h"
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>

#include <QDebug>


SignHelper::SignHelper(QObject *parent)
        : QObject{parent}
{
}

QString SignHelper::generateSignature(
        const QString &secretId,
        const QString &secretKey,
        const QString &method,
        const QString &path,
        const QMap<QString, QString> &headers,
        const QMap<QString, QString> &params,
        int expiresIn
){
    QString signTime = QString::number(QDateTime::currentSecsSinceEpoch() - 60) + ";" +
                       QString::number(QDateTime::currentSecsSinceEpoch() + expiresIn);

    QByteArray filteredHeaders = filterHeaders(headers);
    QByteArray formattedString = formatString(method, path, filteredHeaders, params);
    qDebug() << formattedString;

    QByteArray sha1 = QCryptographicHash::hash(formattedString, QCryptographicHash::Sha1);
    QByteArray strToSign = QString("sha1\n%1\n%2\n").arg(signTime).arg(QString(sha1.toHex())).toUtf8();

    QByteArray signKey = QMessageAuthenticationCode::hash(signTime.toUtf8(), secretKey.toUtf8(), QCryptographicHash::Sha1);
    QByteArray sign = QMessageAuthenticationCode::hash(QString(strToSign).toUtf8(), QString(signKey.toHex()).toUtf8(), QCryptographicHash::Sha1);
    QString authorizationTemplate = QString(
            "q-sign-algorithm=sha1&q-ak=%1&q-sign-time=%2&q-key-time=%2&q-header-list=%3&q-url-param-list=%4&q-signature=%5")
            .arg(secretId)
            .arg(signTime)
            .arg(QString(filteredHeaders))
            .arg(QString(params.keys().join(";")))
            .arg(QString(sign.toHex()));

    return authorizationTemplate;
}

QByteArray SignHelper::filterHeaders(const QMap<QString, QString> &headers) {
    QByteArray filtered;
    QStringList validHeaders = {"cache-control", "content-disposition", "content-encoding", "content-type",
                                "content-md5", "content-length", "expect", "expires", "host",
                                "if-match", "if-modified-since", "if-none-match", "if-unmodified-since",
                                "origin", "range", "transfer-encoding", "pic-operations"};

    for (auto it = headers.begin(); it != headers.end(); ++it) {
        QString key = it.key().toLower();
        if (validHeaders.contains(key) || key.startsWith("x-cos-")) {
            filtered.append(QString("%1=%2&").arg(key, it.value()));
        }
    }
    return filtered;
}

QByteArray SignHelper::formatString(const QString &method, const QString &path, const QByteArray &headers, const QMap<QString, QString> &params) {
    QString paramsString = QString(params.keys().join("&"));
    return QString("%1\n%2\n%3\n%4\n").arg(method.toLower(), path, paramsString, headers).toUtf8();
}


QString SignHelper::generateAliSignature(
        const QString &accessKeyId,
        const QString &accessKeySecret,
        const QString &method,
        const QString &bucket,
        const QString &objectKey,
        QMap<QString, QString> &headers,
        QMap<QString, QString> &params)
{
    // record request time
    QString date = QLocale::c().toString(QDateTime::currentDateTimeUtc(), "ddd, dd MMM yyyy HH:mm:ss 'GMT'");
    QString contentMd5 = headers.value("Content-MD5", "");
    QString contentType = headers.value("Content-Type", "");
    QString canHeaders = canonicalizeHeaders(headers);
    QString canResource = canonicalizeResource(bucket, objectKey);

    if (!params.isEmpty()) {
        canResource += "?" + params.keys().join("&");
    }

    // ¹¹½¨´ýÇ©Ãû×Ö·û´®
    QString stringToSign = method + "\n" + contentMd5 + "\n" + contentType + "\n" + date + "\n" +
            canHeaders + canResource;

    QByteArray hmac = QMessageAuthenticationCode::hash(stringToSign.toUtf8(), accessKeySecret.toUtf8(), QCryptographicHash::Sha1);
    QByteArray signature = hmac.toBase64();

    // set Date to header
    headers.insert("Date", date);
    return "OSS " + accessKeyId + ":" + QString(signature);
}

QString SignHelper::canonicalizeResource(const QString &bucket, const QString &objectKey)
{
    QString result = "";
    if (!bucket.isEmpty() && !objectKey.isEmpty()) {
        result = "/" + bucket + "/" + objectKey;
    } else if (!bucket.isEmpty()) {
        result = "/" + bucket;
    } else {
        result = "/";
    }
    return result;
}

QString SignHelper::canonicalizeHeaders(const QMap<QString, QString> &headers)
{
    QString result = "";
    for (auto it = headers.cbegin(); it != headers.cend(); ++it) {
        QString header = it.key().toLower();
        if (header.startsWith("x-oss-")) {
            result += header + ":" + it.value() + "\n";
        }
    }
    return result;
}
