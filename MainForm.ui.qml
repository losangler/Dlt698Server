import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 1
        anchors.topMargin: 0
        anchors.fill: parent

        ChoseBox {
            id: choseBox1
            x: 173
            y: 137
        }
    }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
        anchors.verticalCenterOffset: -91
        anchors.horizontalCenterOffset: 0
    }
}
