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

    int max = 0;
    for(int i = 0; i < length; i ++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int CountingArrLength = max + 1;
    int CountingArray[CountingArrLength];
    for(int i = 0; i < CountingArrLength; i ++){
        CountingArray[i] = 0;
    }
    for(int i = 0; i < length; i ++){
        CountingArray[arr[i]] ++;
    }
    for(int i = 1; i < CountingArrLength; i ++){
        CountingArray[i] += CountingArray[i - 1];
    }

    int OutputArr[length];
    for(int i = 0; i < length; i ++){
        OutputArr[i] = 0;
    }
    for(int i = length - 1; i >= 0; i --){
        OutputArr[CountingArray[arr[i]] - 1] = arr[i];
        CountingArray[arr[i]] --;
    }

    printf("Counting Sort:  ");
    PrintArray(OutputArr, length);

}
void BubbleSort(int* arr, int length){

    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Bubble Sort:    ");
    PrintArray(arr, length);

}
void InsertionSort(int* arr, int length){

    for(int i = 0; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while((cnt > 0) && (temp < arr[cnt - 1])){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

    printf("Insertion Sort: ");
    PrintArray(arr, length);

}

int Compare(const void* a, const void* b){

    return *(int*)a - *(int*)b;

}
void QuickSort(int* arr, int length){

    qsort(arr, length, sizeof(int), Compare);

    printf("Quick Sort:     ");
    PrintArray(arr, length);

}

void Merge(int* arr, int length, int start, int mid, int end){

    int left = mid - start;
    int right = end - mid;
    int arrL[left];
    for(int i = 0; i < left; i ++){
        arrL[i] = arr[start + i];
    }

    int arrR[right];
    for(int i = 0; i < right; i ++){
        arrR[i] = arr[mid + i];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while((i < left) && (j < right)){
        if(arrL[i] >= arrR[j]){
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
void MergeLoop(int* arr, int length, int start, int end){

    while(start >= end - 1){
        return;
    }

    int mid = start + (end - start) / 2;
    MergeLoop(arr, length, start, mid);
    MergeLoop(arr, length, mid, end);
    Merge(arr, length, start, mid, end);

}
void MergeSort(int* arr, int length){

    MergeLoop(arr, length, 0, length - 1);

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