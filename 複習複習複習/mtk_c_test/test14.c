#include "stdio.h"
#include "stdlib.h"

int test(int x){
    static int a;
    return a + x;
}

int main(void){

    int a = 0;
    int b = 0;
    while(1){
        b = 0;
        for(int i = 0; i < 3; i++){
            a = test(a);
            b = test(b);
            a ++;
            b ++;
        }
        printf("a = %d, b = %d\n", a, b);
        break;
    }
    printf("a = %d, b = %d\n", a, b);

    return 0;
}