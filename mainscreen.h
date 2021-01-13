#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include<QPainter>
#include<QPaintEvent>
#include<QComboBox>
#include <QHBoxLayout>

class mainScreen : public QWidget
{
    Q_OBJECT
public:
    explicit mainScreen(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event)override;


signals:
public slots:
};

#endif // MAINSCREEN_H
