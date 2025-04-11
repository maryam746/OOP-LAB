#include <iostream>

using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int row, int col, int value);
};

class Matrix2x2 {
private:
    int a, b, c, d;  // Matrix format: [a b]
                     //                [c d]

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        int r1c1 = a * other.a + b * other.c;
        int r1c2 = a * other.b + b * other.d;
        int r2c1 = c * other.a + d * other.c;
        int r2c2 = c * other.b + d * other.d;
        return Matrix2x2(r1c1, r1c2, r2c1, r2c2);
    }

    friend int determinant(const Matrix2x2& m);
    friend class MatrixHelper;

    friend ostream& operator<<(ostream& out, const Matrix2x2& m) {
        out << "[" << m.a << " " << m.b << "]" << endl;
        out << "[" << m.c << " " << m.d << "]";
        return out;
    }
};

int determinant(const Matrix2x2& m) {
    return (m.a * m.d) - (m.b * m.c);
}

void MatrixHelper::updateElement(Matrix2x2& m, int row, int col, int value) {
    if (row == 0 && col == 0) m.a = value;
    else if (row == 0 && col == 1) m.b = value;
    else if (row == 1 && col == 0) m.c = value;
    else if (row == 1 && col == 1) m.d = value;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix m1:\n" << m1 << endl;
    cout << "Matrix m2:\n" << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "\nSum (m1 + m2):\n" << sum << endl;
    cout << "\nDifference (m1 - m2):\n" << diff << endl;
    cout << "\nProduct (m1 * m2):\n" << prod << endl;

    cout << "\nDeterminant of m1: " << determinant(m1) << endl;
    cout << "Determinant of m2: " << determinant(m2) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 1, 9);  // change m1.b to 9

    cout << "\nMatrix m1 after updating element (0,1) to 9:\n" << m1 << endl;

    return 0;
}


