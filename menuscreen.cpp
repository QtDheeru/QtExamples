#include "menuscreen.h"

menuScreen::menuScreen(QWidget *parent) : QWidget(parent)
{
    data=0;
    m_hbox1 = new QHBoxLayout;
    m_hbox2 = new QHBoxLayout;
    m_hbox3 = new QHBoxLayout;
    m_hbox4 = new QHBoxLayout;
    m_hbox5 = new QHBoxLayout;
    m_hbox6 = new QHBoxLayout;
    m_vbox1=new QVBoxLayout;
    m_button1 =new QPushButton(tr("SEVA BOOKING"));
    m_button1->setMinimumSize(300,50);
    m_button1->setStyleSheet("background-color:#ccffcc;border:4px solid #000000;");
    m_button1->setFont(QFont("Times NEw Roman",m_button1->height() * 0.04));
    m_button2 =new QPushButton(tr("ACCOUNT DETAILS"));
    m_button2->setMinimumSize(300,50);
    m_button2->setStyleSheet("background-color: #99ff99;border:4px solid #000000;");
    m_button2->setFont(QFont("Times NEw Roman",m_button2->height() * 0.04));
    m_button3 =new QPushButton(tr("BOOKING REPORT"));
    m_button3->setMinimumSize(300,50);
    m_button3->setStyleSheet("background-color:#33ff33;border:4px solid #000000;");
    m_button3->setFont(QFont("Times NEw Roman",m_button3->height() * 0.04));

    m_button4 =new QPushButton(tr("ADMIN"));
    m_button4->setMinimumSize(300,50);
    m_button4->setStyleSheet("background-color: #1aff1a;border:4px solid #000000;");
    m_button4->setFont(QFont("Times NEw Roman",m_button4->height() * 0.04));
    m_button5 =new QPushButton(tr("CLOSE PROJECT"));
    m_button5->setMinimumSize(300,50);
    m_button5->setStyleSheet("background-color: #00cc00;border:4px solid #000000;");
    m_button5->setFont(QFont("Times NEw Roman",m_button5->height() * 0.04));
    m_hbox1->addWidget(m_button1);
    m_hbox2->addWidget(m_button2);
    m_hbox3->addWidget(m_button3);
    m_hbox4->addWidget(m_button4);
    m_hbox5->addWidget(m_button5);
    m_vbox1->addLayout(m_hbox1);
    m_vbox1->addLayout(m_hbox2);
    m_vbox1->addLayout(m_hbox3);
    m_vbox1->addLayout(m_hbox4);
    m_vbox1->addLayout(m_hbox5);
    this->setLayout(m_vbox1);
    this->setWindowTitle("MENU");
    connect(m_button1,SIGNAL(clicked()),this,SLOT(button1pressed()));
    connect(m_button2,SIGNAL(clicked()),this,SLOT(button2pressed()));
    connect(m_button3,SIGNAL(clicked()),this,SLOT(button3pressed()));
    connect(m_button4,SIGNAL(clicked()),this,SLOT(button4pressed()));
    connect(m_button5,SIGNAL(clicked()),this,SLOT(button5pressed()));

}

void menuScreen::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setWidth(10);
    QRect rect = this->rect();
    QPainter painter(this);
    pen.setColor(QColor(5, 3, 13));
    painter.setPen(pen);
    painter.setBrush(QColor("#ff80b3"));
    painter.drawRect(rect);
}


void menuScreen::button1pressed()
{
    data =0;
    emit type(data);
    dbfile::getInstance()->seva_type_adding();
    dbfile::getInstance()->gotra_list();
    dbfile::getInstance()->receipt_no_printing();

    qDebug()<<"SEVA BOOKING"<<data<<endl;
}

void menuScreen::button2pressed()
{
    data =1;
    emit type(data);
    qDebug()<<"ACCOUNT DETAILS"<<data<<endl;
    dbfile::getInstance()->seva_type_adding();
}

void menuScreen::button3pressed()
{
    data =2;
    emit type(data);
    qDebug()<<"BOOKING REPORT"<<data<<endl;
    dbfile::getInstance()->seva_type_adding();

}

void menuScreen::button4pressed()
{
    data =3;
    emit type(data);
    qDebug()<<"ADMIN"<<data<<endl;

}

void menuScreen::button5pressed()
{
    data =4;
    emit type(data);
    qDebug()<<"CLOSE PROJECT"<<data<<endl;

}

void menuScreen::menu_show()
{
    this->show();
}

menuScreen::~menuScreen()
{

}
