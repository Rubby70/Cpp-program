#include "stdio.h"
#include "stdlib.h"

#define gun

int main(void){

    #ifdef gun
        printf("mock ");
    #else
        printf("technical\n");
    #endif

    printf("This is a simple question\n");

    return 0;
}