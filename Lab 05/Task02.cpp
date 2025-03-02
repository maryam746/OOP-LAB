#include<iostream>
using namespace std;


class Student {
    int ID;
    string name;
    int *scores = new int [5];

    public:
    Student(const Student &s){
        ID = s.ID;
        name = s.name;
        scores = new int [5];
        for (int i = 0; i < 5; i++){
            scores[i] = s.scores[i];
        }
}

 void displaydetails(){
    cout<<"Student details:"<<endl;
    cout<<"ID:"<<ID<<endl;
    cout<<"Name:"<<name<<endl;  
    cout<<"Scores:";
    for (int i = 0; i < 5; i++){
        cout<<scores[i]<<" ";
    }

 }

    Student(int id, string name, int *score): ID(id), name(name){
        scores = new int [5];
        
        for (int i = 0; i < 5; i++){
            scores[i] = score[i];
        }
    }

    ~Student(){
        delete [] scores;
    }
};

int main(){
    int score[5] = {90, 80, 70, 60, 50};
    Student s1(1, "Ali", score);
    s1.displaydetails();
    Student s2(s1);
    s2.displaydetails();
    return 0;
    

}


