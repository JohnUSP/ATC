#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <QObject>
#include <QStringList>

class RestaurantManager : public QObject
{
    Q_OBJECT
public:
    explicit RestaurantManager(QObject *parent = nullptr);

    Q_INVOKABLE QStringList availableHours(const QString& csvPath, const QString& time);
};

#endif // RESTAURANTMANAGER_H

