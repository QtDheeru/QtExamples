import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtMultimedia 5.6
import QtQuick.Controls.Styles 1.4

Rectangle
{
    id: homemainrect
    width: Screen.width
    height: Screen.height
    gradient: Gradient
    {
        GradientStop{position: 0.38;color:"#020303"}
        GradientStop{position: 0.44;color:"#585A5C"}
        GradientStop{position: 0.88;color:"#020303"}
    }


    Rectangle
    {
        id:dvdinsertrect

        width:Screen.width/1.335
        height: Screen.height/85
        anchors.top:parent.top
        anchors.topMargin: Screen.width/55
        radius: 3
        color:"transparent"
        border.color: "#787B7D"
        anchors.horizontalCenter: parent.horizontalCenter;

    }

    Button
    {
        id:dvdbuttoncontrol

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: Screen.width/80
        anchors.topMargin: Screen.width/90
        enabled: false
        background: Rectangle
        {
            id:dvdejectbutton
            implicitWidth:Screen.width/12
            implicitHeight:Screen.height/24
            border.color:"#787B7D"
            border.width:dvdbuttoncontrol.activeFocus?3:1
            gradient: Gradient
            {
                GradientStop { position: 0.0 ; color:dvdbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                GradientStop { position: 0.22 ; color:dvdbuttoncontrol.pressed?"#000305": "transparent" }
                GradientStop { position: 0.33 ; color:dvdbuttoncontrol.pressed?"#000305": "transparent"  }
                GradientStop { position: 0.77 ; color:dvdbuttoncontrol.pressed?"#000305":  "transparent" }
                GradientStop { position: 1.0 ; color: dvdbuttoncontrol.pressed?"#000305": "#B3B9BA"}
            }



        }

        Image
        {
            id: dvdejecticon
            width:Math.min(Screen.width/30,Screen.height/30)
            height: width
            source: "qrc:/Images/DvdEjectIcon.png"
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
        }

        onPressed:
        {
            dvdejectbutton.border.color="silver"
        }

        onReleased:
        {
            dvdejectbutton.border.color="#037EF8"
        }


    }


    Row
    {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: Screen.width/80
        anchors.topMargin: Screen.width/90


        Button
        {

            id:minusbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:screenbrightnessminusbutton
                implicitWidth:Screen.width/36
                implicitHeight:Screen.height/24
                border.color:"#787B7D"
                border.width:minusbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:minusbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:minusbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:minusbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:minusbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: minusbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }

            Text
            {
                id:textminus
                text: "-"
                font.pixelSize: Math.min(Screen.width/10,Screen.height/20)
                color:"white"
                anchors.centerIn: parent
                font.family: "Brie Light"
            }
            onClicked:
            {
                if(displayrect.opacity==1.0)
                {
                    displayrect.opacity=0.9

                }
                else if(displayrect.opacity==0.9)
                {
                    displayrect.opacity=0.8
                }
                else if(displayrect.opacity==0.8)
                {
                    displayrect.opacity=0.7
                }
                else if(displayrect.opacity==0.7)
                {
                    displayrect.opacity=0.6
                }
                else if(displayrect.opacity==0.6)
                {
                    displayrect.opacity=0.5
                }
                if(displayrect.opacity==0.5)
                {
                    displayrect.opacity=0.4
                }
                else if(displayrect.opacity==0.4)
                {
                    displayrect.opacity=0.3
                }
                else if(displayrect.opacity==0.3)
                {
                    displayrect.opacity=0.2
                }
                else if(displayrect.opacity==0.2)
                {
                    displayrect.opacity=0.1
                }
                else if(displayrect.opacity==0.1)
                {
                    displayrect.opacity=0.0
                }
            }

            onPressed:
            {
                screenbrightnessminusbutton.border.color="silver"
            }

            onReleased:
            {
                screenbrightnessminusbutton.border.color="#037EF8"
            }

        }

        Button
        {

            id:screenimagebuttoncontrol
            background: Rectangle
            {
                id:screenbrightnessimagebutton
                implicitWidth:Screen.width/36
                implicitHeight:Screen.height/24
                border.color:"#787B7D"
                border.width:screenimagebuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:screenimagebuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:screenimagebuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:screenimagebuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:screenimagebuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: screenimagebuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }


            Image
            {
                id: brightnessicon
                width:Math.min(Screen.width/28,Screen.height/28)
                height: width
                anchors.centerIn: parent
                source: "qrc:/Images/brightnessicon.png"
                fillMode: Image.PreserveAspectFit
            }

            onPressed:
            {
                screenbrightnessimagebutton.border.color="silver"
            }

            onReleased:
            {
                screenbrightnessimagebutton.border.color="#037EF8"
            }
        }

        Button
        {

            id:plusbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:screenbrightnessplusbutton
                implicitWidth:Screen.width/36
                implicitHeight:Screen.height/24
                border.color:"#787B7D"
                border.width:plusbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:plusbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:plusbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:plusbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:plusbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: plusbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }
            }



            Text {
                id:textplus
                text: "+"
                font.pixelSize: Math.min(Screen.width/30,Screen.height/40)
                color:"white"
                anchors.centerIn: parent
                font.family: "Brie Light"
            }

            onClicked:
            {
                if(displayrect.opacity==0.0)
                {
                    displayrect.opacity=0.1
                }
                else if(displayrect.opacity==0.1)
                {
                    displayrect.opacity=0.2
                }
                else if(displayrect.opacity==0.2)
                {
                    displayrect.opacity=0.3
                }
                else if(displayrect.opacity==0.3)
                {
                    displayrect.opacity=0.4
                }
                else if(displayrect.opacity==0.4)
                {
                    displayrect.opacity=0.5
                }
                if(displayrect.opacity==0.5)
                {
                    displayrect.opacity=0.6
                }
                else if(displayrect.opacity==0.6)
                {
                    displayrect.opacity=0.7
                }
                else if(displayrect.opacity==0.7)
                {
                    displayrect.opacity=0.8
                }
                else if(displayrect.opacity==0.8)
                {
                    displayrect.opacity=0.9
                }
                else if(displayrect.opacity==0.9)
                {
                    displayrect.opacity=1.0
                }


            }

            onPressed:
            {
                screenbrightnessplusbutton.border.color="silver"
            }

            onReleased:
            {
                screenbrightnessplusbutton.border.color="#037EF8"
            }


        }
    }


    Rectangle
    {
        id:borderrect
        width:Screen.width/1.08
        height: Screen.height/200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:dvdinsertrect.bottom
        anchors.topMargin:Screen.width/70
        radius: 3
        color:"#020303"

    }
    Rectangle
    {
        id:displayrect
        width:Screen.width/1.335
        height: Screen.height/1.5
        anchors.top: borderrect.bottom
        anchors.topMargin: Screen.width/80
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "#787B7D"
        border.width: 2
        color:"#032135"
        opacity: 0.8


        Image
        {
            id: logoicon
            width:Math.min(Screen.width/4.8,Screen.height/4.8)
            height: width
            source: "qrc:/Images/Gold_logo2.png"
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            visible: false
        }
        TimeComponent
        {
            id:timecomponent
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: Screen.width/120
            anchors.rightMargin: Screen.width/120
            visible: false

        }

        MusicandVideoButtonComponent
        {
            id:mediacomponent
            anchors.centerIn: displayrect
            visible: false
        }

        VideoPlayerComponent
        {
            id:videocomponent
            anchors.centerIn: displayrect
            visible: false

        }

        RadioScreen
        {
            id:radioScreenComponent
            anchors.centerIn: displayrect
            visible: false
        }


        MusicPlayerComponent
        {
            id:audiocomponent
            anchors.centerIn: displayrect
            visible: false
            Audio
            {
                id:audioplayer
                source:""
                volume:0

                playlist: Playlist {
                    id: playlist

                    PlaylistItem { source: "song1.ogg"; }
                    PlaylistItem { source: "song2.ogg"; }
                    PlaylistItem { source: "song3.ogg"; }
                    PlaylistItem { source: "song1.ogg"; }

                }


            }
        }

        GalleryImagesComponent
        {
            id:gallerycomponent
            anchors.centerIn: displayrect
            visible: false
        }



    }
    Column
    {
        id:phoneandmusicrect
        anchors.left: parent.left
        anchors.top: borderrect.bottom
        anchors.leftMargin: Screen.width/80
        anchors.topMargin: Screen.width/80

        Button
        {

            id:phonebuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:phonebutton
                implicitWidth:Screen.width/12
                implicitHeight:implicitWidth
                border.color:"#787B7D"
                border.width:phonebuttoncontrol.activeFocus?3:1

                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:phonebuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.11 ; color:phonebuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.22 ; color:phonebuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:phonebuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:phonebuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 0.88 ; color:phonebuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 1.0 ; color: phonebuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }


            }

            Rectangle
            {
                id:phoneborderrect
                width:Screen.width/14
                height: Screen.height/200
                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin:Screen.width/130
                radius: 3
                color:"#020303"

            }
            Image
            {
                id: phoneicon
                width:Math.min(Screen.width/12,Screen.height/12)
                height: width
                source: "qrc:/Images/Mobile_Icon.png"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: phoneborderrect.bottom
                anchors.topMargin: Screen.width/100
                fillMode: Image.PreserveAspectFit
            }

            onPressed:
            {
                phonebutton.border.color="silver"
            }

            onReleased:
            {
                phonebutton.border.color="#037EF8"
            }

        }
        Button
        {
            id:mediabuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:mediabutton
                implicitWidth:Screen.width/12
                implicitHeight:implicitWidth
                border.color:"#787B7D"
                border.width:mediabuttoncontrol.activeFocus?3:1

                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:mediabuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.11 ; color:mediabuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.22 ; color:mediabuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:mediabuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:mediabuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 0.88 ; color:mediabuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 1.0 ; color: mediabuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }



            }


            Image
            {
                id: mediaicon
                width:Math.min(Screen.width/14,Screen.height/14)
                height: width
                source: "qrc:/Images/mediaicon.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit


            }


            onClicked:
            {


                loadpages.source="MusicandVideoButtonComponent.qml"
                mediacomponentanimation.running=true
                backbuttoncontrol.enabled=true
            }

            onPressed:
            {
                mediabutton.border.color="silver"
            }

            onReleased:
            {
                mediabutton.border.color="#037EF8"
            }


            Rectangle
            {
                id:mediaborderrect
                width:Screen.width/14
                height: Screen.height/200
                anchors.bottom:parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottomMargin:Screen.width/130
                radius: 3
                color:"transparent"
            }

        }

    }
    Column
    {
        id:radioandcdrect
        anchors.right: parent.right
        anchors.top: borderrect.bottom
        anchors.rightMargin: Screen.width/80
        anchors.topMargin: Screen.width/80

        Button
        {

            id:radiobuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:radiobutton
                implicitWidth:Screen.width/12
                implicitHeight:implicitWidth
                border.color:"#787B7D"
                border.width:radiobuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:radiobuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.11 ; color:radiobuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.22 ; color:radiobuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:radiobuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:radiobuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 0.88 ; color:radiobuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 1.0 ; color: radiobuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }



            }

            onPressed:
            {
                radiobutton.border.color="silver"
            }

            onReleased:
            {
                radiobutton.border.color="#037EF8"
            }

            onClicked:
            {
                textradio.color="#CB0432"
                textCdandAux.color="#037EF8"
                loadpages.source="RadioScreen.qml"
                timecomponent.visible=false


            }


            Rectangle
            {
                id:radioborderrect
                width:Screen.width/14
                height: Screen.height/200
                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin:Screen.width/130
                radius: 3
                color:"#020303"

            }
            Text {
                id:textradio
                text: "Radio"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }




        }
        Button
        {
            id:cdbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:cdbutton
                implicitWidth:Screen.width/12
                implicitHeight:implicitWidth
                border.color:"#787B7D"
                border.width:cdbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:cdbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.11 ; color:cdbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.22 ; color:cdbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:cdbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:cdbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 0.88 ; color:cdbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 1.0 ; color: cdbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }

            onPressed:
            {
                cdbutton.border.color="silver"
            }

            onReleased:
            {
                cdbutton.border.color="#037EF8"
            }
            onClicked:
            {
                textCdandAux.color="#CB0432"
                textradio.color="#037EF8"

            }


            Rectangle
            {
                id:cdborderrect
                width:Screen.width/14
                height: Screen.height/200
                anchors.bottom:parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottomMargin:Screen.width/130
                radius: 3
                color:"transparent"
            }
            Text {
                id:textCdandAux
                text: "CD/AUX"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/32,Screen.height/42)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }

        }
    }


    Dial
    {
        id:menusscrolldial
        anchors.left: parent.left
        anchors.top:phoneandmusicrect.bottom
        anchors.leftMargin: Screen.width/80
        anchors.topMargin: Screen.width/20
        width: Screen.width/12
        height: width

        background:Rectangle
        {
            id:menulistrect
            width: Screen.width/12
            height: width
            radius:width/2
            border.color:"grey"
            border.width:6
            gradient: Gradient
            {
                GradientStop{position: 0.2;color:"#000305"}
                GradientStop{position: 0.88;color:"#000305"}
                GradientStop{position: 1;color:"#585A5C"}
            }
        }



        Text
        {
            id:textlist
            text: "List"
            anchors.top:parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: Screen.width/100
            font.pixelSize: Math.min(Screen.width/50,Screen.height/50)
            color:"#037EF8"
            font.family: "Brie Light"
            visible: false

        }

        Text
        {
            id:textpush
            text: "Push"
            anchors.top:textlist.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: Screen.width/160
            font.pixelSize: Math.min(Screen.width/50,Screen.height/50)
            color:"#037EF8"
            font.family: "Brie Light"
            visible: false

        }

        Text
        {
            id:textselect
            text: "Select"
            anchors.top:textpush.bottom
            anchors.topMargin: Screen.width/200
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: Math.min(Screen.width/50,Screen.height/50)
            color:"#037EF8"
            font.family: "Brie Light"
            visible: false

        }

    }


    Dial
    {
        id:volumescrolldial
        anchors.right: parent.right
        anchors.top:radioandcdrect.bottom
        anchors.rightMargin: Screen.width/80
        anchors.topMargin: Screen.width/20
        width: Screen.width/12
        height: width

        background:Rectangle
        {
            id:volumerect
            width: Screen.width/12
            height: width
            radius:width/2
            border.color:"grey"
            border.width:6
            gradient: Gradient
            {
                GradientStop{position: 0.2;color:"#000305"}
                GradientStop{position: 0.88;color:"#000305"}
                GradientStop{position: 1;color:"#585A5C"}
            }

        }

        Text
        {
            id:textvolume
            text: "Volume"
            anchors.centerIn: parent
            font.pixelSize: Math.min(Screen.width/32,Screen.height/40)
            color:"#037EF8"
            font.family: "Brie Light"
            visible: false

        }

        onValueChanged:
        {
            audioplayer.volume=volumescrolldial.value

        }


    }



    Image
    {
        id: buttonBackgroundImage
        width:Screen.width/1.335
        height: Screen.height/8
        source: "qrc:/Images/ButtonBackground.png"
        anchors.top: displayrect.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false

    }


    Row
    {
        id:bottombuttons
        anchors.top: displayrect.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        Button
        {

            id:button1control
            enabled: false

            background: Rectangle
            {
                id:button1

                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button1control.activeFocus?3:1

                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: button1control.pressed?"#000305": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button1control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button1control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button1control.pressed?"#000305": "transparent" }
                    GradientStop { position: 1.0 ; color: button1control.pressed?"#000305": "#B3B9BA"}
                }


            }
            Text {
                id:textone
                text: "1"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }

            onClicked:
            {
                textone.color="#CB0432"
                texttwo.color="#037EF8"
                textthree.color="#037EF8"
                textfour.color="#037EF8"
                textfive.color="#037EF8"
                textsix.color="#037EF8"

            }

            onPressed:
            {
                button1.border.color="silver"
            }

            onReleased:
            {
                button1.border.color="#037EF8"
            }


        }
        Button
        {

            id:button2control
            enabled: false
            background: Rectangle
            {
                id:button2
                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button2control.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:button2control.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button2control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button2control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button2control.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: button2control.pressed?"#000305": "#B3B9BA"}
                }
            }
            Text {
                id:texttwo
                text: "2"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }

            onClicked:
            {
                textone.color="#037EF8"
                texttwo.color="#CB0432"
                textthree.color="#037EF8"
                textfour.color="#037EF8"
                textfive.color="#037EF8"
                textsix.color="#037EF8"

            }

            onPressed:
            {
                button2.border.color="silver"
            }

            onReleased:
            {
                button2.border.color="#037EF8"
            }


        }
        Button
        {

            id:button3control
            enabled: false
            background: Rectangle
            {
                id:button3
                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button3control.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:button3control.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button3control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button3control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button3control.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: button3control.pressed?"#000305": "#B3B9BA"}
                }

            }

            Text {
                id:textthree
                text: "3"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }
            onClicked:
            {
                textone.color="#037EF8"
                texttwo.color="#037EF8"
                textthree.color="#CB0432"
                textfour.color="#037EF8"
                textfive.color="#037EF8"
                textsix.color="#037EF8"

            }

            onPressed:
            {
                button3.border.color="silver"
            }

            onReleased:
            {
                button3.border.color="#037EF8"
            }




        }
        Button
        {

            id:button4control
            enabled: false
            background: Rectangle
            {
                id:button4
                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button4control.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:button4control.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button4control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button4control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button4control.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: button4control.pressed?"#000305": "#B3B9BA"}
                }

            }
            Text {
                id:textfour
                text: "4"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }
            onClicked:
            {
                textone.color="#037EF8"
                texttwo.color="#037EF8"
                textthree.color="#037EF8"
                textfour.color="#CB0432"
                textfive.color="#037EF8"
                textsix.color="#037EF8"

            }

            onPressed:
            {
                button4.border.color="silver"
            }

            onReleased:
            {
                button4.border.color="#037EF8"
            }



        }
        Button
        {

            id:button5control
            enabled: false
            background: Rectangle
            {
                id:button5
                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button5control.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ;  color:button5control.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button5control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button5control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button5control.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ;  color: button5control.pressed?"#000305": "#B3B9BA"}
                }

            }
            Text {
                id:textfive
                text: "5"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }

            onClicked:
            {
                textone.color="#037EF8"
                texttwo.color="#037EF8"
                textthree.color="#037EF8"
                textfour.color="#037EF8"
                textfive.color="#CB0432"
                textsix.color="#037EF8"

            }

            onPressed:
            {
                button5.border.color="silver"
            }

            onReleased:
            {
                button5.border.color="#037EF8"
            }




        }
        Button
        {

            id:button6control
            enabled: false
            background: Rectangle
            {
                id:button6
                implicitWidth:Screen.width/8
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:button6control.activeFocus?3:1

                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:button6control.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:button6control.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:button6control.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:button6control.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: button6control.pressed?"#000305": "#B3B9BA"}
                }
            }
            Text {
                id:textsix
                text: "6"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/28,Screen.height/38)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }
            onClicked:
            {
                textone.color="#037EF8"
                texttwo.color="#037EF8"
                textthree.color="#037EF8"
                textfour.color="#037EF8"
                textfive.color="#037EF8"
                textsix.color="#CB0432"

            }

            onPressed:
            {
                button6.border.color="silver"
            }

            onReleased:
            {
                button6.border.color="#037EF8"
            }



        }

    }

    Row
    {
        id:backandmenubutton
        anchors.left: parent.left
        anchors.leftMargin: Screen.width/80
        anchors.top:menusscrolldial.bottom
        anchors.topMargin: Screen.width/13.6
        Button
        {

            id:backbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:backbutton
                implicitWidth:Screen.width/24
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:backbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:backbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:backbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:backbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:backbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: backbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }
            Image
            {
                id: backicon
                width:Math.min(Screen.width/15,Screen.height/15)
                height: width
                source: "qrc:/Images/backbutton.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit

            }
            onClicked:
            {
                audiocomponent.visible=false
                videocomponent.visible=false
                gallerycomponent.visible=false
                loadpages.source="MusicandVideoButtonComponent.qml"
                audioplayer.stop()

            }

            onPressed:
            {
                backbutton.border.color="silver"
            }

            onReleased:
            {
                backbutton.border.color="#037EF8"
            }



        }
        Button
        {

            id:menuclockbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:menuclockbutton
                implicitWidth:Screen.width/24
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:menuclockbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:menuclockbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:menuclockbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:menuclockbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:menuclockbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: menuclockbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }
            Text {
                id:textmenuclock
                text: "<br>Menu</br><br> Clock</br>"
                anchors.top:parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin:Screen.width/110

                font.pixelSize: Math.min(Screen.width/40,Screen.height/44)
                color:"#037EF8"
                font.family: "Brie Light"
                visible: false

            }

            onPressed:
            {
                menuclockbutton.border.color="silver"
            }

            onReleased:
            {
                menuclockbutton.border.color="#037EF8"
            }

        }



    }
    Row
    {
        id:backandfarwardbutton
        anchors.right: parent.right
        anchors.rightMargin: Screen.width/80
        anchors.top:volumescrolldial.bottom
        anchors.topMargin: Screen.width/13.6
        Button
        {
            id:backwardbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:backwardbutton

                implicitWidth:Screen.width/24
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:backwardbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:backwardbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:backwardbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:backwardbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:backwardbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: backwardbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }

            }
            Image
            {
                id: backwardicon
                width:Math.min(Screen.width/22,Screen.height/22)
                height: width
                source: "qrc:/Images/Backwardicon.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit

            }

            onPressed:
            {
                backwardbutton.border.color="silver"
            }

            onReleased:
            {
                backwardbutton.border.color="#037EF8"
            }


        }
        Button
        {

            id:forwardbuttoncontrol
            enabled: false
            background: Rectangle
            {
                id:forwardbutton

                implicitWidth:Screen.width/24
                implicitHeight:Screen.height/8
                border.color:"#787B7D"
                border.width:forwardbuttoncontrol.activeFocus?3:1
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color:forwardbuttoncontrol.pressed?"#000305":  "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:forwardbuttoncontrol.pressed?"#000305": "transparent" }
                    GradientStop { position: 0.33 ; color:forwardbuttoncontrol.pressed?"#000305": "transparent"  }
                    GradientStop { position: 0.77 ; color:forwardbuttoncontrol.pressed?"#000305":  "transparent" }
                    GradientStop { position: 1.0 ; color: forwardbuttoncontrol.pressed?"#000305": "#B3B9BA"}
                }


            }
            Image
            {
                id: forwardicon
                width:Math.min(Screen.width/22,Screen.height/22)
                height: width
                source: "qrc:/Images/forwardIcon.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
            }

            onPressed:
            {
                forwardbutton.border.color="silver"
            }

            onReleased:
            {
                forwardbutton.border.color="#037EF8"
            }


        }



    }


    Rectangle
    {
        id:enginestartandstopcomponent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: displayrect.bottom
        color:"white"

        EngineStartComponent
        {

            Rectangle
            {
                id:blickrect
                width:Screen.width/45
                height: Screen.height/80
                radius: 3
                anchors.centerIn: parent
                color:"#CB0432"

            }

        }
    }

    PropertyAnimation
    {
        id:imageanimation

        from:0
        to:1
        duration: 2000
        running: false
        target:buttonBackgroundImage
        property: "opacity"

    }





    PropertyAnimation
    {
        id:coloranimation

        from:"#CB0432"
        to:"white"
        duration: 1000
        running: false
        target:blickrect
        property: "color"
        loops: Animation.Infinite
    }
    PropertyAnimation
    {
        id:coloranimation1

        from:"white"
        to:"#CB0432"
        duration: 1000
        running: false
        target:blickrect
        property: "color"


    }

    PropertyAnimation
    {
        id:logoanimation

        from:0
        to:1
        duration: 2000
        running: false
        target:logoicon
        property: "opacity"

    }

    PropertyAnimation
    {
        id:logoanimation1

        from:1
        to:0
        duration: 2000
        running: false
        target:logoicon
        property: "opacity"

    }

    PropertyAnimation
    {
        id:mediacomponentanimation

        from:0
        to:1
        duration: 2000
        running: false
        target:mediacomponent
        property: "opacity"

    }

    Timer
    {
        id:logoanimationtimer
        interval:3000
        running: true

        onTriggered:
        {

            logoanimation1.running=true


        }
    }
    Timer
    {
        id:time_timer
        interval:5000
        running: false

        onTriggered:
        {


            timecomponent.visible=true

        }
    }

    Loader
    {
        id:loadpages
        anchors.centerIn: displayrect

    }

}

