import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

import vdBosch 1.0

Page {
    id: page
    width: window.width
    height: window.height
    implicitWidth: 640
    implicitHeight: 480
    title: qsTr("Mijn Uren")

    Rectangle {
        id: dateBar
        color: "#C0BEBD"
        width: window.width
        height: window.height*0.1

        Label {
            id: date
            text: Qt.formatDate(new Date(), "dd-MM-yyyy")
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
                width: parent.width
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
                    height: time.implicitHeight
                    Text {
                        id: time
                        text: model.uren + " UUR"
                        x: parent.width-time.width
                        font.pixelSize: 22
                        horizontalAlignment: Text.AlignRight

                        Component.onCompleted: {

                            time.rightPadding = (parent.width*0.1)+(time.width/2)

                        }

                    }
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
            //font: addHours.font
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

    Component.onCompleted: {
        addHours.x = parent.width*0.8-addHours.width/2
        addHours.y = parent.height*0.8-addHours.height/2
    }
}
