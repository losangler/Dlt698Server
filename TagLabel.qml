import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    property var title: qsTr("title")
    property real titleSize: 15

    height: parent.height
    width: taglabel.width

    Label {
        id: taglabel
        width: Text.width
        height: parent.height
        text: title
        font.pixelSize: titleSize
        verticalAlignment: Text.AlignVCenter
    }

}
