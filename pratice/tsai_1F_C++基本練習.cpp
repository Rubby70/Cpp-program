#include <iostream>
#include <fstream>
using namespace std;


int main(void){

    ofstream outfile("my.out", ios::out);
    if(!outfile){
        cout << "Cannot open my.out" << endl;
        return 1;
    }

    int i = 10;
    float f = 1.23;
    outfile << "i:" << i << endl;
    outfile << "f:" << f << endl;
    return 0;

}