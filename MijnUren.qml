import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import Qt.labs.calendar 1.0

import vdBosch 1.0

Page {
    id: page
    width: window.width
    height: window.height
    implicitWidth: 640
    implicitHeight: 480
    title: qsTr("Mijn Uren")


    property int selectedRow


    Rectangle {
        id: dateBar
        color: "#C0BEBD"
        width: window.width
        height: window.height*0.1

        Label {
            id: date
            text: dateHandler.date
            color: "white"
            font.pixelSize: 22
            x: parent.width/2-date.width/2
            y: parent.height/2-date.height/2
        }

        Button {
            id: previousDate
            text: "<"
            font.pixelSize: 25
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
                hourRegistrationHandler.fetchHours(hourRegistrationList, dateHandler.date)
            }
        }

        Button {
            id: nextDate
            text: ">"
            font.pixelSize: 25
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
                hourRegistrationHandler.fetchHours(hourRegistrationList, dateHandler.date)
            }
        }
    }

    ListView {
        width: parent.width
        height: parent.height*0.9
        y: dateBar.y + dateBar.height
        clip: true

        model: HourRegistrationModel {
            list: hourRegistrationList
        }

        delegate: ColumnLayout {
            width: parent.width

            RowLayout {
                width: parent.width*0.8
                x: parent.width*0.1
                Text {
                    id: projectAndCustomer
                    text: model.project + " - " + model.company
                    x: 0
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignLeft
                    leftPadding: parent.width*0.1
                }

                Item {
                    Layout.fillWidth: true
                }
                Item {
                    Layout.fillWidth: true
                }
                Item {
                    Layout.fillWidth: true
                }

                Text {
                    id: time
                    text: model.uren + " UUR"
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignRight
                }

                Button {
                    id: delRegistration
                    text: "X"

                    visible: !model.projectFinished

                    implicitWidth: 30
                    x: parent.right - delRegistration.width

                    onClicked: {
                        selectedRow = index;
                        confirmDeletion.open()
                    }

                    //delRegistration.rightPadding: parent.width*0.1
                }

                Item {
                    Layout.fillWidth: true
                }



            }

            RowLayout {
                width: parent.width
                Item {
                    Layout.fillWidth: true
                }

                Rectangle {
                    width: parent.width*0.8
                    height: 3
                    color: "#000"
                    opacity: 0.3
                }

                Item {
                    Layout.fillWidth: true
                }
            }
        }

        Component.onCompleted: {
            hourRegistrationHandler.fetchHours(hourRegistrationList)
        }
    }

    RoundButton {
        id: addHours
        text: "+"
        width: parent.height * 0.1
        height: parent.height * 0.1
        background: Rectangle {
            radius: addHours.radius
            color: "#6abc93"
        }

        x: parent.width*0.8-addHours.width/2
        y: parent.height*0.8-addHours.height/2

        contentItem: Text {
            text: addHours.text
            font.pointSize: 40
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        onClicked: {
            stackView.push("UrenRegistreren.qml")
        }
    }


    MessageDialog {
        id: confirmDeletion
        title: "Zeker verwijderen?"
        text: "Ben je er zeker van dat je de uren wilt verwijderen? Dit kan niet meer ongedaan gemaakt worden"

        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {
            hourRegistrationHandler.deleteHours(selectedRow, hourRegistrationList)
        }
    }

    Component.onCompleted: {
        addHours.x = parent.width*0.8-addHours.width/2
        addHours.y = parent.height*0.8-addHours.height/2
    }
}
