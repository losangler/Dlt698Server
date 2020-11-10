import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var labelTitle: qsTr("Title")

    Column {
        id: column

        anchors.fill: parent

        Label {
            id: title
            width: parent.width
            height: 40

            text: labelTitle
            font.pixelSize: 20

            verticalAlignment: Text.AlignVCenter
            leftPadding: 5
        }
        Rectangle {
            id: separator
            width: parent.width - 10
            height: 3
            color: "black"
            x: parent.x + 5
        }
    }
}
