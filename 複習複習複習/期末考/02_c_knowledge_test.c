// 第一題, 下面程式碼會印出甚麼

#include "stdio.h"

#define fcn(j) j *= 2; j += 1


int main(void) {
    int i = 1;
    for (int k = 0; k < 5; k++)
        fcn(i);
    printf("answer = %d\n", i);
}
33

#include "stdio.h"

#define swap(a, b) \
  temp = a;        \
  a = b;           \ 
  b = temp;

int main(void) { 
    int i = 5;
    int j = 10;

    int temp = 0;
    if (i > j) swap(i, j);
    
    printf("%d %d %d", i, j, temp);
}
10, 0, 0

// 第二題, malloc是甚麼, 他能做些甚麼,要注意甚麼,還有回答下面那個程式碼會印出甚麼
#include<stdio.h>

int main()
{
    char *ptr;
    if ((ptr = (char *)malloc(0)) == NULL) 
    {
        puts("Got a null pointer");
    } else {
        puts("Got a valid pointer");
    }
}
malloc可以動態索取一串記憶體位置用來儲存byte
必須指定要存取的變數型態及數量
並且在前方作強制轉型
若malloc而不釋放記憶體的話會造成記憶體洩漏(memory leak)
這段程式碼會印出 "Got a valid pointer"
因為malloc(0)會讓ptr變成實際存在的指標
但不能對其dereference
並且其值不等於NULL

// 第三題
#include "stdio.h"
#include "stdlib.h"

int main(void) {
    int *a = (int *)malloc(sizeof(int));
    // return 0;  如果這行註解被打開 會發生甚麼事情
    free(a);
	// *a = 100;  如果這行註解被打開 會發生甚麼事情
	return 0;

}
只有第一個註解被打開時,a會指向可以儲存整數指標並且大小只有一個int的byte
只有第二個註解被打開時,*a為未定義行為

// 第四題, 下面程式碼會印出甚麼
#include "stdio.h"

int main(void) { 
    int arr[] = {5, 1, 2, 3, 4};
    int *p = (&arr+1);
    printf("(*p - 1) = %d\n", (*p - 1));
    printf("*(p - 1) = %d\n", *(p - 1));
    return 0;
}
(*p - 1) = 0
*(p - 1) = 5

// 第五題, 下面程式碼會印出甚麼
#include "stdio.h"


int main(void){
    int arr[] = {1, 2, 3, 11, 22, 55};
    int *a = arr;
    int *b = arr + 3;
    int c = *a++ + *b++;
    int d = *++a + *++b;
    printf("%d %d\n", c, d);
}
a = arr[0] = 1
b = arr[3] = 11
c = arr[0] + arr[3] = 1 + 11 = 12, a = arr[1], b = arr[4]
d = arr[2] + arr[5] = 3 + 55 = 58

// 第六題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int main(void){
    int cnt = 0;
    char* pc = "welcome";
    while(*pc++){
        cnt++;
    }
    printf("cnt = %d\n", cnt);
    return 0;
}
7

// 第七題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int main(void){
    float a = 0.7;
    float b = 0.8;

    if(a < 0.7 && b < 0.8){
        printf("problem A\n");
    }
    else if(a < 0.7 && b > 0.8){
        printf("problem B\n");
    }
    else if(a > 0.7 && b < 0.8){
        printf("problem C\n");
    }
    else if(a > 0.7 && b > 0.8){
        printf("problem D\n");
    }
    else{
        printf("problem E");
    }
    return 0;
}
problem B

// 第八題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int main(void){

    int arr[] = {3,6,4,6,6,3,3,-1,3,6,4,6,6,3,3,-2};
    int cnt = 0, sum = 0;
    int i = 0;
    do{
        sum += arr[i];
        if(arr[i++] < 0)
            continue;
        cnt ++;
        
    }while(i < 16);

    printf("cnt = %d, sum = %d\n", cnt, sum);

    return 0;
}
14
59

// 第九題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE -1
#define NULL 0

int main(void){

    if(NULL)
        printf("NULL\n");
    else if(FALSE){
        printf("FALSE\n");
    }
    else
        printf("TRUE\n");

    return 0;
}
FALSE

