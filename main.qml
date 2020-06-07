import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.0

ApplicationWindow {
    id: window
    visible: true
    width: 411
    height: 811
    font.family: "helvetica"
    property alias stackView: svItems
    property alias window: window
    property alias toolBar: toolBar
    title: qsTr("vdbosch Registratie")

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
            //text: stackView.depth > 1 ? "\u25C0" : "\u2630"
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
            color: "white"
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Mijn uren")
                width: parent.width
                onClicked: {
                    stackView.replace("MijnUren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Materialen")
                width: parent.width
                onClicked: {
                    stackView.replace("GebruikteMaterialen.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: exportHours
                visible: false
                text: "Exporteer uren"
                width: parent.width
                onClicked: {
                    stackView.replace("ExportProject.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerUser
                visible: false
                text: "Registreer gebruiker"
                width: parent.width
                onClicked: {
                    stackView.replace("GebruikerRegistreren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerProject
                visible: false
                text: "Registreer project"
                width: parent.width
                onClicked: {
                    stackView.replace("ProjectRegistreren.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                id: registerKlant
                visible: false
                text: "Registreer nieuwe klant"
                width: parent.width
                onClicked: {
                    stackView.replace("KlantRegistreren.qml")
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
            svItems.replace("MijnUren.qml")
            toolBar.visible = true;
        }

        onCorrectAdminLogin: {
            svItems.replace("MijnUren.qml")
            toolBar.visible = true;
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
