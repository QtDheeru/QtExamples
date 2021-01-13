#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QWidget>
#include<QPainter>
#include<QPalette>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QDebug>
#include<QLabel>
#include<QComboBox>
#include<QGroupBox>
#include"seva_receipt.h"
#include"currentreport.h"
#include"bookingreport.h"
#include"login.h"
#include"dbfile.h"
#include"fullsevatransactiondetails.h"
#include"seva_booking_receipt.h"
class adminScreen : public QWidget
{
    Q_OBJECT
public:
    explicit adminScreen(QWidget *parent = nullptr);
    QPushButton *but1,*but2,*but3,*but4,*but5;
    QHBoxLayout *h1,*h2,*h3,*h4,*hbox1;
    QVBoxLayout *v1,*v2,*v3;
    QComboBox *alltype;
    QWidget *w1,*w2;
    QPixmap *image;
    QGroupBox *g_box,*g_box1,*g_box2;
    QLabel *line1;

    bookingReport *breport;
    CurrentReport *creport;
    seva_receipt *seva;
    dbfile *db;
    fullSevaTransactionDetails *full;
    seva_booking_receipt *seva_booking;
    login *log;
    //    void paintEvent(QPaintEvent *event)override;
~adminScreen();
signals:

public slots:
    void buttonClicked();
    void displaying_type(int);
    void closingProgram();
//    void alldisplay();

private:
    QList<QString> list;
};

#endif // ADMINSCREEN_H
