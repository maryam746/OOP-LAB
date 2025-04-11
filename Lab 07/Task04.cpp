#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber
             << "\nAddress: " << (address.empty() ? "N/A" : address) << endl;
    }

    virtual void updateInfo(string newInfo, string type) {
        if (type == "address") {
            address = newInfo;
        } else if (type == "contact") {
            contactNumber = newInfo;
        }
    }

    virtual ~Person() {}
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, int id, string history, string doctor)
        : Person(n, a, contact), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory
             << "\nAssigned Doctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    Patient* patientsList[10];
    int numPatients;

public:
    Doctor(string n, int a, string contact, string specialization, double fee)
        : Person(n, a, contact), specialization(specialization), consultationFee(fee), numPatients(0) {}

    void addPatient(Patient* patient) {
        if (numPatients < 10) {
            patientsList[numPatients++] = patient;
        } else {
            cout << "Patient list is full!" << endl;
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: $" << consultationFee << endl;
        cout << "Patients: ";
        for (int i = 0; i < numPatients; ++i) {
            cout << patientsList[i]->name << " ";
        }
        cout << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift)
        : Person(n, a, contact), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string dept, double sal)
        : Person(n, a, contact), department(dept), salary(sal) {}

    void updateInfo(string newInfo, string type) override {
        if (type == "department") {
            department = newInfo;
        } else if (type == "salary") {
            salary = stod(newInfo);
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << endl;
    }
};

int main() {
    Patient p1("John Doe", 45, "123-456-7890", 1001, "Diabetes", "Dr. Smith");
    Doctor d1("Dr. Smith", 50, "987-654-3210", "Cardiologist", 200.0);
    Nurse n1("Nancy", 30, "555-123-4567", "Cardiology", "9 AM - 5 PM");
    Administrator a1("Anna", 40, "555-987-6543", "HR", 5000.0);

    d1.addPatient(&p1);

    cout << "--- Doctor Info ---\n";
    d1.displayInfo();

    cout << "\n--- Patient Info ---\n";
    p1.displayInfo();

    cout << "\n--- Nurse Info ---\n";
    n1.displayInfo();

    cout << "\n--- Administrator Info ---\n";
    a1.displayInfo();

    return 0;
}
