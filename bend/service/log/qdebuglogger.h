
#ifndef QDEBUGLOGGER_H
#define QDEBUGLOGGER_H


#include <QObject>
#include "basiclogger.h"


class QDebugLogger : public BasicLogger
{
    Q_OBJECT
public:
    explicit QDebugLogger(QObject *parent = nullptr);
    ~QDebugLogger();

protected:
    virtual void print(const QString& file, int line, const QString& func, void* tid, int level, const QVariant& var, bool up);

private:
    static void handle(QtMsgType type, const QMessageLogContext &context, const QString &msg);

signals:

};

#endif // QDEBUGLOGGER_H
