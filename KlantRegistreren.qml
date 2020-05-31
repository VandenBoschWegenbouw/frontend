import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.14

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
        columns: 5
        Item {
            Layout.column: 0
            Layout.row: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 0
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 1
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 2
                Layout.fillHeight: true
            }

            Label {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 3
                id: lblKlant
                text: qsTr("Klant naam")
                font.pointSize: 16
            }

            TextField {
                id: klant
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 4
                width: parent.width*0.5
                height: 40
                placeholderText: "Klant naam"
                onTextChanged: companyHandler.name = text
            }

            Rectangle {
                id: btnAddHours
                y: parent.height*0.7
                width: parent.width*0.3
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 5
                height: 40
                color: "#6abc93"
                radius: 10

                Layout.alignment: Qt.AlignHCenter

                Label {
                    color: "#ffffff"
                    text: qsTr("Toevoegen")
                    font.pointSize: 12

                    anchors.horizontalCenter: parent.horizontalCenter
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                }

                MouseArea {
                    anchors.fill: btnAddHours
                    onClicked: {
                        companyHandler.createCompany()
                        svItems.replace("MijnUren.qml")
                    }
                }
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 6
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 7
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 8
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 4
                Layout.row: 0
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }


