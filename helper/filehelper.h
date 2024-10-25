
#ifndef FILEHELPER_H
#define FILEHELPER_H


#include <QObject>


class FileHelper : public QObject
{
    Q_OBJECT
public:
    FileHelper();

    static QString readAllText(const QString& filePath);
    static QVariant readAllJson(const QString& filePath);
    static QList<QStringList> readAllCsv(const QString& filePath);

    static void writeFile(const QStringList lines, const QString& filePath);

    static QString joinPath(const QString& path1, const QString& path2);
    static bool mkPath(const QString& path);

signals:

};

#endif // FILEHELPER_H
