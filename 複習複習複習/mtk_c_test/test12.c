#include "stdio.h"
#include "stdlib.h"

int main(void){
    int a = 320;
    char* pc = (char*)&a;
    printf("%d\n", *pc);

    return 0;
}