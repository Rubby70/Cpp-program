#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinaryPrint(int target){

    for(int i = 10; i >= 0; i --){
        int temp = target >> i;
        temp = temp & 1;
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
    
    printf("C: %3d, ", target);
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

    printf("F: %3d, ", target);
    BinaryPrint(target);

}
void SetBit(int target, int position){

    int mask = 1 << position;
    target |= mask;

    printf("S: %3d, ", target);
    BinaryPrint(target);

}
void ClearBit(int target, int position){

    int mask = 1 << position;
    target &= ~mask;

    printf("C: %3d, ", target);
    BinaryPrint(target);

}
void ToggleBit(int target, int position){

    int mask = 1 << position;
    target ^= mask;

    printf("T: %3d, ", target);
    BinaryPrint(target);

}
void CheckBit(int target, int position){

    int mask = 1 << position;
    target &= mask;
    target >> position;

    printf("Check #%d Bit: %d\n", position, target);

}
void HighestBit(int target){

    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;

    printf("H: %3d, ", copy);
    BinaryPrint(copy);

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
        printf("Is 2 Pow.\n");
    }
    else{
        printf("Not 2 Pow.\n");
    }

}

int main(void){

    int target = 64;
    printf("T: %3d, ", target);
    BinaryPrint(target);

    Ceiling(target);
    Flooring(target);
    SetBit(target, 0);
    ClearBit(target, 1);
    ToggleBit(target, 2);
    CheckBit(target, 3);

    HighestBit(target);
    Check2Pow(target);
    return 0;

}