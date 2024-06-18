#ifndef STATICPLUGIN_H
#define STATICPLUGIN_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QtPlugin>

class StaticPlugin : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit StaticPlugin(QObject *parent = nullptr);

signals:
};
//Q_IMPORT_PLUGIN(StaticPlugin)

#endif // STATICPLUGIN_H
