import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var sqlModel;
    property var dataArray;

    Column {
        id: myTable
        anchors.fill: parent

        Row {
            id: columnsHeader

            anchors.horizontalCenter: parent.horizontalCenter
            height: tableView.rowHeightProvider(0)

            Repeater {
                model: tableView.columns > 0 ?  tableView.columns : 1
                Rectangle {
                    implicitWidth:  tableView.columnWidthProvider(index) + tableView.columnSpacing
                    implicitHeight: tableView.rowHeightProvider(index)
                    Text {
                        id: column_text
                        anchors.centerIn: parent
                        text: sqlModel.headerData(modelData, Qt.Horizontal)
                    }
                }
            }
        }

        TableView {
            id: tableView
            anchors.horizontalCenter: parent.horizontalCenter
            width: columnsHeader.width
            height: parent.height

            columnSpacing: 1
            rowSpacing: 1
            clip: true

            model: sqlModel

            delegate: Rectangle {

                Rectangle { anchors.left: parent.left; height: parent.height; width: 1; color: "#dddddd"}
                Rectangle { anchors.top: parent.top; width: parent.width; height: 1; color: "#dddddd"}
                Rectangle { anchors.right: parent.right; height: parent.height; width: 1; color: "#dddddd"; visible: model.column === tableView.columns -1 }
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: "#dddddd"; visible: model.row === tableView.rows - 1 }


                Text {
                    id: item_text
                    anchors.centerIn: parent
                    text: display
                }
            }

            rowHeightProvider: function(row) {return 30;}
            columnWidthProvider: function(column) {
                return Math.max(1, dataArray[column])
            }

        }
    }
}
