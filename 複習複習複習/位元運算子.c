#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinaryPrint(int target){}
void Ceiling(int target){}
void Flooring(int target){}
void SetBit(int target, int position){}
void ClearBit(int target, int position){}
void ToggleBit(int target, int position){}
void CheckBit(int target, int position){}
void HighestBit(int target){}
void Check2Pow(int target){}

int main(void){

    int target = 85;
    printf("target: %3d, ", target);
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