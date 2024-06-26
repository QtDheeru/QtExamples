import QtQuick 2.0

Item {
    id : top
    width: 500;
    height: 500;
    Rectangle{
        id : r1
        width: parent.width;
        height: top.height;
        color:Qt.rgba(0.5,0.5,0.5,1)
        Rectangle{
            id : r2
            width: 100;
            height: 100;
            color:"blue"
            anchors.fill: parent
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.left: parent.left
//            anchors.right: parent.right
//            anchors {
//                top: parent.top
//                bottom: parent.bottom
//                left: parent.left
//                right: parent.right
//            }
        }
    }
}

