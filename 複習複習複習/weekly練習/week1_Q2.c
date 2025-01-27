// 輸入一個數字 (0~999) 檢查每個digits，如果是奇數則保持不變 ，偶數則要除以2
// Ex. 111 -> 111, 444 -> 222, 121 -> 111
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int* CheckDigits(int* arr, int input){

    for(int i = 0; i < 3; i ++){
        arr[i] = 0;
    }
    int temp;
    for(int i = 0; i <= 2; i ++){
        temp = input;
        temp /= (int)pow(10, i);
        temp %= 10;
        arr[2 - i] = temp;
    }

}
void PrintNumber(int* arr){

    int count = 0;
    for(int i = 0; i < 3; i ++){
        if(arr[i] != 0) //如果開始有非1的數字出現才開始印數字
            count = 1;
        if(count)
            printf("%d", arr[i]);
    }
    if(count == 0) // 如果count == 0 代表三個位數的數字都是0
        printf("0");
    printf("\n");

}
void IfPrime(int* arr){

    int i = 0;
    while(i < 3){
        if(arr[i] != 0 && arr[i] % 2 == 0)
            arr[i] /= 2;
        i ++; 
    }

}

int main(void){

    srand(time(0));
    int input = rand() % 1000;
    printf("目標數字: %d\n", input);

    int arr[3];
    CheckDigits(arr, input);
    printf("處理前:");
    PrintNumber(arr);

    IfPrime(arr);
    printf("處理後:");
    PrintNumber(arr);
    return 0;

}