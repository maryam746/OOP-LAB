#include <iostream>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xVal = 0, double yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);

    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int main() {
    Vector2D a(3.0, 4.0);
    Vector2D b(1.0, 2.0);

    Vector2D sum = a + b;
    Vector2D diff = a - b;
    Vector2D scaled = a * 2.5;
    double dot = dotProduct(a, b);

    cout << "Vector a: " << a << endl;
    cout << "Vector b: " << b << endl;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << diff << endl;
    cout << "a * 2.5 = " << scaled << endl;
    cout << "Dot product of a and b = " << dot << endl;

    return 0;
}

