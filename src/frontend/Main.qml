import QtQuick
import QtQuick.Controls

Window {
    width: 400
    height: 400
    visible: true
    title: "Car Simulator"
    color: "#2b2b2b"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: controller.speed + " km/h"
            font.pixelSize: 48
            font.bold: true
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: controller.rpm + " RPM"
            font.pixelSize: 24
            color: "lightgreen"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: "Gear: " + controller.gear
            font.pixelSize: 24
            color: "orange"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 15
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Turn on Engine"
                onClicked: controller.turnOnIgnition()
            }
            Button {
                text: "turn off Engine"
                onClicked: controller.turnOffIgnition()
            }
        }

        Row {
            spacing: 15
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "GAS"
                width: 100
                height: 60
                onPressed: controller.pressGas()
                onReleased: controller.releaseGas()
            }
            Button {
                text: "BREAK"
                width: 100
                height: 60
                onPressed: controller.pressBrake()
                onReleased: controller.releaseBrake()
            }
        }
    }
}
