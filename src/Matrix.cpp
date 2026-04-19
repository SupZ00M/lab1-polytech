#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int n) : rows(n), cols(n) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = (i == j) ? 1.0 : 0.0;
}

Matrix::Matrix(int m, int n, double fill_value) : rows(m), cols(n) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = fill_value;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix() {}

double Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::runtime_error("get: Index out of range");
    return data[i][j];
}

void Matrix::set(int i, int j, double value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::runtime_error("set: Index out of range");
    data[i][j] = value;
}

int Matrix::get_height() const {
    return rows;
}

int Matrix::get_width() const {
    return cols;
}

void Matrix::negate() {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = -data[i][j];
}

void Matrix::add_in_place(Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::runtime_error("add_in_place: rows != other.rows || cols != other.cols");
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] += other.data[i][j];
}

Matrix Matrix::multiply(Matrix& other) {
    if (cols != other.rows)
        throw std::runtime_error("multiply: cols != other.rows");
    Matrix result(rows, other.cols, 0.0);
    for (int i = 0; i < rows; ++i)
        for (int k = 0; k < cols; ++k) {
            double r = data[i][k];
            for (int j = 0; j < other.cols; ++j)
                result.data[i][j] += r * other.data[k][j];
        }
    return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    rows = other.rows;
    cols = other.cols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    return *this;
}
