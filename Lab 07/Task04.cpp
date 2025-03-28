#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactnumber;
    string address;

public:
    Person(string name, int age, string contactnumber, string address) : name(name), age(age), contactnumber(contactnumber), address(address) {};

    virtual void displayinfo()
    {
        cout << " Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Contact Number : " << contactnumber << endl;
        cout << "Address : " << address << endl;
    }

    virtual void updateinfo(string name, int age, string contactnumber, string address)
    {
        this->name = name;
        this->age = age;
        this->contactnumber = contactnumber;
        this->address = address;
    }

    virtual ~Person() {}
};

class Patient;

class Doctor : public Person
{
private:
    string specialization;
    int consultationfee;
    Patient *patientlist[10];

    public : 
    Doctor(string name, int age, string contactnumber, string address, string specialization, string consulatationfee

};

class Patient : public Person
{
    int patientID;
    string medicalhistory;
    Doctor *doctorassigned;

    public:
    Patient(string name, int age, string contactnumber, string address, int patientID, string medicalhistory, Doctor *doctorassigned) : Person(name, age, contactnumber, address), patientID(patientID), medicalhistory(medicalhistory), doctorassigned(doctorassigned) {}

};

class Nurse : public Person
{
private:
    string assignedward;
    string shifttimings;

public:
    Nurse(string name, int age, string contactnumber, string address, string assignedward, string shifttimings) : Person(name, age, contactnumber, address), assignedward(assignedward), shifttimings(shifttimings) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Assigned Ward : " << assignedward << endl;
        cout << "Shift Timings : " << shifttimings << endl;
    }
};

class Administrator : public Person
{
private:
    string department;
    double salary;

public:
    Administrator(string name, int age, string contacnumber, string address, string department, double salary) : Person(name, age, contactnumber, address), department(department), salary(salary) {}

    void displayinfo() override
    {
        Person ::displayinfo();
        cout << "Department : " << department << endl;
        cout << "Salary : " << salary << endl;
    }

    void updateInfo(string newName, int newAge, string newContact, string newAddress, string newDept, double newSalary)
    {
        Person::updateInfo(newName, newAge, newContact, newAddress);
        department = newDept;
        salary = newSalary;
    }

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Department : " << department << endl;
        cout << "Salary : " << salary << endl;
    }
};
int main()
{
    Patient p("John Doe", 30, "1234567890", "123 Main St", 101, "No known allergies", nullptr);
}
