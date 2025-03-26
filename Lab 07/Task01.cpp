#include <iostream>
using namespace std;

class Device
{
private:
    int deviceID;
    string devicename;

protected:
    bool status;

public:
    Device(int id, string name, bool status) : deviceID(id), devicename(name), status(status) {}
    virtual void turnOn()
    {
        status = true;
    }
    virtual void turnOff()
    {
        status = false;
    }
    virtual void getstatus()
    {
        if (status == true)
        {
            cout << "ON" << endl;
        }
        else
        {
            cout << "OFF" << endl;
        }
    }

    virtual void displayinfo()
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << devicename << endl;
        cout << "Device Status: ";
        getstatus();
    }
    virtual ~Device() {}
};

class Light : public Device
{
private:
    int brightnesslevel;
    string colormode;

public:
    Light(int id, string name, bool status, int brightness, string color) : Device(id, name, status), brightnesslevel(brightness), colormode(color) {}

    void displayinfo() override
    {
        Device::displayinfo();
        cout << "Brightness Level: " << brightnesslevel << endl;
        cout << "Color Mode: " << colormode << endl;
    }
};

class Thermostat : public Device
{
private:
    float temperature;
    string mode;
    float targettemperature;

public:
    Thermostat(int id, string name, bool status, float temp, string mode, float targettemp) : Device(id, name, status), temperature(temp), mode(mode), targettemperature(targettemp) {}

    void getstatus() override
    {
        Device::getstatus();
        cout << "Temperature: " << temperature << endl;
    }
};

class Securitycamera : public Device
{

private:
    bool recordingstatus;
    int resolution;
    bool nightvision;

public:
    Securitycamera(int id, string name, bool status, bool recording, int res, bool night) : Device(id, name, status), recordingstatus(recording), resolution(res), nightvision(night) {}
    void turnOn() override
    {
        status = true;
        recordingstatus = true;
        cout << "Recording has been started" << endl;
    }
};

class SmartPlug : public Device
{
private:
    float powerconsumption;
    int timersetting;
    bool power;

public:
    SmartPlug(int id, string name, bool status, float power, int time) : Device(id, name, status), powerconsumption(power), timersetting(time) {}

    void turnOff() override
    {
        status = false;
        power = false;
        cout << "Device has been turned off" << endl;
    }
};

int main()
{

    Light l1(1, "Light", true, 100, "White");
    l1.displayinfo();

    Thermostat t1(2, "Thermostat", true, 25, "Cool", 20);
    t1.displayinfo();

    Securitycamera s1(3, "Security Camera", true, true, 1080, true);
    s1.displayinfo();

    SmartPlug sp1(4, "Smart Plug", true, 100, 5);
    sp1.displayinfo();

    return 0;
}
