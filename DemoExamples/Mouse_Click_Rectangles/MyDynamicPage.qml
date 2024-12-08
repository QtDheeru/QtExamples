import QtQuick 2.0

Rectangle {
    width: 400;height: 400;color: "black"

    Rectangle {
        id : r1
        width: 100;height: 100;color: "yellow"
    }
    Rectangle {
        id : r2
        width: 100;height: 100;color: "yellow"
    }

    MouseArea{
        id : ms
        anchors.fill: parent
        drag.target: r1
        drag.axis: Drag.XAndYAxis
        drag.minimumX: 10
        drag.maximumX: 300
        onClicked: {
            r1.anchors.right= undefined
            r1.anchors.top  = undefined
            console.log("Welcome to Mouse")
        }
    }
    Component.onCompleted: {
        console.log("Welcome to MT")
    }
}
