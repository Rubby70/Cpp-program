#include <iostream>
using namespace std;


class heap{

    private:
        int size;
        int capacity;
        int* arr;
    public:
        heap(int heapcapacity){
            capacity = heapcapacity;
            size = 0;
            arr = new int[capacity];
            for(int i = 0; i < capacity + 1; i ++){
                arr[i] = 0;
            }
        }
        bool empty(){

            return size == 0;

        }
        // int top(){}
        void push(int data){

            int currentNode = ++ size;
            while(currentNode > 1 && data > arr[currentNode / 2]){
                arr[currentNode] = arr[currentNode / 2];
                currentNode = currentNode / 2;
            }
            arr[currentNode] = data;
            
        }
        void pop(){

            int least = size --;
            int least_data = arr[least];
            int currentNode = 1;
            int child = 2;
            while(currentNode < size){
                if(arr[child] < arr[child + 1])
                    child ++;
                if(arr[child] < least_data)
                    break;
                arr[currentNode] = arr[child];
                currentNode = child;
                child *= 2;
            }
            arr[currentNode] = least_data;
            arr[least] = 0;

        }
        void view(){

            for(int i = 1; i < capacity + 1; i ++){
                cout << arr[i] << " ";
            }

        }
        int root(){

            return arr[1];

        }

};

int main(void){

    int A[15] = {5, 13, 11, 8, 3, 15, 7, 12, 2, 16, 6, 10, 14, 9, 4};
    heap H(15);
    for(int i = 0; i < 15; i ++){
        H.push(A[i]);
    }
    int sorted[15];
    for(int i = 0; i < 15; i ++){
        sorted[i] = H.root();
        H.pop();
    }
    cout << "排序前:[ ";
    for(int i = 0; i < 15; i ++){
        cout << A[i] << " ";
    }
    cout << "]" << "\n";
    cout << "排序後:[ ";
    for(int i = 0; i < 15; i ++){
        cout << sorted[i] << " ";
    }
    cout << "]" << "\n";
    return 0;

}

// [5, 13, 11, 8, 3, 15, 7, 12, 2, 16, 6, 10, 14, 9, 4]