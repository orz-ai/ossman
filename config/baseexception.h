
#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H


#include <QObject>


typedef QMap<QString, QString> ErrorMap;
class BaseException
{
public:
    BaseException(const QString& code, const QString& msg);

    static ErrorMap parseErrorCode(const QString& csvPath);

    static void generateErrorCodeHFile(const QString& csvPath, const QString& targetPath);

    QString msg() const;

    QString code() const;

private:
    QString ecode;

    QString emsg;
};

#endif // EXCEPTION_H
