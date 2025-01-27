#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE -1
#define NULL 0

int main(void){

    if(NULL)
        printf("NULL\n");
    else if(FALSE){
        printf("FALSE\n");
    }
    else
        printf("TRUE\n");

    return 0;
}