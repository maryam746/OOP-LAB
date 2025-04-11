#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc = "")
        : deviceID(id), deviceName(name), location(loc), status(false) {}

    virtual void turnOn() {
        status = true;
    }

    virtual void turnOff() {
        status = false;
    }

    virtual void getStatus() const {
        cout << deviceName << " is " << (status ? "On" : "Off") << endl;
    }

    virtual void displayInfo() const {
        cout << "Device ID: " << deviceID << "\nName: " << deviceName
             << "\nLocation: " << location << "\nStatus: " << (status ? "On" : "Off") << endl;
    }

    virtual ~Device() {}
};

// Derived class: Light
class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string loc, int brightness, string color)
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel
             << "\nColor Mode: " << colorMode << endl;
    }
};

// Derived class: Thermostat
class Thermostat : public Device {
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id, string name, string loc, float temp, string m, float target)
        : Device(id, name, loc), temperature(temp), mode(m), targetTemperature(target) {}

    void getStatus() const override {
        cout << deviceName << " is set to " << mode << " mode, "
             << "Current Temp: " << temperature << "°C, "
             << "Target: " << targetTemperature << "°C" << endl;
    }
};

// Derived class: SecurityCamera
class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string loc, string res, bool nightVision)
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

    void turnOn() override {
        status = true;
        recordingStatus = true;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Resolution: " << resolution
             << "\nNight Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled")
             << "\nRecording: " << (recordingStatus ? "Yes" : "No") << endl;
    }
};

// Derived class: SmartPlug
class SmartPlug : public Device {
private:
    double powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, string loc, double power, int timer)
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        status = false;
        cout << deviceName << " turned off. Power used: " << powerConsumption << " kWh." << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption
             << " kWh\nTimer Setting: " << timerSetting << " mins" << endl;
    }
};

// Main function to test all devices
int main() {
    Light livingRoomLight(101, "Living Room Light", "Living Room", 75, "Warm White");
    Thermostat homeThermostat(102, "Nest Thermostat", "Hallway", 22.5, "Heating", 24.0);
    SecurityCamera frontCamera(103, "Front Door Camera", "Entrance", "1080p", true);
    SmartPlug coffeePlug(104, "Coffee Maker Plug", "Kitchen", 0.65, 30);

    livingRoomLight.turnOn();
    homeThermostat.turnOn();
    frontCamera.turnOn();
    coffeePlug.turnOn();

    cout << "\n--- Device Status & Info ---\n" << endl;
    livingRoomLight.displayInfo();
    cout << endl;
    homeThermostat.getStatus();
    homeThermostat.displayInfo();
    cout << endl;
    frontCamera.displayInfo();
    cout << endl;
    coffeePlug.turnOff(); // triggers logging power consumption
    coffeePlug.displayInfo();

    return 0;
}
