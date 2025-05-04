#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream createFile("large_log.txt");
    createFile << "This is the first part of the log.\n";
    createFile << "This is the second part of the log.\n";
    createFile << "And the third part.\n";
    createFile.close();

    ifstream inFile("large_log.txt");
    char buffer[11] = {};
    inFile.read(buffer, 10);
    cout << "Read: " << buffer << endl;
    cout << "Current Read Position: " << inFile.tellg() << endl;
    inFile.close();
    return 0;
}