import QtQuick 2.0

Rectangle {
    width: 400
    height: 400
    Rectangle {
        id : r1
        width: 100
        height: 100
        color : "blue"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
    }
    Rectangle {
        id : r2
        width: 100
        height: 100
        color : "red"
        anchors.left:  r1.right
        anchors.margins: 20
    }
}
