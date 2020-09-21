import QtQuick 2.5
import QtQuick.Window 2.0
import Gallery 1.0

Window {
    id : _rootItem
    visible: true
    width: 800
    height: 600
    property int photoWidth : 150;
    property int photoHeight : 150
    property variant dateRows:[]
    property variant dates:[]
    title: qsTr("Hello World")
    property var obj : null;
    function resetGridView(selectedItem){
        console.log(" resetGridView for a Selected Item ="+selectedItem);
        var idx = md.getGridViewIndex(selectedItem)
        console.log(" Grid Index of selected Item="+idx);
        gridView.currentIndex = idx;
    }

    function createFlatView(media_index) {
        console.log(" Create the new List View object ="+media_index)
        var comp  = Qt.createComponent("ImageDetailedView.qml")
        obj = comp.createObject(null,{topIndex : media_index,bottomIndex:media_index})
    }

    Component{
        id : _photoDel
        Rectangle{
            width: _rootItem.photoWidth;height: _rootItem.photoHeight;color: "blue"
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
                    _rootItem.createFlatView(myindex)
                }
            }
            Component.onCompleted: {
                console.log(" Photo delegate Index ="+index);
            }
            Component.onDestruction: {
                console.log(" Delegate deleted ="+index);
            }
        }
    }
    Connections{
        target : md.dateModel
        onCurrentRowChanged :{
            console.log(" Current row to changed in ListView"+row)
            l1.currentIndex = row;
        }
        onDateChanged :{
          console.log(" New Date added for Row = " + row + " Date ="+date)
        }
    }

    Connections{
        target : md
        onNewDate:{
            _rootItem.newDateAdded(row,date);
            console.log(" New Date added for Row = " + row + " Date ="+date)
        }
    }

    function newDateAdded(row,newdate){
        console.log("******* Row = " + row + " Date ="+newdate)
        _rootItem.dateRows.push(row);
        _rootItem.dates.push(newdate);
        console.log(" Rows list ="+_rootItem.dateRows + " Date List ="+_rootItem.dates);
    }

    MediaList{
        id : md
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
        id : gridHighlight
        Rectangle{
            width: 150
            height: 150;
            color: Qt.rgba(1,0,0,0.5)
            border.color: "black"
            border.width: 1;
            z:2
        }
    }

    function dateRowExist(index){
        var retVal = -1;
        console.log(" Rows list ="+_rootItem.dateRows + " Date List ="+_rootItem.dates);
        for(var i=0;i<dateRows.length;i++){
            console.log(" Date Row exist with me="+dateRows[i])
            if (index === dateRows[i]){
                retVal = i;
                console.log(" Date Found ="+  index);
                break;
            }
        }
        return retVal;
    }

    Component{
        id : _listViewDele
        Rectangle {
            id : r1
            width: parent.width
            height: filteredModel.dateVisible ?20:200
            Row {
                id : t1
                width: parent.width
                height: 20
                spacing: 10
                visible: dateRowExist(index)
                Rectangle{width: (parent.width/2)-25;height: 2;border.width:2;border.color:"blue"}
                Text {
                    id : t2
                    width: 10
                    height: 20
                    text : index
                    font.pixelSize: 20
                }
                Rectangle{width: (parent.width/2);height: 2;border.width:2;border.color:"blue"}
            }

            ListView{
                id : l1
                spacing: 10
                width: parent.width
                height: 190
                model : filteredModel
                delegate: _photoDel
                orientation: ListView.Horizontal
                anchors.top: t1.bottom
                anchors.topMargin: 2
                interactive: false
            }
            Component.onDestruction: {
                console.log("ListView component is getting destroyed Row ="+index)
                md.dateModel.gc(index);
            }
        }
    }

    Component {
        id : _listViewDelegate
        Rectangle {
            id : _delegateRoot
            width: parent.width;height: 170;border.width: 0;border.color: "green"
            Component{
                id : _noDateDelegate
                ListView{
                    id : l1
                    spacing: 5
                    width: parent.width
                    height: 190
                    model : filteredModel
                    delegate: _photoDel
                    orientation: ListView.Horizontal
                    anchors.topMargin: 2
                    interactive: false
                }
            }

            Component{
                id : _dateDelegate
                Column {
                    width: parent.width ;height: parent.height + 20
                    property alias photoDate : t2.text
                    spacing: 5
                    Row {
                        width: parent.width
                        height: 20
                        spacing: 15
                        Item{
                            width: (parent.width/2)-50;height: 20;
                            Rectangle{
                                width: parent.width;height: 2;border.width:2;border.color:"blue"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                        Text {
                            id : t2
                            width: 100
                            height: 20
                            font.pixelSize: 20
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Item{
                            width: (parent.width/2)-50;height: 20;
                            Rectangle{
                                width: parent.width;height: 2;border.width:2;border.color:"blue"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                    ListView{
                        id : l1
                        spacing: 5
                        width: parent.width
                        height: 190
                        model : filteredModel
                        delegate: _photoDel
                        orientation: ListView.Horizontal
                        anchors.topMargin: 2
                        interactive: false
                    }
                }
            }
            Component.onCompleted: {
                var mydate = md.dateModel.getDateForRow(index);
                if (mydate !== "") {
                    console.log(" Row Number =" + index + " Date Index =" + mydate)
                    _delegateRoot.height +=20;
                    _dateDelegate.createObject(_delegateRoot,{photoDate:mydate})
                }else {
                    _noDateDelegate.createObject(_delegateRoot)
                }
            }
            Component.onDestruction: {
                console.log("ListView component is getting destroyed Row ="+index)
                md.dateModel.gc(index);
            }
        }
    }

    Item {
        id : r1
        anchors.fill: parent
        ListView{
            id : l1
            anchors.fill: parent
            spacing: 5
            delegate:_listViewDelegate
            model : md.dateModel
            anchors.bottom: parent.bottom
        }
        focus: true
        Keys.onEscapePressed: {
            console.log(" Print debug data")
            md.print();
        }
    }
}
