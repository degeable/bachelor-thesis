import QtQuick 2.9
import QtQuick.Window 2.2
import FrameBufferObject 1.0


Window {
    id: root
    visible: true

    width: 640
    height: 480

    title: qsTr("Hello Triangles!")
    Item {
        id: fboItem
        anchors.fill: parent

        FrameBuffer	{
            id : buff
            enabled: true
            anchors.fill: parent

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    animation.start()

                }
            }
            RotationAnimator {
                  id : animation
                  target: buff;
                  from: 0;
                  to: 360;
                  duration: 1000
                  running: false
              }
        }
    }

    Text {
        id: element
        x: 218
        y: 451
        width: 204
        height: 29
        color: "#f02c2c"
        text: qsTr("Basic Triangle as own Item in QML")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

}
