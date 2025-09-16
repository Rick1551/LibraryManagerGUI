#ifndef BORROW_H
#define BORROW_H

#include <QObject>

class Borrow : public QObject
{
    Q_OBJECT
public:
    explicit Borrow(QObject *parent = nullptr);

signals:
};

#endif // BORROW_H
