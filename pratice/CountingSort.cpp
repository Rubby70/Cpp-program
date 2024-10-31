#include <iostream>
#include <algorithm>
using namespace std;


void PrintArray(int* arr, int n){

    cout << "[";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << "]\n";

}
void CountingSort(int* inputArr, int n){

    int m = 0;
    for(int i = 0; i < n; i ++){
        m = max(m, inputArr[i]);
    }
    int countArr[m + 1] = {0};
    for(int i = 0; i < n; i ++){
        countArr[inputArr[i]] ++;
    }
    for(int i = 1; i < m + 1; i ++){
        countArr[i] += countArr[i - 1];
    }
    int outputArr[n] = {0};
    for(int i = (n - 1); i >= 0; i --){
        outputArr[countArr[inputArr[i]] - 1] = inputArr[i];
        countArr[inputArr[i]] --;
    }
    PrintArray(outputArr, n);

}

int main(void){

    int arr[8] = { 4, 3, 12, 1, 5, 5, 3, 9 };
    int n = 8;
    cout << "排序前:";
    PrintArray(arr, n);

    CountingSort(arr, n);

    // cout << "排序後:";
    // PringArray(arr, n);
    return 0;

}

