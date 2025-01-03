// 第二題, merge sort
#include "iostream"
#include "time.h"

void mergeSort(int *arr, int start, int end);
void fuse(int *arr, int start, int mid, int end);
void mergeSort_loop(int *arr, int start, int end);

int main(void) {

    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        printf("%d -> ", arr[i]);
    }
    printf("End\n");
    mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < 10; i++) {
        // arr[i] = rand() % 100;
        printf("%d -> ", arr[i]);
    }
    printf("End\n");

    return 0;
}

void mergeSort(int *arr, int start, int end){

    mergeSort_loop(arr, start, end);

};
void fuse(int *arr, int start, int mid, int end){
    
    printf("start: %d, mid: %d, end: %d, ", start, mid, end);
    int n1 = mid - start + 1;
    int n2 = end - mid;
    printf("n1 = %d, n2 = %d\n", n1, n2);
    int arr1[n1];
    printf("arr1:[ ");
    for(int i = 0; i < n1; i ++){
        arr1[i] = arr[start + i];
        printf("%d ", arr1[i]);
    }
    printf("], ");
    printf("arr2:[ ");
    int arr2[n2];
    for(int i = 0; i < n2; i ++){
        arr2[i] = arr[mid + 1 + i];
        printf("%d ", arr2[i]);
    }
    printf("], ");

    int i = 0;
    int j = 0;
    int k = start;
    while(i < n1 && j < n2){
        if(arr1[i] >= arr2[j]){
            arr[k] = arr1[i];
            i ++;
        }
        else if(arr1[i] < arr2[j]){
            arr[k] = arr2[j];
            j ++;
        }
        k ++;
    }
    while(i < n1){
        arr[k] = arr1[i];
        i ++;
        k ++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j ++;
        k ++;
    }
    printf("merge:[");
    for(int i = start; i <= end; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

};
void mergeSort_loop(int *arr, int start, int end){

    if(start >= end)
        return;
    int mid = start + ((end - start) / 2);
    mergeSort_loop(arr, start, mid); //左閉右閉
    mergeSort_loop(arr, mid + 1, end);
    fuse(arr, start, mid, end);

};