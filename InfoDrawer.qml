import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    Drawer {
        id: drawer
        width: parent.width * 0.5
        height: parent.height
        modal: true
        clip: true
        //抽屉起始方向
        edge: Qt.LeftEdge
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        background: Rectangle{
            anchors.fill: parent
            color: "aliceblue"
            opacity: 1
        }

        Column {

            anchors.fill: parent
            anchors.margins: 8

            spacing: 10

            TitleSeparator {
                labelTitle: qsTr("在线终端")
            }

            InfoList {
                width: parent.width
                height: parent.height / 4
            }

            TitleSeparator {
                labelTitle: qsTr("接收数据")
            }

            InfoList {
                width: parent.width
                height: parent.height / 4
            }
        }
    }

    function open() {
        drawer.open()
    }
}
