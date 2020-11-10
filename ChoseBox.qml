import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root
    property int modifier: 0
    property var boxModel: [
        { value: Qt.NoModifier, text: qsTr("No modifier") },
        { value: Qt.ShiftModifier, text: qsTr("Shift") },
        { value: Qt.ControlModifier, text: qsTr("Control") }
    ]

    ComboBox {
        textRole: "text"
        width: 200

        onActivated: modifier = currentIndex
        Component.onCompleted: currentIndex = modifier

        model: boxModel
    }
}
