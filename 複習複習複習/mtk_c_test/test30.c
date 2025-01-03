#include "stdio.h"

#define swap(a, b) \
  temp = a;        \
  a = b;           \ 
  b = temp;

int main(void) { 
    int i = 5;
    int j = 10;

    int temp = 0;
    if (i > j) swap(i, j);
    
    printf("%d %d %d", i, j, temp);
}
