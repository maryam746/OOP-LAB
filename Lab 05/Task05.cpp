#include<iostream>
using namespace std;


class Doctor{
    string name;
    string speciality;
    int experience;

    public:
    Doctor(string n, string s, int e){
        name=n;
        speciality=s;
        experience=e;
    }

    void displaydoctordetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Speciality: "<<speciality<<endl;
        cout<<"Experience: "<<experience<<" years"<<endl;
    }
};

class Hospital{
    Doctor **doctors;
    int num_doctors;
    string hospital_name;

    public:
    void assigndoctor(Doctor *d){
        if(num_doctors<10){
            
            doctors[num_doctors++] = d;
        }
        else{
            cout<<"No more doctors can be assigned"<<endl;
        }
        
    }

    Hospital(string name){
        hospital_name=name;
        doctors = new Doctor *[10];
        num_doctors=0;
    }

    void displayhospitaldetails(){
        cout<<"Hospital Name: "<<hospital_name<<endl;
        cout<<"Doctors: "<<endl;
        for(int i=0;i<num_doctors;i++){
            doctors[i]->displaydoctordetails();
        }
        }

        


};

int main(){
    Doctor d1("Dr. Aslam","Cardiologist",10);
    Doctor d2("Dr. Akram","Neurologist",15);
    Doctor d3("Dr. Ayesha","Dermatologist",5);
    Hospital h1("Agha khan Hospital");

    h1.assigndoctor(&d1);
    h1.assigndoctor(&d2);
    h1.assigndoctor(&d3);

    h1.displayhospitaldetails();



}
