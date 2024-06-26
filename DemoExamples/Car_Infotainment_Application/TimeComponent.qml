import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4


Item
{
    property int hour :0
    property int minute :0


    Timer
    {
        id: datetime_timer

        interval: 10
        repeat: true
        running: true

        onTriggered:
        {
            datetimetext.text= Qt.formatTime(new Date(), " hh:mm AP")
        }
    }

    Timer {
        id:time2

        interval: 3600000; running: false; repeat: true
        onTriggered:
        {
            if(hour<24)
            {
                hour = hour + 1
                if(hour<10)
                {
                    hour = "0" + hour
                }
            }
            else
            {
                hour = 00
            }
        }
    }

    Timer
    {
        id:time3

        interval: 60000; running: false; repeat: true
        onTriggered:
        {

            if(minute<60)
            {
                minute = minute + 1

                if(minute<10)
                {
                    minute = "0" + minute
                }
            }
            else
            {
                minute = 00
            }

        }
    }


    Text
    {
        id:datetimetext

        text: ""
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: Screen.width/120
        anchors.rightMargin: Screen.width/120
        font.pixelSize: Math.min(Screen.width/34,Screen.height/38)
        color:"white"
        font.family: "Brie Light"
    }


}
