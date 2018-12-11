#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void handleData(signed long long data);

signals :
    void sendLong(signed long long);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
