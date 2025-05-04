#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("records.txt");
    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();

    ifstream inFile("records.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
