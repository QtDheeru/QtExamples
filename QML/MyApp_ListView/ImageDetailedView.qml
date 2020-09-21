import QtQuick 2.14
import QtQuick.Window 2.0
import Gallery 1.0
import QtQuick.Controls 2.14
Window {
    id : root
    visible: true
    width: 500
    height: 600
    title: qsTr("Hello World")
    property int listViewHeight : 100
    property alias bottomIndex : _listView.currentIndex
    property alias topIndex : _topView.currentIndex

    Component {
        id: delegate
        Rectangle {
            id: wrapper
            width: _topView.width
            height: _topView.height
            color: "blue"
            Text {
                anchors.centerIn: parent
                font.pointSize: 26
                font.bold: true
                color: "white"
                text:model.title
            }
            Component.onCompleted: {
                console.log(" Delegate Index ="+index)
            }
            Component.onDestruction: {
                console.log(" Delegate destructed ="+index)
            }
        }
    }

    ListView {
        id: _topView
        width: parent.width
        height: parent.height - 102
        snapMode: PathView.SnapOneItem
        highlightRangeMode: PathView.StrictlyEnforceRange
        orientation: ListView.Horizontal
        onCurrentIndexChanged: {
            console.log("Top-ListView Current index changed="+currentIndex)
            bindingBreaker.setTopIndex(currentIndex);
            md.flatModel.setCurrentIndex(currentIndex)
        }
        highlightMoveDuration: 1000
        highlightMoveVelocity: -1
        model: md.flatModel
        delegate: delegate
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

    Connections{
        target :bindingBreaker
        onMoveBottomView:{
            console.log("Move the bottom ListView")
            _listView.currentIndex = bottomIndex;
        }
        onMoveTopView:{
            console.log("Move the top listView");
            _topView.currentIndex = topIndex;
        }
    }

    ListView{
        id :_listView
        width:parent.width
        height: listViewHeight + 2
        delegate: del
        model: md.flatModel
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
        anchors.bottom: parent.bottom
        preferredHighlightBegin: width/2 -50
        preferredHighlightEnd: width/2 + 50
        highlightRangeMode: ListView.StrictlyEnforceRange
        highlight: h1
        highlightFollowsCurrentItem: true

        onCurrentIndexChanged: {
            console.log("Bottom-ListView Current index changed="+currentIndex)
            bindingBreaker.setBottomIndex(currentIndex);
        }
    }
    QtObject{
        id : bindingBreaker
        signal moveTopView(int topIndex);
        signal moveBottomView(int bottomIndex);
        property var local_topIndex:0
        property var local_bottomIndex:0
        function setBottomIndex(cIndex){
             local_bottomIndex=cIndex;
             if (local_topIndex != local_bottomIndex){
                 moveTopView(local_bottomIndex)
             }
        }
        function setTopIndex(cIndex){
            local_topIndex = cIndex;
            if (local_bottomIndex !=local_topIndex){
                moveBottomView(local_topIndex);
            }
        }
    }
}
