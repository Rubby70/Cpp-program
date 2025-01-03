// 著名的 matched parentheses 
// 給你一個字串，這個字串只會由 "(“, “)”, "[", "]", "{", "}" 這三種刮號組成  
// 我們定義一組配對的刮號代表 (), [], {}是成對出現的 
// 告訴我給你的字串是否是配對的
// Ex: 
// (是不成對的
// ()是成對的
// []也是成對的 
// (]) 是不成對的
// ([]) 是成對的

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;


class stack{

    private:
        int capacity;
        int size;
        char* list = NULL;
    public:
        stack(int cap){
            size = -1;
            capacity = cap;
            list = new char[capacity];
        }
        bool isEmpty(){
            return size <= -1;
        }
        void push(char character){
            if(size < capacity){
                list[++ size] = character;
            }
            else{
                cout << "This stack is full" << "\n";
            }
        }
        void pop(){
            if(!this->isEmpty()){
                size --;
            }
            else{
                cout << "This stack is empty" << "\n";
            }
        }
        void view(){
            if(size <= -1){
                cout << "This stack is empty" << "\n";
                return ;
            }
            cout << "List: ";
            for(int i = 0; i <= size; i ++){
                cout << list[i] << " ";
            }
            cout << "\n";
        }
        char top(){
            if(this->isEmpty()){
                return 0;
            }
            else{
                return list[size];
            }
        }

};

int scan_char(char **ptr2arr){

    int size = 0;
    int max_size = 0;
    while(1){
        if(size >= max_size){
            max_size += 5;
            char *ptr_temp = new char[max_size];
            if(size == 0){
                *ptr2arr = ptr_temp;
            }
            else{
                strcpy(ptr_temp, *ptr2arr);
                delete [] *ptr2arr;
                *ptr2arr = ptr_temp;
            }
        }
        scanf("%c", &(*ptr2arr)[size]);
        if((*ptr2arr)[size] == '\n'){
            (*ptr2arr)[size] = '\0';
            break;
        }
        size ++;
    }
    return size;

}

int main(void){

    stack SS(10);
    char *arr = NULL;
    int size = scan_char(&arr);
    
    char top_char; //保存在stack最上方的字元
    char current_char; //目前正在檢查的字元
    for(int i = 0; i < size; i ++){
        current_char = arr[i];
        cout << "i = " << i << '\n';
        cout << "current_char: " << current_char << '\n';
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){ //檢查current_char是否為任何一種左括號
            SS.push(arr[i]); //若為左括號則push進stack
        }
        else{
            top_char = SS.top(); //如果不是左括號，則進入判斷區，先從stack取出最近一次遇到的左括號
            cout << "top_char: " << top_char << '\n';
            switch(arr[i]){ //判斷目前的字元是哪一種右括號
                case ')': //若目前的字元是右小括號
                    if(top_char == '('){ //則檢查stack裡top的字元是不是左小括號
                        SS.pop(); //若左右都是小括號則匹配，將左括號從stack中刪除
                        cout << "pop '()'" << '\n'; //印出匹配的括號
                        break; // 進入下一個i繼續判斷
                    }
                    else{
                        cout << "不成對" << '\n'; //若stack中最上方的括號不是左小括號，則代表無法匹配
                        return 0; //直接結束判斷
                    }
                case ']':
                    if(top_char == '['){
                        SS.pop();
                        cout << "pop '[]'" << '\n';
                        break;
                    }
                    else{
                        cout << "不成對" << '\n';
                        return 0;
                    }
                case '}':
                    if(top_char == '{'){
                        SS.pop();
                        cout << "pop '{}'" << '\n';
                        break;
                    }
                    else{
                        cout << "不成對" << '\n';
                        return 0;
                    }
            }
        }
    }
    if(SS.isEmpty()){ //若到最後stack中沒有剩餘的括號需要匹配，則代表所有括號皆成對
        cout << "是成對的" << '\n';
    }
    else{ //若最後stack中有剩餘的括號，則代表不成對
        cout << "不成對" << '\n';
    }
    return 0;

}

// (       是不成對的
// ()      是成對的
// []      也是成對的 
// (])     是不成對的
// ([])    是成對的