import QtQuick 2.5

Item {
    id: root
    property alias textFont: text1.font
    signal clicked(string buttonColor)

    Text {
        id: text1
        textFormat: Text.StyledText
        text: "<h6>Hello</h6> <i>World!</i>"
        font.bold: true
        font { pointSize: 14; capitalization: Font.AllUppercase }

        Behavior on rotation {
            NumberAnimation {
                id: animation
                duration: 500
            }
        }

    }

    Rectangle {
        id: colorRect
        width: 40
        height: width
        radius: 20
        border.color: "black"
        border.width: 5

        anchors.left: text1.right
        anchors.leftMargin: 10
        anchors.verticalCenter: text1.baseline

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.debug("colorRect:", parent.border.color)
                if(text1.rotation % 360 == 0)
                {
                    text1.rotation += 360
                }

                text1.color = parent.border.color

                root.clicked(parent.border.color)
            }

            hoverEnabled: true
            onEntered: {
                parent.border.color = "green"
            }
            onExited: {
                parent.border.color = "black"
            }
        }

        Rectangle {
            width: 24
            height: width
            //radius: 12
            color: parent.border.color
            anchors.centerIn: parent
        }
    }

    Image {
        id: backImag
        source: "images/small.png"
        width: parent.width
        anchors.bottom: parent.bottom
        fillMode: Image.PreserveAspectCrop
    }

    function changeDuration(duration) {
        animation.duration = duration
    }
}
