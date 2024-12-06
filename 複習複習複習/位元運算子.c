#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

void BinaryPrint(int input){

    for(int i = 16; i >= 0; i --){
        int temp = (input >> i) & 1;
        printf("%d", temp);
    }

}
void ceiling(int target){ 

    printf("\nceiling.\n");
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void flooring(int target){

    printf("\nflooring.\n");
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target - 1;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void setbit(int target, int whichBit){
    
    printf("\nsetbit. whilchBit: %d\n", whichBit);
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    int mask = 1 << whichBit;
    copy |= mask;
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void clearbit(int target, int whichBit){

    printf("\nclearbit. whichBit: %d\n", whichBit);
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    int mask = 1 << whichBit;
    copy &= (~mask);
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void togglebit(int target, int whichBit){

    printf("\ntogglebit. whichBit: %d\n", whichBit);
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    int mask = 1 << whichBit;
    copy ^= mask;
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void checkBit(int target, int whichBit){

    printf("\ncheckbit. whichBit: %d\n", whichBit);
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    int mask = 1 << whichBit;
    copy &= (mask);
    
    if(copy == 0){
        printf("bit: 0\n");
    }
    else{
        printf("bit: 1\n");
    }

}
void highestBit(int target){

    printf("\nhighestbit.\n");
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;   
    
    printf("output: ");
    BinaryPrint(copy);
    printf("\n");

}
void check2Pow(int target){

    printf("\ncheck2Pow.\n");
    printf("input : ");
    BinaryPrint(target);
    printf("\n");

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;
    copy -= target;
    
    if(copy == 0){
        printf("是2的次方數\n");
    }
    else{
        printf("不是2的次方數\n");
    }

}

int main(void){

    int target;
    printf("target (建議小於65536) = ");
    scanf("%d", &target);

    ceiling(target);
    flooring(target);
    setbit(target, 3);
    clearbit(target, 1);
    togglebit(target, 1);
    checkBit(target, 1);
    highestBit(target);
    check2Pow(target);
    return 0;

}