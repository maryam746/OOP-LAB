#include<iostream>
using namespace std;

class Shipment{
    protected:
    double weight;
    string trackingnumber;

    public:
    virtual void estimateddeliverytime() = 0;
    virtual void showdetails() =0;


};


class Airfreight: public Shipment{
    public:
    void estimateddeliverytime() override {
        cout << "Estimated delivery time for Airfreight: 2-3 days" << endl;
    }

    void showdetails() override {
        cout << "Airfreight shipment details:" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Tracking number: " << trackingnumber << endl;
    }
};

class Groundshipment : public Shipment{
    public:
    void estimateddeliverytime() override {
        cout << "Estimated delivery time for Ground shipment: 5-7 days" << endl;
    }

    void showdetails() override {
        cout << "Ground shipment details:" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Tracking number: " << trackingnumber << endl;
    }
};


int main(){
    Airfreight airShipment;
    Groundshipment groundShipment;

    Shipment* shipments[2];
    shipments[0] = &airShipment;
    shipments[1] = &groundShipment;
    for (int i = 0; i < 2; ++i) {
        shipments[i]->estimateddeliverytime();
}
}