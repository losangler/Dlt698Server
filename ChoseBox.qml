import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    property var labelTitle: qsTr("Title")
    property int modifier: 0
    property var boxModel: [
        { value: Qt.NoModifier, text: qsTr("No modifier") },
        { value: Qt.ShiftModifier, text: qsTr("Shift") },
        { value: Qt.ControlModifier, text: qsTr("Control") }
    ]

    width: 200
    height: 50

    Row {
        id: row
        spacing: 10
        anchors.fill: parent

        Label {
            id: label
            text: labelTitle
            width: Text.width
            height: 40
            font.pixelSize: 18

            verticalAlignment: Text.AlignVCenter
            leftPadding: 5
        }

        ComboBox {
            id: box

            textRole: "text"
            width: parent.width - label.width - 10
            height: parent.height

            onActivated: modifier = currentIndex
            Component.onCompleted: currentIndex = modifier

            model: boxModel
        }
    }


}
