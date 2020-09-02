#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class ImageModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum {
        NAME=Qt::UserRole+1
    };

    ImageModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private :
    QList<QString> m_items;
    bool firstTime = true;
    int m_size;
};

#endif // IMAGEMODEL_H
