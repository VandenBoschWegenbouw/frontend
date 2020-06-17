import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4

import vdBosch 1.0

Page {
    id: page
    width: window.width
    height: window.height
    implicitHeight: 811
    implicitWidth: 411
    title: "Gebruiker registreren"
    anchors.verticalCenter: window.verticalCenter
    anchors.top: window.top
    anchors.horizontalCenter: window.horizontalCenter
    anchors.left: window.left

    GridLayout {
        anchors.fill: parent
        columns: 4
        Item {
            Layout.column: 0
            Layout.row: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
            Item {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 0
                Layout.rowSpan: 2
                Layout.fillHeight: true
            }

            Label {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 2
                id: lblUsername
                text: qsTr("Gebruikersnaam")
                font.pointSize: 16
            }

            TextField {
                id: username
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 3
                width: parent.width*0.5
                implicitWidth: parent.width*0.5
                height: 40
                implicitHeight: 40
                placeholderText: "Gebruikersnaam"
                onTextChanged: registerHandler.username = text
                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
            }

            Label {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 4
                id: lblPassword
                text: qsTr("Wachtwoord")
                font.pointSize: 16
            }

            TextField {
                id: password
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 5
                width: parent.width*0.5
                implicitWidth: parent.width*0.5
                height: 40
                implicitHeight: 40
                placeholderText: "Wachtwoord"
                onTextChanged: registerHandler.password = text
                echoMode: "Password"
                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
            }

            Label {
                Layout.column: 1
                Layout.row: 6
                id: lblAdmin
                text: qsTr("Admin")
                font.pointSize: 16
            }

            CheckBox {
                Layout.column: 2
                Layout.row: 6
                id: admin
                onCheckedChanged: registerHandler.admin = checked

            }

            Rectangle {
                id: btnAddHours
                y: parent.height*0.7
                width: parent.width*0.3
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 7
                height: 40
                color: "#6abc93"
                radius: 10

                Layout.alignment: Qt.AlignHCenter

                Label {
                    color: "#ffffff"
                    text: qsTr("Toevoegen")
                    font.pointSize: 16

                    anchors.horizontalCenter: parent.horizontalCenter
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: btnAddHours
                    onClicked: {
                        registerHandler.registerUser()
                        svItems.replace("MijnUren.qml")
                    }
                }
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 8
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 9
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 2
                Layout.row: 10
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            Item {
                Layout.column: 3
                Layout.row: 0
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }


