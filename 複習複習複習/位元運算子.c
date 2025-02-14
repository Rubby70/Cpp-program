#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinaryPrint(int target){

    printf("%3d, ", target);
    int temp;
    for(int i = 16; i >= 0; i --){
        temp = (target >> i) & 1;
        printf("%d", temp);
    }
    printf("\n");

}

void Ceiling(int target){



    printf("ceiling:%5s", "");
    BinaryPrint(target);

}
void Flooring(int target){



    printf("Flooring:%4s", "");
    BinaryPrint(target);

}
void SetBit(int target, int position){

    int mask = 1 << position;

    printf("SetBit(%d):%3s", position, "");
    BinaryPrint(target);

}
void ClearBit(int target, int position){

    int mask = 1 << position;

    printf("ClearBit(%d):%1s", position, "");
    BinaryPrint(target);

}
void ToggleBit(int target, int position){

    int mask = 1 << position;

    printf("ToggleBit(%d):", position);
    BinaryPrint(target);

}
void CheckBit(int target, int position){

    int mask = 1 << position;

    target = (target >> position) & 1;

    printf("CheckBit(%d):%1s", position, "");
    printf("%d\n", target);

}
void HighestBit(int target){


    printf("HighestBit:%2s", "");
    BinaryPrint(target);

}
void Check2Pow(int target){



}

int main(void){

    int target = 85;

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