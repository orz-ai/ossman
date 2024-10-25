
#ifndef VERSIONCONFIG_H
#define VERSIONCONFIG_H


#include <QObject>


class VersionConfig
{
public:
    VersionConfig();

    virtual void setVersion() = 0;

    QString version();
    QString versionNum();
    QString major() const;

protected:
    QString m_major;
    QString m_env;

    int m_v1;
    int m_v2;
    int m_v3;

};

#endif // VERSIONCONFIG_H
