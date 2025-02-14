#include<iostream>
using namespace std;

class Fitnesstracker{

string username;
int dailygoal;
int stepstaken=0;
float caloriesburned =0.0;

public:
 void logsteps(int steps){

if(steps>0){
    stepstaken+=steps;
    caloriesburned += calculatecalories(steps);
    cout<<"Steps logged successfully"<<steps<<endl;    

}
else{
    cout<<"Invalid step count";

}
 }


 Fitnesstracker(string name,int goal){
    username=name;
    dailygoal=goal;
 }

 float calculatecalories(int steps){
    return 0.4 * stepstaken;
   
 }

 void displayprogress(){

    cout<<"Fitness Progress:"<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Daily step goal:"<<dailygoal<<endl;
    cout<<"Calories burned:"<<caloriesburned<<endl;
    

    if(stepstaken >= dailygoal){
        cout<<"Congratulations, you have reached your daily step goal!";
    }
    else{
        cout<<"You need "<<(dailygoal - stepstaken)<<"to meet you daily goal"<<endl;

    }

 }


};


int main (){
    string name;
    int goal;

    cout<<"Enter name:";
    getline(cin,name);
    cout<<"Enter Daily step Goal:";
    cin>>goal;

    Fitnesstracker laiba(name,goal);

    laiba.logsteps(5000);
    laiba.displayprogress();



}

