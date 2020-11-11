import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var labelTitle: qsTr("Title")

    width: parent.width
    height: 50

    Column {
        id: column

        anchors.fill: parent

        Label {
            id: title
            width: parent.width
            height: 40

            text: labelTitle
            font.italic: true
            font.pixelSize: 25

            verticalAlignment: Text.AlignVCenter
        }
        Rectangle {
            id: separator
            width: parent.width
            height: 3
            color: "darkcyan"
        }
    }
}
