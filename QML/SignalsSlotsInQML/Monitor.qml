import QtQuick 2.0

Rectangle {
    width: 200;height: 200;color:"blue"
    signal sendValue();
    Text{
        text : "Click Me"
        font.pixelSize: 20
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            sendValue()
        }
    }
}
