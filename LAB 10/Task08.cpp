#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("config.txt");
    file << "AAAAA88888CCCCC";
    file.close();

    fstream updateFile("config.txt", ios::in | ios::out);
    updateFile.seekp(5);
    updateFile << "XXXXX";
    updateFile.close();

    ifstream readFile("config.txt");
    string content;
    getline(readFile, content);
    cout << "Updated File: " << content << endl;
    return 0;
}
