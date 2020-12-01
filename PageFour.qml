import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtPositioning 5.12
import QtQuick.Controls 2.12

Item {
    id: root

    width: 512
    height: 512
    visible: true

    Plugin {
        id: mapPlugin
        name: "mapboxgl" // "mapboxgl", "esri", ...
    }



    Map {
        id: item_map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(30.67, 104.07)
        zoomLevel: 14
        bearing: bearing_slider.value

        MapQuickItem {
            id: point1
            zoomLevel: 0
            coordinate: QtPositioning.coordinate(30.67, 104.07)
            anchorPoint: Qt.point(sourceItem.width / 2, sourceItem.height)
            sourceItem: Image {
                    id: addressImage
                    width: 35
                    height: 35
                    source: "qrc:/images/Address.png"
                }
        }
    }

    Column {
        id: item_ui
        spacing: 20
        anchors.fill: parent
        anchors.margins: 20

        Slider {
            id: bearing_slider
            height: 20
            width: parent.width
            from: 0
            to: 360
            value: 0

        }

        Rectangle {
            height: item_center.height + 20
            width: item_center.width + 20
            color: "green"

            Text {
                id: item_center
                anchors.centerIn: parent
                text: "zoom level:"+Math.floor(item_map.zoomLevel)+
                      " center:"+item_map.center.latitude+
                      "  "+item_map.center.longitude
            }
        }

    }
}
