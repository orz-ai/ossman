
#include "globalmanager.h"



GlobalManager::GlobalManager()
{
    mLog = new LoggerProxy(this);
    cloudMgr = new CloudManager(this);
    dbMgr = new DbManager(this);
    signalMgr = new SignalManager(this);
    pluginMgr = new PluginManager(this);
    gateway = new Gateway(this);
}

void GlobalManager::init(int argc, char *argv[])
{

}

