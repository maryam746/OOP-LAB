#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    float rentalPrice;
    bool availability;
    float totalPrice;

public:
    Car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        availability = true;
        totalPrice = 0.0;
    }

    // Parameterized constructor
    Car(string b, string m, float price)
    {
        brand = b;
        model = m;
        rentalPrice = price;
        availability = true;
        totalPrice = 0.0;
    }

    bool isAvailable()
    {
        return availability;
    }

    float rentCar(int days)
    {
        if (availability)
        {
            totalPrice = applyDiscount(days, rentalPrice * days);
            availability = false;
            cout << "Car rented successfully!" << endl;
            cout << "Total Price after discount (if applicable): $" << totalPrice << endl;
            return totalPrice;
        }
        else
        {
            cout << "Sorry, this car is already rented." << endl;
            return 0;
        }
    }

    float applyDiscount(int days, float price)
    {
        if (days > 10)
        {
            price -= price * 0.10;
        }
        else if (days > 5)
        {
            price -= price * 0.05;
        }
        return price;
    }

    void update(string b, string m, float price)
    {
        brand = b;
        model = m;
        rentalPrice = price;
    }

    void display()
    {
        cout << "Brand: " << brand << "\nModel: " << model
             << "\nRental Price: $" << rentalPrice;
        
    }
};

    int main()
    {
        Car car1;
        car1.update("Toyota", "Corolla", 100.0);
        car1.applyDiscount(15, 1500.0);
        car1.display();
        cout << endl;
    }
