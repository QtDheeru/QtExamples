import QtQuick 2.12
import QtQuick.Window 2.12
import "LoginLogic.js" as LoginMethods

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color: "#6677FF"
        Column{
            anchors.fill: parent
            Text {
                id : header
                text : "Display Logged in user"
                width: parent.width
                height: 50
                font.pixelSize: 25
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
            }
            Row {
              height: 70
              anchors.horizontalCenter: parent.horizontalCenter
              Text { width : 70;height: 50;text : "User"}
              Rectangle{
                  width: 200;height: 50
                  border.color: "black"
                  TextInput{id : userI;anchors.fill: parent;font.pixelSize: 30}
              }
            }
            Row {
              height: 70
              anchors.horizontalCenter: parent.horizontalCenter
              Text { width : 70;height: 50;text : "Password"}
              Rectangle{
                  width: 200;height: 50
                  border.color: "black"
                  TextInput{
                      id : passI;anchors.fill: parent;font.pixelSize: 30
                      echoMode: TextInput.Password
                  }
              }
            }
            Row {
                height: 70
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                MTButton{value :"OK"
                    onClicked: {
                        console.log("Done")
                    }
                }
                MTButton{value :"Cancel"}
                MTButton{value :"Clear"}
            }
        }
    }
}
