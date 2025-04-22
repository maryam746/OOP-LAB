#include <iostream>
using namespace std;


class Patient {
protected:
    string name;
    string id;
public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() = 0;
    virtual float calculateCost() = 0;

    virtual ~Patient() {}
};


class InPatient : public Patient {
    int daysAdmitted;
    float dailyRate;
public:
    InPatient(string n, string i, int days, float rate)
        : Patient(n, i), daysAdmitted(days), dailyRate(rate) {}

    void displayTreatment() override {
        cout << "InPatient: " << name << " (ID: " << id << ")\n";
        cout << "Admitted for " << daysAdmitted << " days.\n";
    }

    float calculateCost() override {
        return daysAdmitted * dailyRate;
    }
};


class OutPatient : public Patient {
    int consultations;
    float feePerConsultation;
public:
    OutPatient(string n, string i, int cons, float fee)
        : Patient(n, i), consultations(cons), feePerConsultation(fee) {}

    void displayTreatment() override {
        cout << "OutPatient: " << name << " (ID: " << id << ")\n";
        cout << "Consulted " << consultations << " times.\n";
    }

    float calculateCost() override {
        return consultations * feePerConsultation;
    }
};


int main() {
   
    InPatient inPatient("John Doe", "P001", 5, 1500.0f);
    OutPatient outPatient("Jane Smith", "P002", 3, 500.0f);

   
    Patient* patients[2];
    patients[0] = &inPatient;
    patients[1] = &outPatient;

    
    for (int i = 0; i < 2; ++i) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << "\n\n";
    }

    return 0;
}