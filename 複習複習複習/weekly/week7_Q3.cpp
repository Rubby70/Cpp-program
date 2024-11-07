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
#include <stdlib.h>
#include <stack>
using namespace std;


char* ScanString(char* str, int* ptr2length){

    *ptr2length += 5;
    str = (char*)malloc(sizeof(char) * (*ptr2length));
    int i = 0;
    while(1){
        if(i == *ptr2length)
            *ptr2length += 5;
        
        scanf("%c", &str[i]);
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
        i ++;
    }
    return str;

}
int CountStringLength(char* str){

    int i = 0;
    while(1){
        if(str[i] == '\0')
            break;

        i ++;
    }
    return i --;

}

int main(void){

    stack<char> S;
    int size = 5;
    printf("請指定str: ");
    char* str = ScanString(str, &size);
    int length = CountStringLength(str);
    
    char current;
    char target = '\0'; //將target初始化成空字元
    for(int i = 0; i < length; i ++){  
        if(target == '\0'){ //如果target == '\0',表示目前stack是空的
            if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
                printf("右括號先出現, 不成對。\n");
                return 0;
            }
            printf("Current Target: '\\0', str[%d]: %c, ", i, str[i]);
        }
        else{
            printf("Current Target: '%2c', str[%d]: %c, ", target, i, str[i]);
        }

        if(str[i] != ')' && str[i] != ']' && str[i] != '}'){ //如果是左括號,就push進stack
            S.push(str[i]);
            printf("push str[%d] into Stack. \n", i);
        }

        if(target != '\0' && target == str[i]){ //如果target == '\0',表示目前stack是空的
            printf("matched!\n");
            target = '\0';
            S.pop();
        }
        
        if(!S.empty()){ //如果出現過左括號並且還存在stack內,則更新target
            current = S.top();
            switch(current){
                case '(':
                    target = ')';
                    break;
                case '[':
                    target = ']';
                    break;
                case '{':
                    target = '}';
                    break;
            }
        }
    }
    
    if(S.empty() == 1){
        printf("成對\n");
    }
    else{
        printf("不成對\n");
    }
    return 0;

}