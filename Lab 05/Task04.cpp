#include<iostream>
using namespace std;


class AlarmSystem{
    string securitylevel;
     public:
        AlarmSystem(string level){
            securitylevel=level;

        }

        void  display(){
            cout<<"Security Level: "<<securitylevel<<endl;
        }

        ~AlarmSystem(){
            cout<<"Alarm system destroyed"<<endl;
        }

};

class Smarthome{
AlarmSystem alarm;
string id;

public:
Smarthome(string id, string level):alarm(level),id(id){}
void display(){
    cout<<"ID: "<<id<<endl;
    alarm.display();
}

~Smarthome(){
    cout<<"Smart home is destroyed"<<endl;
}

};

 int main(){
    Smarthome home("1234","High");
    home.display();


    return 0;
 }
