// 我會給你一個數字, 範圍在1~2147483647，這個數字只由6跟9組成。
// 告訴我 在"最多只能把一個digit從6換成9，或者9換成6的情況下"  你能組成的最大數字。

// 不小心寫成交換6和9 !!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int CheckDigits(int input){ //確認input是幾位數

    int HowManyDigits = 0;
    for(int i = 0; (int)pow(10, i) < input; i ++)
        HowManyDigits ++;
    return HowManyDigits;

}
int* SeperateDigits(int input){ //將數字一個一個放進陣列裡

    int length = CheckDigits(input);
    int* arr = malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        int temp = input;
        temp /= (int)pow(10, i);
        temp %= 10;
        arr[i] = temp;
    }
    return arr;

}
void GenerateSpecialNumber(int* arr, int length){ //將隨機數轉換成由6和9組成的數字

    for(int i = 0; i < length; i ++){
        if(arr[i] % 2 == 0)
            arr[i] = 6;
        else if(arr[i] % 2 == 1)
            arr[i] = 9;
    }

}
int Find_Left_6(int* arr, int length){

    int position = -1;
    for(int i = 0; i < length; i ++){
        if(arr[i] == 6){
            position = i;
        }
    }
    if(position == -1) //代表沒有任何一個6
        return -1;
    else
        return position;

}
int Find_Right_9(int* arr, int length){

    int position = -1;
    for(int i = 0; i < length; i ++){
        if(arr[i] == 9){
            position = i;
            break;
        }
    }
    if(position == -1) //代表沒有任何一個9
        return -1;
    else
        return position;

}
void Rearrange(int* arr, int length){

    int left = Find_Left_6(arr, length);
    int right = Find_Right_9(arr, length);
    if(left == -1 || right == -1){
        printf("沒有數字可以交換\n");
        return;
    }
    printf("第%d個數字和第%d個數字交換 (個位數字是第一個數字)\n", left + 1, right + 1);
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

}

int main(void){

    // 這一區是在產生符合題目要求的input (由6和9組成)
    srand(time(0));
    int RandomNumber = (rand() % 10000) + 1;
    int HowManyDigits = CheckDigits(RandomNumber);
    //printf("RandomNumber: %d, 是%d位數\n", RandomNumber, HowManyDigits);
    int* arr = SeperateDigits(RandomNumber);
    GenerateSpecialNumber(arr, HowManyDigits);
    printf("input: ");
    for(int i = HowManyDigits - 1; i >= 0; i --){
        printf("%d", arr[i]);
    }
    printf("\n");

    // 實際解題的部分
    Rearrange(arr, HowManyDigits);
    printf("output: ");
    for(int i = HowManyDigits - 1; i >= 0; i --){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;

}