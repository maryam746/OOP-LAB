#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual void applyDiscount() {}

    virtual double calculateTotalPrice(int quantity) const {
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << "\nName: " << productName
             << "\nPrice: $" << price << "\nStock: " << stockQuantity << endl;
    }

    double getPrice() const {
        return price;
    }

    // Operator + for adding product prices (e.g., bulk purchases)
    double operator+(const Product& other) const {
        return this->price + other.price;
    }

    // Operator << for formatted product info
    friend ostream& operator<<(ostream& out, const Product& p) {
        p.displayProductInfo();
        return out;
    }

    virtual ~Product() {}
};

// Electronics class
class Electronics : public Product {
private:
    int warrantyPeriod; // in months
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string b)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << " months" << endl;
    }
};

// Clothing class
class Clothing : public Product {
private:
    string size, color, fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string f)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(f) {}

    void applyDiscount() override {
        price *= 0.8; // 20% off
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << "\nColor: " << color << "\nFabric: " << fabricMaterial << endl;
    }
};

// FoodItem class
class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string exp, int cal)
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}

    double calculateTotalPrice(int quantity) const override {
        if (quantity >= 10) return price * quantity * 0.9; // 10% bulk discount
        return Product::calculateTotalPrice(quantity);
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expires on: " << expirationDate << "\nCalories: " << calories << " kcal" << endl;
    }
};

// Book class
class Book : public Product {
private:
    string author, genre;

public:
    Book(int id, string name, double p, int stock, string a, string g)
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << endl;
    }
};

// Main function to demonstrate
int main() {
    Electronics laptop(101, "Dell XPS 13", 1500.0, 5, 24, "Dell");
    Clothing tshirt(102, "Graphic Tee", 30.0, 20, "M", "Black", "Cotton");
    FoodItem rice(103, "Basmati Rice", 2.5, 100, "2025-05-01", 360);
    Book novel(104, "1984", 12.0, 50, "George Orwell", "Dystopian");

    cout << "--- Product Catalog ---\n" << endl;

    cout << laptop << endl;
    cout << tshirt << endl;
    cout << rice << endl;
    cout << novel << endl;

    cout << "\n--- Applying Discount to Clothing ---\n" << endl;
    tshirt.applyDiscount();
    cout << tshirt << endl;

    cout << "\n--- Calculating Total Price for 12 Rice Bags ---\n";
    cout << "Total: $" << rice.calculateTotalPrice(12) << endl;

    cout << "\n--- Price Addition Example (Laptop + Book) ---\n";
    double total = laptop + novel;
    cout << "Combined Price: $" << total << endl;

    return 0;
}
