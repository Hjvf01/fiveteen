import QtQuick 2.5
import Cells 1.0

Item {
    visible: true
    width: 640
    height: 480

    Rectangle {
        color: "grey"
        width: 480
        height: 480
        x: 0
        y: 0
    }

    Cell {
        x: 0
        y: 0
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(
                qsTr('Clicked on background.')
            )
        }
    }

}
