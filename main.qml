import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 411
    height: 811
    font.family: "arial"
    property alias stackView: svItems
    property alias window: window
    property alias toolBar: toolBar
    title: qsTr("van den Bosch Registratie")

    header: ToolBar {
        id: toolBar
        contentHeight: toolButton.implicitHeight
        visible: false
        height: window.height*0.1

        background: Rectangle {
            anchors.fill: parent
            color: "#343a40"
        }

        ToolButton {
            id: toolButton
            Image {
                width: parent.width*0.3
                height: parent.height*0.3
                source: stackView.depth > 1 ? "images/left-arrow.png" : "images/bars.png"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            height: parent.height
            width: parent.height
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
            background: Rectangle {
                anchors.fill: parent
                color: "#343a40"
            }
            contentItem: Text {
                text: parent.text
                font: parent.font
                opacity: parent.opacity
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
            font.pixelSize: 20
            color: "white"
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height
        font.pixelSize: 16

        background: Rectangle {
            anchors.fill: parent
            color: "#343a40"
        }



        Column {
            anchors.fill: parent
            padding: 10

            ItemDelegate {
                text: qsTr("Mijn uren")
                width: drawer.width-20


                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }

                background: Rectangle {
                    id: bgUren
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgUren.color = "#C0BEBD"

                onReleased: bgUren.color = "#343a40"
                onClicked: {
                    stackView.replace("MijnUren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Materialen")

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }

                background: Rectangle {
                    id: bgMaterialen
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgMaterialen.color = "#C0BEBD"

                onReleased: bgMaterialen.color = "#343a40"

                width: parent.width - 20
                onClicked: {
                    stackView.replace("GebruikteMaterialen.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: exportHours

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }
                background: Rectangle {
                    id: bgExport
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgExport.color = "#C0BEBD"

                onReleased: bgExport.color = "#343a40"
                visible: false
                text: "Exporteer uren"

                width: parent.width - 20
                onClicked: {
                    stackView.replace("ExportProject.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerUser

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }
                background: Rectangle {
                    id: bgUser
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgUser.color = "#C0BEBD"

                onReleased: bgUser.color = "#343a40"
                visible: false
                text: "Registreer gebruiker"
                width: parent.width - 20
                onClicked: {
                    stackView.replace("GebruikerRegistreren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerProject

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }
                background: Rectangle {
                    id: bgProject
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgProject.color = "#C0BEBD"

                onReleased: bgProject.color = "#343a40"
                visible: false
                text: "Registreer project"
                width: parent.width - 20
                onClicked: {
                    stackView.replace("ProjectRegistreren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerKlant

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }
                background: Rectangle {
                    id: bgCustomer
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgCustomer.color = "#C0BEBD"

                onReleased: bgCustomer.color = "#343a40"
                visible: false
                text: "Registreer nieuwe klant"
                width: parent.width - 20
                onClicked: {
                    stackView.replace("KlantRegistreren.qml")
                    drawer.close()
                }
            }

            ItemDelegate {
                height: (parent.height-y) - (idLogout.height+10)
                implicitHeight: (parent.height-y) - (idLogout.height+10)


                background: Rectangle {
                    id: bgFiller
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgFiller.color = "#343a40"
            }


            ItemDelegate {
                id: idLogout
                text: qsTr("Log uit")

                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    opacity: parent.opacity
                    color: "white"
                }

                background: Rectangle {
                    id: bgLogout
                    anchors.fill: parent
                    color: "#343a40"
                }

                onPressed: bgLogout.color = "#C0BEBD"

                onReleased: bgLogout.color = "#343a40"


                width: parent.width - 20
                onClicked: {
                    stackView.replace("Login.qml")
                    toolBar.visible = false
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: svItems
        anchors.fill: parent
        anchors.bottom: parent.bottom
        initialItem: "Login.qml"
    }

    Connections {
        target: loginHandler
        onCorrectLogin: {
            toolBar.visible = true;
            svItems.replace("MijnUren.qml")
        }

        onCorrectAdminLogin: {
            toolBar.visible = true;
            svItems.replace("MijnUren.qml")
            exportHours.visible = true;
            registerUser.visible = true;
            registerProject.visible = true;
            registerKlant.visible = true;
        }

        onIncorrectLogin: {
            incorrectLogin.visible = true
        }
    }

    Connections {
        target: hourRegistrationHandler
        onWorkedTooHard: {
            workedTooHard.visible = true
        }

    }

    MessageDialog {
        id: workedTooHard
        title: "Worked too hard"
        text: "Sorry you worked too hard, you have deserved some rest!"
    }

    MessageDialog {
        id: incorrectLogin
        title: "Incorrect login attempt"
        text: "The provided information was incorrect, please try again"
    }
}
