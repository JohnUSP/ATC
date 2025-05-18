#include "restaurantManager.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>

RestaurantManager::RestaurantManager(QObject *parent)
    : QObject(parent)
{}

QStringList RestaurantManager::availableHours(const QString& csvPath, const QString& inputTimeStr) {
    QStringList openRestaurants;
    QTime inputTime = QTime::fromString(inputTimeStr, "HH:mm");
    if (!inputTime.isValid()) return openRestaurants;

    QFile file(csvPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return openRestaurants;

    QTextStream in(&file);
    QString header = in.readLine(); // descarta cabeçalho

    while (!in.atEnd()) {
        QStringList parts = in.readLine().split(',');
        if (parts.size() != 2) continue;

        QString name = parts[0].trimmed();
        QStringList timeRange = parts[1].trimmed().split('-');
        if (timeRange.size() != 2) continue;

        QTime openTime = QTime::fromString(timeRange[0].trimmed(), "H:mm");
        if (!openTime.isValid()) openTime = QTime::fromString(timeRange[0].trimmed(), "HH:mm");

        QTime closeTime = QTime::fromString(timeRange[1].trimmed(), "H:mm");
        if (!closeTime.isValid()) closeTime = QTime::fromString(timeRange[1].trimmed(), "HH:mm");

        if (!openTime.isValid() || !closeTime.isValid()) continue;

        bool isOpen =
            (openTime <= closeTime && inputTime >= openTime && inputTime < closeTime) ||
            (openTime > closeTime && (inputTime >= openTime || inputTime < closeTime));

        if (isOpen)
            openRestaurants.append(name);
    }

    return openRestaurants;
}

