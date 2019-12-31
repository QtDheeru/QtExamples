#include "xmlReader.h"
QVariant xmlReader::helloText() const
{
    return m_helloText;
}

void xmlReader::setHelloText(QVariant helloText)
{
    if (m_helloText == helloText)
        return;

    m_helloText = helloText;
    emit helloTextChanged(m_helloText);
}

QString xmlReader::name() const
{
    return m_name;
}

void xmlReader::setName(const QString &name)
{
    m_name = name;
}

xmlReader::xmlReader(QObject *parent) : QObject(parent)
{
    QString helloText = "hi"; //testing text
}
