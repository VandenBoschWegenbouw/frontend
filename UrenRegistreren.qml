import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.14

Page {
    id: page
    width: window.width
    height: window.height
    implicitHeight: 811
    implicitWidth: 411
    property alias spinBox: spinBox
    property alias btnAddHours: btnAddHours
    title: "Uren registreren"
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

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
                model: ListModel {
                    ListElement {
                        text: "Test"
                    }
                    ListElement {
                        text: "Test 2"
                    }
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

            ComboBox {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 6
                id: cbSelectProject
                implicitWidth: parent.width*0.6
                implicitHeight: parent.height*0.05

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }

                model: ListModel {
                    ListElement {
                        text: "Test project"
                    }
                    ListElement {
                        text: "Test project 2"
                    }
                }

                Component.onCompleted: {
                    hourRegistrationHandler.fetchProjects()
                }
            }



            Label {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 7
                id: lblUren
                text: qsTr("Uren")
                font.pointSize: 16
            }

            SpinBox {
                Layout.column: 1
                Layout.row: 8
                id: spinBox
                to: 10
                implicitWidth: parent.width*0.6
            }

            Label {
                id: lblOpmerking
                text: "Beschrijving"
                Layout.column: 1
                Layout.row: 9
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
                Layout.row: 10
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
                }
                ScrollBar.vertical: ScrollBar{}
            }



//            Button {
//                Layout.column: 1
//                Layout.row: 10
//                id: btnAddHours
//                text: qsTr("Voeg uren toe")
//            }

            Rectangle {
                id: btnAddHours
                y: parent.height*0.7
                width: parent.width*0.3
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 11
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
                        stackView.pop()
                    }
                }
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 12
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 13
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 14
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


