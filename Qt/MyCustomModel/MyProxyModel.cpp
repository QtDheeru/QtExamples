#include "MyProxyModel.h"

MyProxyModel::MyProxyModel(QObject *parent)
{

}

bool MyProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if (this->startRow==0){
        if (source_row == this->startRow)
            return true;
         else
            return false;
    }else {
        if (source_row >= this->startRow)
            return true;
         else
            return false;
    }
}

int MyProxyModel::getStartRow() const
{
    return startRow;
}

void MyProxyModel::setStartRow(int value)
{
    startRow = value;
}

int MyProxyModel::getEndRow() const
{
    return endRow;
}

void MyProxyModel::setEndRow(int value)
{
    endRow = value;
}
