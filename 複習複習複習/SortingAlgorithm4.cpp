#include <bits/stdc++.h>
using namespace std;

void PrintArray(char* arr, int length){

    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%c ", arr[i]);
    }
    printf("]\n");

}
char* NRP_RandomArray(int length, int max){

    char* arr = (char*)malloc(sizeof(char) * length);

    int check[256];
    for(int i = 0; i < 256; i ++){
        check[i] = 0;
    }

    for(int i = 0; i < length; ){
        int temp = (rand() % max) + 'A';
        if(check[temp] == 0){
            check[temp] = 1;
            arr[i] = temp;
            i ++;
        }
    }

    return arr;

}
char* RP_RandomArray(int length, int max){

    char* arr = (char*)malloc(sizeof(char) * length);

    for(int i = 0; i < length; i ++){
        arr[i] = (rand() % max) + 'A';
    }

    return arr;

}
char* CopyArray(char* arr, int length){

    char* temp = (char*)malloc(sizeof(char) * length);

    for(int i = 0; i < length; i ++){
        temp[i] = arr[i];
    }

    return temp;

}

void BubbleSort(char* arr, int length){

    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(arr[j] < arr[i]){
                char temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("Bubble Sort:    ");
    PrintArray(arr, length);

}
void InsertionSort(char* arr, int length){

    for(int i = 1; i < length; i ++){
        char temp = arr[i];
        int cnt = i;
        while((cnt > 0) && temp < arr[cnt - 1]){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

    printf("Insertion Sort: ");
    PrintArray(arr, length);

}
void CountingSort(char* arr, int length){

    int max = -1;
    for(int i = 0; i < length; i ++){
        int temp = arr[i] - 'A';
        if(temp > max){
            max = temp;
        }
    }

    int CountingArray[max + 1];
    for(int i = 0; i < (max + 1); i ++){
        CountingArray[i] = 0;
    }
    for(int i = 0; i < length; i ++){
        int temp = arr[i] - 'A';
        CountingArray[temp] ++; 
    }
    for(int i = 1; i < (max + 1); i ++){
        CountingArray[i] += CountingArray[i - 1];
    }

    char* OutputArray = (char*)malloc(sizeof(char) * length);
    for(int i = length - 1; i >= 0; i --){
        int temp = arr[i] - 'A';
        OutputArray[CountingArray[temp] - 1] = arr[i];
        CountingArray[temp] --;
    }

    printf("Counting Sort:  ");
    PrintArray(OutputArray, length);

}

int Max(const void* A, const void* B){

    return (int*)A - (int*)B;

}
void QiuckSort(char* arr, int length){

    qsort(arr, length, sizeof(char), Max);

    printf("Quick Sort:     ");
    PrintArray(arr, length);

}

void Merge(){}
void MergeLoop(){}
void MergeSort(char* arr, int length){

    printf("Merge Sort:     ");
    PrintArray(arr, length);

}

int main(void){

    srand(time(0));
    int length = 5;
    int max = 5;
    char* arr = NRP_RandomArray(length, max);
    char* arr1 = CopyArray(arr, length);
    char* arr2 = CopyArray(arr, length);
    char* arr3 = CopyArray(arr, length);
    char* arr4 = CopyArray(arr, length);
    char* arr5 = CopyArray(arr, length);
    printf("Initial Array:  ");
    PrintArray(arr, length);

    BubbleSort(arr1, length);
    InsertionSort(arr2, length);
    CountingSort(arr3, length);
    QiuckSort(arr4, length);
    MergeSort(arr5, length);
    return 0;

}