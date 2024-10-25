
#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H


#include <QObject>
#include <QWidget>


class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = nullptr);
    ~PluginManager();



signals:

};

#endif // PLUGINMANAGER_H
