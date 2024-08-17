#include <iostream>
using namespace std;




class queue{

    private:
        int front;
        int rear;
        int capacity;
        int *ptr = NULL;
    public:
        queue(int cap){
            front = 0;
            rear = 0;
            capacity = cap;
            ptr = new int[capacity];
        }

        void pop(){
            if(rear == front){
                cout << "This queue is empty" << "\n";
            }
            else{
                for(int i = 0; i < rear - 1; i ++){
                    ptr[i] = ptr[i + 1];
                }
                ptr[rear - 1] = -1;
                rear --;
            }
        }

        void push(int input){
            if(rear == capacity){
                cout << "This queue is full" << "\n";
            }
            else{
                ptr[rear ++] = input;
            }
        }
        int size(){
            return rear;
        }
        int front_value(){
            return ptr[front];
        }
        int rear_value(){
            return ptr[rear - 1];
        }
        void view(){
            for(int i = front; i < rear; i ++){
                cout << ptr[i] << " ";
            }
        }
        
};

int main(void){

    queue s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);

    s.view();
    cout << "\n";
    cout << "queue目前已填入量: " << s.size() << "\n";
    cout << "front value: " << s.front_value() << "\n";
    cout << "rear value: " << s.rear_value() << "\n";
    
    s.pop();
    cout << "queue目前已填入量: " << s.size() << "\n";
    cout << "front value: " << s.front_value() << "\n";
    cout << "rear value: " << s.rear_value() << "\n";
    
    s.view();
    cout << "\n";

    return 0;

}