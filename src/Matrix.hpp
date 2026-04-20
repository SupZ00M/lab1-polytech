#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    static const int MAX_SIZE = 256;
    int rows;
    int cols;
    double data[MAX_SIZE][MAX_SIZE];

public:
    Matrix(int n);
    Matrix(int m, int n, double fill_value);
    Matrix(const Matrix& other);
    ~Matrix();

    double get(int i, int j) const;
    void set(int i, int j, double value);
    int get_height() const;
    int get_width() const;

    Matrix operator-();
    void operator+=(Matrix& other);
    Matrix operator*(Matrix& other);

    Matrix& operator=(const Matrix& other);
     void print();
};

#endif
