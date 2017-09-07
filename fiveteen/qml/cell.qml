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
        duration: control.durationY
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveLeft
        target: cell
        properties: "x"
        to: 0
        duration: control.durationX
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveDown
        target: cell
        properties: "y"
        to: 0
        duration: control.durationY
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: moveRight
        target: cell
        properties: "x"
        to: 0
        duration: control.durationX
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: scaleWidth
        target: cell
        properties: "width"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    PropertyAnimation {
        id: scaleHeight
        target: cell
        properties: "height"
        to: 0
        duration: 0
        alwaysRunToEnd: true
    }

    CellControl {
        id: control
        objectName: "control"

        onMoveUp: {
            moveUp.to = cell.y - control.stepY;
            moveUp.restart();
        }

        onMoveLeft: {
            moveLeft.to = cell.x + control.stepX;
            moveLeft.restart();
        }

        onMoveDown: {
            moveDown.to = cell.y + control.stepY;
            moveDown.restart();
        }

        onMoveRight: {
            moveRight.to = cell.x - control.stepX;
            moveRight.restart();
        }

        onScaleHeight: {
            scaleHeight.to = control.stepY;
            scaleHeight.restart();
        }

        onScaleWidth: {
            scaleWidth.to = control.stepX;
            scaleWidth.restart();
        }
    }
}
