import QtQuick 2.15
import QtQuick.Controls 2.15


ApplicationWindow {
    visible: true
    width: 800
    height: 1080
    title: "Gestor de Biblioteca"
    property bool mostrarLista: false

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
                LibraryManager.addBook(titleField.text, authorField.text, 2023, isbnField.text)
                console.log("Libros actuales:", LibraryManager.listBooks())
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
    }

}
