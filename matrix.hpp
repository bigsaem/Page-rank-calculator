//
// Created by Sammy on 2019-10-01.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

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
public:
    explicit Matrix(int n = 1);
    Matrix(int r, int c);
    Matrix(std::vector<double> arr);
    Matrix(const Matrix& mt);
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
    void getR(int* a, int n);
    void getC(int* a, int n);

};

