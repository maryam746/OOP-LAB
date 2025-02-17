#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string *brand;
    string *model;
    float *rentalPrice;
    bool *available;

public:
    
    Car() {
        brand = new string("Unknown");
        model = new string ("Generic");
        rentalPrice = new float (50.0);
        available = new bool(true);
    }
    
    Car (const Car& car) {
        brand = new string (*car.brand);
        model = new string (*car.model);
        rentalPrice = new float (*car.rentalPrice);
        available = new bool(*car.available);
    }
    
    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        *brand = newBrand;
        *model = newModel;
        *rentalPrice = newPrice;
    }

    
    bool isAvailable() {
        return available;
    }

    
    void rentCar() {
        if (available) {
            *available = false;
            cout << "Car rented successfully!" << endl;
        } else {
            cout << "Sorry, this car is already rented." << endl;
        }
    }

    
    void displayDetails() const {
        cout << "Brand: " << *brand << "\nModel: " << *model 
             << "\nRental Price: " << *rentalPrice 
             << "\nAvailable: " << (*available ? "Yes" : "No") << endl;
    }


    ~Car() {
        delete brand;
        delete model;
        delete rentalPrice;
        delete available;

        cout<<"Destructor called"<<endl;
    }
};

int main() {
    Car *car1 = new Car();
    car1->displayDetails();
    cout<<endl;
    
    car1->updateDetails("Toyota", "Corolla", 50.0);
    car1->displayDetails();
    cout<<endl;

    Car *car2 = new Car(*car1);
    car2->displayDetails();
    cout<<endl;
    
   car1->updateDetails("Honda", "Civic", 60.0);
    car1->displayDetails();
    cout<<endl;
    car2->displayDetails();

    cout<<endl;

    delete car1;
    cout <<"Car1 deleted"<<endl;
    delete car2;
    cout <<"Car2 deleted"<<endl;
    
    return 0;
}
