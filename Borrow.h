#ifndef BORROW_H
#define BORROW_H

#include <QObject>

class Borrow : public QObject
{
    Q_OBJECT
public:
    explicit Borrow(QObject *parent = nullptr); // Función accesible desde QML

    Q_INVOKABLE bool registerBorrow(int bookId, int userId);

signals:
    void borrowSuccess();
    void borrowFailed(QString reason);
};

#endif // BORROW_H
