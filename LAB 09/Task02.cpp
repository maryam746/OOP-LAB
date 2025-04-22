#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}
    void showDetails() override {
        cout << "Appetizer: " << dishName << " | Price: $" << price << endl;
    }
    void prepare() override {
        cout << "Preparation: Chop ingredients, season, and serve cold or lightly heated.\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}
    void showDetails() override {
        cout << "Main Course: " << dishName << " | Price: $" << price << endl;
    }
    void prepare() override {
        cout << "Preparation: Cook thoroughly with spices, plate, and serve hot.\n";
    }
};

int main() {
    Appetizer springRolls("Garlic bread", 5.99);
    MainCourse steak("Grilled Steak", 19.99);

    MenuItem* menu[2];
    menu[0] = &springRolls;
    menu[1] = &steak;

    for (int i = 0; i < 2; ++i) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << endl;
    }

    return 0;
}
