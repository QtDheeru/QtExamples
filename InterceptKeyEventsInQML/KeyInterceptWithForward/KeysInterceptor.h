#ifndef KEYSINTERCEPTOR_H
#define KEYSINTERCEPTOR_H

#include <QObject>
#include <QDebug>

class KeysInterceptor : public QObject
{
    Q_OBJECT
public:
    explicit KeysInterceptor(QObject *parent = nullptr);

public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // KEYSINTERCEPTOR_H
