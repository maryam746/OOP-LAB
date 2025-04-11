#include <iostream>
#include <string>

using namespace std;

class Car;

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice);
    void displayCar(const Car& car);
};

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) {
        model = m;
        price = p;
    }

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
}

void InventoryManager::displayCar(const Car& car) {
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    } else if (car1.price < car2.price) {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    } else {
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
}

int main() {
    Car car1("Toyota Corolla", 25000);
    Car car2("Honda Civic", 24000);

    InventoryManager manager;

    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car2, 26000);

    cout << "\nAfter price update:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    cout << "\nPrice Comparison:\n";
    comparePrice(car1, car2);

    return 0;
}


