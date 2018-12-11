import QtQuick 2.0
/* Exmple Prepared by dheerendra@pthinks.com
  */

Item {
    property date startDate :new Date();
    property int mils;
    Timer{
        id : tim
        interval: 10000
        repeat: true
        running: true
        onTriggered: {
            var end  = new Date();
            var elapsed = end.getTime() - startDate.getTime()
            if (elapsed>=10000){
                console.log("Blackout")
            }else {
                console.log("No blackout")
                startDate = new Date()
            }
        }
    }

    Keys.onPressed: {
        console.log("Key is pressed in Interceptor")
        startDate = new Date();
    }
}
