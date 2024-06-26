import QtQuick 2.0

Rectangle{
    id : r1
    width: 410
    height: 410
    color :"gray"
    property int i:10;
    property string name :"Gururaja"
    property var x1 ;

    Rectangle{
        width: 100
        height: 100
        radius: width/2
        color :"pink"
    }

    Text{
        id : r2
        width: 100
        height: 50
        text :"Show the Values...."
        visible: true
    }

    MouseArea{
        anchors.fill: parent
        //width: 20;height: 20;
        //hoverEnabled: true
        x : 100
        onClicked: {
            console.log("Mouse Click ="+mouse.x)
        }
        onPressed: {
            console.log("Mouse Press")
            //r1.color = "red"
            r1.border.width = 2;
        }
        onReleased: {
            console.log("Mouse Release")
            //r1.color = "gray"
        }
        onEntered: {
            r1.color = "red"
            r2.visible=true
        }
        onExited: {
            r1.color = "gray"
            r2.visible=false
            r1.i++;
        }
        onPositionChanged: {
            //console.log(mouse.x)
        }
    }
}
