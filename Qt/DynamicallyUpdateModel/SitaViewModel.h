#ifndef SITAVIEWMODEL_H
#define SITAVIEWMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include <QList>
#include <QTimer>

class SitaViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    SitaViewModel();
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
public slots :
    void insertData();
    void startInsert();
    void addData(int val);
    void updateData();

private :
    QList<int> a;
    int m_idex;
};

#endif // SITAVIEWMODEL_H
