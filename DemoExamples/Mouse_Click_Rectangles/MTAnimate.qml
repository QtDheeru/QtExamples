import QtQuick 2.0

Rectangle {
    width: 600;height: 600;color:"black"
    Rectangle {
        id : r1
        width: 100;height: 100;color:"yellow"
    }
    Rectangle {
        x : 200;id : r2;width: 100;height: 100;color:"yellow"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {a1.start()}
    }
    PropertyAnimation{
        id : a1;targets : [r1,r2];property :"y"
        from :0;to:400;
        running: false;duration: 2000
    }
}
