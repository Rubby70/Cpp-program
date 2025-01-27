#include "stdio.h"
#include "stdlib.h"


// 給定範圍[0,10)請問最大的迴圈次數
int bin_search(int *arr, int target){
    int l = 0, r = 10;
    while(l < r){
        int mid = (l + r) / 2;
        if(arr[mid] < target)
            l = mid;
        else if(arr[mid] > target)
            r = mid;
        else
            return mid;
    }

    return -1;
}


int main(void){


    return 0;
}