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
            s1.start()
        }
    }
    SequentialAnimation{
        id : s1
        running: true
        PropertyAnimation{
            id : a1;targets : [r1];
            properties :"width,height"
            from :0;to:400;
            duration: 2000
            easing.type: Easing.InBounce
        }
        PauseAnimation {
            duration: 1000
        }
        PropertyAnimation{
            id : a2;targets : [r1];
            property :"rotation"
            from :0;to:360;
            duration: 2000
            easing.type: Easing.InBounce
        }
        PropertyAction{
           target : r1
           property :"radius"
           value : 10
        }
        ScriptAction{
            script : display
        }
    }
}
