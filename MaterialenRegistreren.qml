import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.14

import vdBosch 1.0

Page {
    id: page
    width: window.width
    height: window.height
    title: "Materialen registreren"

    GridLayout {
        anchors.fill: parent
        columns: 4
        rows: 14

        Item {
            Layout.column: 0
            Layout.row: 0
            Layout.rowSpan: 14
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Item {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 0
        }

        Label {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 1
            id: lblKlant
            text: qsTr("Klant")
            font.pointSize: 16
        }

        ComboBox {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 2
            id: cbSelectKlant
            implicitWidth: parent.width*0.6
            implicitHeight: parent.height*0.05
            textRole: "name"
            model: CompanyModel {
                list: companyList
            }

            Component.onCompleted: {

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
            Layout.columnSpan: 2
            Layout.row: 3
            id: lblProject
            text: qsTr("Project")
            font.pointSize: 16
        }

        ComboBox {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 4
            id: cbSelectProject
            enabled: false
            implicitWidth: parent.width*0.6
            implicitHeight: parent.height*0.05


            textRole: "name"
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
            Layout.columnSpan: 2
            Layout.row: 5
            id: lblDatum
            text: qsTr("Datum")
            font.pointSize: 16
        }

        Rectangle {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 6
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
            Layout.columnSpan: 2
            Layout.row: 7
            id: lblMaterialen
            text: qsTr("Materialen Groep")
            font.pointSize: 16
        }

        ComboBox {
            Layout.column: 1
            Layout.columnSpan: 2
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
            textRole: "type"
            model: PartTypeModel {
                list: partTypeList
            }

            Component.onCompleted: {
                partTypeHandler.fetchPartTypes(partTypeList)
            }
        }


        TextField {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 9
            id: cbSelectMaterialenItem
            implicitWidth: parent.width*0.6
            implicitHeight: parent.height*0.05
            placeholderText: "Beschrijving"

            onTextChanged: usedPartsHandler.specification = text

            background: Rectangle {
                color: "white"
                border.color: "#6abc93"
                border.width: 3
                width: parent.width
                height: parent.height
            }
        }

        SpinBox {
            Layout.column: 1
            Layout.row: 10
            id: cbSelectMaterialenAantal
            implicitWidth: (parent.width*0.3)
            implicitHeight: parent.height*0.05

            background: Rectangle {
                color: "white"
                border.color: "#6abc93"
                border.width: 3
                width: parent.width
                height: parent.height
            }

            onValueChanged: {
                usedPartsHandler.partAmount = value;
            }
        }

        ComboBox {
            Layout.column: 2
            Layout.row: 10
            id: cbSelectMaterialType
            implicitWidth: (parent.width*0.3-7)
            implicitHeight: parent.height*0.05
            Layout.alignment: Qt.AlignHCenter

            textRole: "type"
            model: AmountTypeModel{
                list: amountTypeList
            }

            background: Rectangle {
                color: "white"
                border.color: "#6abc93"
                border.width: 3
                width: parent.width
                height: parent.height
            }

            Component.onCompleted: {
                amountTypeHandler.fetchAmountTypes(amountTypeList)
            }
        }

        Rectangle {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 11
            Layout.topMargin: 10

            id: btnAddMateriaal
            y: parent.height*0.7
            width: parent.width*0.3
            height: 40
            color: "#6abc93"
            radius: 10

            Layout.alignment: Qt.AlignHCenter

            Label {
                color: "#ffffff"
                text: qsTr("Toevoegen")
                font.pointSize: 16

                anchors.horizontalCenter: parent.horizontalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: btnAddMateriaal
                onClicked: {
                    usedPartsHandler.addUsedParts(partTypeList, cbSelectMaterialen.currentIndex, amountTypeList, cbSelectMaterialType.currentIndex, projectList, cbSelectProject.currentIndex, usedPartsList)
                    stackView.pop()
                }
            }
        }

        Item {
            Layout.column: 1
            Layout.columnSpan: 2
            Layout.row: 12
            Layout.rowSpan: 3
            Layout.fillWidth: true
            Layout.fillHeight: true
        }


        Item {
            Layout.column: 3
            Layout.row: 0
            Layout.rowSpan: 14
            Layout.fillWidth: true
            Layout.fillHeight: true
        }



//        Item {
//            Layout.column: 0
//            Layout.row: 0
//            Layout.fillHeight: true
//            Layout.fillWidth: true
//            Layout.rowSpan: 1
//        }
//            Item {
//                Layout.column: 1
//                Layout.columnSpan: 3
//                Layout.row: 0
//                Layout.fillHeight: true
//            }

//            Item {
//                Layout.column: 1
//                Layout.columnSpan: 3
//                Layout.row: 1
//                Layout.fillHeight: true
//            }

//            Item {
//                Layout.column: 1
//                Layout.columnSpan: 3
//                Layout.row: 2
//                Layout.fillHeight: true
//            }

//            Label {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 3
//                id: lblKlant
//                text: qsTr("Klant")
//                font.pointSize: 16
//            }

//            ComboBox {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 4
//                id: cbSelectKlant
//                implicitWidth: parent.width*0.6
//                implicitHeight: parent.height*0.05
//                textRole: "name"
//                model: CompanyModel {
//                    list: companyList
//                }

//                Component.onCompleted: {

//                    companyHandler.fetchCompanies(companyList)
//                }

//                onDisplayTextChanged: {

//                    projectHandler.fetchProjectsByCompany(companyList, projectList, currentIndex);

//                    cbSelectProject.enabled = true;

//                }


//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }


//            }

//            Label {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 5
//                id: lblProject
//                text: qsTr("Project")
//                font.pointSize: 16
//            }

////            ComboBox {
////                Layout.column: 1
////                Layout.columnSpan: 3
////                Layout.row: 6
////                id: cbSelectProject
////                implicitWidth: parent.width*0.6
////                implicitHeight: parent.height*0.05

////                background: Rectangle {
////                    color: "white"
////                    border.color: "#6abc93"
////                    border.width: 3
////                    width: parent.width
////                    height: parent.height
////                }

////                model: ListModel {
////                    ListElement {
////                        text: "Test project"
////                    }
////                    ListElement {
////                        text: "Test project 2"
////                    }
////                }
////            }

//            ComboBox {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 6
//                id: cbSelectProject
//                enabled: false
//                implicitWidth: parent.width*0.6
//                implicitHeight: parent.height*0.05


//                textRole: "name"
//                model: ProjectModel {
//                    list: projectList
//                }

//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }

//                delegate: ItemDelegate {
//                    width: cbSelectProject.width
//                    text: model.finished ? model.name + " - AFGEROND" : model.name
//                    font.weight: cbSelectProject.currentIndex === index ? Font.DemiBold : Font.Normal
//                    enabled: !model.finished
//                    highlighted: ListView.isCurrentItem

//                    Binding {
//                        target: contentItem
//                        property: "color"
//                        value: model.finished ? "gray" : "black"
//                    }
//                }
//            }

//            Rectangle {
//                Layout.column: 1
//                Layout.columnSpan: 3
//                Layout.row: 7
//                width: cbSelectKlant.width
//                height: cbSelectKlant.height

//                color: "#C0BEBD"

//                Label {
//                    id: lblDate
//                    text: dateHandler.date.toString("dd-MM-yyyy H:m:ss AP")
//                    color: "white"
//                    font.pixelSize: 16
//                    x: parent.width/2-lblDate.width/2
//                    y: parent.height/2-lblDate.height/2
//                }

//                Button {
//                    id: previousDate
//                    text: "<"
//                    font.pixelSize: 16
//                    width: parent.height
//                    height: parent.height
//                    contentItem: Text {
//                        text: parent.text
//                        font: parent.font
//                        opacity: parent.opacity
//                        color: "white"
//                        horizontalAlignment: Text.AlignHCenter
//                        verticalAlignment: Text.AlignVCenter
//                        elide: Text.ElideRight
//                    }
//                    background: Rectangle {
//                        anchors.fill: parent
//                        color: "#C0BEBD"
//                    }

//                    onClicked: {
//                        dateHandler.decreaseDate()
//                    }
//                }

//                Button {
//                    id: nextDate
//                    text: ">"
//                    font.pixelSize: 16
//                    width: parent.height
//                    height: parent.height
//                    x: parent.width-nextDate.width
//                    contentItem: Text {
//                        text: parent.text
//                        font: parent.font
//                        opacity: parent.opacity
//                        color: "white"
//                        horizontalAlignment: Text.AlignHCenter
//                        verticalAlignment: Text.AlignVCenter
//                        elide: Text.ElideRight
//                    }
//                    background: Rectangle {
//                        anchors.fill: parent
//                        color: "#C0BEBD"
//                    }
//                    onClicked: {
//                        dateHandler.increaseDate()
//                    }
//                }

//            }

//            Label {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 8
//                id: lblMaterialen
//                text: qsTr("Materialen Groep")
//                font.pointSize: 16
//            }

//            ComboBox {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 9
//                id: cbSelectMaterialen
//                implicitWidth: parent.width*0.6
//                implicitHeight: parent.height*0.05

//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }
//                textRole: "type"
//                model: PartTypeModel {
//                    list: partTypeList
//                }

//                Component.onCompleted: {
//                    partTypeHandler.fetchPartTypes(partTypeList)
//                }
//            }


//            TextField {
//                Layout.column: 2
//                Layout.columnSpan: 1
//                Layout.row: 10
//                id: cbSelectMaterialenItem
//                implicitWidth: parent.width*0.6
//                implicitHeight: parent.height*0.05
//                placeholderText: "Beschrijving"

//                onTextChanged: usedPartsHandler.specification = text

//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }
//            }

//            SpinBox {
//                Layout.column: 2
//                Layout.columnSpan: 1
//                Layout.row: 11
//                id: cbSelectMaterialenAantal
//                implicitWidth: (parent.width*0.3)
//                implicitHeight: parent.height*0.05

//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }

//                onValueChanged: {
//                    usedPartsHandler.partAmount = value;
//                }
//            }

//            ComboBox {
//                Layout.column: 1
//                Layout.row: 11
//                Layout.columnSpan: 5
//                id: cbSelectMaterialType
//                implicitWidth: (parent.width*0.2)
//                implicitHeight: parent.height*0.05
//                Layout.alignment: Qt.AlignHCenter

//                textRole: "type"
//                model: AmountTypeModel{
//                    list: amountTypeList
//                }

//                background: Rectangle {
//                    color: "white"
//                    border.color: "#6abc93"
//                    border.width: 3
//                    width: parent.width
//                    height: parent.height
//                }

//                Component.onCompleted: {
//                    amountTypeHandler.fetchAmountTypes(amountTypeList)
//                }
//            }

//            Rectangle {
//                id: btnAddMateriaal
//                y: parent.height*0.7
//                width: parent.width*0.3
//                Layout.column: 2
//                Layout.columnSpan: 1
//                Layout.row: 12
//                height: 40
//                color: "#6abc93"
//                radius: 10

//                Layout.alignment: Qt.AlignHCenter

//                Label {
//                    color: "#ffffff"
//                    text: qsTr("Toevoegen")
//                    font.pointSize: 12

//                    anchors.horizontalCenter: parent.horizontalCenter
//                    verticalAlignment: Text.AlignVCenter
//                    horizontalAlignment: Text.AlignHCenter
//                    anchors.verticalCenter: parent.verticalCenter
//                }

//                MouseArea {
//                    anchors.fill: btnAddMateriaal
//                    onClicked: {
//                        usedPartsHandler.addUsedParts(partTypeList, cbSelectMaterialen.currentIndex, amountTypeList, cbSelectMaterialType.currentIndex, projectList, cbSelectProject.currentIndex, usedPartsList)
//                        stackView.pop()
//                    }
//                }
//            }

//            Item {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 13
//                Layout.fillHeight: true
//            }

//            Item {
//                Layout.column: 2
//                Layout.columnSpan: 3
//                Layout.row: 14
//                Layout.fillHeight: true
//            }

//            Item {
//                Layout.column: 1
//                Layout.columnSpan: 3
//                Layout.row: 15
//                Layout.fillHeight: true
//            }

//            Item {
//                Layout.column: 3
//                Layout.row: 0
//                Layout.fillHeight: true
//                Layout.fillWidth: true
//            }
//        }

    }
}
