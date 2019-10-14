//
// Created by Sammy on 2019-10-01.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP
#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

#endif //ASSIGNMENT1_MATRIX_HPP

using namespace std;


class Matrix
{
private:
    int n,r,c;
    double **matrix;
    void mySwap(Matrix &another);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt);
    friend bool operator==(const Matrix &mt1, const Matrix &mt2);
    friend bool operator!= (const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator+(Matrix origin, const Matrix& mt);
    friend Matrix operator-(Matrix origin, const Matrix& mt);
    friend Matrix operator*(Matrix origin, const Matrix& mt);
    friend Matrix operator*(Matrix origin, double number);
    friend Matrix operator/(Matrix origin, double number);
public:
    explicit Matrix(const int n = 1);
    Matrix(const int r, const int c);
    Matrix(const vector<double> arr);
    Matrix(const Matrix& mt);
    Matrix(double** input, const int size);
    void set_value(const int row, const int column, const double value);
    double get_value(const int row, const int column)const;
    void clear();
    void getC(int* arr, const int arrSize)const;
    double sumOfCal(const int column)const;
    void importanceCalculate(int* numOf1)const;
    Matrix createQ();
    Matrix createRank();
    ~Matrix();
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    Matrix& operator=(Matrix mt);
    Matrix& operator+=(const Matrix& mt);
    Matrix& operator-=(const Matrix& mt);
    Matrix& operator*=(const Matrix& mt);
    Matrix& operator*=(double number);
    Matrix& operator/=(double number);
};

