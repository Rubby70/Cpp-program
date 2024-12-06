#include <bits/stdc++.h>
using namespace std;


void MergeSort(int* arr, int length, int start, int end);
void MergeLoop(int* arr, int length, int start, int end);
void sorting(int* arr, int length, int start, int mid, int end);

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

    cout << "[ ";
    for(int i = 0; i < length; i ++){
        cout << arr[i] << " ";
    }
    cout << "]\n";

}
void CountingSort(int* InputArray, int length){

    int max = 0;
    for(int i = 0; i < length; i ++){
        if(InputArray[i] > max)
            max = InputArray[i];
    }

    int CountingArray[max + 1];
    for(int i = 0; i < (max + 1); i ++)
        CountingArray[i] = 0;
    // cout << "CountingArray 初始化: ";
    // PrintArray(CountingArray, (max + 1));

    for(int i = 0; i < length; i ++)
        CountingArray[InputArray[i]] ++;
    // cout << "CountingArray 計數:   ";
    // PrintArray(CountingArray, (max + 1));

    for(int i = 1; i < (max + 1); i ++)
        CountingArray[i] += CountingArray[i - 1];
    // cout << "CountingArray 加總:   ";
    // PrintArray(CountingArray, (max + 1));
    
    int OutputArray[length];
    for(int i = length - 1; i >= 0; i --){
        OutputArray[CountingArray[InputArray[i]] - 1] = InputArray[i];
        CountingArray[InputArray[i]] --;
    }
    cout << "Counting Sort:  ";
    PrintArray(OutputArray, length);

}
void BubbleSort(int* arr, int length){
    
    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Bubble Sort:    ";
    PrintArray(arr, length);
    
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
    cout << "Insertion Sort: ";
    PrintArray(arr, length);

}
void MergeSort(int* arr, int length, int start, int end){

    MergeLoop(arr, length, start, end);
    cout << "Merge Sort:     ";
    PrintArray(arr, length);

}
void MergeLoop(int* arr, int length, int start, int end){

    if(start >= end - 1)
        return ;

    int mid = start + (end - start) / 2;
    MergeLoop(arr, length, start, mid);
    MergeLoop(arr, length, mid, end);
    sorting(arr, length, start, mid, end);
    
}
void sorting(int* arr, int length, int start, int mid, int end){

    // cout << "before sort: [ ";
    // for(int i = start; i < end; i ++){
    //     cout << arr[i] << " ";
    // }
    // cout << "]\n";
    int left = mid - start;
    int right = end - mid;
    int arrL[left];
    for(int i = 0; i < left; i ++)
        arrL[i] = arr[start + i];
    
    int arrR[right];
    for(int i = 0; i < right; i ++)
        arrR[i] = arr[mid + i];
    
    int i = 0;
    int j = 0;
    int k = start;
    while(i < left && j < right){
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
    // cout << "after sort: [ ";
    // for(int i = start; i < end; i ++){
    //     cout << arr[i] << " ";
    // }
    // cout << "]\n";

}
int compare(const void* a, const void* b){

    return *(int*)a - *(int*)b;

}

int main(void){

    srand(time(0));
    int length = 5;
    int* arr1 = RandomArray(length);
    int* arr2 = CopyArray(arr1, length);
    int* arr3 = CopyArray(arr1, length);
    int* arr4 = CopyArray(arr1, length);
    int* arr5 = CopyArray(arr1, length);

    cout << "Unsorted Array: ";
    PrintArray(arr1, length);

    CountingSort(arr1, length);
    BubbleSort(arr2, length);
    InsertionSort(arr3, length);
    MergeSort(arr4, length, 0, length);

    qsort(arr5, length, sizeof(int), compare);
    cout << "Quick Sort:     ";
    PrintArray(arr5, length);
    return 0;
    
}