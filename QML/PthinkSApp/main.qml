import QtQuick 2.5
import QtQuick.Window 2.0
import Gallery 1.0

Window {
    id : _rootItem
    visible: true
    width: 500
    height: 600
    title: qsTr("Hello World")
    property var obj : null;
    function resetGridView(selectedItem){
        console.log(" resetGridView for a Selected Item ="+selectedItem);
        var idx = md.getGridViewIndex(selectedItem)
        console.log(" Grid Index of selected Item="+idx);
        gridView.currentIndex = idx;
    }

    signal startNewView(int myindex)
    Connections{
        target: _rootItem
        onStartNewView:{
            console.log(" Everything is complete")
        }
    }

    function createFlatView(media_index) {
        console.log(" Setting the current index="+media_index)
        var comp  = Qt.createComponent("ImageDetailedView.qml")
        obj = comp.createObject(null,{currentIndex : media_index})
        obj.currentSelectedItem.connect(resetGridView)
    }

    Component{
        id : del
        Rectangle{
            width: 490;height: 400;color: "blue"
            border.color: "red";border.width: 2
            Column {
                Text {
                    text : (media_index + " - " + title);
                    font.pixelSize: 20
                    color: "white"
                }
                Text {
                    text : date;
                    font.pixelSize: 20
                    color: "white"
                }
            }
        }
    }
    Component{
        id : del1
        Rectangle{
            width: 80;height: 45;color: "blue"
            property int myindex : media_index
            Column {
                Text {
                    text : (media_index + " :: " + title);
                    font.pixelSize: 10
                    color: "white"
                }
                Text {
                    text : date;
                    font.pixelSize: 10
                    color: "white"
                }
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log(" QML - Selected Item Index ="+myindex);
                    md.selectedItem(myindex,myindex)
                    _rootItem.createFlatView(myindex)
                    _rootItem.startNewView(myindex)
                }
            }
        }
    }

    MediaList{
        id : md
    }
    Component{
        id : gr
        Rectangle{
            id : _r1
            width: 500;
            height: 250
            border.width: 1;border.color: "red"
            Column {
                anchors.fill: parent
                spacing: 3
                //Text { text : index + "-" + date ;font.pixelSize: 20}
                Text { text :  "-" + date ;font.pixelSize: 20}
                GridView{
                    width: parent.width
                    height: parent.height-25
                    cellHeight: 50;
                    cellWidth: 90
                    delegate : del1
                    model : filteredModel
                }
            }
            Component.onCompleted: {
                console.log(" Delegate is created ="+index)
            }
        }
    }

    Component{
        id : l2
        ListView{
            width: 500;
            height: parent.height
            id :l1
            delegate: del
            model: md.flatModel
            orientation: ListView.Horizontal
            snapMode: ListView.SnapToItem
            anchors.bottom: parent.bottom
        }
    }

    Component{
        id : h1
        Rectangle{
            width: 500
            height: 250;
            color: Qt.rgba(0,0,1,0.5)
            border.color: "black"
            border.width: 1;
            z:2
        }
    }

    Component{
        id : checkMe
        Rectangle{
            id : _checkMe1
            width: 500;
            height: 250
            border.width: 1;border.color: "red"
            GridView{
                width: parent.width
                height: parent.height-25
                cellHeight: 50;
                cellWidth: 90
                delegate : del1
                model : filteredModel
            }
            Component.onCompleted: {
                console.log(" Testing Delegate is created ="+index)
            }
        }
    }

    Row {
        id : r1
        anchors.fill: parent
        ListView{
            id : gridView
            width: 500;
            height: parent.height
            delegate:checkMe
            model: md.dateModel
            highlight: h1
            highlightFollowsCurrentItem: true
            currentIndex: 0
        }
        focus: true
        Keys.onEscapePressed: {
            console.log(" Print debug data")
            md.print();
        }
    }
}
