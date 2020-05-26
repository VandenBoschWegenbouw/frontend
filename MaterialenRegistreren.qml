import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.14

Page {
    id: page
    width: window.width
    height: window.height
    title: "Materialen registreren"

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

//                Component.onCompleted: {
//                    hourRegistrationHandler.fetchProjects()
//                }
            }

            Label {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 7
                id: lblMaterialen
                text: qsTr("Materialen Groep")
                font.pointSize: 16
            }

            ComboBox {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 8
                id: cbSelectMaterialen
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
                        text: "Materiaal 1"
                    }
                    ListElement {
                        text: "Materiaal 2"
                    }
                }

                Component.onCompleted: {

                }
            }


            ComboBox {
                Layout.column: 1
                Layout.columnSpan: 5
                Layout.row: 9
                id: cbSelectMaterialenItem
                implicitWidth: parent.width*0.3
                implicitHeight: parent.height*0.05

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
            }

            ComboBox {
                Layout.column: 2
                Layout.columnSpan: 5
                Layout.row: 9
                id: cbSelectMaterialenAantal
                implicitWidth: parent.width*0.2
                implicitHeight: parent.height*0.05

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
            }

            ComboBox {
                Layout.column: 3
                Layout.columnSpan: 5
                Layout.row: 9
                id: cbSelectMaterialenidk
                implicitWidth: parent.width*0.2
                implicitHeight: parent.height*0.05

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }
            }


//            Button {
//                Layout.column: 1
//                Layout.row: 10
//                id: btnAddHours
//                text: qsTr("Voeg uren toe")
//            }

            Rectangle {
                id: btnAddMateriaal
                y: parent.height*0.7
                width: parent.width*0.3
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 13
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
                    anchors.fill: btnAddMateriaal
                    onClicked: {
                        stackView.pop()
                    }
                }
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 14
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 15
                Layout.fillHeight: true
            }

            Item {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 16
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

