#include "Borrow.h"
#include <QDebug>

Borrow::Borrow(QObject *parent)
    : QObject{parent}
{}

bool Borrow::registerBorrow(int bookId, int userId) {
    qDebug() << "Registrando prestamo de libro" << bookId << "para usuario" << userId;

    // Aquí iría la lógica real, por ejemplo con QSqlQuery
    bool success = true; // Simulación

    if (success) {
        emit borrowSuccess();
        return true;
    } else {
        emit borrowFailed("No se pudo registrar el préstamo.");
        return false;
    }
}
