
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
    return nullptr;
}

void PluginManager::installPlugins(int argc, char *argv[])
{
}

