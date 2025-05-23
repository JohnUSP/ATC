import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Restaurantes Abertos"
    color: "#3399ff"

    ListModel {
        id: resultadoModel
    }

    ScrollView {
        id: scrollArea
        anchors.fill: parent
        clip: true
        ScrollBar.vertical.policy: ScrollBar.AsNeeded

        contentItem: Item {
            width: scrollArea.width
            height: scrollArea.height

            Column {
                id: columnContent
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 16

                Row {
                    spacing: 10
                    anchors.horizontalCenter: parent.horizontalCenter

                    TextField {
                        id: hourInput
                        placeholderText: "HH:MM"
                        font.pixelSize: 20
                        width: 120
                        height: 40
                        horizontalAlignment: Text.AlignHCenter
                        inputMask: "00:00;-"
																								Keys.onReturnPressed: {
        																				buscarButton.clicked()
    																							}
																								Keys.onRightPressed: {
    																								if (cursorPosition < text.length) {
																																				cursorPosition += 1
																																}
																												}

                        background: Rectangle {
                            radius: 4
                            color: "white"
                            border.color: "#cccccc"
                        }
                    }

                    Button {
                    				id: buscarButton
                        text: "Buscar"
                        width: 120
                        height: 40
                        font.pixelSize: 20

                        onClicked: {
                            resultadoModel.clear()

                            const horario = hourInput.text.trim()
                            const regex = /^([01]?[0-9]|2[0-3]):[0-5][0-9]$/

                            if (!regex.test(horario)) {
                                resultadoModel.append({ nome: "Formato inválido. Use HH:MM (24h)." })
                                return
                            }

                            let lista = restaurantManager.availableHours("data/restaurant-hours.csv", horario)
                            lista.sort((a, b) => a.localeCompare(b))

                            for (let i = 0; i < lista.length; ++i) {
                                resultadoModel.append({ nome: lista[i] })
                            }

                            if (lista.length === 0) {
                                resultadoModel.append({ nome: "Nenhum restaurante encontrado." })
                            }
                        }
                    }
                }

                Rectangle {
                    width: 400
                    height: 900
                    radius: 6
                    border.color: "#cccccc"
                    border.width: 1
                    color: "#ffffff"
                    anchors.horizontalCenter: parent.horizontalCenter

                    ScrollView {
                        anchors.fill: parent
                        clip: true
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                        ScrollBar.horizontal.policy: ScrollBar.AsNeeded

                        ListView {
                            id: listaRestaurantes
                            width: parent.width
                            height: parent.height
                            model: resultadoModel
                            spacing: 10

                            delegate: Rectangle {
                                width: ListView.view.width
                                height: 40
                                radius: 4
                                color: "#f8f8f8"
                                border.color: "#cccccc"
                                border.width: 1

                                Text {
                                    anchors.centerIn: parent
                                    text: nome
                                    font.pixelSize: 18
                                    color: "#333333"
                                    wrapMode: Text.WordWrap
                                    horizontalAlignment: Text.AlignHCenter
                                    width: parent.width * 0.95
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

