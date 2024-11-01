#include "httphelper.h"
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>

HttpHelper::HttpHelper(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

HttpHelper::~HttpHelper()
{
    delete manager;
}

QString HttpHelper::get(const QString &url)
{
    return get(url, QMap<QString, QString>());
}

QString HttpHelper::get(const QString &url, const QMap<QString, QString> &headers)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);

    QNetworkReply *reply = manager->get(request);
    return handleReply(reply);
}

QString HttpHelper::post(const QString &url, const QByteArray &data)
{
    return post(url, QMap<QString, QString>(), data);
}

QString HttpHelper::post(const QString &url, const QMap<QString, QString> &headers, const QByteArray &data)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, data);
    return handleReply(reply);
}

QString HttpHelper::postForm(const QString &url, const QMap<QString, QString> &params)
{
    return postForm(url, QMap<QString, QString>(), params);
}

QString HttpHelper::postForm(const QString &url, const QMap<QString, QString> &headers, const QMap<QString, QString> &params)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery query;
    for (auto it = params.begin(); it != params.end(); ++it)
    {
        query.addQueryItem(it.key(), it.value());
    }

    QNetworkReply *reply = manager->post(request, query.toString().toUtf8());
    return handleReply(reply);
}

// put
QString HttpHelper::put(const QString &url, const QByteArray &data)
{
    return put(url, QMap<QString, QString>(), data);
}

QString HttpHelper::put(const QString &url, const QMap<QString, QString> &headers, const QByteArray &data)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->put(request, data);
    return handleReply(reply);
}

// delete
QString HttpHelper::del(const QString &url)
{
    return del(url, QMap<QString, QString>());
}

QString HttpHelper::del(const QString &url, const QMap<QString, QString> &headers)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);

    QNetworkReply *reply = manager->deleteResource(request);
    return handleReply(reply);
}

// head
QString HttpHelper::head(const QString &url)
{
    return head(url, QMap<QString, QString>());
}

QString HttpHelper::head(const QString &url, const QMap<QString, QString> &headers)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);

    QNetworkReply *reply = manager->head(request);
    return handleReply(reply);
}


QString HttpHelper::upload(const QString &url, const QString &filePath, const QMap<QString, QString> &headers)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        return QString("Failed to open file: %1").arg(filePath);
    }

    QByteArray fileData = file.readAll();
    file.close();

    QNetworkRequest request(url);
    setHeaders(request, headers);

    // check for content type
    if (!request.hasRawHeader("Content-Type"))
    {
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");
    }

    // compute content length adn content md5
    if (!request.hasRawHeader("Content-Length") || !request.hasRawHeader("Content-MD5"))
    {
        QString contentLength = QString::number(fileData.size());
        QByteArray md5Hash = QCryptographicHash::hash(fileData, QCryptographicHash::Md5);
        QString contentMD5 = md5Hash.toBase64();
        request.setRawHeader("Content-Length", contentLength.toUtf8());
        request.setRawHeader("Content-MD5", contentMD5.toUtf8());
    }

    // exec upload request
    QNetworkReply *reply = manager->put(request, fileData);
    return handleReply(reply);
}


QString HttpHelper::download(const QString &url, const QString &savePath, const QMap<QString, QString> &headers)
{
    QNetworkRequest request(url);
    setHeaders(request, headers);

    QNetworkReply *reply = manager->get(request);

    // 使用事件循环等待请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString result;
    if (reply->error() == QNetworkReply::NoError)
    {
        QFile file(savePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(reply->readAll());
            file.close();
            result = "File downloaded successfully.";
        } else
        {
            result = QString("Failed to save file: %1").arg(savePath);
        }
    } else
    {
        result = reply->errorString();
    }

    reply->deleteLater();
    return result;
}

QString HttpHelper::handleReply(QNetworkReply *reply)
{
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString result;
    if (reply->error() == QNetworkReply::NoError)
    {
        result = reply->readAll();
    } else
    {
        result = reply->errorString();
    }

    reply->deleteLater();
    return result;
}

void HttpHelper::setHeaders(QNetworkRequest &request, const QMap<QString, QString> &headers)
{
    for (auto it = headers.begin(); it != headers.end(); ++it)
    {
        request.setRawHeader(it.key().toUtf8(), it.value().toUtf8());
    }
}
