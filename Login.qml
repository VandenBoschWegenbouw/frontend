import QtQuick 2.14
import QtQuick.Controls 2.14

Page {
    id: page
    width: window.width
    height: window.height
    implicitWidth: 640
    implicitHeight: 480
    title: qsTr("Login")

    Rectangle {
        id: background
        width: parent.width
        height: parent.height
        color: "#393d41"
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left

        MouseArea {
            anchors.fill: parent
            onClicked: Qt.inputMethod.hide()
        }


        Image {
            id: logo
            y: parent.height*0.2
            width: (parent.width*0.4)
            height: (parent.width*0.4)/100*115
            anchors.horizontalCenter: parent.horizontalCenter
            source: "images/Logo.png"
        }



        TextField {
            id: username
            y: parent.height*0.5
            width: parent.width*0.5
            height: 40
            placeholderText: "Gebruikersnaam"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            onTextChanged: loginHandler.username = text
            onAccepted: loginHandler.login();
        }

        TextField {
            id: password
            y: parent.height*0.6
            width: parent.width*0.5
            height: 40
            anchors.verticalCenterOffset: 57
            anchors.horizontalCenterOffset: 0
            placeholderText: "Wachtwoord"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            onTextChanged: loginHandler.password = text
            echoMode: "Password"
            onAccepted: loginHandler.login();
        }

        Rectangle {
            id: btnLogin
            y: parent.height*0.7
            width: parent.width*0.3
            height: 40
            color: "#6abc93"
            radius: 10
            anchors.verticalCenterOffset: parent.height / 16 * 4
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                color: "#ffffff"
                text: qsTr("INLOGGEN")
                font.pointSize: 18

                anchors.horizontalCenter: parent.horizontalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    loginHandler.login();
                }
            }
        }
    }
}
