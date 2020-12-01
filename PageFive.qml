import QtQuick 2.12
import QtQuick.Controls 2.12

import MyInterface 1.5

Item {
    id: root

    property QSqlQueryModel sqlModel: ConnectController.sqlModel()
    property var dataArray: [100, 100, 100, 100, 100 ,100, 100, 200]

    Column{
        anchors.fill: parent

        Row {
            id: columnsHeader

            width: parent.width
            y: tableView.contentY
            z: 2

            Repeater {
                model: tableView.columns > 0 ?  tableView.columns : 1
                Rectangle {
                    implicitWidth:  tableView.columnWidthProvider(index) + tableView.columnSpacing
                    implicitHeight: column_text.height + 20
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
            width: 1000
            height: 500

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

            rowHeightProvider: function(row) {return 50;}
            columnWidthProvider: function(column) {
                return Math.max(1, dataArray[column])
            }

        }

    }



}
