import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{id : r1;width: 100;height: 100;color:"black"}
    Rectangle{id : r2;width: 100;height: 100;color:"#00AA33"
    anchors.left:  r1.right
    anchors.margins: 10
    anchors.right: r3.left
    //anchors.bottom: parent.bottom
    y : 100
    x : 100
    //anchors.top:parent.top
    }
    Rectangle{id : r3;width: 100;height: 100;color:"black"
    anchors.right: parent.right
    }
}
