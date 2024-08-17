#include <iostream>
using namespace std;


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
void random_array_repeatable(int array[], int N, int max){

    for(int i = 0; i < N; i ++){
        array[i] = rand() % max;
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
int binary_std(int array[], int N, int target){

    int left = 0;
    int right = N;
    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(target == array[mid]){
            left = mid;
            break;
        }
        else if(target > array[mid]){
            left = mid + 1;
        }
        else if(target < array[mid]){
            right = mid;
        }
    }
    if(left < 0 || left >= N){
        return -1;
    }
    return left;

}
int binary_left_bound(int array[], int N, int target){

    int left = 0;
    int right = N;
    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(target == array[mid]){
            right = mid;
        }
        else if(target > array[mid]){
            left = mid + 1;
        }
        else if(target < array[mid]){
            right = mid;
        }
    }
    if(left < 0 || left >= N){
        return -1;
    }
    return left;

}
int binary_right_bound(int array[], int N, int target){

    int left = 0;
    int right = N;
    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(target == array[mid]){
            left = mid + 1;
        }
        else if(target > array[mid]){
            left = mid + 1;
        }
        else if(target < array[mid]){
            right = mid;
        }
    }
    if(left < 0 || left - 1 >= N){
        return -1;
    }
    return left - 1;

}

int main(void){

    srand(time(0));
    int N;
    cout << "請指定數列大小: ";
    cin >> N;
    int max = N;

    // int arr_std[N];
    // reset_array(arr_std, N);
    // random_array(arr_std, N, max);
    // rearrange_array(arr_std, N);
    // cout << "無重複的";
    // print(arr_std, N);

    int arr_repeat[N];
    reset_array(arr_repeat, N);
    random_array_repeatable(arr_repeat, N, max);
    rearrange_array(arr_repeat, N);
    cout << "有重複的";
    print(arr_repeat, N);

    int target;
    cout << "目標數字: ";
    cin >> target;

    cout << "\n";
    cout << "標準版 " << binary_std(arr_repeat, N, target) << "\n"; // [0, N]
    cout << "找左邊界 " << binary_left_bound(arr_repeat, N, target) << "\n"; // [0, N)
    cout << "找右邊界 " << binary_right_bound(arr_repeat, N, target) << "\n"; // [0, N)
    return 0;

}










