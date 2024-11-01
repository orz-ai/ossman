
#include "pluginmanager.h"
#include "config/versioncmd.h"
#include "config/global.h"
#include "middle/globalmanager.h"
#include "bend/service/cloud/coscloud.h"
#include "config/common.h"
#include "bend/service/config/versionjson.h"
#include "bend/service/log/qdebuglogger.h"

PluginManager::PluginManager(QObject *parent)
    : QObject{parent}
{

}

PluginManager::~PluginManager()
{

}

CommonCloud *PluginManager::clouds() const
{
    qDebug("PluginManager::clouds() mClouds: %p", mClouds);
    return mClouds;

}

void PluginManager::installPlugins(int argc, char *argv[])
{

    //如果输入命令行，则命令行参数优先级最高，否则直接加载配置文件中的配置信息
    VersionCmd version(argc, argv);
    if(version.isValid()){
        mVersion = new VersionCmd(argc, argv);
    }else{
        mVersion = new VersionJson(CONF::VERSION::JSON_PATH);
    }

    mVersion->setVersion();    //从配置文件中读取版本号
    if(mVersion->major() == CONF::VERSION::MAJOR_BUSINESS){
        mClouds = new CosCloud();
    }

    //为日志代理单例类安装插件
    GM->mLog->setLogger(new QDebugLogger());
}

