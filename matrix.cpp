//
// Created by Sammy on 2019-10-01.
//
#include <vector>
#include <iostream>
#include <cmath>
#include "matrix.hpp"
#include <stdexcept>
using namespace std;


Matrix::Matrix(int n):n(n), r(n), c(n){
    try{
        if(n <= 0) throw n;
    }
    catch(int i) {
        cout<<"error occur"<<endl;
        cerr << "Error: the argument should be integer over 1" << endl;
    }
    matrix = new double* [n];
    for(int i = 0; i < n; ++i)
        matrix[i] = new double[n];
    for(int i = 0; i< n; ++i){
        for(int j = 0; j<n; j++){
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(int r, int c):n(0), r(r), c(c), matrix(new double*[r]){
    try{
        if(r<=0 || c<=0) throw;
    }
    catch(int e) {
        cerr << "Error: the argument should be integer over 1" << endl;
    }
    for(int i = 0; i < r; ++i)
        matrix[i] = new double[c];
    for(int i = 0; i< r; ++i){
        for(int j = 0; j<c; j++){
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(vector<double> arr):n(arr.size()), r(arr.size()), c(arr.size()){
    size_t arrSize;
    try {
        double sqrtVal;
        arrSize = arr.size();
        sqrtVal = sqrt(arrSize);
        if (sqrtVal - floor(sqrtVal) != 0) throw sqrtVal;
    }
    catch(double e) {
        cerr << "Error: the argument should be integer over 1" << endl;
    }
    matrix = new double*[arrSize];
    for(int i = 0; i < r; ++i)
        matrix[i] = new double[arrSize];
    for(int i = 0; i< r; ++i){
        for(int j = 0; j<c; j++){
            matrix[i][j] = arr[i];
        }
    }
}

//copy constructor///////////////////////////////////////////////////
Matrix::Matrix(const Matrix &mt):n(mt.n), r(mt.r), c(mt.c) {
    //do i have to copy it like this way or i cna just do matrix = mt.matrix
    matrix = new double*[r];
    for(int i = 0; i < r; i++){
        matrix[i] = new double [c];
    }
    cout<<"Copy constructor is called"<<endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = mt.matrix[i][j];
        }
    }
}


void Matrix::set_value(int row, int column, double value) {
    try{
        if(row < 0 || row > r ||column < 0 || column >c){
            throw 0;
        }
    }
    catch(int e){
        cerr<< "Error: the argument should be 0 or positive integer" <<endl;
        cerr<< "the index cannot be bigger than matrix size"<<endl;
    }
    matrix[row][column] = value;
}

double Matrix::get_value(int row, int column) {
    try{
        if(row < 0 || row > r ||column < 0 || column >c){
            throw 0;
        }
    }
    catch(int e){
        cerr<< "Error: the argument should be 0 or positive integer" <<endl;
        cerr<< "the index cannot be bigger than matrix size"<<endl;
    }
    return matrix[row][column];
}

void Matrix::clear() {
    for(int i = 0; i<r; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix() {
    delete[] matrix;
}

void Matrix::mySwap(Matrix &another) {
    cout<<"Swap has been operated"<<endl;
    std::swap(this->n,another.n );
    std::swap(this->r,another.r );
    std::swap(this->c,another.c);
    std::swap(this->matrix,another.matrix );
}

std::ostream& operator<<(std::ostream &os, const Matrix &mt) {
    for(int i = 0; i < mt.r;i++){
        for(int j = 0; j < mt.c; j++){
            os << to_string(mt.matrix[i][j]);
            if(j != mt.c -1) os << ", ";
        }
        os<< "\n";
    }
    return os;
}

bool operator==(const Matrix &mt1, const Matrix &mt2) {
    double tolerance = 0.005;
    if(mt1.r != mt2.r) return false;
    if(mt1.c != mt2.c) return false;
    for(int i = 0; i < mt1.r; i++){
        for(int j = 0; j < mt1.c; j++){
            if((mt1.matrix[i][j] - mt2.matrix[i][j]) > tolerance){
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix &lhs, const Matrix &rhs) {
    return !operator==(lhs, rhs);
}

Matrix& Matrix::operator++() {
    for(int i=0; i<r; i++){
        for (int j =0; j<c; j++){
            matrix[i][j] +=1;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix tmp(*this); //is this a copy constructor
    operator++();
    return tmp;
}

Matrix& Matrix::operator--() {
    for(int i=0; i<r; i++){
        for (int j =0; j<c; j++){
            matrix[i][j] -=1;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix tmp(*this);
    operator--();
    return tmp;
}

Matrix& Matrix::operator=(Matrix mt) {
    mySwap(mt);
    return *this;
}

Matrix& Matrix::operator+=(const Matrix &mt) {
    try{
        if(r != mt.r || c != mt.c) throw invalid_argument("size of matrix is not matched");
    }
    catch(invalid_argument e){
        cerr<<e.what()<<endl;
        return *this;
    }
    for(int i = 0; i <r; i++){
        for (int j = 0; j<c; j++){
            matrix[i][j] += mt.matrix[i][j];
        }
    }
    return *this;
}

Matrix operator+(Matrix origin, const Matrix &mt) {
    origin += mt;
    return origin;
}

Matrix& Matrix::operator-=(const Matrix &mt) {
    try{
        if(r != mt.r || c != mt.c) throw invalid_argument("size of matrix is not matched");
    }
    catch(invalid_argument e){
        cerr<<e.what()<<endl;
        return *this;
    }
    for(int i = 0; i <r; i++){
        for (int j = 0; j<c; j++){
            matrix[i][j] -= mt.matrix[i][j];
        }
    }
    return *this;
}

Matrix operator-(Matrix origin, const Matrix &mt) {
    origin -= mt;
    return origin;
}

Matrix& Matrix::operator*=(const Matrix &mt) {
    try{
        if(c != mt.r) throw invalid_argument("size of matrix is not matched");
    }
    catch(invalid_argument e){
        cerr<<e.what()<<endl;
        return *this;
    }
    Matrix newMT(r, mt.c);
    for(int i = 0 ; i <newMT.r; i++){
        for(int j = 0; j <newMT.c; j++){
            for(int k = 0; k<c;k++){
                newMT.matrix[i][j] += matrix[i][k] * mt.matrix[k][j];
            }
        }
    }
    *this = newMT;
    return *this;
}

Matrix operator*(Matrix origin, const Matrix &mt) {
   origin *= mt;
   return origin;
}

void Matrix::getR(int *a, int n) {
    try{
        if(n!=this->n) throw invalid_argument("the array size has to be the same as matrix size");
    }
    catch(invalid_argument e) {
        cerr<<e.what()<<endl;
    }
    for(int i = 0; i < r ; i++){
        for(int j = 0; j<c; j++){
            if(matrix[i][j] == 1) a[i]++;
        }
    }
}
void Matrix::getC(int *a, int n) {
    try{
        if(n!=this->n) throw invalid_argument("the array size has to be the same as matrix size");
    }
    catch(invalid_argument e) {
        cerr<<e.what()<<endl;
    }
    for(int i = 0; i < c ; i++){
        for(int j = 0; j<r; j++){
            if(matrix[j][i] == 1) a[i]++;
        }
    }
}