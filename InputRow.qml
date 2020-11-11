import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var title: qsTr("Title")
    property var desc: qsTr("Enter description")
    property var textValue: qsTr("")

    height: 50
    width: label.width + control.width + 10

    Row {
        id: row
        spacing: 10

        Label {
            id: label
            text: title
            width: Text.width + 10
            height: 40
            font.pixelSize: 18

            verticalAlignment: Text.AlignVCenter
            leftPadding: 5
        }
        TextField {
            id: control
            width: 150
            height: 50

            placeholderText: desc

            leftPadding: 5
            rightPadding: 5

            text: textValue
        }
    }
}
