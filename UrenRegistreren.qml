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
                textRole: "name"
                model: CompanyModel {
                    list: companyList
                }

                Component.onCompleted: {

                    cbSelectKlant.currentIndex = -1;

                    companyHandler.fetchCompanies(companyList)

                }

                onDisplayTextChanged: {

                    projectHandler.fetchProjectsByCompany(companyList, projectList, currentIndex);

                    cbSelectProject.enabled = true;

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

            ComboBox {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 6
                id: cbSelectProject
                enabled: false
                implicitWidth: parent.width*0.6
                implicitHeight: parent.height*0.05


                model: ProjectModel {
                    list: projectList
                }

                background: Rectangle {
                    color: "white"
                    border.color: "#6abc93"
                    border.width: 3
                    width: parent.width
                    height: parent.height
                }

                textRole: "name"


                delegate: ItemDelegate {
                    width: cbSelectProject.width
                    text: model.finished ? model.name + " - AFGEROND" : model.name
                    font.weight: cbSelectProject.currentIndex === index ? Font.DemiBold : Font.Normal
                    enabled: !model.finished
                    highlighted: ListView.isCurrentItem

                    Binding {
                        target: contentItem
                        property: "color"
                        value: model.finished ? "gray" : "black"
                    }
                }
            }

            Label {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 7
                id: lblDatum
                text: qsTr("Datum")
                font.pointSize: 16
            }

            Rectangle {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 8
                width: cbSelectKlant.width
                height: cbSelectKlant.height

                color: "#C0BEBD"

                Label {
                    id: lblDate
                    text: dateHandler.date.toString("dd-MM-yyyy H:m:ss AP")
                    color: "white"
                    font.pixelSize: 16
                    x: parent.width/2-lblDate.width/2
                    y: parent.height/2-lblDate.height/2
                }

                Button {
                    id: previousDate
                    text: "<"
                    font.pixelSize: 16
                    width: parent.height
                    height: parent.height
                    contentItem: Text {
                        text: parent.text
                        font: parent.font
                        opacity: parent.opacity
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                    background: Rectangle {
                        anchors.fill: parent
                        color: "#C0BEBD"
                    }

                    onClicked: {
                        dateHandler.decreaseDate()
                    }
                }

                Button {
                    id: nextDate
                    text: ">"
                    font.pixelSize: 16
                    width: parent.height
                    height: parent.height
                    x: parent.width-nextDate.width
                    contentItem: Text {
                        text: parent.text
                        font: parent.font
                        opacity: parent.opacity
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                    background: Rectangle {
                        anchors.fill: parent
                        color: "#C0BEBD"
                    }
                    onClicked: {
                        dateHandler.increaseDate()
                    }
                }

            }


            Label {
                Layout.column: 1
                Layout.columnSpan: 3
                Layout.row: 9
                id: lblUren
                text: qsTr("Uren")
                font.pointSize: 16
            }

            SpinBox {
                Layout.column: 1
                Layout.row: 10
                id: spinBox
                to: 10
                implicitWidth: parent.width*0.6

                onValueChanged: {
                    hourRegistrationHandler.workedHours = value
                }
            }

            Label {
                id: lblOpmerking
                text: "Beschrijving"
                Layout.column: 1
                Layout.row: 11
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
                Layout.row: 12
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

                    onTextChanged: hourRegistrationHandler.description = text
                }
                ScrollBar.vertical: ScrollBar{}
            }

            Rectangle {
                id: btnAddHours
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
                    anchors.fill: btnAddHours
                    onClicked: {

                        hourRegistrationHandler.addHours(projectList, cbSelectProject.currentIndex, hourRegistrationList, dateHandler.date)

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


