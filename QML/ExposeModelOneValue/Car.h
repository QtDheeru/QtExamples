#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

public:
    explicit Car(QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString &value);

    void updateName();
signals:
    void nameChanged();

public slots:


private :
    QString name;
    int count;
};

#endif // CAR_H
