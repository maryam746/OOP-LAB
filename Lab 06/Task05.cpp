#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}
    void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;
public:
    SmartPhone(int id, bool stat, float screen) : Device(id, stat), screenSize(screen) {}
    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id, bool stat, bool hrMonitor) : Device(id, stat), heartRateMonitor(hrMonitor) {}
    void displayDetails() {
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;
public:
    SmartWearable(int id, bool stat, float screen, bool hrMonitor, int steps)
        : Device(id, stat), SmartPhone(id, stat, screen), SmartWatch(id, stat, hrMonitor), stepCounter(steps) {}
    
    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    SmartWearable wearable(101, true, 5.5, true, 10000);
    wearable.displayDetails();
    return 0;
}
