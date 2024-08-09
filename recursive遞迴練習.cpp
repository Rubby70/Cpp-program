#include <iostream>
using namespace std;


int recursive(int n, int m, int cnt){

    for(int i = 1; i < cnt; i ++){
        cout << " ";
    }
    cout << "進入遞迴" << endl;
    if((n == 0) || (m == 0) || (n == m)){
        return 1;
    }
    cnt ++;
    return recursive(n - 1, m, cnt) + recursive(n - 1, m - 1, cnt);

}

int main(void){

    int result = recursive(3, 2, 1);
    cout << result << endl;
    return 0;

}