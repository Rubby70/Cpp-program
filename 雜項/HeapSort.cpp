#include <iostream>
using namespace std;


void PrintArr(int* arr, int n){

    cout << "[";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << "]\n";

}
void heapify(int* arr, int n, int initial){

    int largest = initial;
    int left = 2 * initial + 1;
    int right = 2 * initial + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != initial){
        swap(arr[largest], arr[initial]);
        heapify(arr, n, largest);
    }
        
}
void HeapSort(int* arr, int n){

    for(int i = (n / 2 - 1); i >= 0; i --){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i --){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }

}

int main(void){

    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    int n = 7;
    cout << "排序前:";
    PrintArr(arr, n);

    HeapSort(arr, n);

    cout << "排序後:";
    PrintArr(arr, n);
    return 0;

}