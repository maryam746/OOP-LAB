#include<iostream>
using namespace std;


class weatherseason{
    protected:
    float temperature;
public:
virtual void readdata() =0;
virtual void displayreport() =0;


};

class Thermometer:public weatherseason {
    public:
    void readdata () override {
        cout << " Reading data from thermometer"<<endl;
        temperature = 25.0; 

    }

    void displayreport () override {
        cout << "Temperature from thermometer: " << temperature << " degrees Celsius" << endl;
    }
};

class Barometer:public weatherseason {
    public:
    void readdata () override {
        cout << " Reading data from barometer"<<endl;
        temperature = 30.0; 
    }

    void displayreport () override {
        cout << "Temperature from barometer: " << temperature << " degrees Celsius" << endl;
    }
};



int main(){
    Thermometer t;
    Barometer b;

    weatherseason* sensors[2];

    
    sensors[0] = &t;
    sensors[1] = &b;

   
    for (int i = 0; i < 2; ++i) {
        sensors[i]->readdata();
        sensors[i]->displayreport();
    }
}