#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// 這個有錯QQ
bool test(int x){
    return ((x >> 8) & 0xff) && !(((x << 8) >> 8) | 0x00);
}

int main(void){
    // 確認一個數字的高位8bit都是1 低位8bit 都是0
    int target = 0b1111111100000100;
    printf("%d\n", test(target));

    return 0;
}