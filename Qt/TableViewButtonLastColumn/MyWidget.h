#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QDebug>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

private :
    QTableView *m_tabView;
    QStandardItemModel *m_model;
    QHBoxLayout  *m_hlyt;
};

#endif // MYWIDGET_H
