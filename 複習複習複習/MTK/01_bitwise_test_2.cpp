#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ceiling(){

    int target;
    cin >> target;
    
    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void flooring(){

    int target;
    cin >> target;
    
    int copy = target - 1;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void setbit(){

    int target;
    int whichbit;
    cin >> target >> whichbit;
    
    int copy = target;
    int mask = 1 << whichbit;
    copy |= mask;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void clearbit(){

    int target;
    int whichbit;
    cin >> target >> whichbit;
    
    int copy = target;
    int mask = 1 << whichbit;
    copy &= (~mask);

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";
    
}
void togglebit(){

    int target;
    int whichbit;
    cin >> target >> whichbit;
    
    int copy = target;
    int mask = 1 << whichbit;
    copy ^= mask;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void checkBit(){

    int target;
    int whichbit;
    cin >> target >> whichbit;
    
    int copy = target;
    int mask = 1 << whichbit;
    copy &= mask;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void highestBit(){

    int target;
    cin >> target;
    
    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;

    bitset<32> bs(target);
    bitset<32> bs1(copy);
    cout << "input  : " << target << ", " << bs << "\n";
    cout << "output : " << copy << ", " << bs1  << "\n";

}
void check2Pow(){

    int target;
    cin >> target;
    
    int copy = target;
    copy |= copy >> 1;
    copy |= copy >> 2;
    copy |= copy >> 4;
    copy |= copy >> 8;
    copy |= copy >> 16;
    copy += 1;
    copy = copy >> 1;

    if(target - copy == 0)
        cout << "是2的次方數\n";
    else
        cout << "不是2的次方數\n";

    bitset<32> bs(target);
    cout << "input  : " << target << ", " << bs << "\n";

}

int main(void){

    //ceiling();
    //flooring();
    //setbit();
    //clearbit();
    //togglebit();
    //checkBit();
    //highestBit();
    //check2Pow();
    return 0;

}