import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var title: qsTr("Title")
    property var desc: qsTr("Enter description")

    Row {
        id: row
        spacing: 10

        Label {
            id: label
            text: title
            width: 64
            height: 40
            font.pixelSize: 20

            verticalAlignment: Text.AlignVCenter
            leftPadding: 5
        }
        TextField {
            id: control
            width: 200
            height: 50

            placeholderText: desc

            leftPadding: 5
            rightPadding: 5
        }
    }
}
