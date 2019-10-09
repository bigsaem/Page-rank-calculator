#include <iostream>
#include <vector>
#include "matrix.hpp"
using namespace std;

int main() {

    char W[4] = {'a','b','c','d'};
    Matrix G(4);
    int r[4] = {0,0,0,0};
    int c[4] = {0,0,0,0};
    G.set_value(0,1,1);
    G.set_value(0,2,1);
    G.set_value(1,0,1);
    G.set_value(1,2,1);
    G.set_value(2,0,1);
    G.set_value(2,1,1);
    G.getR(r, 4);
    G.getC(c,4);
    for (int i = 0; i < 4; i++)
        cout << r[i]<<endl;
    cout<<G;

////////////////////////////////
////Matrix vv(2,5);
////Matrix cc(2,3);
////vv++;
////cout<<vv;
////cc++;
////cc++;
////cout<<cc;
////vv+=cc;
////cout<<vv;
////
////Matrix bb(vv + cc);
////
////cout<<bb;
//
//Matrix multi1(4,2);
//multi1++;
//cout<<multi1;
//
//Matrix multi2(2, 3);
//multi2++;
//multi2++;
////cout<<multi2;
////multi1*=multi2;
////cout<<multi1;
//    cout<<"wow"<<endl;
//Matrix newone(multi1*multi2);
//cout<<newone;
}