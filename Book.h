#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString Author READ getAuthor WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QString isbn READ getIsbn WRITE setIsbn NOTIFY isbnChanged)

    QString m_title;
    QString m_author;
    QString m_isbn;

public:
    explicit Book(QObject *parent = nullptr);
    Book(const QString& title, const QString& author, const QString& isbn, QObject* parent = nullptr);

    QString getTitle() const;
    void setTitle(const QString& t);

    QString getAuthor() const;
    void setAuthor(const QString& a);

    QString getIsbn() const;
    void setIsbn(const QString& i);

signals:
    void titleChanged();
    void authorChanged();
    void isbnChanged();
};

#endif // BOOK_H
