#include<iostream>
using namespace std;


void printArray(int* array, int n){
    
    cout << "[ ";
    for(int i = 0; i < n; i ++)
        cout << array[i] << " ";
    cout << "]\n";

}
void Insertion(int* array, int n){

    for(int i = 1; i < n; i ++){ //有n個數字要排(0 ~ n - 1)
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && temp < array[j]){
            array[j + 1] = array[j];
            cout << j << "與" << j + 1 << "位置交換, ";
            cout << "sroting: ";
            printArray(array, n);
            j --;
        }
        array[j + 1] = temp;
        cout << "i = " << i << ", ";
        printArray(array, n);
    }

}

int main(void){

    int array[] = { 12, 11, 13, 5, 6 };
    int size = sizeof(array) / sizeof(array[0]);
    printArray(array, size);
    Insertion(array, size);
    printArray(array, size);
    return 0;

}