#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QObject>
#include <QSlider>
#include <QDebug>

class MySlider : public QWidget
{
    Q_OBJECT
    Q_CLASSINFO("ClassID","{787719DC-8D8E-46bb-8FFE-FB9C58412B32}")
    Q_CLASSINFO("InterfaceID","{51FE15D0-C6D5-44d7-B1B7-E894CE386056}")
    Q_CLASSINFO("RegisterObject", "yes")
    Q_CLASSINFO("EventsID",    "{13eca64b-ee2a-4f3c-aa04-5d9d975979a7}")

public:
    explicit MySlider(QWidget *parent = nullptr);

public slots :
    void setValue(int val);
signals:

private :
    QSlider *m_slider;
};

#endif // MYSLIDER_H
