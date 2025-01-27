#include "stdio.h"

void foo() { 
    static int i = 0;
    i++;
    printf("%d", i);
}

int main(void) { 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
}
