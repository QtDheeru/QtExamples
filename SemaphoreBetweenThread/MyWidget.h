#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>
#include "Producer.h"
#include "Consumer.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    void setDataConsumer(int sum);
    void setDataProducer(int sum);


private slots:
    void on_pushButton_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButton_Stop_clicked();

private:
    Ui::MyWidget *ui;
    Producer     *m_Producer;
    Consumer     *m_Consumer;
    QSemaphore   *m_semLock;
};

#endif // MYWIDGET_H
