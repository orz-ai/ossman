
#include "filehelper.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>

FileHelper::FileHelper()
{
}

QString FileHelper::readAllText(const QString &filePath)
{
    QFile file(filePath);
    if (file.exists() && file.open(QIODevice::ReadOnly)){
        QByteArray content = file.readAll();
        file.close();

        return content;
    }

    qDebug() << filePath << " not exist";
    throw "file not exist";
}

QVariant FileHelper::readAllJson(const QString &filePath)
{
    QString content = FileHelper::readAllText(filePath);
    QJsonDocument json = QJsonDocument::fromJson(content.toLocal8Bit());

    return json.toVariant();
}

QList<QStringList> FileHelper::readAllCsv(const QString &filePath)
{
    QList<QStringList> records;
    QFile file(filePath);
    if (!file.exists() || !file.open(QIODevice::ReadOnly)){
        return records;
    }

    QTextStream stream(&file);
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList row = line.split(',');
        records.append(row);
    }

    file.close();
    return records;
}

void FileHelper::writeFile(const QStringList lines, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)){
        throw "open file for writing failed.";
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    for(const auto& line: lines) {
        stream << line << endl;
    }
    file.close();
    return;
}

QString FileHelper::joinPath(const QString &path1, const QString &path2)
{
    QString path = path1 + "/" + path2;
    QStringList pathList = path.split(QRegExp("[/\\\\]"), Qt::SkipEmptyParts);
    path = pathList.join("/");
    return QDir::cleanPath(path);
}

bool FileHelper::mkdir(const QString &path)
{
    QDir dir;
    return dir.mkdir(path);
}

