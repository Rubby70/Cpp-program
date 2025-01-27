#include "stdio.h"


typedef struct Test{

    int qaq;
    // long long QQ[1000];
    // char arr[10];
    char c;

} test;

typedef struct _TempStruct{

    test tt;
    char cc;

} TempStruct;

int main(void) {
    // 1. 這個struct的大小是多少？
    // ans:
    // 直接利用struct內成員的變數型別來推論
    // 例如struct test中記憶大小最大的是int型別，佔4 bytes
    // 而char雖然只佔1 byte，但為了達成記憶體對齊
    // compiler會自動在char之後自動塞入3個padding來做對齊
    // 因此整個struct的大小會是4 + 1 + 3 = 8 bytes。

    // 2. 在不使用 sizeof 的情況下，如何取得 struct 的大小
    //ans:
    TempStruct temp;
    test* ptr2test = &temp.tt;
    char* ptr2cc = &temp.cc;
    printf("ptr2test: %p\n", ptr2test);
    printf("ptr2cc:   %p\n", ptr2cc);
    int sizeA = (char*)ptr2cc - (char*)ptr2test;
    // sizeA = 8 / 1 = 8

    int sizeB = (int*)ptr2cc - (int*)ptr2test;
    // sizeB = 8 / 4 = 2

    int sizeC = (size_t)ptr2cc - (size_t)ptr2test;
    // sizeC = 8 / 8 = 8 ??
    // size of size_t = 8

    printf("sizeof size_t = %ld\n", sizeof(size_t));
    printf("sizeA = %d\n", sizeA);
    printf("sizeB = %d\n", sizeB);
    printf("sizeC = %d\n", sizeC);
    return 0;
}
