import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Slider
{
    id:genericslider
    width:parent.width*95/100
    value:0.0
    tickmarksEnabled:true
    stepSize:0.1

    style: SliderStyle {
              groove: Rectangle {
                  id:grooveRect
                  implicitWidth: parent.width
                  implicitHeight: 20
                  gradient: Gradient
                  {
                      GradientStop { position: 0.0 ; color:  "#B3B9BA"  }
                      GradientStop { position: 0.22 ; color: "transparent" }
                      GradientStop { position: 0.33 ; color: "transparent"  }
                      GradientStop { position: 0.77 ; color: "transparent" }
                      GradientStop { position: 1.0 ; color:  "#B3B9BA"}
                  }

                  Rectangle
                  {
                      id: innerRectWidth
                      color: "transparent" // For changing the filling color you set this property
                      height: parent.height
                      implicitHeight: grooveRect.implicitHeight
                      implicitWidth: grooveRect.implicitWidth
                      width: styleData.handlePosition
                      radius: 8
                  }


              }

              handle: Rectangle {

                  anchors.centerIn: parent
                  color: "red"
                  implicitWidth: 2
                  implicitHeight:70
                  radius: implicitWidth/2
              }


          }

}

