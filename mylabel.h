#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>


class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QLabel *parent = 0);
    explicit mylabel(QWidget *parent = 0);
signals:
    void mylabelclicked();
    void mynewlabelclicked();
public slots:
protected:
     void mousePressEvent(QMouseEvent *ev);
     void mouseMoveEvent(QMouseEvent *ev);
};

#endif // MYLABEL_H
