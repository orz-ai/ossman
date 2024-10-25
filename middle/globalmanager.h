
#ifndef GLOBALMANAGER_H
#define GLOBALMANAGER_H

#include <QObject>
#include <QWidget>
#include <config/loggerproxy.h>

#define GM GlobalManager::instance()
#define mLogIns GM->mLog
#define mTotle mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).total
#define mDebug mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug
#define mInfo mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).info
#define mWarning mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).warning
#define mError mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).error
#define mFatal mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).fatal


class CloudManager;
class DbManager;
class PluginManager;
class Gateway;
class SignalManager;
class LoggerProxy;
class ModelManager;


class GlobalManager: public QObject
{
    Q_OBJECT
public:
    explicit GlobalManager(QObject *parent = nullptr);
    ~GlobalManager();

    static GlobalManager* instance();
    void init(int argc, char *argv[]);

    LoggerProxy *mLog = nullptr;
    CloudManager *cloudMgr = nullptr;
    DbManager *dbMgr = nullptr;
    PluginManager *pluginMgr = nullptr;
    Gateway *gateway = nullptr;
    SignalManager *signalMgr = nullptr;
    ModelManager *modelMgr = nullptr;
};

#endif // GLOBALMANAGER_H
