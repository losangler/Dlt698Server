import QtQuick 2.12
import QtQuick.Controls 2.12
import QtCharts 2.0

import MyInterface 1.8

Item {
    id: root

    property var locale: Qt.locale()
    property var dateFormat: "yyyy-MM-dd hh:mm:ss"

    property real limit: 5
    property real offset: 0
    property real pages: ConnectController.getTerminalViewPages(limit)
    property QSqlQueryModel sqlQueryModel: ConnectController.terminalViewModel(offset, limit)

    onOffsetChanged: chartView.updateLine(spline1, sqlQueryModel)

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

                function updateLine(spline, queryModel)
                {
                    if(queryModel.rowCount() === 0)
                        return;

                    var dateStr = [];
                    var dataS = [];
                    var i = 0;
                    for(i = 0;i < queryModel.rowCount(); ++ i)
                    {
                        var parts = queryModel.data(sqlQueryModel.index(i, 7)).toString().split(".");
                        dateStr.push(parts[0]);
                        dataS.push(Number(queryModel.data(queryModel.index(i, 3))));
                    }


                    for (i = 0;i < dateStr.length; i++)
                    {
                        var dateForm = Date.fromLocaleString(locale, dateStr[i], dateFormat);
                        dateStr[i] = dateForm.getTime();
                    }

                    axisX.max = new Date(Math.max.apply(null, dateStr));
                    axisX.min = new Date(Math.min.apply(null, dateStr));
                    axisX.tickCount = dateStr.length;

                    axisY.max = Math.max.apply(null, dataS) * 1.1;
                    axisY.min = Math.min.apply(null, dataS) * 0.9;
                    axisY.tickCount = dataS.length;


                    spline.clear()
                    for (i = 0;i < dateStr.length; i++)
                    {
                        spline.append(dateStr[i], dataS[i]);
                        console.log(dataS[i]);
                    }
                }

                Component.onCompleted: {
                    updateLine(spline1, sqlQueryModel);
                }
            }

    }



}
