#include<iostream>
using namespace std;

class Vehicle{
    string brand;
    int speed;
    
    public:
    Vehicle(string b,int s):brand(b),speed(s){}

    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;

    }
};

class Car:public Vehicle{
    int seats;
    public:
    Car(string b,int s,int seats):Vehicle(b,s),seats(seats){}

    void display(){
        Vehicle::display();
        cout<<"Seats: "<<seats<<endl;
    }
};

class electriccar:public Car{
    int battery_life;
    public:
    electriccar(string b,int s,int seats,int battery_life):Car(b,s,seats),battery_life(battery_life){}

    void display(){
        Car::display();
        cout<<"Battery Life: "<<battery_life<<endl;
    }
};





int main(){

    electriccar e("Tesla",120,5,100);
    e.display();
    return 0;


}
