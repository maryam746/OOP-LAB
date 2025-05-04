#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("vehicles.txt");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;

        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        istringstream iss(line);

        string Type, ID, Name, Year,Extradata, Certification;

        getline(iss, Type, ',');
        getline(iss, ID, ',');
        getline(iss, Name, ',');
        getline(iss, Year, ',');
        getline(iss, Extradata, ',');
        getline(iss, Certification, ',');

        int YearInt = stoi(Year); 

        cout << "Type: " << Type << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Year: " << Year << endl;
        cout << "Year (int): " << YearInt << endl; 
        cout << "ExtraData: " << Extradata << endl;
        cout << "Certification: " << Certification << endl;
        cout << "-----------------------" << endl;
    }

        if (file.is_open())
        {
            file.close();
            cout << "File closed successfully!" << endl;
        }
    
}