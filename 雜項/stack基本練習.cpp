// 寫出一個char的stack
#include <iostream>
using namespace std;


class stack{

    private:
        int top;
        char arr[10];
    public:
        stack(){
            top = -1;
        };

        bool IsEmpty(){
            return top < 0;
        }

        char TopValue(){
            if(top >= 0 && top < 10){
                return arr[top];
            }
            else{
                return -1;
            }
        }

        char pop(){
            if(top >= 0 ){
                return arr[top--];
            }
            else{
                cout << "This Stack Is Empty." << "\n";
                return -1;
            }
        }

        bool push(char input){
            if(top < 10){
                arr[++top] = input;
                return true;
            }
            else{
                cout << "This Stack Is Full." << "\n";
                return false;
            }
        }

        int size(){
            return top + 1;
        }

        void view(stack s){
            while(!s.IsEmpty()){
                cout << s.TopValue() << " ";
                s.pop();
            }
            cout << "\n";
        }

};

int main(void){

    stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    cout << "current top value: " << s.TopValue() << "\n";
    cout << "current size: " << s.size() << "\n";

    cout << "pop top value" << "\n";
    s.pop();

    cout << "current value in stack: ";
    s.view(s);
    return 0;

}