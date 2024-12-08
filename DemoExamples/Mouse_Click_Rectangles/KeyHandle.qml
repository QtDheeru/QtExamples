import QtQuick 2.0

Rectangle {
    width: 400;height: 400;
    color: "black"
    focus: true
    Image {
        id : rocket
        source :"rocket.png"
        //anchors.centerIn: parent
    }
    Keys.onLeftPressed: {
        //rocket.rotation = (rocket.rotation-10)%360
        rocket.y -=1;
    }
}
