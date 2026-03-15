import QtQuick
import QtQuick.Controls

Window {
    width: 600
    height: 400
    visible: true
    title: "Car Dashboard Simulator"
    color: "#2b2b2b"
    Column {
        anchors.centerIn: parent
        spacing: 30

        Row {
            spacing: 40
            anchors.horizontalCenter: parent.horizontalCenter

            CustomGauge {
                value: controller.rpm
                maxValue: 8000
                label: "RPM"
                gaugeColor: "#e74c3c"
            }

            CustomGauge {
                value: controller.speed
                maxValue: 260
                label: "km/h"
                gaugeColor: "#3498db"
            }
        }

        Text {
            text: "GEAR: " + (controller.gear === 0 ? "N" : controller.gear)
            font.pixelSize: 24
            font.bold: true
            color: "orange"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "START/STOP"
                width: 100
                height: 50
                onClicked: controller.rpm > 0 ? controller.turnOffIgnition() : controller.turnOnIgnition()
            }

            Button {
                text: "BREAKE"
                width: 120
                height: 60
                onPressed: controller.pressBrake()
                onReleased: controller.releaseBrake()
            }

            Button {
                text: "GAS"
                width: 120
                height: 60
                onPressed: controller.pressGas()
                onReleased: controller.releaseGas()
            }
        }
    }
}
