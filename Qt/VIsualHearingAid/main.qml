import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 1.0
import QtQuick.Extras 1.4
import QtQuick.Dialogs 1.1
import QtQuick.Controls.Styles 1.2
import VisualHearingAid 1.0
import VHAWatch 1.0
import VHADigital 1.0


Window {
    id: root
    visible: true
    width: 640
    height: 480
    color: "#000000"
    title: qsTr("VisualHearingAid")

    Item {
        id: dialogs
        MessageDialog {
            id: matrixErrorMessage
            title: "Matrix Creator Unrechable!"
            text: "Please check that ODAS is running and that you are using the right Port"
        }

        MessageDialog {
            id: portInfo
            title: "New Port Set"
            text: ""
        }


        MessageDialog {
            id: helpMessage
            title: "Help"
            text: "- Use the X Y Z Sliders to controll the Visualization \n - Calibrate the system in the menu screen\n - Use the toggle Overlay button to switch between Overlays or disable them \n - Set up the port for the ODAS and/or Compass data or use 0 for demo data \n - Tap the Visualization to freeze and unfreeze it (outside of the settings screen)"
        }



        MessageDialog {
            id: calibrateHelp
            title: "Calibrate?"
            text: "- Hold the phone in the same angle as the matrix \n - Press Yes to calibrate and set up the Z axis to align the sound sources afterwards \n"
            standardButtons: StandardButton.Yes | StandardButton.No
            onYes: vha_FBO.calibrateHeadings();
            onNo: calibrateHelp.close();
        }

    }

    Item {
        id: vhaItem
        anchors.fill: parent

        VisualHearingAid_FBO{
            id : vha_FBO
            enabled: true
            anchors.fill: parent

            property var angleData : 0
            transform: [
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 1; y: 0; z: 0 } angle: sliderX.value},
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 1; z: 0 } angle: sliderY.value},
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 0; z: 1 } angle: sliderZ.value},
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 0; z: 1 } angle: vha_FBO.angleData},
                //this rotation is to mirror the visualisation. At start of the app do an calibration with z-axis offset of needed degree to match matrix position
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 1; z: 0 } angle: 180}
            ]
            onAngleChanged: {
                angleData = vha_FBO.angle
                compassData.text = "Diff:"+angleData+"°"
                matrixCompass.text = "Matrix:"+vha_FBO.matrixAngle+"°"
                phoneCompass.text = "Phone:"+vha_FBO.phoneAngle+"°"
            }
        }


    }

    Item{
        id: overlays
        anchors.fill: parent

        VHAWatch_FBO{
            id : watch_FBO
            enabled: true
            visible: true
            anchors.fill: parent
            transform: [
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: -1; y: -1; z: 0 } angle: 180},
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 0; z: -1 } angle: 90}
            ]
        }
        VHADigital_FBO{
            id : digital_FBO
            enabled: true
            visible: false
            anchors.fill: parent
            transform: [
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: -1; y: -1; z: 0 } angle: 180},
                Rotation { origin.x: watch_FBO.width/2 ; origin.y: watch_FBO.height/2; axis { x: 0; y: 0; z: -1 } angle: 90}
            ]
        }

    }

    Item{
        id : buttonItem
        visible: true
        ToggleButton {
            id: debugButton
            x: 23
            y: 36
            width: 34
            height: 26
            text: qsTr("")
            style: ButtonStyle {
                label: Image {
                    anchors.fill: parent
                    source: "pic/button.png"
                }
            }
            onClicked: {
                controls.visible = !controls.visible
                // matrixDummyCompass.enabled = !matrixDummyCompass.enabled
                freezeButton.enabled = !freezeButton.enabled
                if(vha_FBO.getSocketStatus()!== 0 && checked === false){
                    matrixErrorMessage.open();
                }
            }
        }
        ToggleButton {
            id: freezeButton
            opacity: 0
            enabled: true
            x: 68
            y: 150
            width: 429
            height: 302
            text: "Freeze"
            onClicked: {
                vha_FBO.setFrozen(!vha_FBO.frozen)
            }
        }

    }
    Component{
        id : styleButton
        ButtonStyle {
            background: Rectangle {
                id: firstRec
                color: "#606066";
                border.width: 1
                border.color: "red"
                radius:20
                anchors.centerIn: parent

                Rectangle {
                    id: secondRec
                    color: "#606066"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 2
                }
            }
        }
    }
    Component{
        id : styleTextfield
        TextFieldStyle {
            background: Rectangle {
                color: "#606066";
                border.width: 1
                border.color: "red"
                radius:20
                anchors.centerIn: parent
                Rectangle {
                     color: "#606066"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 2
                }
            }
        }
    }




    Item{
        id: controls
        anchors.fill: parent
        visible: true

        Text {
            id: compassData
            x: 23
            y: 258
            color: "red"
            text: qsTr("Diff:0°")
            font.pixelSize: 30
        }

        Text {
            id: matrixCompass
            x: 23
            y: 201
            color: "red"
            text: qsTr("Matrix:0°")
            font.pixelSize: 30
        }

        Text {
            id: phoneCompass
            x: 23
            y: 140
            color: "red"
            text: qsTr("Phone:0°")
            font.pixelSize: 30
        }



        Grid {
            x: 19
            y: 500
            spacing: 12
            Column {
                spacing: 8
                Button {
                    id: calibrate
                    style: styleButton
                    width: 120
                    height: 30
                    text: qsTr("Calibrate")
                    onClicked: {
                        calibrateHelp.open();
                    }
                }

                Button {
                    id: switchOverlay
                    style: styleButton
                    width: 120
                    height: 30
                    property var _state: 0
                    text: "Switch Overlay"
                    onClicked: {
                        _state = (_state+1)%3;
                        if(_state == 0){
                            watch_FBO.visible = true;
                            digital_FBO.visible = false;
                        }else if(_state == 1){
                            watch_FBO.visible = false;
                            digital_FBO.visible = true;
                        }else if(_state == 2){
                            watch_FBO.visible = false;
                            digital_FBO.visible = false;
                        }
                    }
                }

                Button {
                    id: helpButton
                    style: styleButton
                    width: 120
                    height: 30
                    text: qsTr("Help")
                    onClicked: {
                        helpMessage.open()
                    }
                }
            }

            Column {
                spacing: 8
                ToggleButton {
                    id: enableHeadingTracking
                    width: 200
                    height: 30
                    text: qsTr("Use Compass")
                    checked: false
                    style: ButtonStyle {
                        background: Rectangle {

                            color: enableHeadingTracking.checked ? "green" : "#606066";
                            border.width: 1
                            border.color: "red"
                            radius:20
                            anchors.centerIn: parent

                            Rectangle {
                                id: secondRec
                                color: "#606066"
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 2
                            }
                        }
                    }
                    onCheckedChanged:   {
                        if(checked){
                        vha_FBO.setUseCompass();
                        }
                        if(!checked){
                            vha_FBO.setUseCompass();
                            compassData.text = "Diff:0°"
                            matrixCompass.text = "Matrix:0°"
                            phoneCompass.text = "Phone:0°"
                        }

                    }

                }

                Row {

                    Button {
                        id: compassButton
                        style: styleButton
                        width: 120
                        height: 30
                        text: qsTr("Compass Port")
                        onClicked: {
                            vha_FBO.setCompassPort(parseInt(compassInput.text));
                        }
                    }

                    TextField {
                        id: compassInput
                        width: 80
                        horizontalAlignment: TextInput.AlignHCenter
                        style: styleTextfield
                        height: 30
                        text: vha_FBO.getCompassPort();
                        font.pixelSize: 24
                        validator: IntValidator {bottom: 0; top: 9999}
                    }
                }

                Row {

                    Button {
                        id: portButton
                        style: styleButton
                        width: 120
                        height: 30
                        text: qsTr("Matrix Port")
                        onClicked: {
                            vha_FBO.setMatrixPort(parseInt(portInput.text));
                        }
                    }

                    TextField {
                        id: portInput
                        width: 80
                        height: 30
                        horizontalAlignment: TextInput.AlignHCenter
                        style: styleTextfield
                        text: vha_FBO.getMatrixPort();
                        font.pixelSize: 24
                        validator: IntValidator {bottom: 0; top: 9999}
                    }
                }
            }
        }

        Column {
            x: 78
            y: 16
            spacing: 16
            Row {
            Slider {
                id: sliderX
                maximumValue: 360
                minimumValue: 0
                width: 208
                height: 26
            }
            Label{
                text: "X"
                font.pixelSize: 18
                color: "red"
            }
            }
            Row {
            Slider {
                id: sliderY
                maximumValue: 360
                minimumValue: 0
                width: 208
                height: 26

            }
            Label{
                text: "Y"
                font.pixelSize: 18
                color: "red"
            }
            }
            Row {
            Slider {
                id: sliderZ
                maximumValue: 360
                minimumValue: 0
                width: 208
                height: 26
            }
            Label{
                text: "Z"
                font.pixelSize: 18
                color: "red"
            }
            }
        }

    }






}
