import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var infoModel: ListModel {
        ListElement { name: "Blue" }
        ListElement { name: "Red" }
        ListElement { name: "White" }
        ListElement { name: "Blue" }
        ListElement { name: "Red" }
        ListElement { name: "White" }
    }

    property var infoDelegate: Component {
        Rectangle {
            width: parent.width
            height: 30

            color: ListView.isCurrentItem ? "lightyellow" : "lightgrey"

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: name
                font.pixelSize: 17
                padding: 10
            }

            MouseArea {
                anchors.fill: parent
                onClicked: listView.currentIndex = index
            }
        }
    }

    property var headDelegate: Component {
        Item {
            width: parent.width
            height: 40

            Rectangle {
                color: "lightblue"
                anchors.fill: parent
            }

            Text {
                text: qsTr("在线终端")
                anchors.centerIn: parent
            }
        }
    }

    property var footDelegate: Component {
        Item {
            width: parent.width
            height: 35

            Rectangle {
                color: "lightsteelblue"
                anchors.fill: parent
            }
        }
    }

    ListView {
        id: listView

        anchors.fill: parent

        focus: true
        spacing: 5
        clip: true

        model: infoModel
        delegate: infoDelegate
//        header: headDelegate
        footer: footDelegate

        ScrollBar.vertical: ScrollBar {
            id: hbar;
            hoverEnabled: true
            active: hovered || pressed
            size: 10
            anchors.right: parent.right

            onActiveChanged: {
                active = true
            }
        }
    }
}
