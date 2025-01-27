// 給你一個"排序好的"的陣列，範圍會是0 ~ 2N，
// 這次在陣列當中的數字"是可以重複出現的"
// 妳的目標是 將陣列當中 重複出現的數字 刪除到只剩下一個，
// 並且刪除後，為了要維持陣列長度不變，妳要在後面補_
// Ex: 陣列 = [1, 1, 2] 那妳應該要輸出 [1, 2, _]
//     陣列 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4] 那妳應該要輸出 [0, 1, 2, 3, 4, _, _, _, _, _]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void PrintArray(int* arr, int length){

    printf("[");
    for(int i = 0; i < length; i ++)
        printf("%2d, ", arr[i]);
    printf("]\n");

}
void MergeLoop(int* arr, int start, int mid, int end){

    int left = mid - start + 1;
    int right = (end - mid);
    int arr_L[left];
    for(int i = 0; i < left; i ++)
        arr_L[i] = arr[start + i];
    int arr_R[right];
    for(int i = 0; i < right; i ++)
        arr_R[i] = arr[(mid + 1) + i];

    int k = start;
    int i = 0;
    int j = 0;
    while((i < left) && (j < right)){
        if(arr_L[i] >= arr_R[j]){
            arr[k] = arr_R[j];
            j ++;
        }
        else if(arr_L[i] < arr_R[j]){
            arr[k] = arr_L[i];
            i ++;
        }
        k ++;
    }
    while(i < left){
        arr[k] = arr_L[i];
        i ++;
        k ++;
    }
    while(j < right){
        arr[k] = arr_R[j];
        j ++;
        k ++;
    }

}
void MergeSort(int* arr, int start, int end){

    if(start >= end)
        return ;
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid ); //左閉右閉
    MergeSort(arr, (mid + 1), end);
    MergeLoop(arr, start, mid, end);

}
void InsertionSort(int* arr, int length){

    for(int i = 0; i < length; i ++){
        int temp = arr[i];
        int cnt = i;
        while((cnt > 0) && temp < arr[cnt - 1]){
            arr[cnt] = arr[cnt - 1];
            cnt --;
        }
        arr[cnt] = temp;
    }

}

int main(void){

    srand(time(0));
    int N = 10;
    int length = N;
    int maximun = (2 * N) + 1;
    int arr[length];
    for(int i = 0; i < length; i ++)
        arr[i] = rand() % maximun;
    MergeSort(arr, 0, length - 1);
    printf("input : ");
    PrintArray(arr, length);

    int temp = -1;
    for(int i = 0; i < length; i ++){
        if(temp == -1){
            temp = arr[i];
            continue;
        }
        while((arr[i] == temp) && (temp != maximun)){
            printf("temp = %d, arr[%d] = %d. -> 移除\n", temp, i, arr[i]);
            arr[i] = maximun; //用超過範圍的數字來取代原本的值,用來表示刪除
            i ++;
        }
        temp = -1; //若arr[i] != temp,則重置temp,並且i --重新從這一項開始檢查
        i --;
        InsertionSort(arr, length); //每次刪除重複項之後重新sorting,把maximun排去最後面
    }
    printf("output: [");
    for(int i = 0; i < length; i ++){
        if(arr[i] == maximun)
            printf("__, ");
        else
            printf("%2d, ", arr[i]);
    }
    printf("]\n");
    return 0;

}