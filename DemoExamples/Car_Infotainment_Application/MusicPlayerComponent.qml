import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2
import QtMultimedia 5.6
import QtQuick.Dialogs 1.2
import QtQuick.Particles 2.0
import Qt.labs.folderlistmodel 2.1


Rectangle
{
    id:mainrect

    anchors.centerIn: parent
    width:Screen.width/1.34
    height: Screen.height/1.51
    color:"#040405"


    property int maximumduration:audioforwardandbackwardslider.maximumValue
    property int minimumduration: audioforwardandbackwardslider.value


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
            hoverEnabled: true
            onClicked:
            {
                fileDialog.visible = true

            }

        }

    }

    Rectangle
    {
        id:listrect

        width: Screen.width/45
        height:width
        anchors.top:parent.top
        anchors.left: fileflodericon.right
        anchors.leftMargin: Screen.width/170
        anchors.topMargin: Screen.width/120
        radius:2
        color:"#2A89EE"

        Column
        {
            id:columnrects1

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: Screen.width/300
            anchors.leftMargin: Screen.width/340
            spacing: 2

            Repeater
            {
                id:repeaterrects1

                model: 3
                Rectangle{id:insidelistrect1;width:Screen.width/200;height: width;radius: width/2;color:"#353A3E"}
            }

        }
        Column
        {
            id:columnrects2

            anchors.left: columnrects1.right
            anchors.top: parent.top
            anchors.topMargin: Screen.width/300
            anchors.leftMargin: Screen.width/420
            spacing: 6

            Repeater
            {
                id:repeaterrects2

                model: 3
                Rectangle{id:insidelistrect2;width:Screen.width/90;height: Screen.height/200;radius:2;color:"#353A3E"}
            }

        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                playlistrect.visible=true
            }
            onDoubleClicked:
            {
                playlistrect.visible=false
            }
        }

    }

    Text
    {
        id:filenametext

        text:audioplayer.source
        font.pixelSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top
        visible: false
        anchors.topMargin: Screen.width/140
        color:"white"
    }


    Rectangle
    {
        id:playlistrect

        width: Screen.width/5
        height: Screen.height/1.65

        gradient: Gradient
        {
            GradientStop{position: 0;color:"#282A2C"}
            GradientStop{position: 1;color:"#515557"}

        }
    anchors.top: parent.top
    anchors.right: parent.right

    visible: false
    border.color: "silver"
    border.width: 1

    ListView
    {

        id:songsselectedlist

        width: parent.width/2
        height: parent.height
        x: parent.width/1.7
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: Screen.width/240
        anchors.topMargin: Screen.width/240
        model: playlist;
        delegate: Text
        {
        font.pixelSize: 16;
        text: source;
        color:"white"
    }
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true


}
}
Image
{
    id: playericon

    width:Math.min(Screen.width/8,Screen.height/8)
    height: width
    source: "qrc:/Images/Music-Player-Logo.png"
    fillMode: Image.PreserveAspectFit
    anchors.centerIn: parent

}


Slider
{
    id:audioforwardandbackwardslider

    anchors.bottom:  parent.bottom
    anchors.bottomMargin:Screen.width/50
    anchors.horizontalCenter: parent.horizontalCenter
    value: audioplayer.position
    minimumValue: 0
    maximumValue: audioplayer.duration
    width:Screen.width/1.4



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

                color: "#0DE2EA" // For changing the filling color you set this property
                height: parent.height
                implicitHeight: grooveRect.implicitHeight
                implicitWidth: grooveRect.implicitWidth
                width: styleData.handlePosition
            }

        }

        handle: Rectangle
        {
            id:sliderhandle
            anchors.centerIn: parent
            color: "#0DE2EA"
            border.color: "gray"
            border.width: 2
            implicitWidth:20
            implicitHeight: implicitWidth
            radius: implicitWidth/2

        }




    }


    onValueChanged:
    {


        if(audioforwardandbackwardslider.value==maximumValue)
        {

            playicon.visible=true
            pauseicon.visible=false

        }
        else
        {
            audioplayer.seek(audioforwardandbackwardslider.value)
        }

    }

    onPressedChanged:
    {
        audioplayer.seek(audioforwardandbackwardslider.value)


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
            audioplayer.play()
            playericon.visible=false
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
            audioplayer.pause()
            playericon.visible=false
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
    anchors.leftMargin: Screen.width/130
    anchors.bottom: parent.bottom
    anchors.bottomMargin: Screen.width/190

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            audioplayer.stop()
            playericon.visible=true
            audioplayer.source=""
            playicon.visible=true
            pauseicon.visible=false
            minimumdurationtext.visible=false
            maximumdurationtext.visible=false
            particleitem.visible=false

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
    anchors.leftMargin:Screen.width/60
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
    anchors.rightMargin:Screen.width/70
    color:"white"
    visible: false
}




FileDialog
{
    id: fileDialog


    title: "Please Choose a file"
    folder: shortcuts.music
    nameFilters: [ "My Audio files (*.mp3)" ]
    modality: Qt.WindowModal
    onAccepted:
    {
        audioplayer.source = fileDialog.fileUrl
        audioplayer.play()
        playericon.visible=false
        pauseicon.visible=true
        playicon.visible=false
        minimumdurationtext.visible=true
        maximumdurationtext.visible=true
        particleitem.visible=true
        filenametext.visible=true



    }
    onRejected:
    {
        console.log("Canceled")

    }

}
PropertyAnimation
{
    target: playericon
    property: "opacity"
    running: true
    duration: 3000
    from:0
    to:1
}


Item{

    id:particleitem

    width: Screen.width/1.34
    anchors.top: fileflodericon.bottom
    anchors.topMargin: Screen.width/340
    anchors.bottom: audioforwardandbackwardslider.top
    visible: false

    ParticleSystem
    {
        anchors.fill: parent
        ImageParticle
        {
            groups: ["stars"]
            anchors.fill: parent
            source: "qrc:///particleresources/star.png"
        }
        Emitter
        {
            group: "stars"
            emitRate: 800
            lifeSpan: 2400
            size: 24
            sizeVariation: 8
            anchors.fill: parent
        }


        ImageParticle
        {
            anchors.fill: parent
            source: "qrc:///particleresources/star.png"
            alpha: 0
            alphaVariation: 0.2
            colorVariation: 1.0
        }


        Emitter
        {
            anchors.centerIn: parent
            emitRate: 400
            lifeSpan: 2400
            size: 48
            sizeVariation: 8
            velocity: AngleDirection {angleVariation: 180; magnitude: 60}
        }

        Turbulence
        {
            anchors.fill: parent
            strength: 2
        }
    }
}

}


