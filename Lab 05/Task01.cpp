#include<iostream>
using namespace std;

class Apartment{
    int ID;
    string address;
    string *name = new string;

    public:

    Apartment(int id, string address, string ownername): ID(id), address(address){
    name = new string (ownername);
    }

    Apartment (const Apartment & a1){
        ID = a1.ID;
        address = a1.address;
        name = new string (*a1.name);
    }

    void display(){
        cout << "Apartment id:"<<ID<<endl;
        cout <<"Address:"<<address<<endl;
        cout <<"Owner Name:"<<*name<<endl;
    }

    ~Apartment(){
        delete name;
    }
};

int main(){
    Apartment a1(1, "Gulshan", "Ali");
    a1.display();
    Apartment a2=a1;

    a2.display();
    
    a2.display();
    return 0;

}
