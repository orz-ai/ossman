
#include "baseexception.h"
#include "helper/filehelper.h"
#include "config/global.h"

#include <qmap.h>


BaseException::BaseException(const QString& code, const QString& msg)
{
    ecode = code;
    emsg = msg;
}

ErrorMap BaseException::parseErrorCode(const QString &csvPath)
{
    ErrorMap emap;
    int sectionCount = 6;
    QList<QStringList> records = FileHelper::readAllCsv(csvPath);

    for(int i = 1; i < records.size(); ++i){
        auto record = records[i];
        QString code;
        QString msg;
        for(int j = 0; j < sectionCount; ++j){
            if(record[j] == "")
                code += "0";
            else{
                QStringList strs = record[j].split("_");
                msg += strs[0];
                code += strs[1];
            }
        }
        if(record[sectionCount] != "")
            msg = record[sectionCount];

        emap[code] = msg;
    }
    return emap;
}

void BaseException::generateErrorCodeHFile(const QString &csvPath, const QString &targetPath)
{
    QStringList rows;
    rows << "#ifndef ERRORCODE_H" << "#define ERRORCODE_H\n\n";

    ErrorMap errors = parseErrorCode(csvPath);
    ErrorMap::const_iterator iter = errors.constBegin();
    while(iter != errors.constEnd()){
        rows << QString::fromLocal8Bit("#define EC_%1 \"%1\" // %2").arg(iter.key(), iter.value());
        ++iter;
    }
    rows << "\n\n#endif // ERRORCODE_H";
    FileHelper::writeFile(rows, targetPath);
}

QString BaseException::msg() const
{
    static ErrorMap m_map = BaseException::parseErrorCode(CONF::PATH::ERROR_CODE_PATH);
    QString m = QString::fromLocal8Bit("´íÎó(%1): %2").arg(ecode, m_map[ecode]);
    if(emsg != "")
        m += QString::fromLocal8Bit(", ÏêÇé: %1").arg(emsg);
    return m;
}

QString BaseException::code() const
{
    return ecode;
}
