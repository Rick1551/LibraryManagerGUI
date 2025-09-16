#ifndef USERS_H
#define USERS_H

#include <QObject>

class Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = nullptr);

signals:
};

#endif // USERS_H
