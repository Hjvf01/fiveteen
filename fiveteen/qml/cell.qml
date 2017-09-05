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
            moveUp.to = cell.y - control.step;
            moveUp.restart();
        }

        onMoveLeft: {
            moveLeft.to = cell.x + control.step;
            moveLeft.restart();
        }

        onMoveDown: {
            moveDown.to = cell.y + control.step
            moveDown.restart();
        }

        onMoveRight: {
            moveRight.to = cell.x - control.step;
            moveRight.restart();
        }
    }
}
