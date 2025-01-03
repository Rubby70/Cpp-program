#include "stdio.h"
#include "stdlib.h"

int main(void){
    float a = 0.7;
    float b = 0.8;

    if(a < 0.7 && b < 0.7){
        printf("problem A\n");
    }
    else if(a < 0.7 && b > 0.7){
        printf("problem B\n");
    }
    else if(a > 0.7 && b < 0.7){
        printf("problem C\n");
    }
    else if(a > 0.7 && b > 0.7){
        printf("problem D\n");
    }
    else{
        printf("problem E");
    }
    return 0;
}