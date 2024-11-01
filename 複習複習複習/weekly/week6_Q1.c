// 寫出strstr函數
// 當我給你一個字串 str 以及一個目標字串str2 
// 告訴我目標str2字串是否存在在str當中
// 如果不存在  則回傳-1。 
// 存在的話  就把他在str當中的位置印出來(0-indexed)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int CountLength(char* str){

    if(str == NULL)
        return 0;
    int length = 0;
    for(int i = 0; str[i] != '\0'; i ++){
        length ++;
    }
    return length;

}
char* AddSize(char* str){

    int length = CountLength(str);
    int new_length = length + 10;
    printf("擴大容量%d -> %d\n", length, new_length);
    char* temp = (char*)malloc(sizeof(char) * new_length);
    if(length != 0){
        strcpy(temp, str);
        free(str);
    }
    return temp;

}
void scan(char* str){

    int length = CountLength(str);
    if(length == 0)
        AddSize(str);
    int current_length = 1;
    char temp;
    int i = 0;
    while(1){
        scanf("%c", &temp);
        str[i] = temp;
        if(temp == '\n'){
            str[i] = '\0';
            break;
        }
        current_length ++;
        i ++;
        // if(current_length == length)
        //     AddSize(str);
    }

}
int strstrstr(){}

int main(void){

    char* str1 = NULL;
    scan(str1);
    int length = CountLength(str1);
    printf("str1: %s\n", str1);
    printf("str1的長度: %d\n", length);
    return 0;

}