// 第一題, string knowledge
#include "string.h"
#include "stdio.h"
#include "stdlib.h"



int main(void){

    char *str1 = "hello";
    // str1[0] = 'H'; 這行會發生甚麼事情

    char str2[] = "hello";
    //str2[0] = 'H'; 這行會發生甚麼事情

    printf("Sizeof(str1) = %d\n", sizeof(str1));
    printf("Sizeof(str2) = %d\n", sizeof(str2));
    printf("strlen(str1) = %d\n", strlen(str1));
    printf("strlen(str2) = %d\n", strlen(str2));

    return 0;
}
error
Hello
8 bytes
6 bytes
5
5

// 第二題, strcmp
#include "stdio.h"
#include "stdbool.h"

bool fcn(char *str1, char *str2) { 

}

int main(void) {

    char str1[] = "abcd";
    char str2[] = "abcd";
    printf("string same ? %d\n", str1 == str2);
    return 0;

}
A:
bool fcn(char *str1, char *str2) { 

    int i;
    for(i = 0; str1[i] != '\0'; i ++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    if(str2[i] != '\0'){
        return 0;
    }
    return 1;

}
0

// 第三題, reverse string
#include "string.h"
#include "stdio.h"


#define swap(a, b) do{ \
    char temp = (a); \
    (a) = (b); \
    (b) = temp; \
}while(0)

char * reverse_string(char *, int length);

int main(void) {
    char str[10] = "abcdefg";
    printf("len = %ld\n", strlen(str));
    printf("result = %s\n", reverse_string(str, strlen(str)));
    return 0;
}

char *reverse_string(char *str, int length) {

    for(int i = 0; i < length / 2; i ++){
        swap(str[i], str[length - 1 - i]);
    }
    return str;

}


// 第四題, string 比較
#include "bits/stdc++.h"

using namespace std;

int main(void){
    char str1[] = "Hello";
    char str2[] = "Hello";

    const char str3[] = "Hello";
    const char str4[] = "Hello";

    const char* str5 = "Hello";
    const char* str6 = "Hello";

    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
}
0
0
1
