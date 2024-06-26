import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4


Rectangle
{
    id:blackrect

    width: Screen.width/14.2
    height: width
    radius: width/2
    anchors.horizontalCenter: parent.horizontalCenter
    gradient: Gradient
    {
        GradientStop{position: 0;color:"#020303"}
        GradientStop{position: 0.5;color:"#585A5C"}
        GradientStop{position: 0.88;color:"#020303"}
    }

    function mouseAreaSingleClicked()
    {

        forwardbutton.border.color="#037EF8"
        backwardbutton.border.color="#037EF8"
        menuclockbutton.border.color="#037EF8"
        backbutton.border.color="#037EF8"
        button6.border.color="#037EF8"
        button5.border.color="#037EF8"
        button4.border.color="#037EF8"
        button3.border.color="#037EF8"
        button2.border.color="#037EF8"
        button1.border.color="#037EF8"
        cdbutton.border.color="#037EF8"
        radiobutton.border.color="#037EF8"
        mediabutton.border.color="#037EF8"
        phonebutton.border.color="#037EF8"
        screenbrightnessminusbutton.border.color="#037EF8"
        screenbrightnessimagebutton.border.color="#037EF8"
        screenbrightnessplusbutton.border.color="#037EF8"
        dvdejectbutton.border.color="#037EF8"
        volumerect.border.color="#037EF8"
        menulistrect.border.color="#037EF8"
        logoicon.visible=true
        coloranimation.running=true
        logoanimation.running=true
        logoanimationtimer.start()
        time_timer.start()
        mediabuttoncontrol.enabled=true
        minusbuttoncontrol.enabled=true
        plusbuttoncontrol.enabled=true
        borderrect.color="silver"
        textradio.visible=true
        textCdandAux.visible=true
        textmenuclock.visible=true
        textlist.visible=true
        textone.visible=true
        texttwo.visible=true
        textthree.visible=true
        textfour.visible=true
        textfive.visible=true
        textsix.visible=true
        textvolume.visible=true
        textpush.visible=true
        textselect.visible=true
        displayrect.border.color="#037EF8"
        radioborderrect.color="silver"
        mediaborderrect.color="silver"
        cdborderrect.color="silver"
        phoneborderrect.color="silver"
        button1control.enabled=true
        button2control.enabled=true
        button3control.enabled=true
        button4control.enabled=true
        button5control.enabled=true
        button6control.enabled=true
        dvdbuttoncontrol.enabled=true
        phonebuttoncontrol.enabled=true
        radiobuttoncontrol.enabled=true
        cdbuttoncontrol.enabled=true
        menuclockbuttoncontrol.enabled=true
        backwardbuttoncontrol.enabled=true
        forwardbuttoncontrol.enabled=true
        buttonBackgroundImage.visible=true
        imageanimation.start()

    }


    function mouseAreaDoubleClicked()
    {

        coloranimation.running=false
        forwardbutton.border.color="#787B7D"
        backwardbutton.border.color="#787B7D"
        menuclockbutton.border.color="#787B7D"
        backbutton.border.color="#787B7D"
        button6.border.color="#787B7D"
        button5.border.color="#787B7D"
        button4.border.color="#787B7D"
        button3.border.color="#787B7D"
        button2.border.color="#787B7D"
        button1.border.color="#787B7D"
        cdbutton.border.color="#787B7D"
        radiobutton.border.color="#787B7D"
        mediabutton.border.color="#787B7D"
        phonebutton.border.color="#787B7D"
        screenbrightnessminusbutton.border.color="#787B7D"
        screenbrightnessimagebutton.border.color="#787B7D"
        screenbrightnessplusbutton.border.color="#787B7D"
        dvdejectbutton.border.color="#787B7D"
        volumerect.border.color="#787B7D"
        menulistrect.border.color="#787B7D"
        coloranimation1.running=true
        logoicon.visible=false
        timecomponent.visible=false
        time_timer.stop()
        mediabuttoncontrol.enabled=false
        minusbuttoncontrol.enabled=false
        plusbuttoncontrol.enabled=false
        backbuttoncontrol.enabled=false
        borderrect.color="#020303"
        textradio.visible=false
        textCdandAux.visible=false
        textmenuclock.visible=false
        textlist.visible=false
        textone.visible=false
        texttwo.visible=false
        textthree.visible=false
        textfour.visible=false
        textfive.visible=false
        textsix.visible=false
        textvolume.visible=false
        textpush.visible=false
        textselect.visible=false
        displayrect.border.color="#787B7D"
        loadpages.source=""
        radioborderrect.color="#020303"
        mediaborderrect.color="transparent"
        cdborderrect.color="transparent"
        phoneborderrect.color="#020303"
        button1control.enabled=false
        button2control.enabled=false
        button3control.enabled=false
        button4control.enabled=false
        button5control.enabled=false
        button6control.enabled=false
        dvdbuttoncontrol.enabled=false
        phonebuttoncontrol.enabled=false
        radiobuttoncontrol.enabled=false
        cdbuttoncontrol.enabled=false
        menuclockbuttoncontrol.enabled=false
        backwardbuttoncontrol.enabled=false
        forwardbuttoncontrol.enabled=false
        textone.color="#037EF8"
        texttwo.color="#037EF8"
        textthree.color="#037EF8"
        textfour.color="#037EF8"
        textfive.color="#037EF8"
        textsix.color="#037EF8"
        buttonBackgroundImage.visible=false
        textradio.color="#037EF8"
        textCdandAux.color="#037EF8"

    }

    Rectangle
    {
        id:sliverrect

        width: Screen.width/19
        height: width
        radius: width/2
        gradient: Gradient
        {
            GradientStop{position: 0.0;color:"silver"}
            GradientStop{position: 0.5;color:"grey"}
            GradientStop{position: 1;color:"silver"}
        }
        border.color: "#1A1818"
        border.width: 2
        anchors.centerIn: parent

        Rectangle
        {
            id:redrect

            width: Screen.width/24
            height: width
            radius: width/2
            color:"#CB0432"
            border.color: "#EE0E51"
            border.width: 4
            anchors.centerIn: parent

            Text
            {
                id:ontext

                text:"ON"
                font.pixelSize: Math.min(Screen.width/90,Screen.height/80)
                font.bold: true
                anchors.top: parent.top
                anchors.topMargin: Screen.width/150
                anchors.horizontalCenter: parent.horizontalCenter
                color:"#020303"
                font.family: "Brie Light"

            }

            Text
            {
                id:offtext

                text:"OFF"
                font.pixelSize: Math.min(Screen.width/90,Screen.height/80)
                font.bold: true
                anchors.bottom: parent.bottom
                anchors.bottomMargin: Screen.width/150
                anchors.horizontalCenter: parent.horizontalCenter
                color:"#020303"
                font.family: "Brie Light"
            }


            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {

                    mouseAreaSingleClicked()

                }
                onDoubleClicked:
                {
                    mouseAreaDoubleClicked()
                }
            }

        }

    }

}
