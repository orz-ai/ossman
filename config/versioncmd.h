
#ifndef VERSIONCMD_H
#define VERSIONCMD_H


#include <QObject>

#include <bend/service/config/versionconfig.h>


class VersionCmd : public VersionConfig
{
public:
    VersionCmd();

    void setVersion();
    bool isValid();

private:
    QStringList mArgv;

};

#endif // VERSIONCMD_H
