#include "stdio.h"


int main(void){
    int arr[] = {1, 2, 3, 11, 22, 55};
    int *a = arr;
    int *b = arr + 3;
    int c = *a++ + *b++;
    int d = *++a + *++b;
    printf("%d %d\n", c, d);
}
