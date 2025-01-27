// 99 乘法表
#include <stdio.h>


int main(void){

    for(int i = 1; i <= 9; i ++){
        printf("%d\n", i);
        for(int j = 1; j <= 9; j ++){
            printf("%d * %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    return 0;

}