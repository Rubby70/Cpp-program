#include "stdio.h"
#include "stdlib.h"

#define THRB 0x08

int main(void){
    int ch = 26;
    if(ch & 0xf > THRB)
        printf("MORE %d\n", ch & 0xf);
    else
        printf("LESS %d\n", ch & 0xf);

    return 0;
}