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
            color: "white"
            opacity: 1
        }

        Column {

            anchors.fill: parent

            TitleSeparator {
                id: titleS
                height: 50
                width: parent.width
                labelTitle: qsTr("在线终端")
            }

            InfoList {
                width: parent.width - 10
                height: 200
                x: parent.x + 5
            }

            TitleSeparator {
                height: 50
                width: parent.width
                labelTitle: qsTr("接收数据")
            }

            InfoList {
                width: parent.width - 10
                height: 200
                x: parent.x + 5
            }
        }
    }

    function open() {
        drawer.open()
    }
}
