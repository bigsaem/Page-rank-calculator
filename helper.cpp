//
// Created by Sammy on 2019-10-13.
//

#include "helper.hpp"

int helper::getRow(const string filename) {
    string line;
    int numberOfLine = 0;
    ifstream f{filename};
    if(!f.is_open()){
        cerr<<"unable to open file"<<endl;
        exit(1);
    }
    while(getline(f, line)) numberOfLine++;
    f.close();
    return numberOfLine;
}

double ** helper::getInputMt(const string title, int row) {
    char c;
    double **inputMT;
    string line;
    ifstream f{title};
    if(!f.is_open()){
        cerr<<"unable to open file"<<endl;
        exit(1);
    }

    inputMT = new double*[row];
    for(int i = 0; i< row;i++){
        inputMT[i] = new double [row];
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