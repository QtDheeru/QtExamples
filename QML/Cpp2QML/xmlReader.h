#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>
#include <QDebug>
#include <QDomDocument>

class xmlReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant helloText READ helloText WRITE setHelloText NOTIFY helloTextChanged)
    Q_PROPERTY(QString name READ name WRITE setName)
public:
    explicit xmlReader(QObject *parent = nullptr);
    QVariant helloText() const;

    QString name() const;
    void setName(const QString &name);

public slots:
    void setHelloText(QVariant helloText);

    signals:
        void helloTextChanged(QVariant helloText);
private:
    QDomDocument xmlDoc;
    QVariant m_helloText;
    QString m_name;

};

#endif // XMLREADER_H
