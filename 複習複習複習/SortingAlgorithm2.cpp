#include <bits/stdc++.h>
using namespace std;


int* RandomArray(int length, int max){

    int* arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        arr[i] = -1;
    }

    int check[max + 1];
    for(int i = 0; i < (max + 1); i ++){
        check[i] = 0;
    }

    for(int i = 0; i < length; i ++){
        while(1){
            int temp = rand() % (max + 1);
            if(check[temp] == 0){
                arr[i] = temp;
                check[temp] = 1;
                break;
            }
        }
    }
    return arr;

}
int* CopyArray(int* arr1, int length){

    int* arr2 = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        arr2[i] = arr1[i];
    }
    return arr2;

}
void PrintArray(int* arr, int length){

    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
void BubbleSort(int* arr, int length){

    // printf("\nBefore: ");
    // PrintArray(arr, length);

    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("BubbleSort:    ");
    PrintArray(arr, length);

}
void InsertionSort(int* arr, int length){

    // printf("\nBefore: ");
    // PrintArray(arr, length);

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while((cnt > 0) && (temp < arr[cnt - 1])){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

    printf("InsertionSort: ");
    PrintArray(arr, length);

}
void CountingSort(int* arr, int length){

    // printf("\nBefore: ");
    // PrintArray(arr, length);

    //Search Maximun
    int max = 0;
    for(int i = 0; i < length; i ++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    // printf("maximun = %d\n", max);
    int CountingArray[max + 1];
    for(int i = 0; i < (max + 1); i ++){
        CountingArray[i] = 0;
    }
    for(int i = 0; i < length; i ++){
        CountingArray[arr[i]] ++;
    }
    // printf("累加前: ");
    // PrintArray(CountingArray, (max + 1));
    for(int i = 1; i < (max + 1); i ++){
        CountingArray[i] += CountingArray[i - 1];
    }
    // printf("累加後: ");
    // PrintArray(CountingArray, (max + 1));
    int OutputArray[length];
    for(int i = (length - 1); i >= 0; i --){
        OutputArray[CountingArray[arr[i]] - 1] = arr[i];
    }

    printf("CountingSort:  ");
    PrintArray(OutputArray, length);

}
int Tool_QucikSort(const void* a, const void* b){

    int result = *(int*)a - *(int*)b;
    return result;

}
void QuickSort(int* arr, int length){

    // printf("\nBefore: ");
    // PrintArray(arr, length);

    qsort(arr, length, sizeof(int), Tool_QucikSort);

    printf("QuickSort:     ");
    PrintArray(arr, length);

}
void Tool_MergeSort(int* arr, int start, int mid, int end){

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
        else if(arrL[i] < arrR[j]){
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
void MergeLoop(int* arr, int start, int end){

    if(start >= end - 1){
        return ;
    }

    int mid = start + (end - start) / 2;
    MergeLoop(arr, start, mid);
    MergeLoop(arr, mid, end);
    Tool_MergeSort(arr, start, mid, end);

}
void MergeSort(int* arr, int length){

    // printf("\nBefore: ");
    // PrintArray(arr, length);

    MergeLoop(arr, 0, length);

    printf("MergeSort:     ");
    PrintArray(arr, length);

}

int main(void){

    srand(time(0));
    int length = 10;
    int max = 20;
    int* arr1 = RandomArray(length, max);
    int* arr2 = CopyArray(arr1, length);
    int* arr3 = CopyArray(arr1, length);
    int* arr4 = CopyArray(arr1, length);
    int* arr5 = CopyArray(arr1, length);
    printf("Initial Array: ");
    PrintArray(arr1, length);

    BubbleSort(arr1, length);
    InsertionSort(arr2, length);
    CountingSort(arr3, length);
    QuickSort(arr4, length);
    MergeSort(arr5, length);
    return 0;

}