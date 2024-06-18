#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QDebug>

class MySingleton : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    MySingleton(QObject *parent = nullptr)
        : QObject{parent}
    {}

public slots:
    QString exec(const QString &str) {
        qDebug() << Q_FUNC_INFO << " Some string =" << str;
        return (str+"somestring");
    }
};

#endif // MYSINGLETON_H
