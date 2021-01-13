#ifndef PRINT_FILE_H
#define PRINT_FILE_H

#include <QWidget>
#include <QWidget>
#include <QFile>
#include<QList>
#include <QTextStream>
#include <QIODevice>
#include <QPrinter>
#include <QPainter>
#include <cassert>
#include <QDebug>
#include <QDate>
#include <QSvgGenerator>

#include "common.h"

class print_file : public QWidget
{
    Q_OBJECT
private:
    QString newfile;
    QString file_print;
    QString svg_file;
    QFile file;
    QDate current_date;
    QString s_date;
signals:

public:
    explicit print_file(QWidget *parent = nullptr);
    int write2file(QString ,QString ,QString,QString ,float ,QString );
    void PrinterPreview();
    int printing_file(QList<Print_Detail> *pd);
    int printing_file(QString , QString , QString , QString , QString , QString, QString, QString, int, QString, QString );
    void svg_receipt(QString , QString , QString , QString , QString, int, QString, QString, QString);
    void svg_voucher(QString,QString,QString,QString,int,QString);
    QList<QString> *list_seva;
    QList<float> *list_cost;
    QList<QString> *list_tickets;
    QList<QString> *list_sevadate;
    QList<QString> *voc_purpose;
    QList<QString> *voc_cat;
    QList<float> *voc_pri;
    void singleentry(QString, QString, int, QString);

    virtual void paintEvent(QPaintEvent *event);
};

#endif // PRINT_FILE_H
