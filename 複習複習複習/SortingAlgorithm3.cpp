#include <bits/stdc++.h>
using namespace std;

void PrintArray(int* arr, int length){

    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
int* NRRandomArray(int length, int max){

    srand(time(0));
    int check[max];
    for(int i = 0; i < max; i ++){
        check[i] = 0;
    }

    int* arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        int temp = rand() % max;
        if(check[temp] == 0){
            check[temp] = 1;
            arr[i] = temp;
            continue;
        }
        i --;
    }
    return arr;

}
int* RandomArray(int length, int max){

    srand(time(0));
    int* arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        arr[i] = rand() % max;
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

void CountingSort(int* arr, int length){

    int max = -1;
    for(int i = 0; i < length; i ++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

    int CountingArray[max + 1];
    for(int i = 0; i < (max + 1); i ++){
        CountingArray[i] = 0;
    }

    for(int i = 0; i < length; i ++){
        CountingArray[arr[i]] ++;
    }

    for(int i = 1; i < (max + 1); i ++){
        CountingArray[i] = CountingArray[i] + CountingArray[i - 1];
    }

    int OutputArray[length];
    for(int i = (length - 1); i >= 0; i --){
        OutputArray[CountingArray[arr[i]] - 1] = arr[i];
        CountingArray[arr[i]] --;
    }

    for(int i = 0; i < length; i ++){
        arr[i] = OutputArray[i];
    }

}

void BubbleSort(int* arr, int length){

    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

}

void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;

        while((cnt > 0) && (temp < arr[cnt - 1])){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }

        arr[cnt] = temp;
    }

}

int Compare(const void* a, const void* b){

    return *(int*)a - *(int*)b;

}
void QuickSort(int* arr, int length){

    qsort(arr, length, sizeof(int), Compare);

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
void MergeLoop(int* arr, int length, int start, int end){

    if(start >= (end - 1)){
        return ;
    }

    int mid = start + (end - start) / 2;
    MergeLoop(arr, length, start, mid);
    MergeLoop(arr, length, mid, end);
    Merge(arr, length, start, mid, end);

}
void MergeSort(int* arr, int length){

    MergeLoop(arr, length, 0, length);

}

int main(void){

    int length = 8;
    int max = 10;
    int* arr = RandomArray(length, max); //數字可重複
    //int* arr = NRRandomArray(length, max); //數字不重複

    int* arr1 = CopyArray(arr, length);
    int* arr2 = CopyArray(arr, length);
    int* arr3 = CopyArray(arr, length);
    int* arr4 = CopyArray(arr, length);
    int* arr5 = CopyArray(arr, length);

    printf("InputArray:     ");
    PrintArray(arr, length);
    printf("\n");

    CountingSort(arr1, length);
    printf("Counting Sort:  ");
    PrintArray(arr1, length);

    BubbleSort(arr2, length);
    printf("Bubble Sort:    ");
    PrintArray(arr2, length);

    InsertionSort(arr3, length);
    printf("Insertion Sort: ");
    PrintArray(arr3, length);

    QuickSort(arr4, length);
    printf("Quick Sort:     ");
    PrintArray(arr4, length);

    MergeSort(arr5, length);
    printf("Merge Sort:     ");
    PrintArray(arr5, length);
    return 0;

}