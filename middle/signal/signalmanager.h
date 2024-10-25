
#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>

class SignalManager: public QObject
{
    Q_OBJECT
public:
    explicit SignalManager(QObject *parent = nullptr);
    ~SignalManager();

signals:
    void loginSuccess();
    void error(int api, const QString &msg, const QJsonValue &req);
    void loginout();

    void getBucketsSuccess();

    void startDownload();
    void downloadProcess(const QString &jobId, qulonglong transferred, qulonglong total);
    void downloadSuccess(const QString &jobId);

    void startUpload(const QString &jobId, const QString &key, const QString &localPath);
    void uploadProcess(const QString& jobId, qulonglong transferred, qulonglong total);
    void uploadSuccess(const QString& jobId);
};

#endif // SIGNALMANAGER_H
