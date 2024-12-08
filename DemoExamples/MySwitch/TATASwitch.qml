import QtQuick 2.0

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
        id : r3
        width: 200
        height: r2.height
        color : "blue"
        Text { text : "ON"}
    }
    Rectangle{
        id : r4
        width: 200
        height:r2.height
        Text { text : "OFF"}
        color : "red"
        anchors.left: r3.right
    }

    Rectangle{
        id : r2
        width: 200
        height: 100
        color :"pink"
        anchors.top: parent.top

        MouseArea{
            anchors.fill: parent
            drag.target: r2
            drag.minimumX: 0
            drag.maximumX: r1.width-r2.width
            drag.maximumY: r1.height-r2.height
            drag.minimumY: 0
            onReleased: {
                console.log(r2.x)
                // r2 =switch
                // r3= on, r4=OFF
                if(r2.x > (r3.x+r3.width/2)){
                   r2.x = r4.x
                }else {
                   r2.x = r3.x
                }
            }
        }
    }
}

