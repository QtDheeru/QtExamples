import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Rectangle
{
    id:mainrectangle
    width:Screen.width/1.34
    height: Screen.height/1.51
    gradient: Gradient
    {
    GradientStop{position: 0.0;color:"transparent"}
    GradientStop{position: 0.44;color:"#07689F"}
    GradientStop{position: 1.0;color:"#020303"}
    }

TimeComponent
{
    id:timecomponent
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.topMargin: parent.height*2/100
    anchors.rightMargin: parent.width*3/100

}

Text
{
    id:fmText
    text:"FM"
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.topMargin: parent.height*5/100
    anchors.leftMargin: parent.width*3/100
    font.pixelSize: Math.min(Screen.width/34,Screen.height/38)
    color:"white"
    font.family: "Brie Light"
}
Rectangle
{
    id:topborderrect
    width: parent.width*95/100
    height: parent.height*1/100
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top:fmText.bottom
    anchors.topMargin: parent.height*2/100
    radius: 3
    color:"#7EC0E4"

}

Rectangle
{
    id:topRectangle
    width: parent.width*95/100
    height: parent.width*20/100
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: topborderrect.bottom
    color:"transparent"
    border.color: "#07689F"

    Rectangle
    {
        id:fmStationNumberdisplay
        width: parent.width*40/100
        height: parent.height*95/100
        border.color: "#07689F"
        border.width: 2
        anchors.centerIn: parent
        gradient: Gradient
        {
        GradientStop { position: 0.0 ; color:"#B3B9BA"  }
        GradientStop { position: 0.1 ; color:"transparent" }
        GradientStop { position: 0.22 ; color:"transparent" }
        GradientStop { position: 0.33 ; color:"transparent"  }
        GradientStop { position: 0.77 ; color:"transparent" }
        GradientStop { position: 0.9 ; color:"transparent" }
        GradientStop { position: 1.0 ; color: "#B3B9BA"}
        }

        Text
        {
            id:channelText
            text:"87.5"
            anchors.left: parent.left
            anchors.leftMargin: parent.width*20/100
            anchors.top: parent.top
            anchors.topMargin: parent.height*30/100
            font.pixelSize: Math.min(Screen.width/15,Screen.height/12)
            color:"white"
            font.family: "Brie Light"
        }
        Text
        {
            id:mhzText
            text:"MHz"
            anchors.left:channelText.right
            anchors.top: parent.top
            anchors.topMargin: parent.height*45/100
            font.pixelSize: Math.min(Screen.width/25,Screen.height/25)
            color:"white"
            font.family: "Brie Light"
        }
    }
    Column
    {
        id:leftSideColumn
        anchors.left: parent.left
        anchors.leftMargin: parent.width*3/100
        anchors.top: parent.top
        anchors.topMargin: parent.height*20/100
        spacing: 15
        Row
        {
            id:leftSidetoprowButtons
            Button
            {
                id:scanButton
                background: Rectangle
                {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                GradientStop { position: 0.0 ; color: scanButton.pressed?"transparent": "#B3B9BA"  }
                GradientStop { position: 0.22 ; color:scanButton.pressed?"transparent": "transparent" }
                GradientStop { position: 0.33 ; color:scanButton.pressed?"transparent": "transparent"  }
                GradientStop { position: 0.77 ; color:scanButton.pressed?"transparent": "transparent" }
                GradientStop { position: 1.0 ; color: scanButton.pressed?"transparent": "#B3B9BA"}
            }
        }
        Text
        {
            id:scanText
            text:"SCAN"
            anchors.centerIn: parent
            font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
            color:"white"
            font.family: "Brie Light"
        }
    }
    Button
    {
        id:fmButton
        background: Rectangle
        {
        implicitWidth:topRectangle.width*8/100
        implicitHeight:topRectangle.height*28/100
        border.color:"#787B7D"
        gradient: Gradient
        {
        GradientStop { position: 0.0 ; color: fmButton.pressed?"transparent": "#B3B9BA"  }
        GradientStop { position: 0.22 ; color:fmButton.pressed?"transparent": "transparent" }
        GradientStop { position: 0.33 ; color:fmButton.pressed?"transparent": "transparent"  }
        GradientStop { position: 0.77 ; color:fmButton.pressed?"transparent": "transparent" }
        GradientStop { position: 1.0 ; color: fmButton.pressed?"transparent": "#B3B9BA"}
    }

}
Text
{
    id:fm1Text
    text:"FM1"
    anchors.centerIn: parent
    font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
    color:"white"
    font.family: "Brie Light"
}
}
Button
{
    id:backwardButton
    background: Rectangle
    {
        implicitWidth:topRectangle.width*8/100
        implicitHeight:topRectangle.height*28/100
        border.color:"#787B7D"
        gradient: Gradient
        {
            GradientStop { position: 0.0 ; color: backwardButton.pressed?"transparent": "#B3B9BA"  }
            GradientStop { position: 0.22 ; color:backwardButton.pressed?"transparent": "transparent" }
            GradientStop { position: 0.33 ; color:backwardButton.pressed?"transparent": "transparent"  }
            GradientStop { position: 0.77 ; color:backwardButton.pressed?"transparent": "transparent" }
            GradientStop { position: 1.0 ; color: backwardButton.pressed?"transparent": "#B3B9BA"}
        }

    }
    Image
    {
        id: channelbackwardicon
        width:Math.min(Screen.width/22,Screen.height/22)
        height: width
        source: "qrc:/Images/Channelbacwardicon.png"
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
    }
}
}

Row
{
    id:leftSidebottomrowButtons
    Button
    {
        id:eqButton
        background: Rectangle
        {
            implicitWidth:topRectangle.width*8/100
            implicitHeight:topRectangle.height*28/100
            border.color:"#787B7D"
            gradient: Gradient
            {
                GradientStop { position: 0.0 ; color: eqButton.pressed?"transparent": "#B3B9BA"  }
                GradientStop { position: 0.22 ; color:eqButton.pressed?"transparent": "transparent" }
                GradientStop { position: 0.33 ; color:eqButton.pressed?"transparent": "transparent"  }
                GradientStop { position: 0.77 ; color:eqButton.pressed?"transparent": "transparent" }
                GradientStop { position: 1.0 ; color: eqButton.pressed?"transparent": "#B3B9BA"}
            }

        }
        Text
        {
            id:eqText
            text:"EQ"
            anchors.centerIn: parent
            font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
            color:"white"
            font.family: "Brie Light"
        }
    }
    Button
    {
        id:stButton
        background: Rectangle
        {
            implicitWidth:topRectangle.width*8/100
            implicitHeight:topRectangle.height*28/100
            border.color:"#787B7D"
            gradient: Gradient
            {
                GradientStop { position: 0.0 ; color: stButton.pressed?"transparent": "#B3B9BA"  }
                GradientStop { position: 0.22 ; color:stButton.pressed?"transparent": "transparent" }
                GradientStop { position: 0.33 ; color:stButton.pressed?"transparent": "transparent"  }
                GradientStop { position: 0.77 ; color:stButton.pressed?"transparent": "transparent" }
                GradientStop { position: 1.0 ; color: stButton.pressed?"transparent": "#B3B9BA"}
            }

        }
        Text
        {
            id:stText
            text:"ST"
            anchors.centerIn: parent
            font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
            color:"white"
            font.family: "Brie Light"
        }
    }
    Button
    {
        id:locButton
        background: Rectangle
        {
            implicitWidth:topRectangle.width*8/100
            implicitHeight:topRectangle.height*28/100
            border.color:"#787B7D"
            gradient: Gradient
            {
                GradientStop { position: 0.0 ; color: locButton.pressed?"transparent": "#B3B9BA"  }
                GradientStop { position: 0.22 ; color:locButton.pressed?"transparent": "transparent" }
                GradientStop { position: 0.33 ; color:locButton.pressed?"transparent": "transparent"  }
                GradientStop { position: 0.77 ; color:locButton.pressed?"transparent": "transparent" }
                GradientStop { position: 1.0 ; color: locButton.pressed?"transparent": "#B3B9BA"}
            }

        }
        Text
        {
            id:locText
            text:"LOC"
            anchors.centerIn: parent
            font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
            color:"white"
            font.family: "Brie Light"
        }
    }
}
}


Column
{
    id:rightSideColumn
    anchors.right: parent.right
    anchors.rightMargin: parent.width*3/100
    anchors.top: parent.top
    anchors.topMargin: parent.height*20/100
    spacing: 15
    Row
    {
        id:rightSidetoprowButtons
        Button
        {
            id:forwardButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: forwardButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:forwardButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:forwardButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:forwardButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: forwardButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Image
            {
                id: channelfarwardicon
                width:Math.min(Screen.width/22,Screen.height/22)
                height: width
                source: "qrc:/Images/Channelforwardicon.png"
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
            }

        }
        Button
        {
            id:autoButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: autoButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:autoButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:autoButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:autoButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: autoButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:autoText
                text:"AUTO"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
        }
        Button
        {
            id:saveButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: saveButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:saveButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:saveButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:saveButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: saveButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:saveText
                text:"SAVE"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
        }
    }

    Row
    {
        id:rightSidebottomrowButtons
        Button
        {
            id:ptyButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: ptyButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:ptyButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:ptyButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:ptyButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: ptyButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:ptyText
                text:"PTY"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
        }
        Button
        {
            id:taButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: taButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:taButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:taButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:taButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: taButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:taText
                text:"TA"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
        }
        Button
        {
            id:afButton
            background: Rectangle
            {
                implicitWidth:topRectangle.width*8/100
                implicitHeight:topRectangle.height*28/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: afButton.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:afButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:afButton.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:afButton.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: afButton.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:afText
                text:"AF"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
        }
    }
}

}

Rectangle
{
    id:bottomborderrect
    width: parent.width*95/100
    height: parent.height*1/100
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top:topRectangle.bottom
    radius: 3
    color:"#7EC0E4"
}

CustomizeSlider
{
    id:frequencySlider
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top:bottomborderrect.bottom
    anchors.topMargin: parent.height*5/100
}

Row
{
    id:rowChannelButtons
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: bottomRowButtonBorderRect.top
    anchors.bottomMargin: parent.height*2/100

            Button
            {
                id:channelButton1
                background: Rectangle
                {
                    implicitWidth:topRectangle.width*12.5/100
                    implicitHeight:topRectangle.height*35/100
                    border.color:"#787B7D"
                    gradient: Gradient
                    {
                        GradientStop { position: 0.0 ; color: channelButton1.pressed?"transparent": "#B3B9BA"  }
                        GradientStop { position: 0.22 ; color:channelButton1.pressed?"transparent": "transparent" }
                        GradientStop { position: 0.33 ; color:channelButton1.pressed?"transparent": "transparent"  }
                        GradientStop { position: 0.77 ; color:channelButton1.pressed?"transparent": "transparent" }
                        GradientStop { position: 1.0 ; color: channelButton1.pressed?"transparent": "#B3B9BA"}
                    }

                }
                Text
                {
                    id:channelText1
                    text:"87.5"
                    anchors.centerIn: parent
                    font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                    color:"white"
                    font.family: "Brie Light"
                }
                onClicked:
                {
                    frequencySlider.value=0.1
                    channelText.text=channelText1.text
                }
            }

        Button
        {
            id:channelButton2
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton2.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton2.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton2.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton2.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton2.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText2
                text:"91.9"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.2
                channelText.text=channelText2.text
            }
        }

        Button
        {
            id:channelButton3
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton3.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton3.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton3.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton3.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton3.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText3
                text:"92.7"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.3
                channelText.text=channelText3.text
            }
        }

        Button
        {
            id:channelButton4
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton4.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton4.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton4.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton4.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton4.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText4
                text:"95.0"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.4
                channelText.text=channelText4.text
            }
        }

        Button
        {
            id:channelButton5
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton5.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton5.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton5.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton5.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton5.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText5
                text:"98.3"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.5
                channelText.text=channelText5.text
            }
        }

        Button
        {
            id:channelButton6
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton6.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton6.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton6.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton6.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton6.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText6
                text:"100.3"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.6
                channelText.text=channelText6.text
            }
        }

        Button
        {
            id:channelButton7
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton7.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton7.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton7.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton7.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton7.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText7
                text:"102.9"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.7
                channelText.text=channelText7.text
            }
        }

        Button
        {
            id:channelButton8
            background: Rectangle
            {
                implicitWidth:topRectangle.width*12.5/100
                implicitHeight:topRectangle.height*35/100
                border.color:"#787B7D"
                gradient: Gradient
                {
                    GradientStop { position: 0.0 ; color: channelButton8.pressed?"transparent": "#B3B9BA"  }
                    GradientStop { position: 0.22 ; color:channelButton8.pressed?"transparent": "transparent" }
                    GradientStop { position: 0.33 ; color:channelButton8.pressed?"transparent": "transparent"  }
                    GradientStop { position: 0.77 ; color:channelButton8.pressed?"transparent": "transparent" }
                    GradientStop { position: 1.0 ; color: channelButton8.pressed?"transparent": "#B3B9BA"}
                }

            }
            Text
            {
                id:channelText8
                text:"104.0"
                anchors.centerIn: parent
                font.pixelSize: Math.min(Screen.width/42,Screen.height/44)
                color:"white"
                font.family: "Brie Light"
            }
            onClicked:
            {
                frequencySlider.value=0.8
                channelText.text=channelText8.text
            }
        }

     }
    Rectangle
    {
        id:bottomRowButtonBorderRect
        width: parent.width*95/100
        height: parent.height*1/100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height*3/100
        radius: 3
        color:"#7EC0E4"
    }
}
