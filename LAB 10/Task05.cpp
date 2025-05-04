#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "HybridTruck";
    string extraData = "Cargo:300|Battery:80";

    if (type == "HybridTruck") {
        size_t pos1 = extraData.find(":");
        size_t pos2 = extraData.find("|");
        size_t pos3 = extraData.find(":", pos2);

        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            int cargo = stoi(extraData.substr(pos1 + 1, pos2 - pos1 - 1));
            int battery = stoi(extraData.substr(pos3 + 1));

            cout << "Cargo: " << cargo << ", Battery: " << battery << endl;
        }
    }
    return 0;
}