#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "AutonomousCar";
    string extraData = "Software:3.5";

    if (type == "AutonomousCar") {
        size_t pos = extraData.find(":");
        if (pos != string::npos) {
            float version = stof(extraData.substr(pos + 1));
            cout << "Software Version: " << version << endl;
        }
    } else if (type == "ElectricVehicle") {
        extraData = "Battery:75";
        size_t pos = extraData.find(":");
        if (pos != string::npos) {
            int battery = stoi(extraData.substr(pos + 1));
            cout << "Battery Capacity: " << battery << endl;
        }
    }
    return 0;
}