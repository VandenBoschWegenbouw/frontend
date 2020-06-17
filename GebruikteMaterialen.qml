import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

import vdBosch 1.0

Page {
    id: page
    width: window.width
    height: window.height
    implicitWidth: 640
    implicitHeight: 480
    title: qsTr("Materialen")

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
                usedPartsHandler.fetchUsedParts(usedPartsList, dateHandler.date)
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
                usedPartsHandler.fetchUsedParts(usedPartsList,dateHandler.date)
            }
        }
    }
    ListView {
        width: parent.width
        height: parent.height*0.9
        y: dateBar.y + dateBar.height + 10
        clip: true

        model: UsedPartsModel {
            list: usedPartsList
        }

        Component.onCompleted: {
            usedPartsHandler.fetchUsedParts(usedPartsList, dateHandler.date )
        }

        delegate: ColumnLayout {
            width: parent.width

            RowLayout {
                width: parent.width
                Text {
                    id: projectAndCustomer
                    text: model.project + " - " + model.company
                    font.pixelSize: 22
                    leftPadding: parent.width*0.1
                }
            }

            RowLayout {
                width: parent.width
                Text {
                    id: materialAndType
                    text: model.partType + " - " + model.specification
                    font.pixelSize: 22
                    leftPadding: parent.width*0.2
                }

                Item {
                    Layout.fillWidth: true
                }

                Text {
                    id: amount
                    text: model.amount + " " + model.amountType
                    font.pixelSize: 22
                    rightPadding: parent.width*0.1
                }
            }

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
        MouseArea {
            anchors.fill: parent
            onClicked: stackView.push("MaterialenRegistreren.qml")
        }
    }

}
