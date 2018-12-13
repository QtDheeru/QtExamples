#ifndef TIMERHANDLING_H
#define TIMERHANDLING_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include "GPRS.h"

namespace Ui {
class TimerHandling;
}

class TimerHandling : public QWidget
{
    Q_OBJECT

public:
    explicit TimerHandling(QWidget *parent = 0);
    ~TimerHandling();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TimerHandling *ui;
    GPRS *m_gprs;
};

#endif // TIMERHANDLING_H
