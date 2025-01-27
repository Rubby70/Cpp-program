#include<bits/stdc++.h>
using namespace std;


class Stack{

    public:
        int capacity;
        int top;
        int* arr;
        
        Stack(int StackSize){

            this->capacity = StackSize;
            top = -1;
            arr = new int[StackSize];

            for(int i = 0; i < StackSize; i ++){
                arr[i] = -1;
            }

        }
        bool IsEmpty(){

            return top == -1;

        }
        void Push(int element){

            if(top + 1 == this->capacity){
                printf("This Stack is full.\n");
                return ;
            }

            if(this->IsEmpty()){
                top = 0;
                arr[top] = element;
            }
            else{
                arr[++ top] = element;
            }

        }
        void Pop(){

            if(this->IsEmpty()){
                printf("This Stack is empty.\n");
                return ;
            }

            if(top == 0){
                arr[top] = -1;
                top = -1;
            }
            else{
                arr[top --] = -1;
            }
            printf("Pop.\n");

        }
        int Top(){

            if(this->IsEmpty()){
                printf("This Stack is empty.\n");
                return -1;
            }

            return arr[top];
        
        }

};

int main(void){

    Stack S(5);
    for(int i = 1; i <= 5; i ++){
        S.Push(i);
        printf("S.top() = %d\n", S.Top());
    }

    S.Push(6);

    S.Pop();
    printf("S.top() = %d\n", S.Top());

    S.Push(9);
    printf("S.top() = %d\n", S.Top());
    return 0;

}