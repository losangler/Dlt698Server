import QtQuick 2.12
import QtQuick.Controls 1.4

Item {
    id: root

    property var dataArray: [
        ["银行卡号","开户行","卡种类型","归属地","止付开始时间","止付结束时间","状态"],
        [150,150,150,150,170,170,100],
        ["name","author","type","location","opeStartDate","opeEndDate","cardStatus"]
    ]
    property var infoModel: ListModel {
        ListElement { name: "Blue"; author: "jie" }
        ListElement { name: "Red"; author: "july" }
        ListElement { name: "White"; author: "lucy" }
        ListElement { name: "Blue"; author: "cat" }
        ListElement { name: "Red"; author: "tom" }
        ListElement { name: "White"; author: "jack"}
    }

    TableView {
        id: tableview
        anchors.fill: parent
        model: infoModel
        itemDelegate: Item {
            Text {
                anchors.verticalCenter: parent.verticalCenter
                elide: styleData.elideMode
                text: styleData.value
                font.pixelSize: 18
                leftPadding: 5
            }

        }

        Component.onCompleted: {
            root.updateColumn2Table(dataArray)
        }
    }


    function updateColumn2Table(arrayData){
        if(arrayData.length !== 3){
            console.log("DataShowTable.qml updateColumn2Table arrayData.length !=3");
            return;
        }

        var arrayTitle = arrayData[0]; //标题数组
        var arrayWidth = arrayData[1]; //宽度数组
        var arrayRoles = arrayData[2]; //role数组
        if(arrayTitle.length !== arrayWidth.length || arrayTitle.length > arrayRoles.length){
            console.log("arrayTitle argument error in DataShowTable.qml updateColumn2Table(arrayTitle,arrayWidth,arrayRoles)");
            return;
        }

        //tableview.model.clear(); //先将model里面的数据清空避免在更新的列里面有相同的role直接显示
        var i,str,count = tableview.columnCount;
        var sum = new Number(0);
        //求出长度累加和以便于按比例分配列宽
        for(i =0;i<arrayWidth.length;i++){
            sum += arrayWidth[i];
        }
        var prefix = 'import QtQuick 2.7;import QtQuick.Controls 1.4;TableViewColumn {width: Math.round(tableview.width *'; //创建TableViewColumn的代码
        //前缀
        //将现在的每列全部删除
        for(i=0;i<count;i++){
            tableview.removeColumn(0);
        }
        //循环添加TableViewColumn
        for(i=0;i<arrayTitle.length;i++){
            str = prefix + arrayWidth[i]/sum +");role:\"" + arrayRoles[i] + "\";title:\"" + arrayTitle[i] + "\"}";
            tableview.addColumn(Qt.createQmlObject(str,tableview,"dynamicSnippet1"));
        }
    }
}
