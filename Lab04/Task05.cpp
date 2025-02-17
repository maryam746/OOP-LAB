#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string *brand;
    string *model;
    float *rentalPrice;
    bool *available;
    string *ID;
    float *totalPrice;
    

public:
    
    Car() {
        brand = new string("Unknown");
        model = new string ("Generic");
        rentalPrice = new float (50.0);
        available = new bool(true);
    }


    Car (string id){
        ID = new string(id);
        brand = new string("Unknown");
        model = new string ("Generic");
        rentalPrice = new float (50.0);
        available = new bool(true);
        totalPrice = new float(0.0);
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
    
    
    
    bool isAvailable() {
        return available;
    }

    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        *brand = newBrand;
        *model = newModel;
        *rentalPrice = newPrice;
    }


    
    

    
    void displayDetails() const {
        cout << "ID: " << *ID << endl;
        cout << "Brand: " << *brand << "\nModel: " << *model 
             << "\nRental Price: " << *rentalPrice 
             << "\nAvailable: " << (*available ? "Yes" : "No") << endl;
             cout<<"Total revenue: "<<*rentalPrice<<endl;
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
    Car *car1 = new Car("1001");
    car1->updateDetails("Toyota", "Corolla", 50.0);
    car1->rentcar(3,5000);
   
    car1->displayDetails();
    cout<<endl;

    Car *car2 = new Car("1003");
    cout<<endl;
    
    car2->updateDetails("Honda", "Civic", 60.0);
car2->rentcar(5,5000);
    car2->displayDetails();

    cout<<endl;

    delete car1;
    cout <<"Car1 deleted"<<endl;
    delete car2;
    cout <<"Car2 deleted"<<endl;
    
    return 0;
}

