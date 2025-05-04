#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    outFile << "Sensor A: 100" << endl;
    cout << "Position after write 1: " << outFile.tellp() << endl;
    outFile << "Sensor B: 200" << endl;
    cout << "Position after write 2: " << outFile.tellp() << endl;
    outFile.close();
    return 0;
}
