// 1. 回答這題的結果
#include "stdio.h"


int x = 15;

void func(int a) { 
    int x = 10;
    if (a > 0) {
        extern int x;
        printf("x = %d\n", x);
    }

}


int main(void) { 
    int a = 110;
    func(a);
    return 0;
}

// 2. 理解static的用法

1. static 加在函數裡的變數前面 (局部靜態變數)
在函數內的變數在函數呼叫完畢後記憶體空間不會被釋放掉,
下次呼叫同樣的函數時,會繼承前一次函數執行完畢的值

2. static 加在變數前面 (全域靜態變數)
當main.c在include其他.c檔案時,
若兩個.c檔案存在同名的變數時,
透過在該變數前加入static修飾後,
可以在編譯時讓編譯器知道這兩個變數存在於不同.c檔中,
在呼叫時可以針對某一個.c檔案的函數書叫

3. static 加在class裡的變數前面 (靜態成員變數)
在main函數中同時建立了相同class但不同instance時,
各個instance會共享這個靜態成員變數

4. static 加在class裡的函數前面 (靜態成員函數)
不在main函數建立任何屬於該class的instance時,
依舊可以呼叫該class裡的靜態成員函術
