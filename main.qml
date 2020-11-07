import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import "scripts/myscript.js" as Script

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    MainForm {
//        anchors.fill: parent

//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }

    Grid {
        id: column1

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        columns: 2
        spacing: 5

        Rectangle {
            color: "lightblue"
            radius: 10.0
            width: 50
            height: 50

            Text {
                anchors.centerIn: parent
                text: parent.Positioner.index
            }
        }

        Rectangle {
            color: "gold"
            radius: 10.0
            width: 50
            height: 50

            Text {
                anchors.centerIn: parent
                text: parent.Positioner.index
            }
        }


        Rectangle {
            color: "lightblue"
            radius: 10.0
            width: 50
            height: 50
        }

        Rectangle {
            color: "gold"
            radius: 10.0
            width: 50
            height: 50
        }


    }

    ColorText {
        id: colorText1

        height: 30
        z: 20

        anchors.left: column1.left
        anchors.bottom: column1.top

        textFont {
            underline: true
            italic: true
            letterSpacing: 3
            wordSpacing: 6
            weight: Font.ExtraBold
            pointSize: 20
        }

        onClicked: {
            console.log("colorButton: ", buttonColor)
        }

        Component.onCompleted: {
            changeDuration(2000)
            console.log("change duration")
            Script.calculateWidth(parent)
        }
    }

    RowInput {
        anchors.bottom: colorText1.bottom
        anchors.left: colorText1.left
        anchors.margins: 10
    }

    FlickableTE {

    }

    Item {
        id: group1

        x: 10; y: 10

        Text { z: 10; text: qsTr("group1")}

        Image {
            z: 1
            source: "images/系统管理.png"
            width: 150; height: width
        }

        Image {
            source: "images/菜单管理.png"
            x: 50; y: 50;width: 150; height: width
        }
    }

    Item {
        id: group2

        x: 400; y: 10

        Text { z: 10; text: qsTr("group2")}

        Image {
            opacity: 0.7
            source: "images/系统管理.png"
            width: 150; height: width
        }

        Image {
            source: "images/菜单管理.png"
            x: 50; y: 50;width: 150; height: width
            rotation: 30
        }
    }

    Item {
        id: group3

        x: 10; y: 250

        Text { z: 10; text: qsTr("group3")}

        Image {
            source: "images/系统管理.png"
            width: 150; height: width
        }

        Image {
            source: "images/菜单管理.png"
            x: 50; y: 50;width: 150; height: width
            opacity: 0.7
            scale: -1.3
        }
    }

    Item {
        id: group4

        x: 400; y: 250

        Text { z: 10; text: qsTr("group4")}

        Image {
            opacity: 0.7
            source: "images/系统管理.png"
            width: 150; height: width
            Image {

                source: "images/菜单管理.png"
                x: 50; y: 50;width: 150; height: width
            }
        }
    }
}
