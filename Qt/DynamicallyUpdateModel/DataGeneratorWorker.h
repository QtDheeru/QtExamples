#ifndef DATAGENERATORWORKER_H
#define DATAGENERATORWORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QThread>

class DataGeneratorWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataGeneratorWorker(QObject *parent = nullptr);

signals:
    void sendData(int val);

public slots:

    void generateData();

private :
    int count;
};

#endif // DATAGENERATORWORKER_H
