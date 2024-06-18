import QtQuick
import QMLSingleTonIssue 1.0
import Main 1.0
import StaticPlugins 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Component.onCompleted: {
        console.log(" Calling Single Tone object");
        Message.print();
        MySingleton.exec("Dheerendra");
    }
    TestStatic {

    }
    TestStaticLib{

    }

    StaticPlugin{

    }
}
