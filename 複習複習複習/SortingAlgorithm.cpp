#include <bits/stdc++.h>
using namespace std;

void PrintArray(int* arr, int length){

    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%2d ", arr[i]);
    }
    printf("]\n");

}
int* RP_RandomArray(int length, int max){

    int* arr = new int[length];
    for(int i = 0; i < length; i ++){
        arr[i] = rand() % (max + 1);
    }

    return arr;

}
int* NRP_RandomArray(int length, int max){

    int* arr = new int[length];

    int check[max + 1];
    for(int i = 0; i < (max + 1); i ++){
        check[i] = 0;
    }

    for(int i = 0; i < length;){
        int temp = rand() % (max + 1);
        if(check[temp] == 0){
            arr[i] = temp;
            check[temp] = 1;
            i ++;
        }
    }

    return arr;

}
int* CopyArr(int* arr, int length){

    int* copy = new int[length];
    for(int i = 0; i < length; i ++){
        copy[i] = arr[i];
    }

    return copy;

}

void CountingSort(int* arr, int length){

    printf("Counting Sort:  ");
    PrintArray(OutputArr, length);

}
void BubbleSort(int* arr, int length){

    printf("Bubble Sort:    ");
    PrintArray(arr, length);

}
void InsertionSort(int* arr, int length){

    printf("Insertion Sort: ");
    PrintArray(arr, length);

}
void QuickSort(int* arr, int length){

    printf("Quick Sort:     ");
    PrintArray(arr, length);

}
void MergeSort(int* arr, int length){

    printf("Merge Sort:     ");
    PrintArray(arr, length);

}

int main(void){

    srand(time(0));
    int length = 9;
    int max = 10;
    int* RParr = RP_RandomArray(length, max);
    int* NRParr = NRP_RandomArray(length, max);

    int* arr1 = CopyArr(RParr, length);
    int* arr2 = CopyArr(RParr, length);
    int* arr3 = CopyArr(RParr, length);
    int* arr4 = CopyArr(RParr, length);
    int* arr5 = CopyArr(RParr, length);
    printf("Initial Array:  ");
    PrintArray(arr1, length);

    CountingSort(arr1, length);
    BubbleSort(arr2, length);
    InsertionSort(arr3, length);
    QuickSort(arr4, length);
    MergeSort(arr5, length);
    return 0;

}