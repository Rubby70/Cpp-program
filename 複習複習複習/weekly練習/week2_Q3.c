// 我會給你一個數字, 範圍在1~2147483647之間，
// 你可以將這數字當中的 奇數與奇數交換，偶數與偶數交換，試著去祖出最大的數字
// Ex: 給你1234， 代表 1"只能跟"3交換，2"只能跟"4交換 而交換後最大的結果就是3412
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void Reverse(int* arr, int length){

    int* tempArr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++)
        tempArr[i] = arr[i];
    for(int i = 0; i < length; i ++)
        arr[i] = tempArr[(length - 1) - i];
    
}
void ArrayInitialize(int* arr, int length){

    for(int i = 0; i < length; i ++){
        arr[i] = 0;
    }

}
void PrintArray(int* arr, int length){

    printf("[");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}
int CheckDigits(int input){ //確認input是幾位數

    int HowManyDigits = 0;
    for(int i = 0; (int)pow(10, i) < input; i ++)
        HowManyDigits ++;
    return HowManyDigits;

}
int* SeperateDigits(int input){ //將數字一個一個放進陣列裡

    int length = CheckDigits(input);
    int* arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        int temp = input;
        temp /= (int)pow(10, i);
        temp %= 10;
        arr[i] = temp;
    }
    return arr;

}
void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while(cnt > 0 && temp > arr[cnt - 1]){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

}

int main(void){

    srand(time(0));
    int RandomNumber = (rand() % 10000) + 1;
    int HowManyDigits = CheckDigits(RandomNumber);
    int* arr = SeperateDigits(RandomNumber);
    Reverse(arr, HowManyDigits);
    printf("input : ");
    for(int i = 0; i < HowManyDigits; i ++){
        printf("%d", arr[i]);
    }
    printf("\n");

    int odd[HowManyDigits];
    int even[HowManyDigits];
    int position[HowManyDigits];
    ArrayInitialize(odd, HowManyDigits);
    ArrayInitialize(even, HowManyDigits);
    ArrayInitialize(position, HowManyDigits);
    for(int i = 0; i < HowManyDigits; i ++){
        if(arr[i] % 2 == 1){
            position[i] = 1;
            odd[i] = arr[i];
        }
        else if(arr[i] % 2 == 0){
            position[i] = 2;
            even[i] = arr[i];
        } 
    }
    InsertionSort(odd, HowManyDigits);
    InsertionSort(even, HowManyDigits);

    int cnt_odd = 0;
    int cnt_even = 0;
    printf("output: ");
    for(int i = 0; i < HowManyDigits; i ++){
        if(position[i] == 1){ //奇數
            printf("%d", odd[cnt_odd]);
            cnt_odd ++;
        }
        else if(position[i] == 2){
            printf("%d", even[cnt_even]);
            cnt_even ++;
        }
    }
    printf("\n");
    return 0;

}