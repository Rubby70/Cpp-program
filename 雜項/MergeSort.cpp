#include <iostream>
using namespace std;


void PrintArray(int* arr, int n){

    cout << "[ ";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << "]\n";

}
void merge(int* arr, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;
    int tempA[n1];
    for(int i = 0; i < n1; i ++){
        tempA[i] = arr[left + i];
    }
    int tempB[n2];
    for(int i = 0; i < n2; i ++){
        tempB[i] = arr[mid + 1 + i];
    }

    int k = left;
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(tempA[i] < tempB[j]){
            arr[k] = tempA[i];
            i ++;
        }
        else if(tempA[i] > tempB[j]){
            arr[k] = tempB[j];
            j ++;
        }
        k ++;
    }
    while(i < n1){
        arr[k] = tempA[i];
        i ++;
        k ++;
    }
    while(j < n2){
        arr[k] = tempB[j];
        j ++;
        k ++;
    }

}
void MergeSort(int* arr, int n, int left, int right){

    if(left >= right)
        return ;
    int mid = left + (right - left) / 2;
    MergeSort(arr, n, left, mid);
    MergeSort(arr, n, mid + 1, right);
    merge(arr, left, mid, right);

}

int main(void){

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = 6;
    cout << "排序前:";
    PrintArray(arr, n);

    MergeSort(arr, n, 0, n - 1);

    cout << "排序後:";
    PrintArray(arr, n);
    return 0;

}