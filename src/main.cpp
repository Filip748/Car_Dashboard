#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "DashboardController.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    DashboardController dashboardController;

    engine.rootContext()->setContextProperty("controller", &dashboardController);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("Car_Dashboard", "Main");

    return app.exec();
}
