import QtQuick 2.0

Rectangle {
    width: 600;height: 600;color:"black"
    Rectangle {
        id : r1
        anchors.centerIn: parent
        width: 100;height: 100;color:"yellow"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            a1.start()
            a2.start()
        }
    }
    SequentialAnimation{
        PropertyAnimation{
            id : a1;targets : [r1];
            properties :"width,height"
            from :0;to:400;
            running: false;duration: 2000
            easing.type: Easing.InBounce
        }
        PropertyAnimation{
            id : a2;targets : [r1];
            property :"rotation"
            from :0;to:360;
            running: false;duration: 2000
            easing.type: Easing.InBounce
        }
    }
}
