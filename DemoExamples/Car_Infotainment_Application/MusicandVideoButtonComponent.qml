import QtQuick 2.0
import QtQuick.Window 2.2

Item
{
    anchors.centerIn: parent

    Row
    {
        id:musicandvideorect

        anchors.centerIn: parent
        spacing: Screen.width/8

        Rectangle
        {
            id:musicrect

            width: Screen.width/10
            height:width
            color:"transparent"

            Image
            {
                id: musicicon

                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: Screen.width/120
                width:Math.min(Screen.width/5,Screen.height/5)
                height: width
                source: "qrc:/Images/headphones.png"
                fillMode: Image.PreserveAspectFit
                opacity: 0.4

                MouseArea
                {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered:
                    {

                        musicparallelanimationstart.running=true

                    }
                    onExited:
                    {


                        musicparallelanimationstop.running=true

                    }

                    onClicked:
                    {
                        musicrect.visible=false
                        videorect.visible=false
                        galleryrect.visible=false
                        loadpages.source="MusicPlayerComponent.qml"

                    }
                }
            }

        }


        Rectangle
        {
            id:videorect

            width: Screen.width/10
            height:width
            color:"transparent"


            Image
            {
                id: videoicon

                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: Screen.width/110
                width:Math.min(Screen.width/4,Screen.height/4)
                height: width
                opacity: 0.4
                source: "qrc:/Images/player-icon.png"
                fillMode: Image.PreserveAspectFit

                MouseArea
                {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered:
                    {
                        videoparallelanimationstart.running=true
                    }
                    onExited:
                    {
                        videoparallelanimationstop.running=true
                    }
                    onClicked:
                    {

                        musicrect.visible=false
                        videorect.visible=false
                        galleryrect.visible=false
                        loadpages.source="VideoPlayerComponent.qml"

                    }
                }
            }




        }

        Rectangle
        {
            id:galleryrect

            width: Screen.width/10
            height:width
            color:"transparent"


            Image
            {
                id: galleryicon

                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: Screen.width/120
                width:Math.min(Screen.width/5,Screen.height/5)
                height: width
                source: "qrc:/Images/galleryicon.png"
                fillMode: Image.PreserveAspectFit
                opacity: 0.4

                MouseArea
                {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered:
                    {
                        galleryparallelanimationstart.running=true
                    }
                    onExited:
                    {
                        galleryparallelanimationstop.running=true
                    }

                    onClicked:
                    {
                        musicrect.visible=false
                        videorect.visible=false
                        galleryrect.visible=false
                        loadpages.source="GalleryImagesComponent.qml"
                    }


                }
            }




        }

    }

    ParallelAnimation
    {
        id:musicparallelanimationstart

        running: false
        PropertyAnimation
        {
            id:musiciconwidthandheightanimation

            target: musicicon
            properties: "width,height"
            duration: 1000
            from:musicicon.width
            to:Screen.width/5
        }
        PropertyAnimation
        {
            id:musiciconopacityanimation

            target: musicicon
            property: "opacity"
            duration: 1000
            from:0.4
            to:1.0
        }
    }

    ParallelAnimation
    {
        id:musicparallelanimationstop

        running:false
        PropertyAnimation
        {
            id:musiciconwidthandheightanimation1

            properties: "width,height"
            target: musicicon

            duration: 1000
            from:Screen.width/5
            to:Screen.width/8
        }
        PropertyAnimation
        {
            id:musiciconopacityanimation1

            target: musicicon
            property: "opacity"
            duration: 1000
            from:1.0
            to:0.4
        }
    }

    ParallelAnimation
    {
        id:videoparallelanimationstart

        running: false
        PropertyAnimation
        {
            id:videoiconwidthandheightanimation

            target: videoicon
            properties: "width,height"
            duration: 1000
            from:musicicon.width
            to:Screen.width/5
        }
        PropertyAnimation
        {
            id:videoiconopacityanimation

            target: videoicon
            properties: "opacity"
            duration: 1000
            from:0.4
            to:1.0
        }
    }

    ParallelAnimation
    {
        id:videoparallelanimationstop

        running: false
        PropertyAnimation
        {
            id:videoiconwidthandheightanimation1

            properties: "width,height"
            target: videoicon
            running:false
            duration: 1000
            from:Screen.width/5
            to:Screen.width/8
        }
        PropertyAnimation
        {
            id:videoiconopacityanimation1

            target: videoicon
            properties: "opacity"
            duration: 1000
            from:1.0
            to:0.4
        }
    }

    ParallelAnimation
    {
        id:galleryparallelanimationstart

        running: false

        PropertyAnimation
        {
            id:galleryiconwidthandheightanimation

            target: galleryicon
            properties: "width,height"
            duration: 1000
            from:musicicon.width
            to:Screen.width/5
        }
        PropertyAnimation
        {
            id:galleryiconopacityanimation

            target: galleryicon
            properties: "opacity"
            duration: 1000
            from:0.4
            to:1.0
        }
    }

    ParallelAnimation
    {
        id:galleryparallelanimationstop

        running: false
        PropertyAnimation
        {
            id:galleryiconwidthandheightanimation1

            properties: "width,height"
            target: galleryicon
            duration: 1000
            from:Screen.width/5
            to:Screen.width/8
        }
        PropertyAnimation
        {
            id:galleryiconopacityanimation1

            target: galleryicon
            properties: "opacity"
            duration: 1000
            from:1.0
            to:0.4
        }
    }

}
