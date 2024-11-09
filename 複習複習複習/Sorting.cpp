#include <bits/stdc++.h>
using namespace std;


int* RandomArray(){

    int length = 10;
    int* ptr = new int(length);
    for(int i = 0; i < length; i ++){
        ptr[i] = rand() % 10;
    }
    return ptr;

}

int main(void){

    srand(time(0));
    int* arr1 = RandomArray();
    cout << arr1 << "\n";
    return 0;
    
}