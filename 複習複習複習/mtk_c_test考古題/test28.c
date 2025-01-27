#include "stdio.h"


int main(void){
    int i = 0, a = 0, b = 0, c = 0, d = 0;
    for (i = 0, a = 0; ++i < 5; a++);
    for (i = 5, b = 0; --i; b++);
    for (i = 0, c = 0; i++ < 5; c++);
    for (i = 5, d = 0; i--; d++);
    printf("%d %d %d %d\n", a, b, c, d);
    printf("%d\n", a * b * c * d);
}
