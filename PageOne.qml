import QtQuick 2.12
import QtQuick.Controls 2.12

import MyInterface 1.0

Item {
    id: root

    property Model m_model: Model {
        userName: qsTr("192.584.783.100")
    }

    Column {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 20

        TitleSeparator {
            labelTitle: qsTr("监听参数")
        }

        Flow {
            width: parent.width
            spacing: 10

            InputRow {
                id: ipInput
                title: "IP地址:"
                textValue: m_model.userName//qsTr("127.0.0.1")
            }
            InputRow {
                id: portInput
                title: "端口号:"
                textValue: qsTr("8888")
            }
            InputRow {
                id: timeOutInput
                title: "连接超时:"
                textValue: qsTr("3000")
            }
            InputRow {
                id: connectMaxInput
                title: "最大连接数:"
                textValue: qsTr("10")
            }
        }

        TitleSeparator {
            labelTitle: qsTr("帧域参数")
        }

        Flow {
            width: parent.width
            spacing: 10

            ChoseBox {
                id: choseInput

                labelTitle: qsTr("地址类型:")
                width: 210

                boxModel: ListModel {
                    ListElement { text: "单地址" }
                    ListElement { text: "通配地址" }
                    ListElement { text: "组地址" }
                    ListElement { text: "广播地址" }
                }
            }
            InputRow {
                id: srvAddrInput
                title: "终端地址:"
                textValue: qsTr("01 02 03 04 05")
            }
            InputRow {
                id: cliAddrInput
                title: "客户机地址:"
                textValue: qsTr("0")
            }
        }

        TitleSeparator {
            labelTitle: qsTr("连接参数")
        }

        Flow {
            width: parent.width
            spacing: 10

            InputRow {
                id: piidInput
                title: "服务序号优先级:"
                textValue: qsTr("0")
            }
            InputRow {
                id: protocolInput
                title: "协议版本号:"
                textValue: qsTr("1")
            }
            InputRow {
                id: protocolForwardInput
                title: "期望的协议一致性:"
                textValue: qsTr("FFFFFFFFFFFFFFFF")
            }
            InputRow {
                id: functionForwardInput
                title: "期望的功能一致性:"
                textValue: qsTr("FFFFFFFFFFFFFFFF")
            }
            InputRow {
                id: revFrameInput
                title: "发送帧最大尺寸:"
                textValue: qsTr("1024")
            }
            InputRow {
                id: sedFrameInput
                title: "发送帧最大尺寸:"
                textValue: qsTr("1024")
            }
            InputRow {
                id: revWindowInput
                title: "窗口最大尺寸:"
                textValue: qsTr("1024")
            }
            InputRow {
                id: apduMaxInput
                title: "APDU最大尺寸:"
                textValue: qsTr("1")
            }
            InputRow {
                id: connectTimeOutInput
                title: "应用连接超时时间:"
                textValue: qsTr("1024")
            }
        }

        Button {
            id: updeteBtn
            text: qsTr("更新数据")
            onClicked: {
                m_model = Controller.getModel()
            }
        }
    }
}
