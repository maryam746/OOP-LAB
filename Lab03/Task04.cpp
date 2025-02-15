#include <iostream>
using namespace std;

class Car
{
    string brand;
    string model;
    float fuelcapacity;
    float currentfuelevel;
    float consumptionperkm;

public:
   
    Car(string b, string mod, float cap, float consum)
    {
        brand = b;
        model = mod;
        fuelcapacity = cap;
        currentfuelevel = cap;
        consumptionperkm = consum;  
    }

    void drive(float dist)
    {
        float fuelneeded = dist * consumptionperkm;
        if (fuelneeded > currentfuelevel)
        {
            cout << "Fuel is not enough to drive " << dist << " km. Please refuel." << endl;
        }
        else
        {
            currentfuelevel -= fuelneeded;
            cout << "Car has driven " << dist << " km." << endl;
        }
        checkfuelstatus();
    }

    void refuel(float fuel)
    {
        if (fuel <= 0)
        {
            cout << "Invalid fuel amount!" << endl;
            return;
        }

        if (fuel + currentfuelevel > fuelcapacity)
        {
            float addedfuel = fuelcapacity - currentfuelevel;
            currentfuelevel = fuelcapacity;
            cout << "Tank is full. Added " << addedfuel << " liters." << endl;
        }
        else
        {
            currentfuelevel += fuel;
            cout << "Refueled " << fuel << " liters. Current fuel level: " << currentfuelevel << " liters." << endl;
        }
    }

    void checkfuelstatus()
    {
        cout << "Current fuel level: " << currentfuelevel << " liters." << endl;
        if (currentfuelevel < 2)
        {
            cout << "Warning: Fuel is critically low! Refuel immediately." << endl;
        }
    }
};

int main()
{
    Car car1("Toyota", "Aqua", 36, 0.5);
    car1.drive(50);
    car1.refuel(2);
    car1.drive(30);
    car1.refuel(10);

    return 0;
}
