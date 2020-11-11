import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: root

    width: 100
    height: 40

    MenuBar {
        Menu {
            anchors.centerIn: parent
            title: "添加对象"
            Menu {
                title: "电能量类对象"
                Menu {
                    title: "组合有功电能"
                    Menu {
                        title: "属性"
                        Action {text: "逻辑名"}
                        Action {text: "换算及单位"}
                    }
                    Menu {
                        title: "方法"
                        Action {text: "复位"}
                        Action {text: "执行"}
                    }
                }
            }
            Menu {
                title: "最大需量类对象"
                Action {text: "next"}
                Action {text: "prev"}
                Action {text: "replace"}
            }
            Menu {
                title: "变量类对象"
                Action {text: "next"}
                Action {text: "prev"}
                Action {text: "replace"}
            }
        }
    }
}
