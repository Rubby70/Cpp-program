// 第一題, 請問這個程式會因為ambiguous而無法編譯嗎?
#include "bits/stdc++.h"

using namespace std;

class A{
    public:
        void out(){
            cout << "A" << endl;
        }
};

class B{
    public:
        void out(){
            cout << "B" << endl;
        }
};

class C: public A, public B{
    public:
        void print(){
            out();
        }
};


int main(void){
    C c;
    c.out();
}

// 第二題, 下面程式碼會印出甚麼
#include "bits/stdc++.h"

using namespace std;

class A{
    public:
        A(){
            cout << "A" << endl;
        }
        ~A(){
            cout << "~A" << endl;
        }
};

class B: public A{
    public:
        B(){
            cout << "B" << endl;
        }
        ~B(){
            cout << "~B" << endl;
        }
};



int main(void){
    B b;
    return 0;
}


// 第三題
#include "bits/stdc++.h"

using namespace std;

class A{
    public:
        virtual void func(int val = 0){
            printf("Func A");
        }
        void test(){
            func();
        }
};

class B: public A{
    public:
        void func(int val = 0){
            printf("Func B\n");
        }
};



int main(void){
    B* b = new B();
    b->test();
    return 0;
}


// 第四題 如何宣告一個元素是int's deque

// 第五題 如何使用iterator遍歷vector<int> ivec

// 第六題 map<int,vector<int>>的key_type是什麼? val_type又是什麼

// 第七題 polymorphism 是藉由virtual function來實現嗎?

