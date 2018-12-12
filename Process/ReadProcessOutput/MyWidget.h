#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QProcess>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

public slots:
    void readData();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
    QProcess *proc;
};

#endif // MYWIDGET_H
