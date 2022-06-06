import QtQuick 2.12
import QtQuick.Window 2.12

import Controller 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Test Thread")

    Controller {id: controller}

    Rectangle {
        id: source
        width: 100
        height: 100
        gradient: Gradient {
            GradientStop {position: 0; color: "steelblue" }
            GradientStop {position: 1; color: "black" }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                source.grabToImage(function(result){
                    controller.prepareTakingShot(result.image, "something.png");
                    controller.startTakingShot();
                });
            }
        }

    }
}
