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

    printf("Ceiling: %d, ", target);
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

    printf("Flooring: %d, ", target);
    BinaryPrint(target);

}
void SetBit(int target, int position){

    int mask = 1 << position;
    target |= mask;

    printf("SetBit: %d, ", target);
    BinaryPrint(target);

}
void ClearBit(int target, int position){

    int mask = 1 << position;
    target &= ~mask;

    printf("ClearBit: %d, ", target);
    BinaryPrint(target);

}
void ToggleBit(int target, int position){

    int mask = 1 << position;
    target ^= mask;

    printf("ToggleBit: %d, ", target);
    BinaryPrint(target);

}
void CheckBit(int target, int position){

    int mask = 1 << position;
    target &= mask;

    target = target >> position;
    target &= 1;

    printf("CheckBit: %d\n", target);

}
void HighestBit(int target){

    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    target += 1;
    target = target >> 1;

    printf("HighestBit: %d, ", target);
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

    if(target - copy == 0){
        printf("Is 2 Pow.\n");
    }
    else{
        printf("Not 2 Pow.\n");
    }

}

int main(void){

    int target = 64;
    printf("target: %3d, ", target);
    BinaryPrint(target);

    Ceiling(target);
    Flooring(target);
    SetBit(target, 0);
    ClearBit(target, 1);
    ToggleBit(target, 2);
    CheckBit(target, 1);

    HighestBit(target);
    Check2Pow(target);
    return 0;

}