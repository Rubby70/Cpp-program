// 給定一個長度為n的array， array中的數字是[1,n+1] 美個數字只會出現一次，找出不在array中的數字
// Ex. [1,2,4,5,6,7,8,9]  -> 印出  消失的是3唷 你這個小可愛
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomArr(int* arr, int n){

    int check[n + 2]; //因為arr範圍是1 ~ n+1
    for(int i = 0; i < n + 2; i ++)
        check[i] = 0;
    for(int i = 0; i < n; i ++){
        int temp = (rand() % (n + 1)) + 1;
        if(check[temp] == 0){
            arr[i] = temp;
            check[temp] = 1;
        }
        else
            i --;
    }

}
void PrintArr(int* arr, int n){

    printf("[");
    for(int i = 0; i < n; i ++)
        printf("%d ", arr[i]);
    printf("]\n");

}
int FindMissing(int* arr, int n){

    int sum = (1 + (n + 1)) * (n + 1) / 2;
    for(int i = 0; i < n; i ++){
        sum -= arr[i];
    }
    return sum;

}

int main(void){

    srand(time(0));
    int n;
    scanf("%d", &n);
    
    int arr[n];
    RandomArr(arr, n);
    PrintArr(arr, n);

    int missing = FindMissing(arr, n);
    printf("缺少的數字是: %d\n", missing);
    return 0;

}