import QtQuick 2.0

Rectangle{
    id : top
    width: 500;
    height: 500;
    color:"white"
    Rectangle{
        id : r1
        width: 100;
        height: 100;
        color:"blue"
    }
    Rectangle{
        id: r2
        //width: 100;
        height: 100;
        color:"green"
        visible: true
        anchors.left: r1.right
        anchors.right: r3.left
    }
    Rectangle{
        id: r3
        width: 100;
        height: 100;
        color:"#112233"
        visible: true
        x : 350
        //anchors.right: r1.left
    }
}
