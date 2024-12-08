import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle
{
    id:maingalleryrect

    anchors.centerIn: parent
    width:Screen.width/1.34
    height: Screen.height/1.51
    color:"#040405"


    property variant images :
    [
        "qrc:/Images/Chrysanthemum.jpg",
        "qrc:/Images/Desert.jpg",
        "qrc:/Images/Hydrangeas.jpg",
        "qrc:/Images/Jellyfish.jpg",
        "qrc:/Images/Koala.jpg",
        "qrc:/Images/Lighthouse.jpg"
    ];

    property int currentImage : 0;

    Repeater
    {
        id: repeaterImg;

        model: images;
        delegate: Image {
            source: modelData
            anchors.fill: parent
            asynchronous: false;
            visible: (model.index === currentImage);
        }
    }

    Timer
    {
        id: timerAnimImg

        interval: 2000;
        running: true;
        repeat: true;
        onTriggered:
        {
            if (currentImage < images.length -1)
            {
                currentImage++;
            }
            else
            {
                currentImage = 0;
            }
        }
    }

}
