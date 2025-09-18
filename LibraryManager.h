#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <QWidget>
#include <QObject>
#include <QStringList>
#include "Book.h"

class LibraryManager : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryManager(QWidget *parent = nullptr);

    Q_INVOKABLE bool addBook(const QString& title, const QString& author, int year, const QString& isbn);
    Q_INVOKABLE QStringList listBooks() const;

signals:

private:
    QList<Book*> m_books;
};

#endif // LIBRARYMANAGER_H
