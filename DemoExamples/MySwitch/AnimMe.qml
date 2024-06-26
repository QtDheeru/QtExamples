import QtQuick 2.0

Rectangle{
    id : r1
    width: 410
    height: 410
    color :"white"
    Rectangle{
        id : r2
        width: 410
        height: 410
        color :"red"
        visible: true
    }
    Rectangle{
        id : r3
        width: 0
        height: 410
        color :"blue"
        visible: false
   }
   MouseArea{
       anchors.fill: parent
       onClicked: {
            console.log("Clicked")
            p1.start()
            p4.start()
            r3.visible=true
            p2.start()
            p3.start()
            p5.start()
       }
   }

   PropertyAnimation{
       id : p1
       target: r2;
       property :"width"
       from : 410
       to:0
       running: false
       duration: 1900
   }
   PropertyAnimation{
       id : p4
       target: r2;
       property :"scale"
       from : 1
       to:0
       running: false
       duration: 1900
   }
   PropertyAnimation{
       id : p5
       target: r2;
       property :"rotation"
       from : 0
       to:360
       running: false
       duration: 1000
   }
   PropertyAnimation{
       id : p2
       target: r3;
       property :"x"
       from : 410
       to:0
       running: false
       duration: 2000
   }
   PropertyAnimation{
       id : p3
       target: r3;
       property :"width"
       from : 0
       to:410
       running: false
       duration: 2000
   }
}
