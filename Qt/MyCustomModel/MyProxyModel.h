#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QDebug>
class MyProxyModel : public QSortFilterProxyModel
{
public:
    MyProxyModel(QObject *parent = 0);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

    int getStartRow() const;
    void setStartRow(int value);

    int getEndRow() const;
    void setEndRow(int value);

private :
    int startRow;
    int endRow;
};

#endif // MYPROXYMODEL_H
