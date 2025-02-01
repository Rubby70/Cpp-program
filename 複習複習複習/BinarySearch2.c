#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int BS(int* arr, int length, int target){

    int left = 0;
    int right = length;
    int mid = -1;
    
    while(left < right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            right = mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return -1;
    
}
int BS_LeftBound(int* arr, int length, int target){

    int left = 0;
    int right = length;
    int mid = -1;

    while(left < right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            right = mid;
        }
        else if(arr[mid] > target){
            right = mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return left;

}
int BS_RightBound(int* arr, int length, int target){

    int left = 0;
    int right = length;
    int mid = -1;

    while(left < right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            left = mid + 1;
        }
        else if(arr[mid] > target){
            right = mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
    }
    return right - 1;

}

int main(void){
    
    srand(time(0));
    int length = 7;
    int arr[7] = {1, 3, 5, 5, 5, 7, 9};
    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    int target = 0;
    while(target != -1){
        printf("plz set target number (輸入-1時停止): ");
        scanf("%d", &target);
        int position = BS(arr, length, target);
        int positionL = BS_LeftBound(arr, length, target);
        int positionR = BS_RightBound(arr, length, target);
        printf("基本二分搜索: %d, 左邊界: %d, 右邊界: %d\n", position, positionL, positionR);
    }
    return 0;

}