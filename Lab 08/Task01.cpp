#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        if (c.imag >= 0)
            out << "(" << c.real << " + " << c.imag << "i)";
        else
            out << "(" << c.real << " - " << -c.imag << "i)";
        return out;
    }

    friend double magnitude(const Complex& c);
};

double magnitude(const Complex& c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;
    cout << "c1 / c2 = " << quot << endl;

    cout << "Magnitude of c1 = " << magnitude(c1) << endl;
    cout << "Magnitude of c2 = " << magnitude(c2) << endl;

    return 0;
}

