import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

ApplicationWindow {
    id: window

    visible: true
    width: 1024
    height: 768
    title: qsTr("Hello World")

    InfoDrawer {
        id: infoDrawer
    }

    menuBar: MenuBar {

        Menu {
            title: qsTr("File")

            Action {
                text: qsTr("New...")
            }

            Action {
                text: qsTr("Open...")
            }

            Action {
                text: qsTr("Save")
            }
            MenuSeparator {}
            Action {
                text: qsTr("Quit")
                onTriggered: {
                    window.close()
                }
            }
        }
        Menu {
            title: qsTr("Edit")
            Action {
                text: qsTr("Cut")
            }
            Action {
                text: qsTr("Copy")
            }
            Action {
                text: qsTr("Paste")
            }
        }
        Menu {
            title: qsTr("Help")
            Action {
                text: qsTr("About")
            }
        }
    }

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("<")
                enabled: view.currentIndex > 0
                onClicked: view.currentIndex --
            }
            ToolButton {
                text: qsTr(">")
                enabled: view.currentIndex < view.count - 1
                onClicked: view.currentIndex ++
            }
            Label {
                text: "当前连接：" + "无"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: infoDrawer.open()
            }
        }
    }

    footer: TabBar {
        id: bar
        width: parent.width
        currentIndex: view.currentIndex

        Repeater {
            model: ["连接",  "读取",  "设置",  "行为",  "代理"]

            TabButton {
                text: modelData
                width: Math.max(100, bar.width / 5)

                onClicked: {
                    view.currentIndex = bar.currentIndex
                }
            }
        }
    }

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Page{
            PageOne {
                anchors.fill: parent
            }
        }

        Page{
            PageTwo {
                anchors.fill: parent
            }
        }

        Page{
            Text {

                text:"第三页"
            }
            ListView {
                width: 100; height: 100
                anchors.centerIn: parent
                model: myModel
                delegate: Rectangle {
                    height: 25
                    width: 100
                    Text { text: "Animal: " + type + ", " + size }
                }
            }
        }

        Page{
            Text {
                text:"第四页"
            }

        }

        Page{
            Text {
                text:"第五页"
            }
            Button {
                anchors.centerIn: parent

                text: "Open"

                onClicked: popup.open()
            }

            Popup {
                id: popup
                anchors.centerIn: parent
                width: 300
                height: 400
                modal: true
                focus: true
                closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

                ObjectTree {
                    treeModel: myTree

                    anchors.fill: parent
                }
            }
        }
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Component {
        id: mainView

        Column {
            anchors.centerIn: parent

            spacing: 10

            Label {
                id: label
                text: ""
            }

            Button {
                id: getBtn
                text: "获取"
                width: 120
                height: 40

                onClicked: {
                    label.text = myModel.getValue()
                }
            }
        }
    }
}
