import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2
import QtMultimedia 5.6
import QtQuick.Dialogs 1.2


Rectangle

{
    id:mainrect

    anchors.centerIn: parent
    width:Screen.width/1.5
    height: Screen.height/2
    color:"#040405"
    property int maximumduration:videoforwardandbackwardslider.maximumValue
    property int minimumduration: videoforwardandbackwardslider.value

    Image
    {
        id: fileflodericon

        width:Math.min(Screen.width/22,Screen.height/22)
        height: width
        source: "qrc:/Images/Downloads.png"
        fillMode: Image.PreserveAspectFit
        anchors.left:parent.left
        anchors.leftMargin: Screen.width/120
        anchors.top: parent.top
        anchors.topMargin: Screen.width/120

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {

               fileDialog.visible = true
            }
        }

    }


    Video
    {
        id: video

        anchors.fill: parent
        anchors.top: fileflodericon.bottom
        anchors.topMargin: Screen.width/40
        anchors.bottom: videoforwardandbackwardslider.top
        anchors.bottomMargin: Screen.width/30
        source: ""


    }

    Text
    {
        id: videotext

        text: qsTr("Media Player")
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: Math.min(Screen.width/34,Screen.height/38)
        font.italic: true
        font.family: "Brie Light"
    }


    Slider
    {
        id:videoforwardandbackwardslider

        anchors.bottom:  parent.bottom
        anchors.bottomMargin:Screen.width/50
        anchors.horizontalCenter: parent.horizontalCenter
        value: video.position
        minimumValue: 0
        maximumValue: video.duration
        width:Screen.width/1.6


        style: SliderStyle
        {
        groove: Rectangle
        {
        id:grooveRect

        implicitWidth: Screen.width/1.4
        implicitHeight: Screen.height/380
        radius: 8
        color:"grey"

        Rectangle
        {
            id: innerRectWidth

            color: "#0DE2EA" // For changing the filling color
            height: parent.height
            implicitHeight: grooveRect.implicitHeight
            implicitWidth: grooveRect.implicitWidth
            width: styleData.handlePosition
        }

    }
    handle: Rectangle
    {
    anchors.centerIn: parent
    color: "#0DE2EA"
    border.color: "gray"
    border.width: 2
    implicitWidth: Screen.width/70
    implicitHeight: implicitWidth
    radius: implicitWidth/2
}

}



onValueChanged:
{


    if(videoforwardandbackwardslider.value==maximumValue)
    {

        playicon.visible=true
        pauseicon.visible=false

    }
    else
    {
        video.seek(videoforwardandbackwardslider.value)
    }

}

onPressedChanged:
{
    video.seek(videoforwardandbackwardslider.value)
}

}

Image
{
    id: playicon

    width:Math.min(Screen.width/28,Screen.height/28)
    height: width
    source: "qrc:/Images/Play.png"
    fillMode: Image.PreserveAspectFit
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/350

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            video.play()
            videotext.visible=false
            pauseicon.visible=true
            playicon.visible=false

        }
    }

}


Image
{
    id: pauseicon

    width:Math.min(Screen.width/36,Screen.height/36)
    height: width
    source: "qrc:/Images/Pauseicon.png"
    fillMode: Image.PreserveAspectFit
    visible: false
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/240
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            video.pause()
            videotext.visible=false
            playicon.visible=true
            pauseicon.visible=false
        }
    }
}
Image
{
    id: stopicon

    width:Math.min(Screen.width/38,Screen.height/38)
    height: width
    source: "qrc:/Images/stopicon.png"
    fillMode: Image.PreserveAspectFit
    anchors.left: pauseicon.right
    anchors.leftMargin: 10
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/190

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            video.stop()
            videotext.visible=true
            video.source=""
            playicon.visible=true
            pauseicon.visible=false
            minimumdurationtext.visible=false
            maximumdurationtext.visible=false

        }
    }
}



Text
{

    id:minimumdurationtext

    text:parseInt( Math.floor(minimumduration / 3600000))+":"+Math.floor((minimumduration % 3600000) / 60000) + ":" + (Math.floor(minimumduration / 1000 % 60))
    anchors.bottom:parent.bottom
    anchors.bottomMargin:Screen.width/140
    anchors.left:parent.left
    anchors.leftMargin:Screen.width/50
    color:"white"
    visible: false
}

Text
{

    id:maximumdurationtext

    text:parseInt( Math.floor(maximumduration / 3600000))+":"+Math.floor((maximumduration % 3600000) / 60000) + ":" + (Math.floor(maximumduration / 1000 % 60))
    anchors.bottom:parent.bottom
    anchors.bottomMargin:Screen.width/140
    anchors.right:parent.right
    anchors.rightMargin:Screen.width/25
    color:"white"
    visible: false
}

Image
{
    id: fullscreenicon

    width:Math.min(Screen.width/35,Screen.height/35)
    height: width
    source: "qrc:/Images/fullscreenicon.png"
    fillMode: Image.PreserveAspectFit
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/240
    anchors.left: maximumdurationtext.right
    anchors.leftMargin:Screen.width/240

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            fullscreenicon.visible=false
            halfscreenicon.visible=true
            fullscreenanimation.running=true


        }
    }

}
Image
{
    id: halfscreenicon

    width:Math.min(Screen.width/35,Screen.height/35)
    height: width
    source: "qrc:/Images/halfscreenicon.png"
    fillMode: Image.PreserveAspectFit
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/240
    anchors.left: maximumdurationtext.right
    anchors.leftMargin:Screen.width/240
    visible: false
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            fullscreenicon.visible=true
            halfscreenicon.visible=false
            halfscreenanimation.running=true
        }
    }


}


FileDialog
{
    id: fileDialog

    title: "Please Choose a file"
    folder: shortcuts.movies
    nameFilters: [ "My Videos files (*.mp4 *.avi *.3gp *.mkv *.wmv)" ]
    onAccepted:
    {
        video.source = fileDialog.fileUrl
        video.play()
        videotext.visible=false
        pauseicon.visible=true
        playicon.visible=false
        minimumdurationtext.visible=true
        maximumdurationtext.visible=true


    }
    onRejected:
    {
        console.log("Canceled")

    }

}
PropertyAnimation
{
    target: videotext
    property: "opacity"
    running: true
    duration: 3000
    from:0
    to:1
}
ParallelAnimation
{
    id:fullscreenanimation

    running: false
    PropertyAnimation
    {
        target: mainrect
        properties: "width"
        duration: 1000
        from:Screen.width/1.5
        to:Screen.width/1.34
    }
    PropertyAnimation
    {
        target: mainrect
        properties: "height"
        duration: 1000
        from:Screen.height/2
        to:Screen.height/1.51
    }
    PropertyAnimation
    {
        target: videoforwardandbackwardslider
        properties: "width"
        duration: 1000
        from:Screen.width/1.6
        to:Screen.width/1.4
    }

}

ParallelAnimation
{
    id:halfscreenanimation

    running: false
    PropertyAnimation
    {
        target: mainrect
        properties: "width"
        duration: 1000
        from:Screen.width/1.34
        to:Screen.width/1.5

    }
    PropertyAnimation
    {
        target: mainrect
        properties: "height"
        duration: 1000
        from:Screen.height/1.51
        to:Screen.height/2

    }
    PropertyAnimation
    {
        target: videoforwardandbackwardslider
        properties: "width"
        duration: 1000
        from:Screen.width/1.4
        to:Screen.width/1.6

    }

}

}

