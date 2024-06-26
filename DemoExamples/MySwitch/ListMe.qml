import QtQuick 2.0

Item {
    width: 400;height: 400;
    property var arr :["one.qml","two.qml","three.qml"]
    Component.onCompleted: {
        for(var i=0;i<arr.length;i++){
            console.log(arr[i])
        }
    }
}
