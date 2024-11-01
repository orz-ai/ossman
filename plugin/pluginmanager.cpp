
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

    //������������У��������в������ȼ���ߣ�����ֱ�Ӽ��������ļ��е�������Ϣ
    VersionCmd version(argc, argv);
    if(version.isValid()){
        mVersion = new VersionCmd(argc, argv);
    }else{
        mVersion = new VersionJson(CONF::VERSION::JSON_PATH);
    }

    mVersion->setVersion();    //�������ļ��ж�ȡ�汾��
    if(mVersion->major() == CONF::VERSION::MAJOR_BUSINESS){
        mClouds = new CosCloud();
    }

    //Ϊ��־�������లװ���
    GM->mLog->setLogger(new QDebugLogger());
}

