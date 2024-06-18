#ifndef TESTSTATICLIB_H
#define TESTSTATICLIB_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QtPlugin>

class TestStaticLib : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TestStaticLib(QObject *parent = nullptr);

signals:
};
//Q_IMPORT_PLUGIN(liblogicmodule)

#endif // TESTSTATICLIB_H
