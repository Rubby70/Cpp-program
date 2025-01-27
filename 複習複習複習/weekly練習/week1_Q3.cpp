// 輸入一個數字 (0~999) 把每個digits 轉成對應的英文字母
// Ex. 000 -> aaa, 123 -> bcd
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;


int main(void){

    srand(time(0));
    stack<int> S;
    int input = rand() % 1000;
    int DigitCount = 0;
    if(input == 0){
        cout << "a\n";
        return 0;
    }
        
    for(int i = 0; ; i ++){
        if((int)pow(10, i) > input)
            break;
        int CheckDigit = (input / (int)pow(10, i)) % 10;
        S.push(CheckDigit);
        DigitCount ++;
    }
    char buffer[128] = {};
    sprintf(buffer, "input: %d, 是%d位數\n", input, DigitCount);
    cout << buffer;

    int temp;
    while(!S.empty()){
        temp = S.top() + 97;
        S.pop();
        cout << (char)temp;
    }
    cout << "\n";
    return 0;

}