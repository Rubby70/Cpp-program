#include "stdio.h"
#include "stdlib.h"

void printBit(int input){

    int temp;
    printf("%4d, ", input);
    for(int i = 15; i >= 0; i --){
        temp = (input >> i);
        temp &= 1;
        printf("%d", temp);
    }
    printf("\n");

}
int ceiling(int target){

    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    return target;

}
int flooring(int target){

    target = target - 1;
    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    target = target >> 1;
    return target;

}
int setbit(int target){

    int mask = 1 << 1;
    target |= mask;
    return target;

}
int clearbit(int target){

    int mask = 1 << 1;
    target &= (~mask);
    return target;

}
int togglebit(int target){

    int mask = 1 << 1;
    target ^= mask;
    return target;

}
int checkBit(int target){

    int mask = 1 << 1;
    target &= mask;
    return target;
    
}
int highestBit(int target){

    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    target = target >> 1;
    return target;

}
int check2Pow(int target){

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;
    return copy - target == 0 ? 1: 0 ;

}

int main(void){

    int target;
    scanf("%d", &target);

    int Q1 = ceiling(target);
    int Q2 = flooring(target);
    int Q3 = setbit(target);
    int Q4 = clearbit(target);
    int Q5 = togglebit(target);
    int Q6 = checkBit(target);
    int Q7 = highestBit(target);
    int Q8 = check2Pow(target);

    printf("input     : ");
    printBit(target);
    printf("ceiling   : ");
    printBit(Q1);
    printf("flooring  : ");
    printBit(Q2);

    printf("\n以下統一改第2個數字\n");
    printf("setbit    : ");
    printBit(Q3);
    printf("clearbit  : ");
    printBit(Q4);
    printf("togglebit : ");
    printBit(Q5);
    printf("checkBit  : %d的第2個bit是 %d\n", target, Q6);
    printf("highestBit: ");
    printBit(Q7);

    if(Q8)
        printf("%d是2的次方數\n", target);
    else
        printf("%d不是2的次方數\n", target);
    return 0;

}