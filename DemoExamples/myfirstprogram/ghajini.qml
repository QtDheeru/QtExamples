import QtQuick 2.0

Rectangle {
    width: 300
    height:300
    color: "green"
    function display() {
        var abc;
    }

    Rectangle {
        id:head
        width: 50
        radius:50
        height:50
        color: "purple"
        x:125
        //source : Qt.resolvedUrl("file:///c:/")
    }
    Rectangle {
        id:body
        width: 2
        height:100
        color: "pink"
        x:149
        y:50
    }
    Rectangle {
        id:hand
        width:2
        height:100
        color: "yellow"
        x:149
        y:50
        rotation:90

    }

    Rectangle {
        id:legleft
        width: 2
        height:80
        color: "yellow"
        x:120
        y:135
        rotation:45

    }
    Rectangle {
        id:legright
        width: 2
        height:80
        color: "yellow"
        x:178
        y:135
        rotation:135

    }
    Rectangle {
        id:eyeleft
        width: 10
        height:10
        radius: 5
        color: "yellow"
        x:135
        y:15


    }

    Rectangle {
        id:eyeright
        width: 10
        height:10
        radius: 5
        color: "yellow"
        x:155
        y:15

    }
}
