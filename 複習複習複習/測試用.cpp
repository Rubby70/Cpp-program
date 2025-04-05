#include "stdio.h"

int a = 0;
int b;

int main(void){
    static int c = 0;
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);

    return 0;
}