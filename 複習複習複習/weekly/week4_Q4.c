// 給定一個目標數字 N 你要把他轉成二進位印出來
// 迴圈跟遞迴各一次
#include <stdio.h>


void binary_recursive(int N, int cnt){

    if(cnt == 31){
        printf("recursive version\n");
        printf("N = %d => ", N);
    }
    printf("%d", (N >> cnt) & 1);
    if(cnt == 0){
        printf("\n");
        return ;
    }
    if(cnt > 0){
        cnt --;
        binary_recursive(N, cnt);
    }

}
void binary_iterator(int N){

    printf("iterator version\n");
    printf("N = %d => ", N);
    for(int i = 31; i >= 0; i --){
        printf("%d", (N >> i) & 1);
    }
    printf("\n");

}

int main(void){

    int N;
    printf("請指定N: ");
    scanf("%d", &N);
    binary_recursive(N, 31);
    binary_iterator(N);
    return 0;

}