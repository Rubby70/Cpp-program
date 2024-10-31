// 給定一個目標數字N 你要算出Fibonacci 數量的第N項第數字
// 迴圈跟遞迴各一次
// Fib(0) = 0
// Fib(1) = 1
// Fib(2) = Fib(0) + Fib(1) = 1
// Fib(3) = Fib(1) + Fib(2) = 2
// Fib(4) = Fib(2) + Fib(3) = 3
// Fib(5) = Fib(3) + Fib(4) = 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* check = NULL;

int Fib_recursive(int N){
    
    if(check[N] != -1){
        printf("%d已經計算過了, Fib[%d] = %d\n", N, N, check[N]);
        return check[N];
    }
    if(N == 0){
        check[N] = 0;
        return 0;
    }
    else if(N == 1){
        check[N] = 1;
        return 1;
    }
    int value = Fib_recursive(N - 2) + Fib_recursive(N - 1);
    check[N] = value;
    return value;

}
int Fib_iterator(int N){

    if(N == 0){
        return 0;
    }
    else if(N == 1){
        return 1;
    }
    int value = 0;
    int value_pre2 = 0; //Fib(0) = 0
    int value_pre1 = 1; //Fib(1) = 1
    for(int i = 2; i <= N; i ++){
        value = value_pre2 + value_pre1;
        value_pre2 = value_pre1;
        value_pre1 = value;
    }
    return value;

}

int main(void){

    int N;
    printf("請指定N: ");
    scanf("%d", &N);
    check = (int*)malloc(sizeof(int) * N + 1);
    for(int i = 0; i < N + 1; i ++){
        check[i] = -1;
    }
    printf("Fib_recursive(%d) = %d\n", N, Fib_recursive(N));
    printf("Fib_iterator(%d) = %d\n", N, Fib_iterator(N));
    return 0;

}