#ifndef HWDEVICE_H
#define HWDEVICE_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class HWDevice : public QObject
{
    Q_OBJECT
public:
    explicit HWDevice(QObject *parent = nullptr);

signals:
    void data1();
    void data2();

public slots:
};

#endif // HWDEVICE_H
