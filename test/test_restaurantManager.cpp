#include <QtTest>
#include "../src/restaurantManager.h"

class TestRestaurantManager : public QObject {
    Q_OBJECT

private slots:
    void horarioNoMeio();
    void horarioFora();
    void horarioNoLimiteSup();
    void horarioNoLimiteInf();
};

void TestRestaurantManager::horarioNoMeio() {
    RestaurantManager manager;
    QStringList res = manager.availableHours("test_restaurant-hours.csv", "12:00");
    QVERIFY(!res.isEmpty()); // espera-se pelo menos um restaurante aberto
}

void TestRestaurantManager::horarioFora() {
    RestaurantManager manager;
    QStringList res = manager.availableHours("test_restaurant-hours.csv", "03:00");
    QVERIFY(res.isEmpty()); // espera-se nenhum restaurante aberto
}

void TestRestaurantManager::horarioNoLimiteInf() {
    RestaurantManager manager;
    QStringList res = manager.availableHours("test_restaurant-hours.csv", "09:00"); // Depende dos dados
    QVERIFY(!res.isEmpty()); // espera-se pelo menos um restaurante aberto
}

void TestRestaurantManager::horarioNoLimiteSup() {
    RestaurantManager manager;
    QStringList res = manager.availableHours("test_restaurant-hours.csv", "23:00"); // Depende dos dados
    QVERIFY(res.isEmpty()); // espera-se nenhum restaurante aberto
}

QTEST_MAIN(TestRestaurantManager)
#include "test_restaurantManager.moc"

