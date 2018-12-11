#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QDebug>
class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr);

signals:

public slots:
    void handleData(signed long long dt);
};

#endif // DATAHANDLER_H
