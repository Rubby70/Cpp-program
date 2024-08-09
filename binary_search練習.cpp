#include <iostream>
using namespace std;


void print(int array[], int N);
void reset_array(int array[], int N);
void random_array(int array[], int N, int max);
void rearrange_array(int array[], int N);



int main(void){

    srand(time(0));
    int N;
    cout << "請指定數列大小: ";
    cin >> N;
    int max = 3 * N;
    int arr[N];
    reset_array(arr, N);
    random_array(arr, N, max);
    rearrange_array(arr, N);
    print(arr, N);

    //int target = rand() % max;
    int target;
    cout << "目標數字: ";
    cin >> target;
    int left = 0;
    int right = N - 1;
    int mid;
    int find;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(target == arr[mid]){
            find = mid;
            break;
        }
        else if(target > arr[mid]){
            left = mid + 1;
            cout << "array:[ ";
            for(int i = left; i <= right; i ++){
                cout << arr[i] << " ";
            }
            cout << "]" << "\n";
        }
        else if(target < arr[mid]){
            right = mid - 1;
            cout << "array:[ ";
            for(int i = left; i <= right; i ++){
                cout << arr[i] << " ";
            }
            cout << "]" << "\n";
        }
    }
    if(left > right){
        find = -1;
    }
    cout << find << "\n";
    return 0;

}

void print(int array[], int N){

    cout << "array:[ ";
    for(int i = 0; i < N; i ++){
        cout << array[i] << " ";
    }
    cout << "]" << "\n";

}

void reset_array(int array[], int N){
    
    for(int i = 0; i < N; i ++){
        array[i] = -1;
    }

}

void random_array(int array[], int N, int max){

    int check[max];
    reset_array(check, max);
    for(int i = 0; i < N; i ++){
        while(array[i] == -1){
            array[i] = rand() % max;
            if(check[array[i]] != -1){
                array[i] = -1;
                continue;
            }
            check[array[i]] = 0;
        }
    }

}

void rearrange_array(int array[], int N){

    for(int i = 0; i < N; i ++){
        for(int j = i; j < N; j ++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

}
