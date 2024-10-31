#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b){

    return ( *(int*)a - *(int*)b );

}
void print(int* arr, int n){

    printf("[ ");
    for(int i = 0; i < n; i ++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

}

int main(void){

    int arr[] = { 88, 56, 100, 2, 25 };
    int n = 5;
    print(arr, n);
    qsort(arr, n, sizeof(int), compare);
    print(arr, n);
    return 0;

}