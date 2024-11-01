
#include "versionjson.h"
#include "helper/filehelper.h"
#include <QJsonObject>


VersionJson::VersionJson(const QString &path)
{
    mPath = path;
}

void VersionJson::setVersion()
{
    QJsonObject obj = FileHelper::readAllJson(mPath).toJsonObject();
    obj = obj["version"].toObject();
    m_major = obj["major"].toString();
    m_env = obj["env"].toString();
    m_v1 = obj["v1"].toInt();
    m_v2 = obj["v2"].toInt();
    m_v3 = obj["v3"].toInt();

    qDebug() << m_major << m_env << m_v1 << m_v2 << m_v3;
}
