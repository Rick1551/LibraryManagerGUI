#include "Book.h"

Book::Book(QObject *parent)
    : QObject(parent), m_title(""), m_author(""), m_isbn("")
{}

Book::Book(const QString& title, const QString& author, const QString &isbn, QObject *parent)
: QObject(parent), m_title(title), m_author(author), m_isbn(isbn) {}


QString Book::getTitle() const {
    return m_title;
}

void Book::setTitle(const QString& t) {
    if (m_title != t) {
        m_title = t;
        emit titleChanged();
    }
}

QString Book::getAuthor() const {
    return m_author;
}

void Book::setAuthor(const QString& a) {
    if (m_author != a) {
        m_author = a;
        emit authorChanged();
    }
}

QString Book::getIsbn() const {
    return m_isbn;
}

void Book::setIsbn(const QString& i) {
    if (m_isbn != i) {
        m_isbn = i;
        emit isbnChanged();
    }
}
