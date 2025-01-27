#include<bits/stdc++.h>
using namespace std;


class Queue{

    public:
        int capacity;
        int CurrentSize;
        int front;
        int last;
        int* arr;

        Queue(int QueueSize){

            this->capacity = QueueSize;
            this->CurrentSize = 0;
            this->front = -1;
            this->last = -1;
            arr = new int[QueueSize];

            for(int i = 0; i < QueueSize; i ++){
                arr[i] = -1;
            }

        }
        bool IsEmpty(){

            return front == -1;

        }
        void Push(int data){

            printf("Push %d, ", data);

            if((last + 1) % capacity == front){
                printf("Queue is Full.\n");
                return ;
            }

            if(last == -1){
                front = 0;
                last = 0;
                arr[last] = data;
            }
            else if(last + 1 % capacity == 0){
                last = 0;
                arr[last] = data;
                
            }
            else{
                arr[++ last] = data;
            }
            this->CurrentSize ++;
            printf("Current Size = %d, front = %d, last = %d.\n", CurrentSize, front, last);

        }
        void Pop(){

            printf("Pop, ");

            if(this->IsEmpty()){
                printf("Queue is empty.\n");
                return ;
            }

            if(front == last){
                arr[front] = -1;
                front = -1;
                last = -1;
                CurrentSize = 0;
            }
            else if((front + 1) % capacity == 0){
                arr[front] = -1;
                front = 0;
                CurrentSize --;
            }
            else{
                arr[front ++] = -1;
                CurrentSize --;
            }
            printf("Current Size = %d, front = %d, last = %d.\n", CurrentSize, front, last);

        }
        int Front(){

            return arr[front];

        }
        void ShowAll(){

            if(this->IsEmpty()){
                printf("Queue is empty.\n");
                return ;
            }

            printf("[ ");
            if(last >= front){
                for(int i = front; i <= last; i ++){
                    printf("%d ", arr[i]);
                }
            }
            else if(last < front){
                for(int i = front; i < capacity; i ++){
                    printf("%d ", arr[i]);
                }
                for(int i = 0; i <= last; i ++){
                    printf("%d ", arr[i]);
                }
            }
            printf("]\n");

        }

};

int main(void){

    Queue Q(5);
    for(int i = 1; i <= 6; i ++){
        Q.Push(i);
        Q.ShowAll();
    }

    printf("\n");
    for(int i = 1; i <= 5; i ++){
        Q.Pop();
        Q.ShowAll();
    }

    printf("\n");
    for(int i = 1; i <= 6; i ++){
        Q.Push(i);
    }
    Q.Pop();
    Q.Push(9);
    Q.ShowAll();
    return 0;

}