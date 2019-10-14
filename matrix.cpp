//
//Created by Keunsaem Lee on 2019-10-01.
//Matrix class creates a matrix with various input and provide functionalities to get and set those.
//It allows user to create a matrix in a numer of ways.
//To support Google's page rank algorithm, it provides functionalities to create rank, Q matricies.
//
#include "matrix.hpp"
using namespace std;

//create a square matrix of which size is n
Matrix::Matrix(const int n):n(n), r(n), c(n){
    try{
        if(n <= 0) throw invalid_argument("the square size has to be an integer over 0");
    }
    catch(invalid_argument e) {
        cerr<<e.what()<<endl;
        return;
    }
    matrix = new double* [n];
    for(int i = 0; i < n; ++i)
        matrix[i] = new double[n];
    for(int i = 0; i< n; ++i){
        for(int j = 0; j<n; j++){
            matrix[i][j] = {0.0};
        }
    }
}

//create a matrix with a certain row and column size
Matrix::Matrix(const int r, const int c):n(r), r(r), c(c), matrix(new double*[r]){
    try{
        if(r<=0 || c<=0) throw invalid_argument("row and column has to be an integer over 0");
    }
    catch(invalid_argument e) {
        cerr << e.what()<<endl;
        return;
    }
    for(int i = 0; i < r; ++i)
        matrix[i] = new double[c];
    for(int i = 0; i< r; ++i){
        for(int j = 0; j<c; j++){
            matrix[i][j] = {0.0};
        }
    }
}

//accept a vector and create a matrix with that
Matrix::Matrix(const vector<double> arr):n(arr.size()), r(arr.size()), c(arr.size()){
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

//copy constructor
Matrix::Matrix(const Matrix &mt):n(mt.n), r(mt.r), c(mt.c) {
    matrix = new double*[r];
    for(int i = 0; i < r; i++){
        matrix[i] = new double [c];
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = mt.matrix[i][j];
        }
    }
}

//accept 2d array and assign it to the object's matrix
Matrix::Matrix(double **input, int size) {
    matrix = input;
    r=size;
    c=size;
    n=size;
}

//set matrix value at a certain row and column
void Matrix::set_value(int row, int column, double value) {
    try{
        if(row < 0 || row > r ||column < 0 || column >c){
            throw invalid_argument("the argument should be 0 or positive integer");
        }
    }
    catch(invalid_argument e){
        cerr<< e.what()<<endl;
    }
    matrix[row][column] = value;
}

//getter for matrix value at a certain row and column
double Matrix::get_value(int row, int column)const {
    try{
        if(row < 0 || row > r ||column < 0 || column >c){
            throw invalid_argument("the argument should be 0 or positive integer");;
        }
    }
    catch(invalid_argument e){
        cerr<< e.what()<<endl;
    }
    return matrix[row][column];
}

//clear matrix by setting all values as 0
void Matrix::clear() {
    for(int i = 0; i<r; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = 0.0;
        }
    }
}

//matrix deconstroctor
Matrix::~Matrix() {
    delete[] matrix;
}

//swap all data member with another passed matrix
void Matrix::mySwap(Matrix &another) {
    std::swap(this->n,another.n );
    std::swap(this->r,another.r );
    std::swap(this->c,another.c);
    std::swap(this->matrix,another.matrix );
}

//override insertion operator to print out matrix's information
std::ostream& operator<<(std::ostream &os, const Matrix &mt) {
    char website = 'A';
    for(int i = 0; i < mt.r;i++){
        for(int j = 0; j < mt.c; j++){
            os << "page "<<website << ":  "<<mt.matrix[i][j]*100<<"%";
            if(j != mt.c -1) os << ", ";
        }
        website++;
        os<< "\n";
    }
    return os;
}

//override comparison operator to check if two matricies are identical
//it returns true if the difference is under the defined tolerance
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

//increament matrix value by 1
Matrix& Matrix::operator++() {
    for(int i=0; i<r; i++){
        for (int j =0; j<c; j++){
            matrix[i][j] +=1;
        }
    }
    return *this;
}

//return a copied matrix and increment the original matrix by 1
Matrix Matrix::operator++(int) {
    Matrix tmp(*this);
    operator++();
    return tmp;
}

//decrement matrix value by 1
Matrix& Matrix::operator--() {
    for(int i=0; i<r; i++){
        for (int j =0; j<c; j++){
            matrix[i][j] -=1;
        }
    }
    return *this;
}

//
Matrix Matrix::operator--(int) {
    Matrix tmp(*this);
    operator--();
    return tmp;
}

//return a copied matrix and decrement the original matrix by 1
Matrix& Matrix::operator=(Matrix mt) {
    mySwap(mt);
    return *this;
}

//add another matrix value to this matrix
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

//add two matricies and return the result
Matrix operator+(Matrix origin, const Matrix &mt) {
    origin += mt;
    return origin;
}

//subtract another matrix value from this matrix
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

//calculate subtraction of two matricies and return the result
Matrix operator-(Matrix origin, const Matrix &mt) {
    origin -= mt;
    return origin;
}

//multiply this matrix by another matrix
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

//multiply this matrix by a certain constant
Matrix& Matrix::operator*=(const double number) {
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c ; j++){
            matrix[i][j] = matrix[i][j] * number;
        }
    }
    return *this;
}

//multiply two matricies and return the result
Matrix operator*(Matrix origin, const Matrix &mt) {
   origin *= mt;
   return origin;
}

//multiply two matricies and return the result
Matrix operator*(Matrix origin, double number){
    origin *= number;
    return origin;
}

//divide this matrix by a certain constant
Matrix& Matrix::operator/=(double number) {
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c ; j++){
            matrix[i][j] = matrix[i][j] / number;
        }
    }
    return *this;
}

//divide a matrix by a certain constant and return the result matrix
Matrix operator/(Matrix origin, double number){
    origin /= number;
    return origin;
}

//create Q matrix based on this matrix's information
Matrix Matrix::createQ() {
    Matrix Q(*this);
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            Q.matrix[i][j] = double(1)/r;
        }
    }
    return Q;
}

//create a rank matrix based on this matrix's information
Matrix Matrix::createRank() {
    Matrix rank(r,1);
    for(int i = 0 ; i < r; i++){
        rank.matrix[i][0] = 1;
    }
    return rank;
}

//count 1's number of columns of this matrix and store in an array
void Matrix::getC(int *arr, const int arrsize)const{
    try{
        if(arrsize!=this->n) throw invalid_argument("the array size has to be the same as matrix size");
    }
    catch(invalid_argument &e) {
        cerr<<e.what()<<endl;
    }
    for(int i = 0; i < c ; i++){
        int count = 0;
        for(int j = 0; j<r; j++){
            if(matrix[j][i] == 1) count++;
        }
        arr[i] = count;
    }
}

//calculate the sum of a certain column
double Matrix::sumOfCal(const int column)const{
    double sum =  0;
    for(int i = 0 ; i<r; i++){
        sum += matrix[i][column];
    }
    return sum;
}

//calculate the importance by dividing each value by the number of 1's in a column
//if the sum of a column is 0, fill it with 1/the number of columns
void Matrix::importanceCalculate(int *numOf1)const {
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            if(numOf1[i] != 0){
                matrix[j][i] /= numOf1[i];
            } else {
                matrix[j][i] = double(1)/c;
            }
        }
    }
}
