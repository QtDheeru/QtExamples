import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 420
    height: 480
    title: qsTr("Hello World")
    color: "black"

    function display() {
        console.log("Welcome to QML")
    }

    Monitor{
        id : m
        anchors.centerIn: parent
    }
    Connections{
        target: m
        onSendValue:{
            display()
        }
    }
}
