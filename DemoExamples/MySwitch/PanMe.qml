import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id : r1
    width: 600
    height: 600
    color:"white"
    RowLayout {
        id : grid
        spacing: 2
        width: parent.width
        height: parent.height
        Rectangle{id : r2;
            Layout.minimumWidth: 50
            Layout.minimumHeight: 50
            Layout.maximumWidth: 200
            Layout.maximumHeight: 200
            Layout.preferredWidth: 100
            //Layout.preferredHeight: 100
            radius: 10;color:"black"
            Layout.fillHeight: false
            Layout.fillWidth: true
        }
        Rectangle{id : r3;
            Layout.minimumWidth: 50
            Layout.minimumHeight: 50
            Layout.maximumWidth: 200
            Layout.maximumHeight: 200
            Layout.preferredWidth: 100
            //Layout.preferredHeight: 100
            radius: 10;color:"black"
            Layout.fillWidth: true
            Layout.fillHeight: false
        }
    }
}
