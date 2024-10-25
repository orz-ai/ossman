
#include "basiclogger.h"
#include "qdatetime.h"
#include "config/global.h"

BasicLogger::BasicLogger(QObject *parent)
    : QObject{parent}
{
    mTd=new QThread();
    moveToThread(mTd);
    mTd->start();
}


BasicLogger::~BasicLogger()
{
    if(mTd->isRunning()){
        mTd->quit();
        if(mTd->wait(1000)){
            mTd->terminate();
            mTd->wait(1000);
        }
    }
    delete mTd;
}


void BasicLogger::onLog(const QString &file, int line, const QString &func, void *tid, int level, const QVariant &var, bool up)
{
    print(file, line, func, tid, level, var, up);
}


QString BasicLogger::filePath()
{
    QString name = QDate::currentDate().toString(Qt::ISODate);
    return FileHelper::joinPath(CONF::PATH::LOG_DIR, QString::fromLocal8Bit("%1.log").arg(name));
}

