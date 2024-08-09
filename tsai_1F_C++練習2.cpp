#include <iostream>
#include <fstream>
using namespace std;

int main(void){

    ifstream infile("my.out", ios::in);
    if(!infile){
        cout << "Cannot open my.out" << endl;
        return 1;
    }

    int x;
    while(!infile.eof()){
        infile >> x;
        cout << x << endl;
    }
    return 0;

}