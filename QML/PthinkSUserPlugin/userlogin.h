#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QQuickItem>

class UserLogin : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(UserLogin)

public:
    UserLogin(QQuickItem *parent = nullptr);
    ~UserLogin();
};

#endif // USERLOGIN_H
