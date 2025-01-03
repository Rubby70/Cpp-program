#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void){

    char str[20] = "ABCDE";
    printf("%d,%d\n", sizeof(str), strlen(str));

    return 0;
}