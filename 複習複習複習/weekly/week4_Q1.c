// 給你一個"排序好的"、"每個數字只會出現一次"的陣列，範圍會是0 ~ 2N 
// 妳的目標是要將數字統整在一起 如果有連續出現的數字，只要告訴我頭尾就好，而沒有跟人相連的數字就獨自表示
// Ex: 陣列 = [0, 1, 2, 4, 5, 7] 那你應該要輸出 ["0->2", "4->5", "7"]
//     陣列 = [0, 2, 3, 4, 6, 8, 9] 那妳應該要輸出 ["0", "2->4", "6", "8->9"]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void PrintArray(int* arr, int length){

    printf("[");
    for(int i = 0; i < length; i ++)
        printf("%d ", arr[i]);
    printf("]\n");

}
void InsertionSort(int* arr, int length){

    for(int i = 1; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while((cnt > 0) && (temp < arr[cnt - 1])){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

}
void InitializeArray(int* arr, int length, int target){

    for(int i = 0; i < length; i ++)
        arr[i] = target;

}

int main(void){

    srand(time(0));
    int N = 10;
    int maximun = (2 * N) + 1;
    int arr[N];
    int check[maximun];
    InitializeArray(check, maximun, 0);
    for(int i = 0; i < N; i ++){
        int temp = rand() % (maximun);
        if(check[temp] == 0){
            arr[i] = temp;
            check[temp] = 1;
        }
        else{
            i --;
        }
    }
    InsertionSort(arr, N);
    PrintArray(arr, N);

    int arrow = 0;
    printf("[ %d", arr[0]);
    for(int i = 1; i < N; i ++){
        if(arr[i] == arr[i - 1] + 1){
            if(!arrow){
                printf("->");
                arrow = 1;
            }
            while(1){
                arrow = 0;
                if(i == N){
                    printf("%d ]\n", arr[i - 1]);
                    return 0;
                }
                if(arr[i] != arr[i - 1] + 1){
                    printf("%d", arr[i - 1]);
                    break;
                }
                i ++;
            }  
        }
        printf(", %d", arr[i]);
    }
    printf("]\n");
    return 0;

}