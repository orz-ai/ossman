#ifndef HTTPHELPER_H
#define HTTPHELPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMap>
#include <QUrlQuery>
#include <QFile>

class HttpHelper : public QObject {
Q_OBJECT

public:
    explicit HttpHelper(QObject *parent = nullptr);
    ~HttpHelper();

    QString get(const QString &url);
    QString get(const QString &url, const QMap<QString, QString> &headers);

    QString post(const QString &url, const QByteArray &data);
    QString post(const QString &url, const QMap<QString, QString> &headers, const QByteArray &data);

    QString postForm(const QString &url, const QMap<QString, QString> &params);
    QString postForm(const QString &url, const QMap<QString, QString> &headers, const QMap<QString, QString> &params);

    // put
    QString put(const QString &url, const QByteArray &data);
    QString put(const QString &url, const QMap<QString, QString> &headers, const QByteArray &data);

    // delete
    QString del(const QString &url);
    QString del(const QString &url, const QMap<QString, QString> &headers);

    // head
    QString head(const QString &url);
    QString head(const QString &url, const QMap<QString, QString> &headers);

    // download and upload
    QString upload(const QString &url, const QString &filePath, const QMap<QString, QString> &headers = {});
    QString download(const QString &url, const QString &savePath, const QMap<QString, QString> &headers = {});

private:
    QNetworkAccessManager *manager;

    QString handleReply(QNetworkReply *reply);
    void setHeaders(QNetworkRequest &request, const QMap<QString, QString> &headers);
};

#endif // HTTPHELPER_H
