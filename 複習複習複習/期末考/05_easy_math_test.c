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

void prime1(){

    int i;
    int j;
    printf("prime1:\n");
    printf("[ ");
    for(i = 2; i <= 100; i ++){
        for(j = 2; j < i; j ++){
            if((i % j) == 0){ //如果有除了自己以外的數字可以整除，代表不是質數
                break;
            }
        }

        if(j == i){ //j == i 代表沒有任何數字可以整除i
            printf("%d ", i);
        }
    }
    printf("]\n");

}
void prime2(){

    printf("prime2:\n");
    int arr[101];
    for(int i = 0; i < 100; i ++){
        arr[i] = i;
    }
    arr[0] = 0;
    arr[1] = 0;

    for(int i = 2; i <= sqrt(100); i ++){
        for(int j = 2; (i * j) <= 100; j ++){
            arr[(i * j)] = 0;
        }
    }
    printf("[ ");
    for(int i = 0; i <= 100; i ++){
        if(arr[i] != 0){
            printf("%d ", arr[i]);
        }
    }
    printf("]\n");

}
void Maximum_Sum_Subarray(){

    int arr[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int MaxSum = 0;
    int Start, End;
    int TempSum = 0;
    for(int i = 0; i < 10; i ++){
        TempSum = 0;
        for(int j = i; j < 10; j ++){
            TempSum += arr[j];
            if(TempSum > MaxSum){
                MaxSum = TempSum;
                Start = i;
                End = j;
            }
        }
    }

    printf("MaxSum = %d, Start: %d, End: %d\n", MaxSum, Start, End);
    printf("[ ");
    for(int i = Start; i <= End; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}

int main(void) { 
    
    // printf("100內的質數:\n[ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 ]\n");
    // prime1();
    // prime2();

    Maximum_Sum_Subarray();
    return 0;

}
