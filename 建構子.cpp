#include <iostream>
using namespace std;


class test{

    public:
        test(int x, int y){
            cout << "Hello World" << "\n";
            AA = x;
            BB = y;
        }
        
        void print(){
            cout << AA << "\n";
            cout << BB << "\n";
        }
    private:
        int AA;
        int BB;
};

int main(void){

    test player(1, 2);
    player.print();
    return 0;

}