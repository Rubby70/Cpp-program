#include "stdio.h"


int main(void){
    int i = 100;
    printf("%d\n", (i++, ++i));

    return 0;
}