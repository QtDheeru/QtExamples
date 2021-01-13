#ifndef SEVA_BOOKING_BACK_H
#define SEVA_BOOKING_BACK_H

#include <QObject>
#include"seva_booking_receipt.h"
class seva_booking_back : public QObject
{
    Q_OBJECT
public:
    explicit seva_booking_back(QObject *parent = nullptr);
    seva_booking_receipt *seva;
signals:

public slots:
};

#endif // SEVA_BOOKING_BACK_H
