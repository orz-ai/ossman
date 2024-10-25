
#ifndef CLOUDMODEL_H
#define CLOUDMODEL_H


#include <QObject>
#include <QWidget>

struct BaseObject {
    bool isValid() const {return !isInvalid();}
    bool isInvalid() const {return name.isNull() || name.isEmpty();}
    QString name;
};
// �ź����Զ����������Ҫ���������
Q_DECLARE_METATYPE(BaseObject);


struct MyBucket : public BaseObject
{
    MyBucket();
    QString location;
    QString createDate;
};
Q_DECLARE_METATYPE(MyBucket);

struct MyObject: public BaseObject
{
    bool isDir() const{return isValid() && name.endsWith("/");}
    bool isFile() const{return isValid() && !name.endsWith("/");}

    QString lastModified;
    qulonglong size = 0;
    QString dir;
    QString key;
};

#endif // CLOUDMODEL_H
