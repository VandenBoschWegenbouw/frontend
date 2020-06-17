import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
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
            visible: !(Qt.formatDateTime(new Date(), "dd-MM-yyyy") == dateHandler.date)
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
        y: dateBar.y + dateBar.height + 10
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
                    text: model.uren + " uur"
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignRight
                }

                Button {
                    id: delRegistration
                    text: "X"

                    contentItem: Text {
                        text: parent.text
                        font.pixelSize: 16
                        opacity: enabled ? 1.0 : 0.3
                        color: "red"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        color: "transparent"
                    }

                    visible: !model.projectFinished

                    implicitWidth: 30
                    x: parent.right - delRegistration.width

                    onClicked: {
                        selectedRow = index;
                        confirmDeletion.open()
                    }
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
            hourRegistrationHandler.fetchHours(hourRegistrationList, dateHandler.date)
        }
    }

    Image {
        id: addHours
        source: "images/button.png"
        width: parent.height*0.1
        height: parent.height*0.1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20 + addHours.height
        anchors.right: parent.right
        anchors.rightMargin: 20
        //        x: parent.width*0.8-addHours.width/2
        //        y: window.height*0.8-addHours.height/2

        MouseArea {
            anchors.fill: parent
            onClicked: stackView.push("UrenRegistreren.qml")
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
