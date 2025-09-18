import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 1080
    title: "Gestor de Biblioteca"

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
                titleField.text = ""
                authorField.text = ""
                isbnField.text = ""
            }
        }

        ListView {
            width: parent.width * 0.9
            height: 300
            model: LibraryManager.listBooks()
            delegate: Text {
                text: modelData
                font.pixelSize: 16
            }
        }
    }

}
