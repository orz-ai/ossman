
#include "versionconfig.h"

VersionConfig::VersionConfig()
{
}

QString VersionConfig::version()
{
    return QString("%1.%2.%3").arg(m_major, m_env, versionNum());
}

QString VersionConfig::versionNum()
{
    return QString("%1.%2.%3").arg(m_v1).arg(m_v2).arg(m_v3);
}

QString VersionConfig::major() const
{
    return m_major;
}
