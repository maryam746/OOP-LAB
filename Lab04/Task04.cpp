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
        model = new string ("Generic");
        rentalPrice = new float (50.0);
        available = new bool(true);
        totalPrice = new float(0.0);
    }
    
    
    
    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        *brand = newBrand;
        *model = newModel;
        *rentalPrice = newPrice;
    }

    
    bool isAvailable() {
        return available;
    }


    float rentcar(int days,float rent){
        if(available){

            *rentalPrice = rent;
            *totalPrice = days * *rentalPrice;
            cout << "Car rented successfully!" << endl;
            cout << "Total Price: " << *totalPrice << endl;
            *available = false;
            return *totalPrice;
        } else {
            cout << "Sorry, this car is already rented." << endl;
            return 0;
        }

    }

  

    
    void displayDetails() const {
        cout << "Brand: " << *brand << "\nModel: " << *model 
             << "\nRental Price: " << *rentalPrice 
             << "\nAvailable: " << (*available ? "Yes" : "No") 
             <<"\nTotal Price: " << *totalPrice << endl;
    }


    ~Car() {
        delete brand;
        delete model;
        delete rentalPrice;
        delete available;
    }
};

int main() {
    Car *car1 = new Car();
    car1->updateDetails("Toyota", "Corolla", 50.0);
    car1->displayDetails();
    cout<<endl;
    car1->rentcar(5,5000);
    car1->displayDetails();


    Car *car2 = new Car();
    car2->updateDetails("Honda", "Civic", 60.0);
    cout<<endl;
    car2->displayDetails();
    car2->rentcar(2,3000);
    car2->displayDetails();

    delete car1;

    delete car2;
    
    return 0;
}
