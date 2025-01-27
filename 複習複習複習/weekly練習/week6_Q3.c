// 不使用sizeof 求出一個陣列的大小
#include <stdio.h>


void method(int* first, int* last){

    printf("first: %p, last: %p, ", first, last);
    int length = (last - first) ;
    printf("method1: %d\n", length);

}

int main(void){

    int length = 10;
    int arr[length];
    for(int i = 0; i < length; i ++)
        arr[i] = i;
    
    method1(&(arr[0]), &(arr[length - 1]));
    return 0;

}