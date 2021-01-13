#include "seva_booking_back.h"

seva_booking_back::seva_booking_back(QObject *parent) : QObject(parent)
{
seva = new seva_booking_receipt;
}
