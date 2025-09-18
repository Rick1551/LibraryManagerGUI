import QtQuick 2.15
import QtQuick.Controls 2.15


ApplicationWindow {
    visible: true
    width: 800
    height: 1080
    title: "Gestor de Biblioteca"
    property bool mostrarLista: false
    property string resultadoDialogText: ""

    Column {
        anchors.centerIn: parent
        spacing: 12
        width: parent.width * 0.9

        TextField {
            id: titleField
            placeholderText: "Titulo del libro"
            width: parent.width * 0.9
        }

        TextField {
            id: authorField
            placeholderText: "Autor"
            width: parent.width * 0.9
        }

        TextField {
            id: isbnField
            placeholderText: "ISBN"
            width: parent.width * 0.9
        }

        Button {
            text: "Agregar libro"
            width: parent.width * 0.5
            onClicked: {
                var exito = LibraryManager.addBook(titleField.text, authorField.text, 2023, isbnField.text)
                console.log(exito)
                if (exito) {
                    resultadoDialogText = "Libro agregado correctamente."
                } else {
                    resultadoDialogText = "El libro ya existe en la biblioteca."
                }
                resultadoDialog.open()
                titleField.text = ""
                authorField.text = ""
                isbnField.text = ""
            }
        }

        ListView {
            visible: mostrarLista
            width: parent.width * 0.9
            height: 300
            model: LibraryManager.listBooks()
            delegate: Text {
                text: modelData
                font.pixelSize: 16
            }
        }

        Button {
            text: "Mostrar libros"
            onClicked: mostrarLista = !mostrarLista
        }

        Dialog {
            id: resultadoDialog
            title: "Resultado"
            width: parent.width * 0.5
            modal: true
            standardButtons: Dialog.Ok
            onAccepted: resultadoDialog.close()
            contentItem: Label {
                text: resultadoDialogText
                wrapMode: Text.WordWrap
            }
        }



    }

}
