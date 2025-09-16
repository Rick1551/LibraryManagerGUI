import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "Gestor de Biblioteca"

    Column {
        anchors.centerIn: parent
        spacing: 12

        TextField {
            id: titleField
            placeholderText: "Título del libro"
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
                libraryManager.addBook(titleField.text, authorField.text, 2023, isbnField.text)
                titleField.text = ""
                authorField.text = ""
                isbnField.text = ""
            }
        }

        ListView {
            width: parent.width * 0.9
            height: 300
            model: libraryManager.listBooks()
            delegate: Text {
                text: modelData
                font.pixelSize: 16
            }
        }
    }
}
