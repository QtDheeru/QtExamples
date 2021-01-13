#include "hedderforprintreceipt.h"

hedderForPrintReceipt::hedderForPrintReceipt(QWidget *parent) : QWidget(parent)
{
    QPixmap image1("://abc1.jpg");
    QPixmap imag3= image1.scaled(200,200);
    QPixmap image2("://123.jpg");
    QPixmap imag4= image2.scaled(200, 200);
    line1 =new QLabel(tr("SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST"));
    line1->setStyleSheet("QLabel {color : '#000000' ;font: 25pt Times New Roman}");
    line3 =new QLabel(tr("Regd.off : Sri Seetharama Mandira"));
    line3->setStyleSheet("QLabel {color : '#000000' ;font: 18pt Times New Roman}");
    line4 =new QLabel(tr("Survey No.8, Sri Raghavendraswamy Mata Road"));
    line4->setStyleSheet("QLabel {color : '#000000' ;font: 18pt Times New Roman}");
    line5 =new QLabel(tr("  9th Main 3rd Stage BEML Layout"));
    line5->setStyleSheet("QLabel {color : '#000000' ;font: 18pt Times New Roman}");
    line6 =new QLabel(tr("R R Nagar,Bangalore 560098"));
    line6->setStyleSheet("QLabel {color : '#000000' ;font: 18pt Times New Roman}");
    imageLabel1 =new QLabel;
    imageLabel1->setPixmap(imag3);
    imageLabel2 =new QLabel;
    imageLabel2->setPixmap(imag4);
    v1 =new QVBoxLayout;
    v1 =new QVBoxLayout;
    mainv1 =new QVBoxLayout;
    mainv2 =new QVBoxLayout;
    h1=new QHBoxLayout;
    h2=new QHBoxLayout;
    h3=new QHBoxLayout;
    h4=new QHBoxLayout;
    mainh1=new QHBoxLayout;
    v1->addWidget(line1,0,Qt::AlignCenter);
    v1->addWidget(line3,0,Qt::AlignCenter);
    v1->addWidget(line4,0,Qt::AlignCenter);
    v1->addWidget(line5,0,Qt::AlignCenter);
    v1->addWidget(line6,0,Qt::AlignCenter);
    mainv1->addWidget(imageLabel1,0,Qt::AlignLeft);
    mainv2->addWidget(imageLabel2,0,Qt::AlignRight);
    mainh1->addLayout(mainv1);
    mainh1->addLayout(v1);
    mainh1->addLayout(mainv2);
    this->setLayout(mainh1);
}
void hedderForPrintReceipt::paintEvent(QPaintEvent *event)
{
    //qDebug()<<Q_FUNC_INFO<<event<<endl;

    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(5, 3, 13));
    painter.setPen(pen);
    painter.setBrush(QColor(204, 204, 255));
    painter.drawRect(rect);
}
