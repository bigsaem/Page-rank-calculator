//
//Created by Keunsaem Lee on 2019-10-01.
//main.cpp runs the program to analize rank of webpages
//The procedure is as following:
//1. read a text file
//2. create 2d array with the input text which is the map of links between pages
//3. Convert it into Matrix
//4. calculate importance and apply it to that matrix
//5. create Q matrix that has the importance of moving to a website by typing url instead of using links
//6. Multiply the original matrix and Q matrix by 0.85 and 0.15 each which is the possibility that will happen
//7. add those matricies and return to create M matrix.
//7. create Rank matrix which size is 4*1 and having 1 as value.
//8. multiply M matrix by rank to get the converged value.
//9. divide the values by the sum of the column of Rank Matrix..
//10. the final value is the rank of each web pages.

#include "main.hpp"
using namespace std;

int main()
{
    //get the number of lines(rows) of input
    const int matrixSize = helper::getRow("../connectivity.txt");
    //create 2d array from the input file
    double** inputMT = helper::getInputMt("../connectivity.txt", matrixSize);
    const double p{0.85};
    const int firstCol = 0;
    const int precisionLv = 2;
    //create a matrix from the input 2d array
    Matrix g(inputMT, matrixSize);
    int sumofCol[matrixSize];
    //get the number of 1s of each column and store it in sumofCol array
    g.getC(sumofCol, matrixSize);
    //calculate importance of pages with the sumofCol
    g.importanceCalculate(sumofCol);
    //create matrix q that has the importance(0.25) of moving to another page by using URL
    Matrix q = g.createQ();
    //create matrix m that has probability click links + probability teleport
    Matrix m(matrixSize);
    m = g*p + q * (1 - p);
    //create rank matrix
    Matrix rank = g.createRank();
    //converge the result by keeping multyplying rank
    helper::converge(rank, m);
    double ranksum = rank.sumOfCal(firstCol);
    rank /= ranksum;
    cout<<fixed<<std::setprecision(precisionLv)<<rank;
}