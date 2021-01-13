#include "tempmange.h"

Tempmange::Tempmange(QWidget *parent) : QWidget(parent)
{

}
void Tempmange::t_mange(QString username)
{
    add =new addnewseva;
    w = new seva_type;
    table_type = new table_view_type;
    table_seva = new table_view_seva;
    hedder =new hedderForPrintReceipt;
    db = dbfile::getInstance();
    h1=new QHBoxLayout;
    h2=new QHBoxLayout;
    h3=new QHBoxLayout;
    v1=new QVBoxLayout;
    h1->addWidget(hedder);
    h2->addWidget(w);
    h2->addWidget(table_type);
    h3->addWidget(add);
    h3->addWidget(table_seva);
    v1->addLayout(h1);
    v1->addLayout(h2);
    v1->addLayout(h3);

    QScreen *displayscreensize = QGuiApplication::primaryScreen();
    QRect  screenGeometry = displayscreensize->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    this->resize(width,height);
    this->show();

    QObject::connect(w,SIGNAL(modifaid(int,int,QString,int,QString)),table_type,SLOT(modifaid_data(int,int,QString,int,QString)));
    QObject::connect(db,SIGNAL(get_data_db(QString,QString,QString,QString)),table_type,SLOT(print_data_db(QString,QString,QString,QString)));
    QObject::connect(db,SIGNAL(s_type_sig(QString)),add,SLOT(sevaType(QString)));
    QObject::connect(w,SIGNAL(Modify_db(int,QString,int,QString,int,QString,QString)),db,SLOT(modify_db_type(int,QString,int,QString,int,QString,QString)));
    QObject::connect(w,SIGNAL(deletedata(int)),db,SLOT(delete_db(int)));
    QObject::connect(table_type,SIGNAL(resivedata(int,int,QString,QString,QString)),w,SLOT(modifydata(int,int,QString,QString,QString)));
    QObject::connect(db,SIGNAL(seva_Name(int,QString,int,QString,QString,int,QString,int)),table_seva,SLOT(chek_seva(int,QString,int,QString,QString,int,QString,int)));
    QObject::connect(db,SIGNAL(seva_types_adding(QList<QString>)),add,SLOT(collectingSeva(QList<QString>)));
    QObject::connect(add,SIGNAL(sevaName(int,QString,int,QString,QString,int,QString,int)),db,SLOT(chek_sevaname_allreadyexist(int,QString,int,QString,QString,int,QString,int)));
    QObject::connect(db,SIGNAL(modifying_seva(int,int,QString,int,QString,QString,int,QString,int)),table_seva,SLOT(modifaid_data_seva(int,int,QString,int,QString,QString,int,QString,int)));
    QObject::connect(db,SIGNAL(sevaname( QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)),table_seva,SLOT(print_data_db( QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>, QList<QString>)));
    QObject::connect(table_seva,SIGNAL(seva_resived(int,int,QString,QString,QString,QString)),add,SLOT(modify_seva(int,int,QString,QString,QString,QString)));

    add->seva();
    w->user_name(username);
    add->user_name(username);
    this->setLayout(v1);
}

void Tempmange::paintEvent(QPaintEvent *event)
{
    //qDebug()<<Q_FUNC_INFO<<event<<endl;
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(5, 3, 13));
    painter.setPen(pen);
    painter.setBrush(QColor(255, 0, 17));
    painter.drawRect(rect);
}
Tempmange::~Tempmange()
{

}
