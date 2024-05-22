#ifndef MYSUM_H
#define MYSUM_H

#include <QObject>

class MySum : public QObject
{
    Q_OBJECT
        // ClassID->This should be used for set control
    Q_CLASSINFO("ClassID", "{7E7250E5-F595-43f0-8FFA-967B07A858A5}")
    // Did not use this ID anywhere. Not aware of the use now.
    Q_CLASSINFO("InterfaceID", "{BDCDB0EE-98C9-41cc-BB3D-8CC7154B13CD}")
    // Not aware of this usage.
    Q_CLASSINFO("RegisterObject", "yes")
    // Not aware of the EventsID usage.
    Q_CLASSINFO("EventsID",    "{13eca64b-ee2a-4f3c-aa04-5d9d975979a7}")

public:
    explicit MySum(QObject *parent = nullptr);
public slots :
    int sum(int x, int y);

signals:
};

#endif // MYSUM_H
