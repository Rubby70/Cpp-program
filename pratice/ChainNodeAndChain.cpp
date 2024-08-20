#include <iostream>
using namespace std;


class ChainNode{
    
    friend class Chain;
    private:
        int data;
        ChainNode *link;
    public:
        ChainNode(int input_data, ChainNode *next = NULL){
            data = input_data;
            link = next;
        }

};

class Chain{

    private:
        ChainNode *first;
        ChainNode *last;
    public:
        void creat_node(){
            ChainNode *second = new ChainNode(2, 0);
            first = new ChainNode(1, second);
            last = NULL;
        }
        void insertion_node(ChainNode *x){
            if(x){
                x->link = new ChainNode(5, x->link);
            }
            else{
                first = new ChainNode(5, 0);
            }
        }
        void delete_node(ChainNode *x, ChainNode *y){
            if(!x || !y){ //若X或Y其一為NULL，則不能執行
                cerr << "Cannot delete NULL nodes!";
            }
            else{
                if(x == first){ //若X為第一個node
                    first = first->link; //first改成指向Y
                }
                else{ //若Y為第一個node
                    y->link = x->link;  //Y指向X改成指向X的下一個
                }
                delete x;
                x = NULL;
            }
        }
        void insert_last(ChainNode *x){
            if(first){
                last->link = new ChainNode(10, 0);
                last = last->link;
            }
            else{
                first = last = new ChainNode(10, 0);
            }
        }
        void concatenate(Chain *A){
            if(first){
                last->link = A->first;
                last = A->last;
            }
            else{
                first = A->first;
                last = A->last;
                A->first = 0;
                A->last = 0;
            }
        }


};

int main(void){

    return 0;
    
}