import QtQuick 2.11
import QtQuick.Window 2.11


Window {
    visible: true
    width: 440
    height: 480
    title: qsTr("Hello World")
    Component{
        id : del
        Text {
            id: na
            text: name;
        }
    }

    ListView{
        anchors.fill: parent
        model: dataModel
        delegate: del
    }

    Text {
        font.pixelSize: 20;
        anchors.centerIn: parent
        text : dataModel.getCar(0).name;
    }
}
