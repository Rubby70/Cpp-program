// 生成隨機且可以重複 但是要排序好的資料集
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while((cnt > 0) && (temp > arr[cnt - 1])){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

}
void PrintArray(int* arr, int length){
    
    printf("[");
    for(int i = 0; i < length; i ++)
        printf("%d ", arr[i]);
    printf("]\n");

}

int main(void){

    srand(time(0));
    int length = 10;
    int arr[length];
    for(int i = 0; i < length; i ++)
        arr[i] = rand() % length;
    InsertionSort(arr, length);
    printf("array[%d]: ", length);
    PrintArray(arr, length);
    return 0;
    
}