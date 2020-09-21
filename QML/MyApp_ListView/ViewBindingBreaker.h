#pragma once

#include <QObject>
#include <QDebug>

class ViewBindingBreaker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int topIndex READ topIndex WRITE setBottomIndex NOTIFY topIndexChanged)
    Q_PROPERTY(int bottomIndex READ bottomIndex WRITE setBottomIndex NOTIFY bottomIndexChanged)
public:
    explicit ViewBindingBreaker(QObject *parent = nullptr);

    int topIndex() const;
    Q_INVOKABLE void setTopIndex(int topIndex);

    int bottomIndex() const;
    Q_INVOKABLE void setBottomIndex(int bottomIndex);

signals:
    void topIndexChanged(int);
    void bottomIndexChanged(int);

    void moveTopView(int topIndex);
    void moveBottomView(int bottomIndex);

private :
    int m_topIndex;
    int m_bottomIndex;
};

