import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    id : top
    width: 600;height: 400;
    RowLayout {
        anchors.fill: parent
        spacing: 10
        Rectangle{
            id : r1
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100;
            Layout.preferredHeight: 100;

            Layout.maximumWidth: 150
            color:"blue"
            Layout.fillWidth: true
        }
        Rectangle{
            id : r2
            Layout.minimumWidth: 50
            Layout.preferredWidth: 150;
            Layout.preferredHeight: 100;
            Layout.maximumWidth: 250
            color:"green"
            Layout.fillWidth: true
        }
    }
    Text {
        text : r1.width+"x"+r2.width +"x"+top.width
    }
}
