#include "mainscreen.h"

mainScreen::mainScreen(QWidget *parent) : QWidget(parent)
{

}

void mainScreen::paintEvent(QPaintEvent *event)
{
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(5, 3, 13));
    painter.setPen(pen);
    painter.setBrush(QColor(255, 0, 17));
    painter.drawRect(rect);
}
