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
    char* temp = (char*)malloc(sizeof(char) * new_length);
    if(length != 0){
        strcpy(temp, str);
        free(str);
    }
    return temp;

}
void scan(char** ptr2str){

    int length = CountLength(*ptr2str);
    if(length == 0)
        *ptr2str = AddSize(*ptr2str);
    int current_length = 1;
    int i = 0;
    while(1){
        scanf("%c", &(*ptr2str)[i]);
        if((*ptr2str)[i] == '\n'){
            (*ptr2str)[i] = '\0';
            break;
        }
        current_length ++;
        i ++;
        if(current_length == length)
            *ptr2str = AddSize(*ptr2str);
    }

}
int strstrstr(char* str1, char* str2){

    int position_str1 = 0;
    int position_str2 = 0;
    int length_str1 = CountLength(str1);
    int length_str2 = CountLength(str2);
    int start = -1;
    int end = -1;
    while(1){
        if(position_str2 == length_str2){
            end = position_str1 - 1;
            printf("Location: %d - %d\n", start, end);
            return 1;
        }
        if(position_str1 == length_str1)
            break;
        if((start == -1) && (str1[position_str1] == str2[position_str2])){
            start = position_str1;
            printf("發現第一個字母相同的位置: %d\n", start);
        }
        if(str1[position_str1] != str2[position_str2]){
            if(start != -1)
                printf("重新開始檢查\n");
            position_str1 ++;
            position_str2 = 0;
            start = -1;
            continue;
        }
        position_str1 ++;
        position_str2 ++;
    }
    printf("Not found\n");
    return -1;

}

int main(void){

    printf("input 1: ");
    char* str1 = NULL;
    scan(&str1);
    printf("input 2: ");
    char* str2 = NULL;
    scan(&str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    strstrstr(str1, str2);
    return 0;

}