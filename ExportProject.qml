import QtQuick 2.14
import QtQuick.Controls 2.14
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
    title: qsTr("Exporteer projecten")

    ListView {
        width: parent.width
        height: parent.height*0.9
        clip: true



        Component.onCompleted: {
            projectHandler.fetchProjects(projectList)
        }

        model: ProjectModel {
            list: projectList
        }

        delegate: ColumnLayout {
            width: parent.width


            property int delegateIndex: index



            RowLayout {
                width: parent.width
                //visible: !model.finished
                Text {
                    id: project
                    text: qsTr(model.name + " - " + model.company)
                    font.pixelSize: 22
                }
                Item {
                    Layout.fillWidth: true
                }
                Button {
                    text: "Exporteer " + model.name

                    onClicked: {
                        projectHandler.exportProject(model.id)
                    }
                }
            }
        }
    }
}
