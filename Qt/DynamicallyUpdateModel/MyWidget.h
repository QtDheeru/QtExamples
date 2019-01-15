#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>
#include "DataGeneratorWorker.h"
#include "SitaViewModel.h"

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
    SitaViewModel *m_customModel;
    DataGeneratorWorker *m_dataWorker;
};

#endif // MYWIDGET_H
