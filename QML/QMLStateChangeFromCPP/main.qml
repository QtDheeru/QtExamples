import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 440
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id : r1
        anchors.fill: parent
        color: "blue"
        state: "data1"
        states:[
            State {name: "data1";PropertyChanges {target: r1;color:"green"}},
            State {name: "data2";PropertyChanges {target: r1;color:"red"}}
        ]
        Connections{
            target: hwDevice
            onData1:{
                r1.state="data1";
            }
            onData2:{
                r1.state="data2";
            }
        }
    }
}
