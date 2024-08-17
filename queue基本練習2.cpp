#include <iostream>
using namespace std;


template <class Type>
class queue{
    private:
        int front;
        int rear;
        int capacity;
        Type *ptr = NULL;
    public:
        queue(int cap){
            front = 0;
            rear = 0;
            capacity = cap;
            ptr = new Type[capacity];
        }
        bool IsFull(){
            if(front == (rear + 1) % capacity){
                return true;
            }
            else{
                return false;
            }
        }
        Type front_vlaue(){
            return ptr[front];
        }
        Type rear_value(){
            return ptr[rear];
        }
        void push(Type input){
            if(front == (rear + 1) % capacity){
                cout << "This queue is full" << "\n";
            }
            else{
                ptr[rear] = input;
                rear = (rear + 1) % capacity;
            }
        }
        void pop(){
            if(rear == front){
                cout << "This queue is empty" << "\n";
            }
            else{
                front = (front + 1) % capacity;
            }
        }
        void view(){
            int i = front;
            while(i != rear){
                cout << ptr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << "\n";
        }
};

int main(void){

    queue<int> s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.view();

    s.push(25);
    s.view();

    s.pop();
    s.push(25);
    s.view();
    return 0;

}