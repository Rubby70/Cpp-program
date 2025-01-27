#include "stdio.h"
#include "stdlib.h"

int main(void){
    int cnt = 0;
    char* pc = "welcome";
    while(*pc++){
        cnt++;
    }
    printf("cnt = %d\n", cnt);
    return 0;
}