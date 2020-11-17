import QtQuick 2.12
import QtQuick.Controls 2.12

import MyInterface 1.3

Item {
    id: root
    property ServerModel m_server: ConnectController.serverModel()

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
                textValue: m_server.ip
                onTextValueChanged: m_server.ip = textValue
            }
            InputRow {
                id: portInput
                title: "端口号:"
                textValue: m_server.port
                Binding {
                    target: m_server
                    property: "port"
                    value: portInput.textValue
                }
            }
            InputRow {
                id: timeOutInput
                title: "连接超时:"
                textValue: m_server.timeOut
                Binding {
                    target: m_server
                    property: "timeOut"
                    value: timeOutInput.textValue
                }
            }
            InputRow {
                id: connectMaxInput
                title: "最大连接数:"
                textValue: m_server.connectMax
                Binding {
                    target: m_server
                    property: "connectMax"
                    value: connectMaxInput.textValue
                }
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
                ConnectController.serverUpdate()
                ConnectController.saveConfig()
            }
        }
    }
}
