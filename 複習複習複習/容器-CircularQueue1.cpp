#include <bits/stdc++.h>
using namespace std;


class Queue{

    public:
        int front;
        int rear;
        int capacity;
        int* arr;

        Queue(int capacity){

            this->front = -1;
            this->rear = -1;
            this->capacity = capacity;
            arr = (int*)malloc(sizeof(int) * capacity);
            for(int i = 0; i < capacity; i ++){
                arr[i] = -1;
            }

        }
        int frontValue(){

            if(front == -1){
                cout << "Queue is empty.\n";
                return 0;
            }
            return arr[front];

        }
        void pop(){

            if(front == -1){
                cout << "Queue is empty.\n";
                return ;
            }

            if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            } 
            else if((front + 1) == capacity){
                arr[front] = -1;
                front = 0;
            }
            else{
                arr[front ++] = -1;
            }
            cout << "front: " << front << ", rear: " << rear <<"\n";

        }
        void push(int value){

            if((front != -1) && ((rear + 1) % capacity == front)){
                cout << "Queue is full.\n";
                return ;
            }

            if(rear == -1){
                front = 0;
                rear = 0;
                arr[rear] = value;
            }
            else if(rear + 1 == capacity){
                arr[rear] = value;
                rear = 0;
            }
            else{
                arr[++ rear] = value;
            }
            cout << "push " << value << " into queue. ";
            cout << "front: " << front << ", rear: " << rear <<"\n";

        }
        void viewQueue(){
            
            cout << "show all value in queue -> ";
            if(front == -1){
                cout << "Queue is empty.\n";
                return ;
            }
            
            if(rear >= front){
                cout << "[ ";
                for(int i = front; i <= rear; i ++){
                    cout << arr[i] << " ";
                }
                cout << "]\n";
            }
            else if(rear < front){
                cout << "[ ";
                for(int i = front; i < capacity; i ++){
                    cout << arr[i] << " ";
                }
                for(int i = 0; i <= rear; i ++){
                    cout << arr[i] << " ";
                }
                cout << "]\n";
            }

        }
        void ShowAll(){
            
            cout << "[ ";
            for(int i = 0; i < capacity; i ++){
                cout << arr[i] << " ";
            }
            cout << "]\n";

        }

};

int main(void){

    Queue Q(5);
    //Q.viewQueue();

    Q.push(0);
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.viewQueue();

    cout << "pop " << Q.frontValue() << "\n";
    Q.pop();
    Q.ShowAll();
    cout << "pop " << Q.frontValue() << "\n";
    Q.pop();
    Q.ShowAll();
    cout << "pop " << Q.frontValue() << "\n";
    Q.pop();
    Q.ShowAll();
    cout << "pop " << Q.frontValue() << "\n";
    Q.pop();
    Q.ShowAll();
    cout << "pop " << Q.frontValue() << "\n";
    Q.pop();
    Q.ShowAll();
    Q.viewQueue();

    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.viewQueue();
    return 0;
    
}