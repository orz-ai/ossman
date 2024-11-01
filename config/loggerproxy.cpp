
#include "loggerproxy.h"

LoggerProxy::LoggerProxy(QObject *parent)
    : QObject{parent}
{

}

LoggerProxy::~LoggerProxy()
{

}

const LoggerProxy &LoggerProxy::reset(const QString &file, int line, const QString &func)
{
    return *this;
}

void LoggerProxy::total(const QVariant &var, bool up)
{

}

void LoggerProxy::debug(const QVariant &var, bool up) const
{

}

void LoggerProxy::info(const QVariant &var, bool up) const
{

}

void LoggerProxy::warning(const QVariant &var, bool up) const
{

}

void LoggerProxy::error(const QVariant &var, bool up) const
{

}

void LoggerProxy::fatal(const QVariant &var, bool up) const
{

}

void LoggerProxy::setLevel(CONF::LOG_LEVEL newLevel)
{

}

void LoggerProxy::setLogger(BasicLogger *newLogger)
{

}

void LoggerProxy::doLog(CONF::LOG_LEVEL, const QVariant &var, bool up) const
{

}

//void LoggerProxy::sigLog(const QString &file, int line, const QString &func, void *tid, int level, const QVariant &var,
//                         bool up) const
//{
//
//}

