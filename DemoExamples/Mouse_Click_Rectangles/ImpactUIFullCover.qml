import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{id : r1;width: 100;height: 100;color:"black"
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        anchors.top: parent.top
//        anchors.left: parent.left
        anchors.fill: parent
        Text {
            id : t1
            text :"Vignesh"
            font.pixelSize: 40
            font.bold: true
            color: "white"
        }
    }
}
