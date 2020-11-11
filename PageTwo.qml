import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    Column {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 20

        TitleSeparator {
            labelTitle: qsTr("属性操作")
        }

        Flow {
            width: parent.width
            spacing: 10

            ObjectMenu {
                width: 100
                height: 40
            }

            ChoseBox {
                id: choseInput

                labelTitle: qsTr("操作类型:")
                width: 310

                boxModel: ListModel {
                    ListElement { text: "GetRequestNormal" }
                    ListElement { text: "GetRequestNormalList" }
                    ListElement { text: "GetRequestRecord" }
                    ListElement { text: "GetRequestRecordList" }
                    ListElement { text: "GetRequestNext" }
                }
            }

            Button {
                id: readButton
                text: qsTr("开始读取")

            }
        }

        TitleSeparator {
            labelTitle: qsTr("发送数据")
        }

        Flow {
            width: parent.width
            spacing: 10

            InfoTable {
                width: parent.width
                height: 180
                dataArray: [
                    ["对象名称","属性标识", "属性索引", "接受数据", "状态"],
                    [150, 150, 150, 150, 100],
                    ["name", "author", "index", "data", "status"]
                ]
            }
        }

        TitleSeparator {
            labelTitle: qsTr("接受数据")
        }

        Flow {
            width: parent.width
            spacing: 10

            InfoTable {
                width: parent.width
                height: 180
            }
        }
    }
}
