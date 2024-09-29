// 著名的josephus problem 
// 給一個長度為N的陣列 代表有N個人 
// 給你一個起始點P 以及間隔K 
// 從第P個人開始算 每次數到K個人之後 把他殺掉 
// 並從被殺掉的人的下一個人開始計算 直到只剩下1個人 
// 請問最後剩下的人 是編號幾的人
// N > 1 & P < N
#include <stdio.h>
using namespace std;


class ChainNode{

    friend class Chain;
    private:
        ChainNode* previous;
        ChainNode* next;
        int data;
    public:
        ChainNode(int input, ChainNode* p = NULL, ChainNode* n = NULL){
            previous = p;
            next = n;
            data = input;
        }

};
class Chain{

    private:
        ChainNode* first;
        ChainNode* last;
    public:
        Chain(){
            first = NULL;
            last = NULL;
        }
        bool isEmpty(){
            return first == NULL;
        }
        ChainNode* FindNode(int count){
            ChainNode* position = NULL;
            if(this->isEmpty()){
                printf("不存在任何node");
                return position;
            }
            else{
                if(count < 1){
                    printf("輸入1時才是第一個人\n");
                    return position;
                }
                position = first;
                for(int i = 0; i < count - 1; i ++){
                    position = position->next;
                }
                return position;
            }
        }
        void CreateNode(int data, ChainNode* position = NULL){
            if(this->isEmpty()){
                first = new ChainNode(data);
                last = first;
            }
            else{
                if(position == NULL){ //未指定位置時將node串在最後面
                    ChainNode* pre = last;
                    pre->next = new ChainNode(data, pre);
                    last = pre->next;
                }
                else if(position != NULL){ //指定node串接位置時
                    ChainNode* pre = position;
                    ChainNode* next = position->next;
                    position->next = new ChainNode(data, pre, next);
                    last = next;
                }
            }
        }
        ChainNode* DeleteNode(int direction, ChainNode* position = NULL, int count = 0){
            if(this->isEmpty()){
                printf("This LinkedList is empty.\n");
                return 0;
            }
            this->ViewNode(position);
            printf(", 殺人前的node:");
            this->ViewAllNode();
            if(direction >= 0){
                position = this->right_search(position, count);
                printf(", 往\"右\"找%d個, ", count);
            }
            else{
                position = this->left_search(position, count);
                printf(", 往\"左\"找%d個, ", count);
            }
            ChainNode* new_target = NULL;
            if(position == first){
                ChainNode* new_first_position = position->next;
                first = new_first_position;
                first->previous = NULL;
                delete position;
                if(direction >= 0){
                    new_target = first;
                }
                else{
                    new_target = last;
                }
            }
            else if(position == last){
                ChainNode* new_last_position = position->previous;
                last = new_last_position;
                last->next = NULL;
                delete position;
                if(direction >= 0){
                    new_target = first;
                }
                else{
                    new_target = last;
                }
            }
            else{
                ChainNode* previous_position = position->previous;
                ChainNode* next_position = position->next;
                previous_position->next = next_position;
                next_position->previous = previous_position;
                delete position;
                if(direction >= 0){
                    new_target = next_position;
                }
                else{
                    new_target = previous_position;
                }
            }
            printf("殺人後的node:");
            this->ViewAllNode();
            printf("\n");
            return new_target;
        }
        ChainNode* right_search(ChainNode* position, int count){
            for(int i = 0; i < count - 1; i ++){
                if(position->next == NULL){
                    position = first;
                    continue;
                }
                position = position->next;
            }
            return position;
        }
        ChainNode* left_search(ChainNode* position, int count){
            for(int i = 0; i < count - 1; i ++){
                if(position->previous == NULL){
                    position = last;
                    continue;
                }
                position = position->previous;
            }
            return position;
        }
        void ViewNode(ChainNode* position){
            if(position == NULL){
                printf("輸入的指標是NULL\n");
                return ;
            }
            printf("起始目標: %d", position->data);
        }
        void ViewAllNode(){
            ChainNode* position = first;
            printf("[ ");
            while(position != NULL){
                printf("%d ", position->data);
                position = position->next;
            }
            printf("]");
        }
        int numbers_of_node(){
            int number = 0;
            ChainNode* link = first;
            while(!this->isEmpty()){
                number ++;
                if(link->next == NULL){
                    break;
                }
                link = link->next;
            }
            return number;
        }

};

int main(void){

    Chain LL;
    int N, P, K;
    printf("請輸入N P K: ");
    scanf("%d%d%d", &N, &P, &K);
    for(int i = 1; i <= N; i ++){
        LL.CreateNode(i);
    }
    // printf("起始node:");
    // LL.ViewAllNode();
    // printf("\n");
    ChainNode* position = LL.FindNode(P);
    for(int i = 2; i > 0; i ++){
        if(LL.numbers_of_node() == 1){
            break;
        }
        if(i % 2 == 1){
            position = LL.DeleteNode(-1, position, K);
        }
        else{
            position = LL.DeleteNode(1, position, K);
        }
    }
    printf("最後存活的人:");
    LL.ViewAllNode();
    printf("\n");
    return 0;

}