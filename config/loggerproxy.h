
#ifndef LOGGERPROXY_H
#define LOGGERPROXY_H


#include <QObject>
#include <bend/service/log/basiclogger.h>
#include "config/global.h"


class LoggerProxy : public QObject
{
    Q_OBJECT
public:
    explicit LoggerProxy(QObject *parent = nullptr);
    ~LoggerProxy();

    const LoggerProxy& reset(const QString& file, int line, const QString& func);

    void total(const QVariant& var, bool up=false);
    void debug(const QVariant& var, bool up=false) const;
    void info(const QVariant& var, bool up=false) const;
    void warning(const QVariant& var, bool up=false) const;
    void error(const QVariant& var, bool up=true) const;
    void fatal(const QVariant& var, bool up=true) const;

    void setLevel(CONF::LOG_LEVEL newLevel);
    void setLogger(BasicLogger *newLogger);

private:
    BasicLogger *mLogger = nullptr;
    CONF::LOG_LEVEL mLevel;
    QString  mFile;
    int mLine;
    QString mFunc;

    void doLog(CONF::LOG_LEVEL, const QVariant& var, bool up) const;

signals:
    void sigLog(const QString& file, int line, const QString& func, void* tid, int level, const QVariant& var, bool up) const;

};

#endif // LOGGERPROXY_H
