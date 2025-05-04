#include<iostream>
#include<fstream>
#include<string>

using namespace std;



int main(){
    ifstream file("vehicles.txt");

    if(!file.is_open()){
        cerr<<"Error opening file!" << endl;
        exit(1);
    }

string line;
while(getline(file, line)){
    cout<<line<<endl;

    if(line.empty() || line[0] == '#'){
        continue; 
    }

    if(file.is_open()){
        file.close();
        cout<<"File closed successfully!"<<endl;

}
}
}