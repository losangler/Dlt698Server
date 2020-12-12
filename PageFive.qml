import QtQuick 2.12
import QtQuick.Controls 2.12
import QtCharts 2.0

import MyInterface 1.9

Item {
    id: root

    property var locale: Qt.locale()
    property string dateFormat: "yyyy-MM-dd hh:mm:ss"

    property real limit: 5
    property real offset: 0
    property real pages: ConnectController.getTerminalViewPages(limit)
    property QSqlQueryModel sqlQueryModel: ConnectController.terminalViewModel(offset, limit)

    onOffsetChanged: chartView.updateLine(spline1, ConnectController.getTimeAndCurrent())

    Column{
        anchors.fill: parent
        anchors.margins: 20

        TitleSeparator {
            labelTitle: "电流信息表"
        }

        SqlTable {
            id: myTable
            width: parent.width
            height: parent.height / 2 - 50
            sqlModel: sqlQueryModel
            dataArray: [100, 100, 100, 100, 100 ,100, 100, 200]
        }

        Item {
            width: parent.width
            height: 40

            Button {
                id: leftBtn
                text: qsTr("上一页")
                height: parent.height
                anchors.right: nowOffset.left

                onClicked: {
                    if(offset > 0)
                    {
                        sqlQueryModel = ConnectController.terminalViewModel(offset - 1, limit);
                        -- offset;
                    }
                }
            }

            TagLabel {
                id: nowOffset
                anchors.right: nowCenter.left
                title: offset
            }

            TagLabel {
                id: nowCenter
                anchors.centerIn: parent
                title: qsTr("/")
            }

            TagLabel {
                id: nowPages
                anchors.left: nowCenter.right
                title: pages
            }

            Button {
                id: rightBtn
                text: qsTr("下一页")
                height: parent.height
                anchors.left: nowPages.right

                onClicked: {
                    if(offset < pages)
                    {
                        sqlQueryModel = ConnectController.terminalViewModel(offset + 1, limit);
                        ++ offset;
                    }
                }
            }
        }

        TitleSeparator {
            labelTitle: "电流变化图"
        }

        ChartView {
                id:chartView
                title: "Spline"
                width: parent.width
                height: parent.height / 2 - 50
                theme: ChartView.ChartThemeBlueNcs
                antialiasing: true

                DateTimeAxis {
                    id: axisX
                    min : Date.fromLocaleString(Qt.locale(), "2018-05-09 12:00:00", dateFormat)
                    max : Date.fromLocaleString(Qt.locale(), "2018-05-09 20:00:00", dateFormat)
                    format: dateFormat //设置显示样式
                }

                ValueAxis {
                    id: axisY
                    min: -1.5
                    max: 2.5
                }
                SplineSeries {
                         id:spline1;
                         name: "SplineSeries"
                         axisX: axisX
                         axisY: axisY
                         color:"green"
                         width:2
                         capStyle:"RoundCap";
                         style :"DashLine"
                         XYPoint { x: 0; y: 0.19 }
                         XYPoint { x: 2; y: 2.0 }
                         XYPoint { x: 4; y: 0.8 }
                         XYPoint { x: 8; y: 1.5 }
                         XYPoint { x: 9; y: 0.5 }
                         XYPoint { x: 10; y: 2.3 }
                }

                Component.onCompleted: {
                    updateLine(spline1, ConnectController.getTimeAndCurrent())
                }

                function updateLine(spline, dataObject)
                {
                    if(dataObject.length === 0)
                        return;

                    var dateStr = [];
                    var dataS = [];
                    for(var prop in dataObject) {
                        var dateForm = Date.fromLocaleString(locale, prop.split(".")[0], dateFormat);
                        dateStr.push(dateForm.getTime());
                        dataS.push(dataObject[prop]);

                    }
                    axisX.max = new Date(Math.max.apply(null, dateStr));
                    axisX.min = new Date(Math.min.apply(null, dateStr));
                    axisX.tickCount = dateStr.length;

                    axisY.max = Math.max.apply(null, dataS) * 1.1;
                    axisY.min = Math.min.apply(null, dataS) * 0.9;
                    axisY.tickCount = dataS.length;

                    spline.clear()
                    for (var i = 0;i < dateStr.length; i++)
                    {
                        spline.append(dateStr[i], dataS[i])
                    }
                }
            }

    }



}
