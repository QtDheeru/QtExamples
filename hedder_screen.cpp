#include "hedder_screen.h"

hedder_screen::hedder_screen(QWidget *parent) : QWidget(parent)
{

}

void hedder_screen::paintEvent(QPaintEvent *event)
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

void hedder_screen::receipt()
{
    line1 =new QLabel(tr("SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST"));
    line1->setStyleSheet("QLabel {color : '#000000' ;font: 14pt Times New Roman}");
    //line2 =new QLabel(tr("AND CHARITABLE TRUST"));
    //line2->setStyleSheet("QLabel {color : '#000000' ;font: 14pt Times New Roman}") ;
    line3 =new QLabel(tr("Regd.off : Sri Seetharama Mandira"));
    line3->setStyleSheet("QLabel {color : '#000000' ;font: 14pt Times New Roman}");
    line4 =new QLabel(tr("Survey No.8, Sri Raghavendraswamy Mata Road, 9th Main, 3rd Stage BEML Layout"));
    line4->setStyleSheet("QLabel {color : '#000000' ;font: 12pt Times New Roman}");
//    line5 =new QLabel(tr("9th Main 3rd Stage BEML Layout"));
//    line5->setStyleSheet("QLabel {color : '#000000' ;font: 12pt Times New Roman}");
    line6 =new QLabel(tr("R R Nagar,Bangalore 560098      Phone Num : 080-41206779"));
    line6->setStyleSheet("QLabel {color : '#000000' ;font: 12pt Times New Roman}");
    line7 =new QLabel(tr("Office Timings: 8AM to 1PM  & 6PM to 8.30PM"));
    line7->setStyleSheet("QLabel {color : '#000000' ;font: 14pt Times New Roman;font-weight: bold;}");

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
//    v1->addWidget(line2,0,Qt::AlignCenter);
    v1->addWidget(line3,0,Qt::AlignCenter);
    v1->addWidget(line4,0,Qt::AlignCenter);
//    v1->addWidget(line5,0,Qt::AlignCenter);
    v1->addWidget(line6,0,Qt::AlignCenter);
    v1->addWidget(line7,0,Qt::AlignCenter);
    mainh1->addLayout(v1);
    mainh1->addLayout(mainv2);
    this->setLayout(mainh1);
    this->show();
}

hedder_screen::~hedder_screen()
{

}
