#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    float rentalPrice;
    bool available;
    string ID;
    float totalPrice;

public:
    Car(string id) : ID(id), brand("Unknown"), model("Generic"), rentalPrice(50.0), available(true), totalPrice(0.0) {}

    float rentcar(int days, float rent)
    {
        if (available)
        {

            rentalPrice = rent;
            totalPrice = days * rentalPrice;
            cout << "Car rented successfully!" << endl;
            cout << "Total Price: " << totalPrice << endl;
            available = false;
            return totalPrice;
        }
        else
        {
            cout << "Sorry, this car is already rented." << endl;
            return 0;
        }
    }

    bool isAvailable()
    {
        return available;
    }

    void updateDetails(const string &newBrand, const string &newModel, double newPrice)
    {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }

    void displayDetails() const
    {
        cout << "ID: " << ID << endl;
        cout << "Brand: " << brand << "\nModel: " << *model
             << "\nRental Price: " << rentalPrice
             << "\nAvailable: " << (available ? "Yes" : "No") << endl;
        cout << "Total revenue: " << rentalPrice << endl;
    }

    
};

int main()
{
    Car *car1 = new Car("1001");
    car1->updateDetails("Toyota", "Corolla", 50.0);
    car1->rentcar(3, 5000);

    car1->displayDetails();
    cout << endl;

    Car *car2 = new Car("1003");
    cout << endl;

    car2->updateDetails("Honda", "Civic", 60.0);
    car2->rentcar(5, 5000);
    car2->displayDetails();

    cout << endl;

    
    return 0;
}
