#include<bits/stdc++.h>
using namespace std;


double& Compare(double& a, double& b){

    return a <= b ? a : b;

}

int main(void){

    double A = 1.1;
    double B = 2.2;

    double C = Compare(A, B);
    cout << "C = " << C << "\n";

    Compare(A, B) += 2;
    cout << "A = " << A << ", B = " << B << "\n";

    Compare(A, B) += 2;
    cout << "A = " << A << ", B = " << B << "\n";

    Compare(A, B) = 10;
    cout << "A = " << A << ", B = " << B << "\n";
    return 0;

}