#include <bits/stdc++.h>
using namespace std;


class Stack{

    public:
        
        int capacity;
        int top;
        int* arr;

        Stack(int capacity){

            this->top = -1;
            this->capacity = capacity;
            this->arr = (int*)malloc(sizeof(int) * capacity);

            for(int i = 0; i < capacity; i ++){
                arr[i] = -1;
            }

        }
        bool IsEmpty(){

            return top == -1;

        }
        int Top(){

            if(!this->IsEmpty()){
                return arr[top];
            }
            else{
                printf("Stack is empty.\n");
                return -1;
            }

        }
        void push(int value){

            if(this->IsEmpty()){
                top = 0;
                arr[top] = value;
                printf("Push %d into stack.\n", value);
                return ;
            }

            if(top + 1 == capacity){
                printf("Stack is full.\n");
            }
            else{
                arr[++ top] = value;
                printf("Push %d into stack.\n", value);
            }

        }
        void pop(){

            if(top == -1){
                printf("Stack is empty.\n");
                return ;
            }

            if(top == 0){
                arr[top] = -1;
                top = -1;
            }
            else{
                arr[top --] = -1;
            }

        }
        void ShowAll(){

            if(top != -1){
                printf("[ ");
                for(int i = top; i >=0; i --){
                    printf("%d ", arr[i]);
                }
                printf("]\n");
            }
            else{
                printf("Stack is empty.\n");
            }

        }

};

int main(void){

    Stack S(5);
    S.ShowAll();

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    S.ShowAll();

    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.push(6);
    S.push(7);
    S.ShowAll();
    return 0;
    
}