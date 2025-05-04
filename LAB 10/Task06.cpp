#include <iostream>
#include <fstream>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item1 = {101, "Wrench"};

    ofstream outFile("inventory.dat", ios::binary);
    outFile.write((char*)&item1, sizeof(item1));
    outFile.close();

    InventoryItem item2;
    ifstream inFile("inventory.dat", ios::binary);
    inFile.read((char*)&item2, sizeof(item2));
    inFile.close();

    cout << "Read Item ID: " << item2.itemID << ", Name: " << item2.itemName << endl;
    return 0;
}