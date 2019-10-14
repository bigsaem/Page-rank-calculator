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




class Matrix
{
private:
    int n,r,c;
    double **matrix;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt);
    friend bool operator==(const Matrix &mt1, const Matrix &mt2);
    friend bool operator!= (const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator+(Matrix origin, const Matrix& mt);
    friend Matrix operator-(Matrix origin, const Matrix& mt);
    friend Matrix operator*(Matrix origin, const Matrix& mt);
    friend Matrix operator*(Matrix origin, double number);
    friend Matrix operator/(Matrix origin, double number);
public:
    explicit Matrix(int n = 1);
    Matrix(int r, int c);
    Matrix(std::vector<double> arr);
    Matrix(const Matrix& mt);
    Matrix(double** input, int size);
    void set_value(int row, int column, double value);
    double get_value(int row, int column);
    void clear();
    ~Matrix();
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    Matrix& operator=(Matrix mt);
    void mySwap(Matrix &another);
    Matrix& operator+=(const Matrix& mt);
    Matrix& operator-=(const Matrix& mt);
    Matrix& operator*=(const Matrix& mt);
    Matrix& operator*=(double number);
    Matrix& operator/=(double number);
    Matrix createQ();
    Matrix createRank();
    void setMatrix(double **matrix);
    void getR(int* arr, int mtSize);
    void getC(int* arr, int mtSize);
    double sumOfCal(int column);
    void importanceCalculate(int* column);

};

