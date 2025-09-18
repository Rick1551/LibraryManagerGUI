#include "LibraryManager.h"

LibraryManager::LibraryManager(QObject *parent)
    : QObject{parent}
{
    addBook("Cien años de soledad", "Gabriel García Márquez", 1967, "978-0307474728");
    addBook("El Principito", "Antoine de Saint-Exupéry", 1943, "978-0156013987");
}

bool LibraryManager::addBook(const QString& title, const QString& author, int year, const QString& isbn) {
    //Verificar si ya existe un libro con mismo titulo y autor
    for (const Book* book : std::as_const(m_books)) {
        if(book->getTitle() == title && book->getAuthor() == author) {
            qDebug() << "Libro duplicado: " << title << "de" << author;
            return false;
        }
    }

    Book* newBook = new Book(title, author, isbn, this);
    m_books.append(newBook);
    return true;
}

QStringList LibraryManager::listBooks() const {
    QStringList result;
    for (const Book* book : m_books) {
        result << book->getTitle() + " - " + book->getAuthor() + " (" + book->getIsbn() + ")";
    }
    return result;
}
