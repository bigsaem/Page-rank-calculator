//
// Created by Sammy on 2019-10-13.
//

#ifndef ASSIGNMENT1_HELPER_HPP
#define ASSIGNMENT1_HELPER_HPP
#define toDigit(c) (c-'0')
#include "matrix.hpp"
#include <fstream>
using namespace std;

class helper {
public:
    static int  getRow(const string filename);
    static double** getInputMt(const string title, int numOfRow);
    static void converge(Matrix& rank, const Matrix& m);
};


#endif //ASSIGNMENT1_HELPER_HPP
