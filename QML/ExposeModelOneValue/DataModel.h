#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "Car.h"

class DataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    DataModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    void updateDataChanged();
    Q_INVOKABLE Car *getCar(int idx);

private :
    QList<Car*> m_cars;
};

#endif // DATAMODEL_H
