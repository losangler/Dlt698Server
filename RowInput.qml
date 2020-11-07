import QtQuick 2.5

Item {
    id: root
    width: 200
    height: 50

    Row {
        spacing: 10
        anchors.centerIn: parent

        Text {
            id: text0
            text: qsTr("请输入密码：")
            font.pointSize: 15
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            width: input.contentWidth < 100 ? 100 : input.contentWidth + 10
            height: input.contentHeight + 5
            color: "lightgrey"
            border.color: "grey"
            anchors.verticalCenter: text0.verticalCenter

            TextInput {
                id: input
                anchors.fill: parent
                anchors.margins: 2
                font.pointSize: 15
                focus: true

                echoMode: TextInput.PasswordEchoOnEdit

                validator: IntValidator{
                    bottom: 0
                    top: 100
                }

                onEditingFinished: {
                    input.focus = false
                    text1.text = text
                }
            }
        }

        Text {
            id: text1
            text: qsTr("nothing")
        }
    }
}
