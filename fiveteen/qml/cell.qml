import QtQuick 2.5

import Cells 1.0
import Controls 1.0


Cell {
    id: cell

    PropertyAnimation {
        id: moveUp
        target: cell
        properties: "y"
        to: 0
        duration: control.duration
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveLeft
        target: cell
        properties: "x"
        to: 0
        duration: control.duration
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveDown
        target: cell
        properties: "y"
        to: 0
        duration: control.duration
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveRight
        target: cell
        properties: "x"
        to: 0
        duration: control.duration
        alwaysRunToEnd: true
    }


    CellControl {
        id: control
        objectName: "control"

        onMoveUp: {
            console.log("move up");
            moveUp.to = cell.y - control.step;
            moveUp.restart();
        }

        onMoveLeft: {
            console.log("move left");
            moveLeft.to = cell.x + control.step;
            moveLeft.restart();
        }

        onMoveDown: {
            console.log("move down");
            moveDown.to = cell.y + control.step
            console.log(moveDown.to);
            moveDown.restart();
        }

        onMoveRight: {
            console.log("move right");
            moveRight.to = cell.x - control.step;
            moveRight.restart();
        }
    }
}