// 第十題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

void swap(int* x, int* y){
    int* temp = x;
    x = y;
    y = temp;
}

int main(void){

    int a = 10; 
    int b = 20;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
a = 10
b = 20

// 第十一題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"


// 給定範圍[0,10)請問最大的迴圈次數
#include "stdio.h"
#include "stdlib.h"

int bin_search(int *arr, int target){
    int l = 0, r = 10;
    while(l < r){
        int mid = (l + r) / 2;
        if(arr[mid] < target)
            l = mid;
        else if(arr[mid] > target)
            r = mid;
        else
            return mid;
    }

    return -1;
}

int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
    int target = 9;
    int result = bin_search(arr, target);  // 無窮迴圈
    return 0;
}
無限次, l卡在8, r卡在10

// 第十二題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int main(void){
    int x = 0;
    if(x = 0 || x == 0)
        printf("1\n");
    printf("x = %d\n", x);
    if(x == 0)
        printf("2\n");
    printf("3\n");
    return 0;
}
1
x = 1
3

// 第十三題, 下面程式碼會印出甚麼
#include "stdio.h"


int main(void){
    int i = 100;
    printf("%d\n", (i++, ++i));

    return 0;
}
102

// 第十四題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int main(void){
    int a = 320;
    char* pc = (char*)&a;
    printf("%d\n", *pc);

    return 0;
}
*pc取值會只有8個bit
ANS: 64 (1000000)

// 第十五題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int func(int a, int*b){
    static int c = 0;
    a += *b;
    *b += a;
    c += a + *b;
    return c;
}

int main(void){

    int x = 5, y = 7, z = 0;
    x = func(x, &y);
    printf("x = %d, y = %d\n", x, y);
    z = func(x, &y);
    printf("x = %d, y = %d, z = %d\n", x, y,z);

    printf("x+y+z = %d\n", x+y+z);

    return 0;
}
a = 12
b = 19 (y = 19)
c = 12 + 19 = 31
(x = 31, y = 19, z = 0)

a = 50
b = 69 (y = 69)
c = 31 + 50 + 69 = 150
(x = 31, y = 69, z = 150)

1. x = 31, y = 19
2. x = 31, y = 69, z = 150
3. x + y + z = 250


// 第十六題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

int test(int x){
    static int a;
    return a + x;
}

int main(void){

    int a = 0;
    int b = 0;
    while(1){
        b = 0;
        for(int i = 0; i < 3; i++){
            a = test(a);
            b = test(b);
            a ++;
            b ++;
        }
        printf("a = %d, b = %d\n", a, b);
        break;
    }
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
a = 3, b = 3
a = 3, b = 3

// 第十七題, 下面程式碼會印出甚麼
#include "stdio.h"
#include "stdlib.h"

#define THRB 0x08

int main(void){
    int ch = 26;
    if(ch & 0xf > THRB)
        printf("MORE %d\n", ch & 0xf);
    else
        printf("LESS %d\n", ch & 0xf);

    return 0;
}
LESS, 10 (是十進位不是二進位)

// 第十八題, 下面程式碼會印出甚麼
#include "stdio.h"


int main(void){
    int i = 0, a = 0, b = 0, c = 0, d = 0;
    for (i = 0, a = 0; ++i < 5; a++);
    for (i = 5, b = 0; --i; b++);
    for (i = 0, c = 0; i++ < 5; c++);
    for (i = 5, d = 0; i--; d++);
    printf("%d %d %d %d\n", a, b, c, d);
    printf("%d\n", a * b * c * d);
}
a = 4, b = 4, c = 5, d = 5
a * b * c * d = 400


// 第十九題, 下面程式碼會印出甚麼
#include "stdio.h"

void foo() { 
    static int i = 0;
    i++;
    printf("%d", i);
}

int main(void) { 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
    foo(); 
}
12345678


// 第二十題, 下面程式碼會印出甚麼
#include "stdio.h"

int a = 0;
int b;

int main(void){
    static int c = 0;
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);

    return 0;
}
