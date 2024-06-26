import QtQuick 2.0

Item {
    id : top
    width: 500;
    height: 500;
    Rectangle{
        id : r1
        width: parent.width;
        height: top.height;
        color:Qt.rgba(0.5,0.5,0.5,1)
        Rectangle{
            id : r2
            width: 120;
            height: 50;
            radius: 10
            color:"yellow"
            //anchors.centerIn: parent
            Text {
                text : "HWSettings"
                anchors.centerIn: parent
            }

            anchors.horizontalCenter: parent.horizontalCenter
            //            anchors.verticalCenter: parent.verticalCenter
        }
    }
}

