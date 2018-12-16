import QtQuick 2.11
import QtQuick.Window 2.11

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * Program to launch one window from
 * other window
 */

Window {
    visible: true
    width: 440
    height: 480
    title: qsTr("Marito Mesquita")
    Loader{
        id : ld
    }

    Rectangle{
        anchors.fill: parent
        color: "green"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("Dheerendra Window Clicked")
                ld.source = "Monitor.qml"
            }
        }
    }
}
