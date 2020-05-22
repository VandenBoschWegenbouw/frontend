import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3

ApplicationWindow {
    id: window
    visible: true
    width: Screen.width
    height: Screen.height
    property alias stackView: svItems
    property alias window: window
    property alias toolBar: toolBar
    title: qsTr("vdbosch Registratie")


    Component.onCompleted: {
        console.log("density: " + Screen.pixelDensity)
    }

    header: ToolBar {
        id: toolBar
        contentHeight: toolButton.implicitHeight
        visible: false

        ToolButton {
            id: toolButton
            text: "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: drawer.open()
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.replace("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.replace("Page2Form.ui.qml")
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
            svItems.replace("Page1Form.ui.qml")
            toolBar.visible = true;
        }

        onIncorrectLogin: {
            incorrectLogin.visible = true
        }
    }

    MessageDialog {
        id: incorrectLogin
        title: "Incorrect login attempt"
        text: "The provided information was incorrect, please try again"
    }
}
