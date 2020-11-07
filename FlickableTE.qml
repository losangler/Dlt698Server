import QtQuick 2.5

Item {
    id: root
    width: 200
    height: 200

    Rectangle {
        anchors.fill: parent
        color: "lightblue"
    }

    Flickable {
        id: flick

        anchors.fill: parent
        contentWidth: edit.paintedWidth
        contentHeight: edit.paintedHeight
        clip: true

        function ensureVisible(r)
        {
            if(contentX >= r.x)
                contentX = r.x;
            else if(contentX + width <= r.x + r.width)
                contentX = r.x + r.width - width;

            if(contentY >= r.y)
                contentY = r.y;
            else if(contentY + height <= r.y + r.height)
                contentY = r.y + r.height - height;
        }

        TextEdit {
            id: edit
            width: flick.width
            height: flick.height
            font.pointSize: 15
            wrapMode: TextEdit.Wrap
            focus: true
            onCursorRectangleChanged:
                flick.ensureVisible(cursorRectangle)
        }
    }

    Rectangle {
        id: scrollbar
        anchors.right: flick.right
        y: flick.visibleArea.yPosition * flick.height
        width: 10
        height: flick.visibleArea.heightRatio * flick.height
        color: "lightgrey"
    }
}
