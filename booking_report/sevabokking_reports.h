#ifndef SEVABOKKING_REPORTS_H
#define SEVABOKKING_REPORTS_H

#include <QObject>
#include <QWidget>
class sevabokking_reports : public QObject
{
    Q_OBJECT
public:
    explicit sevabokking_reports(QObject *parent = nullptr);
signals:

public slots:
    void  data();
};

#endif // SEVABOKKING_REPORTS_H
