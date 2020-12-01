import QtQuick 2.0
import QtWebEngine 1.2

Item {
    id: root

    visible: true
    width: 640
    height: 480

    WebEngineView {
        id: onlineMap
        visible: true
        backgroundColor: "transparent"
        anchors.fill: parent
        width: parent.width
        height: parent.height
        settings.javascriptEnabled : true
        settings.pluginsEnabled:true
        url:"qrc:/taskMap.html"  //加载地图的html文件
        Component.onCompleted: {
            console.log("map.url: "+url)
        }
    }
}
