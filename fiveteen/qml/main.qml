import QtQuick 2.5
import Cells 1.0

Item {
    signal mouseClicked(int x, int y)

    visible: true
    width: 640
    height: 480

    Rectangle {
        color: "black"
        width: 480
        height: 480
        x: 0
        y: 0

        MouseArea {
            anchors.fill: parent
            onClicked: {
                mouseClicked(mouse.x, mouse.y);
            }
        }
    }
}
