//
//Created by Keunsaem Lee on 2019-10-13.
//helper class helps read file and operate Google's page rank algorithm
//It reads a file and create a 2d array for Matrix class to creeate a right matrix for it
//

#include "helper.hpp"

//scan a file on the passed path and get the number of lines
int helper::getRow(const string title) {
    string line;
    int numberOfLine = 0;
    ifstream f{title};
    if(!f.is_open()){
        cerr<<"unable to open file"<<endl;
        exit(1);
    }
    while(getline(f, line)) numberOfLine++;
    f.close();
    return numberOfLine;
}

//scan a file to create 2d array that has 0 and 1s and return it
double ** helper::getInputMt(const string title, int numOfRow) {
    char c;
    double **inputMT;
    string line;
    ifstream f{title};
    if(!f.is_open()){
        cerr<<"unable to open file"<<endl;
        exit(1);
    }
    inputMT = new double*[numOfRow];
    for(int i = 0; i < numOfRow; i++){
        inputMT[i] = new double [numOfRow];
    }
    int tempr=0 ,tempc = 0;
    while ((c = f.get ()) != EOF)
    {
        if(c!='\n' && c!= '\r') {
            inputMT[tempr][tempc] = toDigit(c);
            tempc++;
        }
        if(c == '\n') {
            tempr++;
            tempc = 0;
        }
    }
    return inputMT;
}

//Multiply the transition matrix M by our column matrix rank, and then
//multiply M by the result and then keep doing this until the rank stops
//changing
void helper::converge(Matrix& rank, const Matrix& m) {
    const double tolerance{0.0001};
    double val1, val2;
    do{
        val1 =  rank.get_value(0,0);
        rank = m*rank;
        val2 = rank.get_value(0,0);
    } while(abs(val1-val2)>tolerance);
}