#include <bits/stdc++.h>
using namespace std;


int* RandomArray(int length){

    int* ptr = new int[length];
    for(int i = 0; i < length; i ++){
        ptr[i] = rand() % 10;
    }
    return ptr;

}
int* CopyArray(int* arr1, int length){

    int* arr2 = new int[length];
    for(int i = 0; i < length; i ++){
        arr2[i] = arr1[i];
    }
    return arr2;

}
void PrintArray(int* arr, int length){

    cout << "[";
    for(int i = 0; i < length; i ++){
        cout << arr[i] << " ";
    }
    cout << "]\n";

}
void CountingSort(int* arr, int length){

    cout << "排序前: ";
    PrintArray(arr, length);

    int max = 0;
    for(int i = 0; i < length; i ++){
        if(arr[i] > max)
            max = arr[i];
    }
    cout << max << "\n";

    int CountingArray[max];

}
void BubbleSort(int* arr, int length){}
void InsertionSort(int* arr, int length){}
void MergeLoop(int* arr, int length, int start, int mid, int end){}
void MergeSort(int* arr, int length, int start, int end){}

int main(void){

    srand(time(0));
    int length = 10;
    int* arr1 = RandomArray(length);
    int* arr2 = CopyArray(arr1, length);
    int* arr3 = CopyArray(arr1, length);
    int* arr4 = CopyArray(arr1, length);

    CountingSort(arr1, length);
    return 0;
    
}