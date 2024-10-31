#include<stdio.h>


int add(int a, int b){

    return a + b;

}
int func(int a, int b, int (*func_ptr)(int, int)){

    int c;
    c = func_ptr(a, b);
    return c;

}

int main(void){

    printf("%d\n", func(3, 5, add));
    return 0;

}