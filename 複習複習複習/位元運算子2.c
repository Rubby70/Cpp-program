#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinaryPrint(int target){

    for(int i = 15; i >= 0; i --){
        int temp = (target >> i) & 1;
        printf("%d", temp);
    }
    printf("\n");

}

void Ceiling(int target){

    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    
    printf("Ceiling:%5s", "");
    BinaryPrint(target);

}
void Flooring(int target){

    target -= 1;
    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    target = target >> 1;

    printf("Flooring:%4s", "");
    BinaryPrint(target);

}
void SetBit(int target, int position){

    int mask = 1 << position;
    target |= mask;

    printf("SetBit(%d):%3s", (position + 1), "");
    BinaryPrint(target);

}
void ClearBit(int target, int position){

    int mask = 1 << position;
    target &= ~mask;

    printf("ClearBit(%d):%1s", (position + 1), "");
    BinaryPrint(target);

}
void ToggleBit(int target, int position){

    int mask = 1 << position;
    target ^= mask;

    printf("ToggleBit(%d):", (position + 1));
    BinaryPrint(target);

}
void CheckBit(int target, int position){

    int mask = 1 << position;
    target &= mask;

    printf("CheckBit(%d):%1s", (position + 1), "");
    BinaryPrint(target);

}
void HighestBit(int target){

    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    target = target >> 1;

    printf("HighestBit:%2s", "");
    BinaryPrint(target);

}
void Check2Pow(int target){

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;

    if(copy - target == 0){
        printf("是\n");
    }
    else{
        printf("不是\n");
    }

}

int main(void){

    // int target;
    // printf("target (建議小於65536) = ");
    // scanf("%d", &target);

    int target = 85; //85

    printf("target:%6s", "");
    BinaryPrint(target);
    Ceiling(target);
    Flooring(target);

    printf("\ntarget:%6s", "");
    BinaryPrint(target);
    SetBit(target, 1);
    ClearBit(target, 2);
    ToggleBit(target, 3);
    CheckBit(target, 4);
    HighestBit(target);
    Check2Pow(target);
    return 0;

}