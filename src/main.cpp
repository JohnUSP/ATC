#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "restaurantManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    RestaurantManager manager;
    engine.rootContext()->setContextProperty("restaurantManager", &manager);
    engine.load(QUrl::fromLocalFile("src/main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

