// 著名的josephus problem 
// 給一個長度為N的陣列 代表有N個人 
// 給你一個起始點P 以及間隔K 
// 從第P個人開始算 每次數到K個人之後 把他殺掉 
// 並從被殺掉的人的下一個人開始計算 直到只剩下1個人 
// 請問最後剩下的人 是編號幾的人
// N > 1 & P < N

#include <iostream>
using namespace std;


class ChainNode{

    friend class Chain;
    private:
        int data;
        ChainNode *next;
    public:
        ChainNode(int input, ChainNode *link = NULL){
            data = input;
            next = link;
        }

};
class Chain{

    private:
        ChainNode *first;
        ChainNode *last;
    public:
        Chain(){
            first = NULL;
            last = NULL;
        }
        void create_node(int input){
            if(!first){ //如果沒有任何節點存在
                first = new ChainNode(input); //將first指向這個新節點
                first->next = first; //因為只有一個節點所以next指向自己
                last = first; //last也指向自己
            }
            else{ //如果已經有節點
                last->next = new ChainNode(input); //將現在的last指向新的節點
                last = last->next; //更新last指向新的節點
                last->next = first; //新的節點的next指向第一個節點
            }
        }
        void insert_node(int input, int count){
            if(!first){
                cout << "沒有節點存在" << "\n";
                return ;
            }
            else{
                ChainNode *link_forward = first; //紀錄第N個node的位置
                ChainNode *link_backward = NULL; //紀錄第N+1個node的位置
                for(int i = 1; i < count - 1; i ++){ //找到第N個node的位置
                    link_forward = link_forward->next;
                }
                link_backward = link_forward->next; //保留第N+1個node的位置
                link_forward->next = new ChainNode(input); //在第N個node後方插入新的node
                link_forward->next->next = link_backward; //在新node後方插入原本第N+1個node
            }
        }
        void view_all_node(){
            if(!first){
                cout << "沒有節點存在" << "\n";
                return ;
            }
            else{
                ChainNode *link = first;
                cout << "剩下的人:[ ";
                do{
                    cout << link->data << " ";
                    link = link->next;
                }while(link != first);
                cout << "]";
            }
        }
        void data(ChainNode* input){
            cout << input->data;
        }
        void reverse(){
            if(!first){
                cout << "沒有節點存在" << "\n";
                return ;
            }
            else{
                ChainNode *current = first;
                ChainNode *previous = NULL;
                while(1){
                    ChainNode *temp = previous; //第一次時為NULL
                    previous = current; //將previous與current往下一個node移動
                    if(temp == NULL){
                        last = previous; //在最一開始時就紀錄反轉後的last node位置
                    }
                    current = current->next; //將previous與current往下一個node移動
                    previous->next = temp; //將previous的下一個node指向前一個node
                    if(current == last){ //若繞完一圈則current會因為circular而重新指向last
                        first = previous; //此時重新定義first位置
                        last->next = first; //將circular重新建立
                        break;
                    }
                }
            }
        }
        bool only1(){
            return first == last;
        }
        ChainNode* delete_node(ChainNode* target, int count){
            ChainNode* new_target = NULL;
            if(first == last){
                cout << "node全部清除";
                delete first;
            }
            else if(count == 0){
                cout << "不能間隔0";
            }
            else{
                ChainNode *link_forward = target; //紀錄第N-1個node的位置
                ChainNode *link_target = NULL;   //紀錄第N個node的位置 (要被刪除的node)
                ChainNode *link_backward = NULL; //紀錄第N+1個node的位置
                if(count == 1){
                    link_target = link_forward;
                }
                else if(count >= 2){
                    for(int i = 0; i < count - 2; i ++){ //找到第N-1、N、N+1個node的位置
                        link_forward = link_forward->next; //第N-1個node
                    }
                    link_target = link_forward->next;
                }

                if(link_target == first){
                    first = first->next;
                    last->next = first;
                    new_target = first;
                    delete link_target;
                }
                else if(link_target == last){
                    last = link_forward;
                    last->next = first;
                    new_target = first;
                    delete link_target;
                }
                else{
                    link_backward = link_target->next; //第N+1個node
                    link_forward->next = link_backward; //將N-1指向N+1
                    new_target = link_backward;
                    delete link_target;
                }
            }
            return new_target;
        }
        ChainNode* find_address(int count){
            ChainNode* target = first;
            for(int i = 0; i < count; i ++){
                target = target->next;
            }
            return target;
        }
        
};

int main(void){

    Chain LL;
    int N, P, K;
    cout << "請輸入N P K: ";
    cin >> N >> P >> K;
    // int N = 10;
    // int P = 2;
    // int K = 4;
    for(int i = 1; i <= N; i ++){ //總共N個人
        LL.create_node(i);
    }
    cout << "共有" << N << "個人, ";
    cout << "從第" << P << "個人開始, ";
    cout << "每隔" << K << "個人就殺掉, ";
    cout << "接著從被殺掉的下一位開始找" << "\n\n";
//-----------------------------------------------------

    ChainNode* target = LL.find_address(P - 1);
    cout << "起始目標: ";
    LL.data(target);
    cout << ", ";
    LL.view_all_node();
    cout << "\n";
    while(!LL.only1()){
        target = LL.delete_node(target, K);
        cout << "起始目標: ";
        LL.data(target);
        cout << ", ";
        LL.view_all_node();
        cout << "\n";
    }
    
//-----------------------------------------------------
    cout << "\n" << "最後";
    LL.view_all_node();
    cout << "\n";
    return 0;

}