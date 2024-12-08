import QtQuick 2.0

Rectangle{
    id : topi
    width: 100;height: 50;color:"#338833"
    property alias value  : t1.text
    signal clicked(string val)
    Text {
         id : t1
         text :topi.value;anchors.centerIn: parent
         font.pixelSize: 20;color: "white"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
//            console.log("OK Clicked Text ="+t1.text);
//            console.log("OK Clicked Text ="+topi.value);
//            t1.text = "Vignesh"
//            console.log("OK Clicked Text ="+t1.text);
//            console.log("OK Clicked Text ="+topi.value);
 //           LoginMethods.okClicked();
            topi.clicked(t1.text)
        }
    }
}
