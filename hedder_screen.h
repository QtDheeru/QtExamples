#ifndef HEDDER_SCREEN_H
#define HEDDER_SCREEN_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QPainter>
#include<QDebug>
#include<QPaintEvent>
class hedder_screen : public QWidget
{
    Q_OBJECT
public:
    explicit hedder_screen(QWidget *parent = nullptr);
    QLabel*imageLabel1,*imageLabel2,*line1,*line2,*line3,*line4,*line5,*line6,*line7;
    QHBoxLayout *mainh1;
    QHBoxLayout *h1,*h2,*h3,*h4;
    QVBoxLayout *mainv1,*mainv2,*mainv3;
    QVBoxLayout *v1;
    void paintEvent(QPaintEvent *event)override;
    void receipt();
~hedder_screen();
signals:

public slots:
};

#endif // HEDDER_SCREEN_H
