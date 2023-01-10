#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#define EPS 1e-7

#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>

namespace LinearAlgebra {
class Matrix {
private:
    int rows, columns;
    double *matrix;

    void Resize();

public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    ~Matrix();

    constexpr int GetRows() const noexcept;
    constexpr int GetColumns() const noexcept;
    double &operator()(int row, int col);
    const double &At(int row, int col) const;

    void SetRows(const int &rows_);
    void SetColumns(const int &columns);

    friend std::ostream &operator<<(std::ostream &out, Matrix source);

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
    Matrix operator*(const double number) const;

    bool operator==(const Matrix &other) noexcept;
    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other) noexcept;
    Matrix &operator+=(const Matrix &other);
    Matrix &operator-=(const Matrix &other);
    Matrix &operator*=(const Matrix &other);
    Matrix &operator*=(double number);

    bool EqMatrix(const Matrix &other) const;
    void SumMatrix(const Matrix &other);
    void SubMatrix(const Matrix &other);
    void MulNumber(const double num);
    void MulMatrix(const Matrix &other);
    Matrix Transpose() const;
    Matrix CalcComplements() const;
    double Determinant() const;
    Matrix InverseMatrix() const;
};
}  // namespace LinearAlgebra

#endif  // SRC_MATRIX_H_