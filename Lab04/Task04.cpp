#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string *brand;
    string *model;
    float *rentalPrice;
    bool *available;
    float *totalPrice;

public:
    Car() {
        brand = new string("Unknown");
        model = new string("Generic");
        rentalPrice = new float(50.0);
        available = new bool(true);
        totalPrice = new float(0.0);
    }

    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        *this->brand = newBrand;
        *this->model = newModel;
        *this->rentalPrice = newPrice;
    }

    bool isAvailable() const {
        return *this->available;
    }

    float rentCar(int days, float rent) {
        if (*this->available) {
            *this->rentalPrice = rent;
            *this->totalPrice = days * *this->rentalPrice;

            cout << "Car rented successfully!" << endl;
            cout << "Total Price: " << *this->totalPrice << endl;

            *this->available = false;  
            return *this->totalPrice;
        } else {
            cout << "Sorry, this car is already rented." << endl;
            return 0;
        }
    }

    void displayDetails() const {
        cout << "Brand: " << *this->brand 
             << "\nModel: " << *this->model 
             << "\nRental Price: " << *this->rentalPrice 
             << "\nAvailable: " << (*this->available ? "Yes" : "No") 
             << "\nTotal Price: " << *this->totalPrice 
             << endl;
    }

    ~Car() {
        delete brand;
        delete model;
        delete rentalPrice;
        delete available;
        delete totalPrice;
    }
};

int main() {
    Car *car1 = new Car();
    car1->updateDetails("Toyota", "Corolla", 50.0);
    car1->displayDetails();
    
    cout << endl;
    car1->rentCar(5, 5000);
    car1->displayDetails();

    cout << "\n-----------------------\n";

    Car *car2 = new Car();
    car2->updateDetails("Honda", "Civic", 60.0);
    car2->displayDetails();
    
    cout << endl;
    car2->rentCar(2, 3000);
    car2->displayDetails();

    delete car1;
    delete car2;
}
