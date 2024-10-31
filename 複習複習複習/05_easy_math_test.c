// 1. 使用兩種方法來印出1~100的質數
// 2. maximum sum subarray, 在這個題目當中我會給你一個array
//   在這個array當中，你需要找出一個subarray，使得這個subarray的總和是最大的
//   並且印出這個subarray的起始index和結束index
//   例如: int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//   最大的subarray是{4, -1, 2, 1}，總和是6
//   起始index是3，結束index是6
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

void prime_1(){

    int max = 20;
    int arr[max];
    for(int i = 0; i < max; i ++){
        arr[i] = i + 1;
    }
    printf("[");
    for(int i = 0; i < max; i ++){
        if(arr[i] == 0)
            continue;
        printf("%d ", arr[i]);
    }
    printf("]\n");

    int i = 1;
    while(i < max){
        int digit = arr[i];
        for(int j = 2; j <= (sqrt(digit)); j ++){
            if(digit % j == 0){
                arr[i] = 0;
                break;
            }
        }
        i ++;
    }

    printf("[");
    for(int i = 0; i < max; i ++){
        if(arr[i] == 0)
            continue;
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
void prime_2(){

    int max = 20;
    int arr[max];
    for(int i = 0; i < max; i ++){
        arr[i] = i + 1;
    }
    printf("[");
    for(int i = 0; i < max; i ++){
        if(arr[i] == 0)
            continue;
        printf("%d ", arr[i]);
    }
    printf("]\n");

    int i = 1;
    while(i < max){
        if(arr[i] != 0){
            int digit = arr[i];
            for(int k = 2; (digit * k) <= max; k ++){
                arr[(digit * k) - 1] = 0;
            }
        }
        i ++;
    }

    printf("[");
    for(int i = 0; i < max; i ++){
        if(arr[i] == 0)
            continue;
        printf("%d ", arr[i]);
    }
    printf("]\n");

}

int main(void) { 
    
    //prime_1();
    prime_2();
    return 0;

}
