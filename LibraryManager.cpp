#include "LibraryManager.h"

LibraryManager::LibraryManager(QWidget *parent)
    : QWidget{parent} {}

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
