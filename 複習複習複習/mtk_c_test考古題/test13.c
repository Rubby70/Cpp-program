#include "stdio.h"
#include "stdlib.h"

int func(int a, int*b){
    static int c = 0;
    a += *b;
    *b += a;
    c += a + *b;
    return c;
}

int main(void){

    int x = 5, y = 7, z = 0;
    x = func(x, &y);
    printf("x = %d, y = %d\n", x, y);
    z = func(x, &y);
    printf("x = %d, y = %d, z = %d\n", x, y,z);

    printf("x+y+z = %d\n", x+y+z);

    return 0;
}