import QtQuick
import QtQuick.Controls

Item {
    id: root

    property real value: 0
    property real maxValue: 100
    property string label: ""
    property color gaugeColor: "#3498db"

    width: 200
    height: 200

    Rectangle {
        anchors.fill: parent
        radius: width / 2
        color: "#1a1a1a"
        border.color: "#333333"
        border.width: 4
    }


    Text {
        text: root.label
        color: "gray"
        font.pixelSize: 16
        font.bold: true
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
    }


    Text {
        text: Math.round(root.value)
        color: "white"
        font.pixelSize: 28
        font.bold: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id: needle
        width: 4
        height: root.height / 2.2
        color: root.gaugeColor
        antialiasing: true

        anchors.bottom: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Bottom

        rotation: -135 + (root.value / root.maxValue) * 270

        Behavior on rotation {
            SpringAnimation {
                spring: 3.0
                damping: 0.25
                mass: 1.0
            }
        }
    }

    Rectangle {
        width: 24
        height: 24
        radius: 12
        color: "#444444"
        border.color: "black"
        border.width: 2
        anchors.centerIn: parent
    }
}
