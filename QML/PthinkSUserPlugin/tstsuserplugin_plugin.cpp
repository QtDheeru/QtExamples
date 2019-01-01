#include "tstsuserplugin_plugin.h"
#include "userlogin.h"

#include <qqml.h>

void TSTSUserPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.tsts.comps
    qmlRegisterType<UserLogin>(uri, 1, 0, "UserLogin");
}

