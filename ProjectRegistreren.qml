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
    title: "Project registreren"
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
                id: lblUsername
                text: qsTr("Klant")
                font.pointSize: 16
            }

            ComboBox {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 4
                id: cbSelectKlant
                implicitWidth: parent.width*0.6
                implicitHeight: parent.height*0.05
                textRole: "name"
                model: CompanyModel {
                    list: companyList
                }

                Component.onCompleted: {

                    companyHandler.fetchCompanies(companyList)
                }

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
                Layout.columnSpan: 3
                Layout.row: 5
                id: lblProject
                text: qsTr("Project")
                font.pointSize: 16
            }

            TextField {
                id: project
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 6
                width: parent.width*0.6
                implicitWidth: parent.width*0.6
                height: 40
                implicitHeight: 40
                placeholderText: "Projectnaam"
                onTextChanged: projectHandler.name = text

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
                Layout.columnSpan: 3
                Layout.row: 7
                id: lblDescription
                text: qsTr("Beschrijving")
                font.pointSize: 16
            }

            Flickable {
                id: flickable
                width: parent.width*0.6
                height: parent.height*0.1
                contentWidth: width
                contentHeight: textArea.implicitHeight
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 8
                TextArea.flickable: TextArea {
                    id: textArea
                    wrapMode: Text.WordWrap
                    background: Rectangle {
                        color: "white"
                        border.color: "#6abc93"
                        border.width: 3
                        width: parent.width
                        height: parent.height
                    }

                    onTextChanged: projectHandler.description = text
                }
                ScrollBar.vertical: ScrollBar{}
            }

            Rectangle {
                id: btnAddHours
                y: parent.height*0.7
                width: parent.width*0.3
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 9
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
                        projectHandler.createProject(companyList, cbSelectKlant.currentIndex)
                        svItems.replace("MijnUren.qml")
                    }
                }
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 10
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 11
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 12
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


