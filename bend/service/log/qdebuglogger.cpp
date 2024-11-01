
#include <QDateTime>
#include "qdebuglogger.h"
#include "config/common.h"
#include "config/global.h"
#include <QDebug>
#include <iostream>

QDebugLogger::QDebugLogger(QObject *parent)
    : BasicLogger{parent}
{
    qInstallMessageHandler(handle);
}

QDebugLogger::~QDebugLogger()
{
}

void QDebugLogger::print(const QString &file, int line, const QString &func, void *tid, int level, const QVariant &var,
                         bool up)
{
    QDateTime dt;
    QString dtStr = dt.currentDateTime().toString(Qt::ISODate);
    QString front = STR("%1 [%2] %3:%4 -").arg(dtStr, CONF::LOG_NAMES[level], file, QString::number(line));
    front = front.replace("..\\", "");

    qDebug() << front.toLocal8Bit().data() << var;
}

void QDebugLogger::handle(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile file(filePath());

    QString key("QVariant(");
    QString message = msg;
    message.replace(msg.indexOf(key), key.size(), "").chop(1);

    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        out << message << "\n";
        file.close();
    }

    std::cout << message.toStdString() << std::endl;
}

