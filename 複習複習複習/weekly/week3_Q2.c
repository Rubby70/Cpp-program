// 寫一個程式  我們會輸入任意數字N， N > 0 
// 對於所有小於N的正整數，計算所有不是3的倍數的數字的和
// Ex:  輸入N = 10 
// 那你就要印出 1+2+4+5+7+8
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    srand(time(0));
    int N;
    scanf("%d", &N);
    printf("N = %d\n", N);

    int sum = 0;
    for(int i = 1; i < N; i ++){
        if(i == 1){
            sum += i;
            printf("%d+", i);
            continue;
        }
        if(i == 2){
            sum += i;
            printf("%d", i);
            continue;
        }
        if(i % 3 == 0)
            continue;
        sum += i;
        printf("+%d", i);
    }
    printf(" = %d\n" , sum);
    return 0;
    
}