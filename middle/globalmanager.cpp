
#include "globalmanager.h"

#include <bend/mgr/cloudmanager.h>
#include <bend/mgr/dbmanager.h>
#include <middle/signal/signalmanager.h>
#include <plugin/pluginmanager.h>
#include <bend/gateway.h>
#include "modelmanager.h"
#include <helper/filehelper.h>
#include <QApplication>

Q_GLOBAL_STATIC(GlobalManager, ins);

GlobalManager::GlobalManager(QObject *parent)
        : QObject{parent}
{
    mLog = new LoggerProxy(this);
    cloudMgr = new CloudManager(this);
    dbMgr = new DbManager(this);
    signalMgr = new SignalManager(this);
    pluginMgr = new PluginManager(this);
    gateway = new Gateway(this);
}

GlobalManager::~GlobalManager()
{

}

GlobalManager *GlobalManager::instance()
{
    return ins();
}


void GlobalManager::init(int argc, char *argv[])
{
    modelMgr = new ModelManager(this);

    // init database path
    FileHelper::mkdir(CONF::PATH::TEMP);
    // init log path
    FileHelper::mkdir(CONF::PATH::LOG_DIR);
    // init plugins
    pluginMgr->installPlugins(argc, argv);

    // init stylesheet
    QString qssStr = FileHelper::readAllText(CONF::PATH::DEFAULT_QSS_PATH);
    qApp->setStyleSheet(qssStr);

    // init database
    dbMgr->init();

}






