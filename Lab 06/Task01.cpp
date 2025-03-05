#include<iostream>
using namespace std;

class Employee{
    string name;
    float salary;

    public:
    Employee(string n ,float s):name(n),salary(s){}
    
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
    }


    
};

class Manager: public Employee{
    float bonus;

    public:
    Manager(string n,float s,float b):Employee(n,s),bonus(b){}

    void display(){
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
    }
};


int main(){

    Manager Hr("Ali",50000,10000);
    Hr.display();
    return 0;

}

