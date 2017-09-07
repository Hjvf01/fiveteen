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

    Keys.onReleased: {
        if(event.key == Qt.Key_Space) {
            startGame.open();
        }
    }

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

    PropertyAnimation {
        id: scaleWidth
        properties: "width"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: scaleHeight
        properties: "height"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    BoardControl {
        id: boardControl
        objectName: "boardControl"

        onScaleWidth: {
            scaleWidth.target = board;
            scaleWidth.to = boardControl.width;
            scaleWidth.restart();

            scaleWidth.target = endGame;
            scaleWidth.restart();

            scaleWidth.target = startGame;
            scaleWidth.restart();
        }

        onScaleHeight: {
            scaleHeight.target = board;
            scaleHeight.to = boardControl.height;
            scaleHeight.restart();

            scaleHeight.target = endGame;
            scaleHeight.restart();

            scaleHeight.target = startGame;
            scaleHeight.restart();
        }
    }

    Popup {
        id: startGame
        x: 0
        y: 0
        width: 480
        height: 480
        modal: true
        opacity: 0.9
        closePolicy: Popup.NoAutoClose

        ColumnLayout {
            anchors.fill: parent

            Button {
                id: gameButton
                Layout.alignment: Qt.AlignCenter
                text: "Start"
                Layout.preferredHeight: 40
                Layout.preferredWidth: 300
                onClicked: {
                    gameButton.text = "Continue..."
                    startGame.close();
                }
            }
            Button {
                id: shuffleButton
                Layout.alignment: Qt.AlignCenter
                text: "Shuffle"
                Layout.preferredHeight: 40
                Layout.preferredWidth: 300
                onClicked: {
                    gameButton.text = "Start";
                    restart();
                }
            }
            Button {
                id: exitButton
                Layout.alignment: Qt.AlignCenter
                text: "Exit"
                Layout.preferredHeight: 40
                Layout.preferredWidth: 300
                onClicked: {
                    Qt.quit();
                }
            }
            TextArea {
                Layout.alignment: Qt.AlignCenter
                text: 'Press "space" for pause.'
                font.pointSize: 10
            }
        }
    }

    Popup {
        id: endGame
        x: 0
        y: 0
        modal: true
        opacity: 0.9
        closePolicy: Popup.NoAutoClose

        ColumnLayout {
            anchors.fill: parent

            TextArea {
                Layout.alignment: Qt.AlignCenter
                id: gameOver
                verticalAlignment: Text.AlignVCenter
            }
            Button {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredHeight: 40
                Layout.preferredWidth: 300

                id: restartButton
                text: "Restart"
                onClicked: {
                    restart();
                    endGame.close();
                }
            }
            Button {
                Layout.alignment: Qt.AlignCenter
                Layout.preferredHeight: 40
                Layout.preferredWidth: 300

                text: "Exit"
                onClicked: {
                    Qt.quit();
                }
            }
        }
    }

    GameControl {
        id: gameControl
        objectName: "game_control"

        onFinish: {
            gameControl.turn = amount;
            endGame.width = boardControl.width;
            endGame.height = boardControl.height;
            gameOver.text = "Game Over!!!(" + amount + " turns)";

            if(boardControl.height < boardControl.width)
                gameOver.font.pointSize = boardControl.height / 20;
            else
                gameOver.font.pointSize = boardControl.width / 20;

            endGame.open();
        }

        onStart: {
            startGame.open();
        }
    }
}
