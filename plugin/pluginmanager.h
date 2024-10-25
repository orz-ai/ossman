
#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H


#include <QObject>
#include <QWidget>

#include <bend/service/cloud/commoncloud.h>
#include <bend/service/config/versionconfig.h>

class CommonCloud;
class VersionConfig;

class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = nullptr);
    ~PluginManager();

    CommonCloud *clouds() const;

    void installPlugins(int argc, char* argv[]);

private:
    CommonCloud* mClouds;
    VersionConfig* mVersion;

signals:

};

#endif // PLUGINMANAGER_H
