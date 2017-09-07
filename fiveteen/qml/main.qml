import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import Qt.labs.controls 1.0

import Cells 1.0
import Controls 1.0


Item {
    signal mouseClicked(int x, int y)
    signal restart()

    id: mainWindow
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

        onScaleWidth: {
            scaleWidth.to = boardControl.width;
            scaleWidth.restart();
        }

        onScaleHeight: {
            scaleHeight.to = boardControl.height;
            scaleHeight.restart();
        }
    }

    Popup {
        id: popup
        x: 0
        y: 0
        width: boardControl.width
        height: boardControl.height
        modal: true
        focus: true
        closePolicy: Popup.OnEscape
        /*
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
        }*/
    }

    GameControl {
        id: gameControl
        objectName: "game_control"

        onFinish: {
            gameControl.turn = amount;
            popup.width = boardControl.width;
            popup.height = boardControl.height;
            gameOver.text = "Game Over!!!(" + gameControl.turn + " turns)";

            if(boardControl.height < boardControl.width)
                gameOver.font.pointSize = boardControl.height / 20;
            else
                gameOver.font.pointSize = boardControl.width / 20;

            popup.open();
        }
    }
}
