#include "MySlider.h"

MySlider::MySlider(QWidget *parent)
    : QWidget{parent}
{

    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_slider = new QSlider(this);
    m_slider->resize(400,200);
    this->resize(400,200);
    connect(m_slider,&QSlider::sliderMoved,this,[](int val){
        qDebug()<< " Value =" << val << Qt::endl;
    });
}

void MySlider::setValue(int val)
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    this->m_slider->setValue(val);
}
