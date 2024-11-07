// 著名的josephus problem
// 給一個長度為N的陣列 代表有N個人 
// 給你一個起始點P 以及間隔K 
// 從第P個人開始算 每次數到K個人之後 把他殺掉 
// 並從被殺掉的人的下一個人開始計算 直到只剩下1個人 
// 請問最後剩下的人 是編號幾的人
// N > 1 & P < N
#include <iostream>
using namespace std;


class LinkedList{

    public:
        int data;
        LinkedList* ptr2previous;
        LinkedList* ptr2current;
        LinkedList* ptr2next;

        LinkedList(int element, LinkedList* pre = NULL, LinkedList* now = NULL, LinkedList* next = NULL){
            
            data = element;
            ptr2previous = pre;
            ptr2current = now;
            ptr2next = next;

        }
        LinkedList* NewNode(int element, LinkedList* PreviousNode = NULL){
            
            LinkedList* temp = new LinkedList(element);
            temp->ptr2previous = PreviousNode;
            temp->ptr2current = temp;
            PreviousNode->ptr2next = temp;
            return temp; //回傳最後一個Node的位置

        }
        LinkedList* DeleteNode(LinkedList* target, LinkedList** ptr2ptr2root){

            LinkedList* initial_root = *ptr2ptr2root;
            LinkedList* NextTarget = NULL;
            if(target == *ptr2ptr2root){ //如果要殺的人是第一個
                target->ptr2next->ptr2previous = NULL;
                *ptr2ptr2root = target->ptr2next;
                NextTarget = target->ptr2next;
            }
            else if(target->ptr2next == NULL){ //如果要殺的人是最後一個
                target->ptr2previous->ptr2next = NULL;
                NextTarget = *ptr2ptr2root;
            }
            else{
                target->ptr2previous->ptr2next = target->ptr2next;
                target->ptr2next->ptr2previous = target->ptr2previous;
                NextTarget = target->ptr2next;
            }
            if(target != initial_root)
                free(target);
            
            return NextTarget;
            
        }
        LinkedList* FindPosition(int element, LinkedList* root){

            LinkedList* CurrentNode = root;
            while(CurrentNode->data != element)
                CurrentNode = CurrentNode->ptr2next;
            return CurrentNode;

        }
        void ShowAllNode(LinkedList* root){

            LinkedList* CurrentNode = root;
            printf("[ ");
            while(CurrentNode != NULL){
                printf("%d ", CurrentNode->data);
                CurrentNode = CurrentNode->ptr2next;
            }
            printf("]\n");
                
        }
        void josephus(int N, int P, int K, LinkedList** ptr2ptr2root){

            LinkedList* ptr2target = *ptr2ptr2root;
            for(int i = 0; i < (P - 1); i ++){ //從P開始數
                if(ptr2target->ptr2next == NULL){
                    ptr2target = *ptr2ptr2root;
                    continue;
                }
                ptr2target = ptr2target->ptr2next;
            }
            printf("從%d號(P)開始數%d個人, 初始號碼:", ptr2target->data, K);
            this->ShowAllNode(*ptr2ptr2root);

            int alive = N;
            int cnt = 1;
            while(alive > 1){
                for(int i = 0; i < (K - 1); i ++){ //數K次
                    if(ptr2target->ptr2next == NULL){
                        ptr2target = *ptr2ptr2root;
                        continue;
                    }
                    ptr2target = ptr2target->ptr2next;
                }
                printf("第%d輪%d號被殺掉, ", cnt, ptr2target->data);
                ptr2target = this->DeleteNode(ptr2target, ptr2ptr2root);
                cnt ++;
                alive --;
                printf("下一輪從%d號開始數, 剩餘號碼: ", ptr2target->data);
                this->ShowAllNode(*ptr2ptr2root);
            }

        }

};

int main(void){

    int N, P, K;
    printf("N, P, K = ");
    scanf("%d%d%d", &N, &P, &K);
    printf("N = %d, P = %d, K = %d\n", N, P, K);
    LinkedList root(1);
    LinkedList* ptr2root = &root;
    root.ptr2current = ptr2root; //讓root的成員變數ptr2current從NULL改成指向自己的位置

    //NewNode
    LinkedList* least = ptr2root;
    for(int i = 1; i < N; i ++){
        least = root.NewNode(i + 1, least);
    }

    //josephus
    root.josephus(N, P, K, &ptr2root);
    return 0;

}