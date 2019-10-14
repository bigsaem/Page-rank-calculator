

#include "main.hpp"
using namespace std;

int main()
{
    int rowNum = helper::getRow("Connectivity.txt");
    int col = rowNum;
    double** inputMT = helper::getInputMt("Connectivity.txt", rowNum);
    double p{0.85};
    double tolerance = 0.0001;
    double val1, val2;

    Matrix G(inputMT, rowNum);
    int numOf1Col[rowNum];
    G.getC(numOf1Col,col);
    G.importanceCalculate(numOf1Col);
    Matrix Q = G.createQ();
    Matrix M(rowNum);
    M = G*p + Q*(1-p);
    Matrix rank = G.createRank();

    do{
        val1 =  rank.get_value(0,0);
        rank = M*rank;
        val2 = rank.get_value(0,0);
    } while(abs(val1-val2)>tolerance);

    double ranksum = rank.sumOfCal(0);

    rank /= ranksum;

    cout<<fixed<<std::setprecision(2)<<rank;

}



void printInput(double** input, int size){
    for(int i = 0; i<size;i++){
        for(int j = 0; j<size; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

Matrix createMatrix(double** input, int size) {
    Matrix matrix(size);
    matrix.setMatrix(input);
    return matrix;
}
