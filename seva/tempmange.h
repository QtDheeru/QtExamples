#ifndef TEMPMANGE_H
#define TEMPMANGE_H
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include<QObject>
#include "seva_type.h"
#include "table_view_type.h"
#include"table_view_seva.h"
#include "dbfile.h"
#include"mainscreen.h"
#include"addnewseva.h"
#include "hedderforprintreceipt.h"
#include<QScreen>
class Tempmange : public QWidget
{
    Q_OBJECT
public:
    explicit Tempmange(QWidget *parent = nullptr);
    QHBoxLayout *h1,*h2,*h3;
    QVBoxLayout *v1;

    addnewseva *add;
    mainScreen *m;
    seva_type *w;
    table_view_type *table_type ;
    table_view_seva *table_seva;
    dbfile *db;
    hedderForPrintReceipt *hedder;
    void t_mange(QString);
    void paintEvent(QPaintEvent *event);
    ~Tempmange();
signals:

public slots:
};


#endif // TEMPMANGE_H
