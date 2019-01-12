#include "MyWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.resize(800,600);
    w.show();
//    QStandardItemModel model(4, 4);
//    for (int row = 0; row < 4; ++row) {
//        for (int column = 0; column < 4; ++column) {
//            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
//            model.setItem(row, column, item);
//            //qDebug() << item->data(Qt::DisplayRole);
//            QStandardItem *itm = model.item(row,column);
//            qDebug() << itm->data(Qt::DisplayRole);
//        }
//    }

    return a.exec();
}
