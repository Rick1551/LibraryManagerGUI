#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Book.h"
#include "LibraryManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Registrar instancia de LibraryManager para QML
    LibraryManager* manager = new LibraryManager();
    engine.rootContext()->setContextProperty("LibraryManager", manager);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("LibraryManagerGUI", "Main");


    return app.exec();
}
