import QtQuick 2.9

Item {
    id : top
    width: 500;
    height: 500;
    Rectangle{
        id : r1
        width: 210
        height: 210
        color:"white"
        Row {
            id : grid
            spacing: 2
            Rectangle{id : r2;width: 100;height: 100;radius: 10;color:"black"
            }
            Rectangle{id : r3;width: 100;height: 100;radius: 10;color:"black"
            }
        }
    }
}
