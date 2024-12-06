#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* RandomArray_nonrepeat(int length, int max){

    int* arr = (int*)malloc(sizeof(int) * length);
    int check[max];
    for(int i = 0; i < max; i ++){
        check[i] = 0;
    }
    int i = 0;
    while(i < length){
        int temp = rand() % max;
        if(check[temp] == 0){
            arr[i] = temp;
            check[temp] = 1;
            i ++;
        }
    }
    return arr;

}
int* RandomArray_repeat(int length, int max){

    int* arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        arr[i] = rand() % max;
    }
    return arr;

}
void PrintArray(int* arr, int length){
    
    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while(cnt > 0 && temp < arr[cnt - 1]){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

}
int BS(int* arr, int length, int target){

    int left = 0;
    int right = length; //左閉右開
    while(left < right){
        int mid = left + (right - mid) / 2;
        if(target == arr[mid]){
            return mid;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
        else if(target < arr[mid]){
            right = mid;
        }
    }
    return -1;

}
int BS_LefrBound(int* arr, int length, int target){

    int left = 0;
    int right = length;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(target == arr[mid]){
            right = mid;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
        else if(target < arr[mid]){
            right = mid;
        }
    }
    if(arr[left] != target){
        return -1;
    }
    return left;

}
int BS_RightBound(int* arr, int length, int target){

    int left = 0;
    int right = length;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(target == arr[mid]){
            left = mid + 1;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
        else if(target < arr[mid]){
            right = mid;
        }
    }
    if(arr[left - 1] != target){
        return -1;
    }
    return left - 1;

}

int main(void){

    srand(time(0));
    int length = 10;
    int max = 100;
    //non repeated random array
    int* arr_nr = RandomArray_nonrepeat(length, max);
    PrintArray(arr_nr, length);

    InsertionSort(arr_nr, length);
    PrintArray(arr_nr, length);

    int target;
    printf("target = ");
    scanf("%d", &target);
    printf("position: %d (基本BS)\n\n", BS(arr_nr, length, target));

    // repeated random array
    max = 10;
    int* arr_r = RandomArray_repeat(length, max);
    PrintArray(arr_r, length);

    InsertionSort(arr_r, length);
    PrintArray(arr_r, length);

    int target2;
    printf("target = ");
    scanf("%d", &target2);
    printf("position: %d (BS找左邊界)\n", BS_LefrBound(arr_r, length, target2));
    printf("position: %d (BS找右邊界)\n", BS_RightBound(arr_r, length, target2));
    return 0;

}