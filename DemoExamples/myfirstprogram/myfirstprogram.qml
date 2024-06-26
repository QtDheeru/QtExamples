import QtQuick 2.0
Rectangle{
    width:200
    height:200
    color:"purple"

    Rectangle {
        width: 100
        height:100
        radius:50
        //color: "red"
        Text {
            anchors.centerIn: parent
            text: "Hello shreepoorna"
            color: "blue"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
    }
}
