#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QString author MEMBER m_author NOTIFY authorChanged)
public:
    Message(QObject *parent = nullptr);
    Q_INVOKABLE bool print();

signals:
    void authorChanged();

private:
    QString m_author;
};

#endif // MESSAGE_H
