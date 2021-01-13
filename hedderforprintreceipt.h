#ifndef HEDDERFORPRINTRECEIPT_H
#define HEDDERFORPRINTRECEIPT_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include<QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QPainter>
#include<QDebug>
#include<QPaintEvent>

class hedderForPrintReceipt : public QWidget
{
    Q_OBJECT
public:
    explicit hedderForPrintReceipt(QWidget *parent = nullptr);
    QLabel*imageLabel1,*imageLabel2,*line1,*line2,*line3,*line4,*line5,*line6,*line7;
    QHBoxLayout *mainh1;
    QHBoxLayout *h1,*h2,*h3,*h4;
    QVBoxLayout *mainv1,*mainv2,*mainv3;
    QVBoxLayout *v1;
    void paintEvent(QPaintEvent *event)override;

signals:

public slots:
};

#endif // HEDDERFORPRINTRECEIPT_H
