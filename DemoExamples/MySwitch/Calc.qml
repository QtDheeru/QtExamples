import QtQuick 2.9

Item {
    id : top
    width: 500;
    height: 500;
    Rectangle{
        id : r1
        width: 210
        height: 210
        color:Qt.rgba(0.5,0.5,0.5,1)
        border.color: "black"
        border.width: 2
        anchors.centerIn: parent
        Column {
            id : grid
            //columns : 2
            //rows : 2
            spacing: 2
            anchors.centerIn: parent
            Rectangle{id : r2;width: 100;height: 100;radius: 10;color:"yellow"
            }
            Rectangle{id : r3;width: 100;height: 100;radius: 10;color:"yellow"
                Text {
                    text : "1"
                    font.pixelSize: 20
                    //anchors.top:parent.top
                    anchors.centerIn: parent
                }
            }
            Rectangle{id : r4;width: 100;height: 100;radius: 10;color:"yellow"}
            Rectangle{id : r5;width: 100;height: 100;radius: 10;color:"yellow"}
            Rectangle{id : r6;width: 100;height: 100;radius: 10;color:"red"}
        }
    }
}
