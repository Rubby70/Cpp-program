// 給你一個array，array的長度則為1~20的隨機一個數字，
// 這個array裡面只會含有1跟0兩種數字。
// 找出這一個array當中，最多的連續的1是幾個
// Ex: [1,1,0,1,1,1] <--- 給你這個array 你要回傳3 因為最多連續出現的1是3次
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void PrintArray(int* arr, int length){

    printf("[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}

int main(void){

    srand(time(0));
    //int length = (rand() % 20) + 1;
    int length = 10;
    printf("length = %d\n", length);
    int arr[length];
    for(int i = 0; i < length; i ++){
        int temp = rand() % 2;
        if(temp % 2 == 0)
            arr[i] = 0;
        else if(temp % 2 == 1)
            arr[i] = 1;
    }
    printf("input: ");
    PrintArray(arr, length);

    int MaxCount = 0;
    int count = 0;
    for(int i = 0; i < length; i ++){
        if(arr[i] == 1){
            count ++;
        }
        if(count > MaxCount)
            MaxCount = count;
        if(arr[i] == 0)
            count = 0;
    }
    printf("1最多連續出現%d次\n", MaxCount);
    return 0;

}