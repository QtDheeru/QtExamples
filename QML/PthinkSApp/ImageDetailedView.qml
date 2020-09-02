import QtQuick 2.5
import QtQuick.Window 2.0
import Gallery 1.0
import QtQuick.Controls 2.1
Window {
    id : _rItem
    visible: true
    width: 500
    height: 600
    title: qsTr("Hello World")
    property int listViewHeight : 100
    property alias currentIndex : l1.currentIndex
    property ListView obj : null;
    signal currentSelectedItem(int selectedItem)

    Connections{
        target: swipeId
        onSendMe:{
           console.log("Swipe View current Index changed ="+idx);
           _rItem.currentSelectedItem(idx)
        }
    }

    SwipeView{
        id:swipeId
        width: parent.width
        height: parent.height - 100
        anchors.horizontalCenter: parent.horizontalCenter
        signal sendMe(int idx)

        Repeater{
            id:repeaterId
            model: md.flatModel

            Loader{
                property int currentIndex : swipeId.currentIndex
                active: SwipeView.isCurrentItem || SwipeView.isPreviousItem ||SwipeView.isNextItem
                sourceComponent: Rectangle{
                    id:rect
                    width: 500
                    height: 500
                    color: "beige"
                    border.color: "blue"
                    Column{
                        anchors.centerIn: parent
                        Text {
                            text:model.title
                        }
                    }
                }
            }
        }
        onCurrentIndexChanged: {
            console.log(" Current Selected Item from SwipeView ="+currentIndex)
            l1.positionViewAtIndex(currentIndex,ListView.SnapOneItem)
            //sendMe(currentIndex);
        }
    }

    Component{
        id:del
        Rectangle{
            id:rect
            width: listViewHeight
            height: listViewHeight
            color: "beige"
            border.color: "blue"
            Text {
                anchors.centerIn: parent
                text:model.title
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    l1.currentIndex = index
                }
            }
        }
    }
    Component{
        id : h1
        Rectangle{
            id:rect
            width: listViewHeight
            height: listViewHeight
            color: Qt.rgba(1,0,0,0.7)
            border.color: "blue"
            z  : 2
        }
    }

    ListView{
        id :l1
        width:parent.width
        height: listViewHeight + 2
        delegate: del
        model: md.flatModel
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
        anchors.bottom: parent.bottom
        currentIndex: swipeId.currentIndex
        preferredHighlightBegin: width/2 -50
        preferredHighlightEnd: width/2 + 50
        highlightRangeMode: ListView.StrictlyEnforceRange
        highlight: h1
        highlightFollowsCurrentItem: true

        onCurrentIndexChanged: {
            swipeId.setCurrentIndex(currentIndex)
            console.log("Current index changed ListView="+currentIndex)
        }
    }
}

