#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void Q1(){

    int n;
    cin >> n;
    bitset<32> b1(n);
    n &= (n - 1);
    bitset<32> b2(n);
    cout << b1 << "\n";
    cout << b2 << "\n";

}
void Q2(){

    int n;
    cin >> n;
    bitset<32> b1(n);
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = n + 1;
    bitset<32> b2(n);
    bitset<32> b3(n >> 1);
    cout << b1 << "\n";
    cout << b2 << "\n";
    cout << b3 << "\n";

}
void Q3(){

    int n;
    cin >> n;
    bitset<32> b1(n);
    bitset<32> b2(-n);
    bitset<32> b3(n &= (-n));
    cout << b1 << "\n";
    cout << b2 << "\n";
    cout << b3 << "\n";

}
void Q4(){

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

    int n;
    cin >> n;
    bitset<32> b1(n);
    bitset<32> b2(n - 1);
    bitset<32> b3(n & (n - 1));
    cout << b1 << "\n";
    cout << b2 << "\n";
    cout << b3 << "\n";
    if((n & (n - 1)) == 0){
        cout << "是2的次方數" << "\n";
    }
    else{
        cout << "不是2的次方數" << "\n";
    }

}
void Q6(){

    int n;
    cin >> n;
    bitset<32> b0(n);
    //setbit
    int n1 = n;
    int mask1 = 1 << 1;
    bitset<32> b1(n1 |= mask1);
    //clearbit
    int n2 = n;
    int mask2 = 1 << 2;
    bitset<32> b2(n2 &= ~mask2);

    //togglebit
    int n3 = n;
    int mask3 = 1 << 3;
    bitset<32> b3(n3 ^= mask3);

    //checkbit
    int n4 = n;
    int mask4 = 1 << 4;
    bitset<32> b4 (n4 &= mask4);

    cout << b0 << "\n";
    cout << b1 << "\n";
    cout << b2 << "\n";
    cout << b3 << "\n";
    cout << b4 << "\n";

}
void Q7(){

    int n;
    cin >> n;
    bitset<32> b0(n);
    //flooring
    int n1 = n;
    n1 |= n1 >> 1;
    n1 |= n1 >> 2;
    n1 |= n1 >> 4;
    n1 |= n1 >> 8;
    n1 |= n1 >> 16;
    bitset<32> b1(n1 - (n1 >> 1));

    //ceiling
    int n2 = n;
    n2 |= n2 >> 1;
    n2 |= n2 >> 2;
    n2 |= n2 >> 4;
    n2 |= n2 >> 8;
    n2 |= n2 >> 16;
    n2 = n2 + 1;
    bitset<32> b2(n2);

    cout << b0 << "->" << n << "\n";
    cout << b1 << "->" << (n1 - (n1 >> 1)) << "\n";
    cout << b2 << "->" << n2 << "\n";

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