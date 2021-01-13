#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <QString>

using namespace std;

struct SigninDetails{
    QString firstName;
    QString LastName;
    QString UserName;
    QString Password;   
};

typedef struct print_details Print_Detail;

struct print_details
{
    QString NAME;
    QString RECPT_NO;
    QString MOB_NO;
    QString DATE;
    QString GOTHRA;
    QString SEVA_DATE;
    QString NAKSHATRA;
    QString SEVA_TIME;
    QString SL_NO;
    QString SEVA_DESCR;
    QString QTY;
    QString AMT;
    QString RATE;
    QString TOTAL_AMT;
    QString TOTAL_IN_WORDS;
    QString NOTE;
    QString CASH;
    QString BANK_REF;

};

#endif // COMMON_H
