#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPen>
#include<QPainter>
#include<QDebug>

#include"dbfile.h"

class menuScreen : public QWidget
{
    Q_OBJECT
public:
    explicit menuScreen(QWidget *parent = nullptr);
    QPushButton *m_button1,*m_button2,*m_button3,*m_button4,*m_button5;
    QHBoxLayout *m_hbox1,*m_hbox2,*m_hbox3,*m_hbox4,*m_hbox5,*m_hbox6;
    QVBoxLayout *m_vbox1;
    void paintEvent(QPaintEvent *event);
    ~menuScreen();
signals:
    void type(int);

public slots:
    void button1pressed();
    void button2pressed();
    void button3pressed();
    void button4pressed();
    void button5pressed();
    void menu_show();

private:
    int data;

};

#endif // MENUSCREEN_H
