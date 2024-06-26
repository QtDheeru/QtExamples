import QtQuick 2.0

Rectangle {
    id : top
    width: 600;height: 600;color: "black"
    property int count :0
    function display(myid,mypos){
        myid.visible=true;
        myid.x = mypos.x
        myid.y = mypos.y
    }

    function handelAll(count,myid,mypos){
        console.log(" Count Value ="+count)
        if (count==0){
            display(r1,mypos)
        }
        if (count==1){
            display(r2,mypos)
        }
        if (count==3){
            display(r3,mypos)
        }
        if (count==4){
            display(r4,mypos)
        }
        top.count++;
    }

    Rectangle {id : r1;visible:false;width: 100;height: 100;color: "yellow"}
    Rectangle {id : r2;visible:false;width: 100;height: 100;color: "red"}
    Rectangle {id : r3;visible:false;width: 100;height: 100;color: "green"}
    Rectangle {id : r4;visible:false;width: 100;height: 100;color: "blue"}

    MouseArea{
        id : ms
        anchors.fill: parent
        onClicked: {
                handelAll(count,r1,mouse)
                if (count == 0){
                    r1.x = mouse.x
                    r1.y = mouse.y
                    r1.visible = true;
                }
                if (count == 1){
                    r2.x = mouse.x
                    r2.y = mouse.y
                    r2.visible = true;
                }
                if (count == 3){
                    r3.x = mouse.x
                    r3.y = mouse.y
                    r3.visible = true;
                }
                if (count == 4){
                    r4.x = mouse.x
                    r4.y = mouse.y
                    r4.visible = true;
                }
                count++;
        }
    }
}






















