#include "StaticPlugin.h"

StaticPlugin::StaticPlugin(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO << " Static library path" << Qt::endl;
}
