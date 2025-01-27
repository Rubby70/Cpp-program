#include<bits/stdc++.h>
using namespace std;


class testA{

    public:
        int a;
        char b;
        char c;

};
class testB{

    public:
        char bb;
        int aa;
        char cc;

};

int main(void){

    testA A;
    testB B;
    cout << "sizeof(A): " << sizeof(A) << "\n";
    cout << "sizeof(B): " << sizeof(B) << "\n";
    return 0;

}