#include "stdio.h"
#include "stdlib.h"

int main(void){

    int arr[] = {3,6,4,6,6,3,3,-1,3,6,4,6,6,3,3,-2};
    int cnt = 0, sum = 0;
    int i = 0;
    do{
        sum += arr[i];
        if(arr[i++] < 0)
            continue;
        cnt ++;
        
    }while(i < 16);

    printf("cnt = %d, sum = %d\n", cnt, sum);

    return 0;
}