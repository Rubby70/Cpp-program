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

int Compare(const void* A, const void* B){

    return *(char*)A - *(char*)B;

}
void QiuckSort(char* arr, int length){

    qsort(arr, length, sizeof(char), Compare);

    printf("Quick Sort:     ");
    PrintArray(arr, length);

}

void Merge(char* arr, int length, int start, int mid, int end){

    int left = mid - start;
    int right = end - mid;
    char arrL[left];
    for(int i = 0; i < left; i ++){
        arrL[i] = arr[start + i];
    }
    char arrR[right];
    for(int i = 0; i < right; i ++){
        arrR[i] = arr[mid + i];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while((i < left) && (j < right)){
        if(arrL[i] > arrR[j]){
            arr[k] = arrR[j];
            j ++;
            k ++;
        }
        else{
            arr[k] = arrL[i];
            i ++;
            k ++;
        }
    }

    while(i < left){
        arr[k] = arrL[i];
        i ++;
        k ++;
    }
    while(j < right){
        arr[k] = arrR[j];
        j ++;
        k ++;
    }

}
void MergeLoop(char* arr, int length, int start, int end){

    if(start >= (end - 1)){
        return ;
    }

    int mid = start + (end - start) / 2;
    MergeLoop(arr, length, start, mid);
    MergeLoop(arr, length, mid, end);
    Merge(arr, length, start, mid, end);

}
void MergeSort(char* arr, int length){

    MergeLoop(arr, length, 0, length);
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