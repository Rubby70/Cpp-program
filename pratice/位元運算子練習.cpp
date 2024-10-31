#include <bits/stdc++.h>
using namespace std;


void Q1(int n){

    bitset<32> b(n);
    bitset<32> b1(n & (n - 1));
    cout << b << endl;
    cout << b1 << endl;

}
void Q2(int n){

    bitset<32> b(n);
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n = n + 1;
    bitset<32> b1(n);
    bitset<32> b2(n >> 1);
    cout << b << endl;
    cout << b1 << endl;
    cout << b2 << endl;

}
void Q3(int n){//X

    bitset<32> b(n);
    bitset<32> bb(- n);
    bitset<32> b1(n & (- n));
    cout << b << endl;
    cout << bb << endl;
    cout << b1 << endl;

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
    cout << check << endl;

}
void Q5(int n){

    bitset<32> b(n);
    bitset<32> bb(n - 1);
    bitset<32> bbb(n & (n - 1));
    cout << b << "\n";
    cout << bb << "\n";
    cout << bbb << "\n";
    if((n & (n - 1)) == 0){
        cout << "是2的次方數" << "\n";
    }
    else{
        cout << "不是2的次方數" << "\n";
    }

}
void Q6(){

    int n = 54;
    bitset<32> b(n);
    cout << b << " -> " << n << "\n";

    //setbit
    int mask1 = 1 << 3;
    n |= mask1;
    bitset<32> b1(n);
    cout << b1 << "\n";

    //clearbit
    int mask2 = 1 << 2;
    n &= ~mask2;
    bitset<32> b2(n);
    cout << b2 << "\n";

    //togglebit
    int mask3 = 1 << 5;
    n ^= mask3;
    bitset<32> b3(n);
    cout << b3 << "\n";

    //checkbit
    int mask4 = 1 << 1;
    n &= mask4;
    bitset<32> b4(n);
    cout << b4 << "\n";

}
void Q7(){//X

    int n = 32;
    bitset<32> b(n);
    cout << b << " -> " << n << "\n";

    //flooring
    int n1 = n;
    n1 |= n1 >> 1;
    n1 |= n1 >> 2;
    n1 |= n1 >> 4;
    n1 |= n1 >> 8;
    n1 |= n1 >> 16;
    n1 = n1 - (n1 >> 1);
    bitset<32> b1(n1);
    cout << b1 << " -> " << (n1) << endl;

    //ceiling
    int n2 = n;
    n2 |= n2 >> 1;
    n2 |= n2 >> 2;
    n2 |= n2 >> 4;
    n2 |= n2 >> 8;
    n2 |= n2 >> 16;
    n2 += 1;
    bitset<32> b2(n2);
    cout << b2 << " -> " << n2 << endl;

}

int main(void){

    int n = 0;
    // cin >> n;

    // Q1(n);
    // Q2(n);
    // Q3(n);
    // Q4();
    // Q5(n);
    Q6();
    // Q7();
    return 0;

}