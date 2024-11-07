#include "stdio.h"
#include "stdbool.h"

bool fcn(char *str1, char *str2) { 
    int i = 0;
    while(str1[i] != '\0'){
        if(str1[i] == str2[i]){
            i ++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(void) {

    char str1[] = "abcd";
    char str2[] = "abcd";
    printf("string same ? %d\n", fcn(str1, str2));
    return 0;
}