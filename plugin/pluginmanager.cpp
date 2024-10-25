
#include "pluginmanager.h"

PluginManager::PluginManager(QObject *parent)
    : QObject{parent}
{

}

PluginManager::~PluginManager()
{

}

CommonCloud *PluginManager::clouds() const
{

}

void PluginManager::installPlugins(int argc, char *argv[])
{
    VersionCmd
}

