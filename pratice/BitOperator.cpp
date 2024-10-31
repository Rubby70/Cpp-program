#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Q1(){
    
    int input;
    cin >> input;
    bitset<32> bs(input);
    input &= (input - 1);
    bitset<32> bs1(input);
    cout << bs << "\n";
    cout << bs1 << "\n";

}
void Q2(){

    int input;
    cin >> input;
    bitset<32> bs(input);
    input |= (input >> 1);
    input |= (input >> 2);
    input |= (input >> 4);
    input |= (input >> 8);
    input |= (input >> 16);
    input += 1;
    bitset<32> bs1(input);
    bitset<32> bs2(input >> 1);
    cout << bs << "\n";
    cout << bs1 << "\n";
    cout << bs2 << "\n";

}
void Q3(){

    int input;
    cin >> input;
    bitset<32> bs(input);
    input &= (-(input - 1));
    bitset<32> bs1(input);
    cout << bs << "\n";
    cout << bs1 << "\n";

}
void Q4(){ //XXXXXXXXXXXX

    vector<int> arr = {1, 2, 5, 4};
    int check = 0;
    for(int i = 0; i <= arr.size(); i ++){
        check ^= (i + 1);
    }
    for(int i = 0; i < arr.size(); i ++){
        check ^= arr[i];
    }
    cout << check << "\n";

}
void Q5(){

    int input;
    cin >> input;
    bitset<32> bs(input);
    if((input & (input - 1)) == 0){
        cout << "是2的次方數\n";
    }
    else
        cout << "不是2的次方數\n";

}
void Q6(){

    int input;
    cin >> input;
    bitset<32> bs(input);
    //setbit
    int mask1 = (1 << 1);
    input |= mask1;
    bitset<32> bs1(input);
    //clearbit
    int mask2 = ~(1 << 1);
    input &= mask2;
    bitset<32> bs2(input);
    //togglebit
    int mask3 = (1 << 1);
    input ^= mask3;
    bitset<32> bs3(input);
    //checkbit
    int mask4 = (1 << 1);
    input &= mask4;
    bitset<32> bs4(input);
    cout << "初始值   " << bs << "\n";
    cout << "設為1    "<< bs1 << "\n";
    cout << "設為0    "<< bs2 << "\n";
    cout << "取反     "<< bs3 << "\n";
    cout << "確認數值 "<< bs4 << "\n";

}
void Q7(){

    int input;
    cin >> input;
    bitset<32> bs(input);
    //flooring
    int N1 = input - 1;
    N1 |= N1 >> 1;
    N1 |= N1 >> 2;
    N1 |= N1 >> 4;
    N1 |= N1 >> 8;
    N1 |= N1 >> 16;
    N1 += 1;
    bitset<32> bs1(N1 >> 1);
    //ceiling
    int N2 = input;
    N2 |= N2 >> 1;
    N2 |= N2 >> 2;
    N2 |= N2 >> 4;
    N2 |= N2 >> 8;
    N2 |= N2 >> 16;
    N2 += 1;
    bitset<32> bs2(N2);
    cout << (input) << ":" << bs << "\n";
    cout << (N1 >> 1) << ":" << bs1 << "\n";
    cout << (N2) << ":" << bs2 << "\n";

}

int main(void){

    //Q1();
    //Q2();
    //Q3();
    //Q4();
    //Q5();
    //Q6();
    //Q7();
    return 0;

}