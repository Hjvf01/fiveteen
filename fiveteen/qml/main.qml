import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import Qt.labs.controls 1.0

import Cells 1.0
import Controls 1.0


Item {
    signal mouseClicked(int x, int y)
    signal restart()

    visible: true
    width: 480
    height: 480

    focus: true

    Rectangle {
        id: board
        objectName: "board"
        color: "black"
        width: 480
        height: 480

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                mouseClicked(mouse.x, mouse.y);
            }
        }
    }

    Keys.onReleased: {
        console.log("restart");
        restart();
    }

    PropertyAnimation {
        id: scaleWidth
        target: board
        properties: "width"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: scaleHeight
        target: board
        properties: "height"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    BoardControl {
        id: boardControl
        objectName: "boardControl"

        onScale: {
            scaleHeight.to = boardControl.size;
            scaleWidth.to = boardControl.size;

            scaleHeight.restart();
            scaleWidth.restart();
        }
    }

    Popup {
        id: popup
        x: 0
        y: 0
        width: boardControl.size
        height: boardControl.size
        modal: true
        focus: true
        closePolicy: Popup.OnEscape

        TextArea {
            id: gameOver
            anchors.fill: parent
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
        }
        Button {
            id: restartButton
            text: "Restart"
            onClicked: {
                restart();
                popup.close();
            }
        }
    }

    GameControl {
        id: gameControl
        objectName: "game_control"

        onFinish: {
            gameControl.turn = amount;
            popup.width = boardControl.size;
            popup.height = boardControl.size;
            gameOver.text = "Game Over!!!(" + gameControl.turn + " turns)";
            gameOver.font.pointSize = boardControl.size / 20
            popup.open();
        }
    }
}
