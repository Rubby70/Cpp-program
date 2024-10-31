// 寫一個程式 他可以計算使用者輸入的數字的總和，我會不停的輸入一個數字 
// 在輸入後你要自己先計算好總和 但不印出。  
// 直到我輸入了一個負數  就把總和印出 並把程式結束。
// Ex:  
// 輸入1 -> 你在背後默默計算
// 輸入3 -> 同理
// 輸入7 -> 同理
// 輸入 -8 -> 遇到負數  把總和印出來 然後結束程式
#include <stdio.h>


int main(void){

    int input;
    int sum = 0;
    while(1){
        scanf("%d", &input);
        if(input < 0)
            break;
        sum += input;
    }
    printf("sum: %d\n", sum);
    return 0;

}