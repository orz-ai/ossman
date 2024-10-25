
#ifndef BASICLOGGER_H
#define BASICLOGGER_H


#include <QObject>
#include <QThread>


class BasicLogger: public QObject
{
    Q_OBJECT
public:
    explicit BasicLogger(QObject *parent = nullptr);
    ~BasicLogger();

protected:
    virtual void print(const QString& file, int line, const QString& func, void* tid, int level, const QVariant& var, bool up) = 0;
    static QString filePath();

private:
    QThread* mTd = nullptr;

public slots:
    void onLog(const QString& file, int line, const QString& func, void* tid, int level, const QVariant& var, bool up);

};

#endif // BASICLOGGER_H
