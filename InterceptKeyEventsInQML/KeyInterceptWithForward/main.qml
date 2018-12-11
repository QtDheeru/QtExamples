import QtQuick 2.11
import QtQuick.Window 2.11
import QtQml 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property date startDate :new Date();
    property int mils;

    KeyInterceptor{
        id: keyI
    }

    Rectangle{
        anchors.fill: parent
        focus: true
        objectName: "Dheerendra"
        Keys.forwardTo: [keyI]
        Keys.onPressed: {
            console.log("Key is pressed in Main")
            startDate = new Date();
        }
    }
}
