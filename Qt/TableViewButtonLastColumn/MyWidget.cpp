#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    this->m_tabView = new QTableView;
    this->m_model = new QStandardItemModel(5, 7);
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 7; ++column) {
            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
            this->m_model->setItem(row, column, item);
        }
    }
    this->m_tabView->setModel(m_model);

    for(int i=0;i<5;i++){
        QStandardItem *itm = this->m_model->item(i,6);
        qDebug() << " Itm value =" << itm->data(Qt::DisplayRole).toString();
        QPushButton *b = new QPushButton(QString::number(1000+i));
        QModelIndex idx = this->m_model->indexFromItem(itm);
        QModelIndex id1 = this->m_model->index(i,6);
        if(!id1.isValid()){
            qDebug() << " Invalid index" << endl;
        }else {
            m_tabView->setIndexWidget(id1,b);
        }
    }
    this->m_hlyt = new QHBoxLayout(this);
    this->m_hlyt->addWidget(this->m_tabView);
}

MyWidget::~MyWidget()
{

}
