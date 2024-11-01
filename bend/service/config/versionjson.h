
#ifndef VERSIONJSON_H
#define VERSIONJSON_H


#include <QObject>
#include "versionconfig.h"


class VersionJson : public VersionConfig
{
public:
    VersionJson(const QString& path);
    void setVersion();


private:
    QString mPath;

};

#endif // VERSIONJSON_H
