import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root

    property var treeModel

    TreeView {
        anchors.fill: parent

        TableViewColumn {
            title: "对象表"
            role: "name"
            width: 200
        }
//        TableViewColumn {
//            title: "Simplify"
//            role: "simplify"
//            width: 100
//        }
        model: treeModel
        itemDelegate: Item {
            Text {
                anchors.verticalCenter: parent.verticalCenter
                elide: styleData.elideMode
                text: styleData.value
            }

        }
    }
}
