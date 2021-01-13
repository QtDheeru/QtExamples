#include "mylabel.h"

mylabel:: mylabel(QLabel *parent):QLabel(parent)
{

}
mylabel:: mylabel(QWidget *parent):QLabel(parent)
{

}
void mylabel:: mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<ev<<endl;
    emit mylabelclicked();
}

void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<<ev<<endl;
    emit mynewlabelclicked();

}
