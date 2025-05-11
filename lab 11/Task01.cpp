#include <iostream>
#include <vector>
#include <exception>
#include <sstream>

using namespace std;

// Custom exception class
class DimensionMismatchException : public exception {
private:
    string message;
public:
    DimensionMismatchException(int rows1, int cols1, int rows2, int cols2) {
        stringstream ss;
        ss << "DimensionMismatch Exception! Matrices must have same dimensions ("
           << rows1 << "x" << cols1 << " vs " << rows2 << "x" << cols2 << ")";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Template Matrix class
template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, vector<T>(c));
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Overloaded + operator for matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.set(i, j, data[i][j] + other.get(i, j));

        return result;
    }

    void display() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

// Main function to demonstrate usage
int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        // Fill matrices with dummy values
        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;  // This will throw exception

        cout << "Matrix C (result):" << endl;
        C.display();
    } catch (const DimensionMismatchException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
