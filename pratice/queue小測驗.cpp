// 寫一個 存struct 的queue 
// 這個struct裡面有兩個int 一個x 一個y
#include <iostream>
using namespace std;

struct str{
    int x;
    int y;
};

template <class type>
class queue{
    private:
        int front;
        int rear;
        int capacity;
        type *ptr = NULL;
    public:
        queue(int cap){
            front = 0;
            rear = 0;
            capacity = cap;
            ptr = new type[capacity];
        }
        void push(type input){
            if(front == (rear + 1) % capacity){
                cout << "This queue is full" << "\n";
            }
            else{
                ptr[rear] = input;
                rear = (rear + 1) % capacity;
                cout << "push成功" << "\n";
            }
        }
        void pop(){
            if(front == rear){
                cout << "This queue is empty" << "\n";
            }
            else{
                front = (front + 1) % capacity;
            }
        }
        void view(){
            int i = front;
            cout << "queue內儲存了: ";
            while(i != rear){
                cout << "(" << ptr[i].x << "," << ptr[i].y << ")" << " ";
                i = (i + 1) % capacity;
            }
            cout << "\n";
        }
        void size(){
            if(front == rear){
                cout << "This queue is empty" << "\n";
            }
            else{
                int i = front;
                int cnt = 0;
                while(i != rear){
                    i = (i + 1) % capacity;
                    cnt ++;
                }
                cout << "Size: " << cnt << "\n";
            }
        }

};

int main(void){

    str A;
    A.x = 1;
    A.y = 1;
    str B;
    B.x = 2;
    B.y = 2;
    str C;
    C.x = 3;
    C.y = 3;

    queue<str> S(3);
    cout << "填入str A" << "\n";
    S.push(A);
    cout << "填入str B" << "\n";
    S.push(B);
    cout << "填入str C" << "\n";
    S.push(C);
    
    S.view();
    S.size();

    cout << "pop" << "\n";
    S.pop();
    S.view();
    S.size();
    return 0;

}