#include<iostream>
using namespace std;

class levels{

    string lev;

    public:
    levels(string l):lev(l){}
    string getlev(){return lev;}
   


};


class videogames{

string title;
string genre;
levels **larr;
int numlevels;

public:
 videogames(string t, string g , levels*l[],int num):title(t),genre(g),numlevels(num){
    larr = new levels*[numlevels];
    for(int i=0;i<numlevels;i++){
        larr[i]=l[i];
    }
}

~videogames(){
    for(int i=0;i<numlevels;i++){
        delete larr[i];
    }
    delete[] larr;
}

void display(){
    cout<<"Title: "<<title<<endl;
    cout<<"Genre: "<<genre<<endl;
    cout<<"Levels: "<<endl;
    for(int i=0;i<numlevels;i++){
        cout<<larr[i]->getlev()<<endl;
    }
}


};


int main(){
    levels l1("Forest of Doom"), l2("Castle of Shadows"), l3("Lava Pit");
    levels* levelArr[] = { &l1, &l2, &l3 };
    
    videogames game("Cyber Quest", "RPG", levelArr, 3);
    game.display();
    return 0;
}

