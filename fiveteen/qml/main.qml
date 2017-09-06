import QtQuick 2.5
import QtQuick.Window 2.0
import Qt.labs.controls 1.0

import Cells 1.0
import Controls 1.0

Item {
    signal mouseClicked(int x, int y)

    visible: true
    width: 480
    height: 480

    Rectangle {
        color: "black"
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent
            onClicked: mouseClicked(mouse.x, mouse.y)
        }
    }

    Popup {
        id: popup
         x: 100
         y: 100
         width: 200
         height: 300
         modal: true
         focus: true
         TextArea {
             anchors.fill: parent
             text: "Game Over"
             font.pointSize: 20
             verticalAlignment: Text.AlignVCenter
         }

         closePolicy: Popup.OnEscape
    }

    GameControl {
        id: gameControl
        objectName: "game_control"

        onFinish: {
            console.log(amount);
            popup.open();
        }
    }
}
