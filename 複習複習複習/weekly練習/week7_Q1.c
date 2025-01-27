// 寫一個函數
// 在函數中利用這個長度使用malloc建立一個整數陣列 
// 在不使用回傳值的情況下 要讓main函數接到這個pointer
// 然後讓這個陣列可以在main裡面使用（印出原有內容並排序）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//declaration
int* CopyArray(int* arr, int length);
void CreatArray(int** ptr2main, int length);
void PrintArray(int* arr, int length);
void InsertionSort(int* arr, int length);
void BubbleSort(int* arr, int length);
void MergeSort(int* arr, int length, int start, int end);
void MergeLoop(int* arr, int start, int mid, int end);

//definition
int* CopyArray(int* arr, int length){

    int* temp = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++)
        temp[i] = arr[i];
    return temp;

}
void CreatArray(int** ptr2main, int length){

    int* temp = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        temp[i] = rand() % 10;
    }
    *ptr2main = temp;

}
void PrintArray(int* arr, int length){

    printf("[");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
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
    printf("Bubble Sort: ");
    PrintArray(arr, length);

}
void MergeSort(int* arr, int length, int start, int end){

    if(start >= (end - 1)){
        return ;
    }
    int mid = start + ((end - start) / 2);

    if(end - start == length){
        printf("(%d ~ %d], 排序前: [ ", start, end);
        for(int i = start; i < end; i ++){
            printf("%d ", arr[i]);
        }
        printf("]\n");
    }

    printf("call MergeSort(start: %d, end: %d)\n", start, mid);
    printf("(%d ~ %d], 排序前: [ ", start, mid);
    for(int i = start; i < mid; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    MergeSort(arr, length, start, mid); //遞迴 [start ~ mid)

    printf("call MergeSort(start: %d, end: %d)\n", mid, end);
    printf("(%d ~ %d], 排序前: [ ", mid, end);
    for(int i = mid; i < end; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    MergeSort(arr, length, mid, end); //遞迴 [mid ~ end)

    MergeLoop(arr, start, mid, end); //排序 [start ~ end)
    printf("(%d ~ %d], 排序後: [ ", start, end);
    for(int i = start; i < end; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
void MergeLoop(int* arr, int start, int mid, int end){

    int left = mid - start;
    int right = end - mid;
    int arr1[left];
    for(int i = 0; i < left; i ++){
        arr1[i] = arr[start + i];
    }
    int arr2[right];
    for(int i = 0; i < right; i ++){
        arr2[i] = arr[mid + i];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while((i < left) && (j < right)){
        if(arr1[i] >= arr2[j]){
            arr[k] = arr2[j];
            j ++;
            k ++;
        }
        else if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i ++;
            k ++;
        }
    }
    while(i < left){
        arr[k] = arr1[i];
        i ++;
        k ++;
    }
    while(j < right){
        arr[k] = arr2[j];
        j ++;
        k ++;
    }

}

int main(void){

    srand(time(0));
    int length = 5;
    int* ptr = NULL;
    CreatArray(&ptr, length);
    int* ptr2 = CopyArray(ptr, length); //複製ptr
    int* ptr3 = CopyArray(ptr, length);
    
    MergeSort(ptr3, length, 0, length);

    printf("\n初始陣列: ");
    PrintArray(ptr, length);

    //sorting algorithm
    BubbleSort(ptr, length);
    InsertionSort(ptr2, length);
    printf("Merge Sort: ");
    PrintArray(ptr3, length);
    return 0;

}