#include<bits/stdc++.h>
using namespace std;


class Node{

    public:
        char element;
        Node* next = NULL;
        Node* previous = NULL;

        Node(char data){

            this->element = data;

        }

};
class LinkedList{

    public:
        int length;
        Node* root = NULL;

        LinkedList(){
            this->length = 0;
        }
        bool IsEmpty(){

            return this->length == 0;

        }
        void AddNode(char data, int direction, Node* position = NULL){

            //direction為1表示往右新增節點，為-1表示往左新增節點
            if(this->IsEmpty()){
                //printf("Case 1 (LL is empty)\n");
                root = new Node(data);
            }
            else if(position == NULL){ //不指定位置時，自動新增在最後面
                //printf("Case 2 (不指定位置)\n");
                Node* last = this->SearchLast();
                Node* temp = new Node(data);
                last->next = temp;
                temp->previous = last;
            }
            else if((position == root) && (direction == 1)){ //指定位置，新增在root右邊
                //printf("Case 3 (新增在root右邊)\n");
                Node* temp = new Node(data);
                Node* PreviousNode = root;
                Node* NextNode = NULL;
                if(position->next != NULL){ //若新增在最後面時，不需要NextNode
                    NextNode = position->next;
                }

                PreviousNode->next = temp;
                temp->previous = PreviousNode;

                temp->next = NextNode;
                NextNode->previous = temp;
            }
            else if((position == root) && (direction == -1)){ //指定位置，新增在root左邊
                //printf("Case 4 (新增在root左邊)\n");
                Node* temp = new Node(data);
                Node* NextNode = root;

                temp->next = NextNode;
                NextNode->previous = temp;
                root = temp;
            } 
            else if((position != NULL) && (direction == 1)){ //指定位置，往右新增節點
                //printf("Case 5 (指定位置，往右新增節點)\n");
                Node* temp = new Node(data);
                Node* PreviousNode = position;
                Node* NextNode = NULL;
                if(position->next != NULL){ //若新增在最後面時，不需要NextNode
                    NextNode = position->next;
                }

                PreviousNode->next = temp;
                temp->previous = PreviousNode;

                if(NextNode != NULL){
                    temp->next = NextNode;
                    NextNode->previous = temp;
                }
            }
            else if((position != NULL) && (direction == -1)){ //指定位置，往左新增節點
                //printf("Case 6 (指定位置，往左新增節點)\n");
                Node* temp = new Node(data);
                Node* PreviousNode = position->previous;
                Node* NextNode = position;

                PreviousNode->next = temp;
                temp->previous = PreviousNode;

                temp->next = NextNode;
                NextNode->previous = temp;
            }
            this->length ++;

        }
        void DeleteNode(char target){

            if(this->IsEmpty()){
                printf("LL is empty.\n");
                return ;
            }
            
            Node* position = this->SearchNode(target);
            if(position == NULL){
                printf("Target not found.\n");
                return ;
            }
            else if(position == root){ //若刪除的節點在最前面
                Node* NextNode = position->next;
                NextNode->previous = NULL;
                root = NextNode;
            }
            else if(position->next != NULL){
                Node* PreviousNode = position->previous;
                Node* NextNode = position->next;
                PreviousNode->next = NextNode;
                NextNode->previous = PreviousNode;
            }
            else if(position->next == NULL){ //若刪除的節點在最後面
                Node* PreviousNode = position->previous;
                PreviousNode->next = NULL;
            }
            length --;
            free(position);

        }
        Node* SearchNode(char target){

            if(this->IsEmpty()){
                printf("LL is empty.\n");
                return NULL;
            }
            Node* position = root;
            while(position != NULL){
                if(position->element == target){
                    break;
                }
                position = position->next;
            }

            if(position == NULL){
                return NULL;
            }
            return position;

        }
        Node* SearchLast(){

            if(this->IsEmpty()){
                printf("LL is empty.\n");
                return NULL;
            }
            Node* last = root;
            while(last->next != NULL){
                last = last->next;
            }
            return last;

        }
        void ViewAllNode(){

            Node* current = root;
            printf("[ ");
            while(current != NULL){
                printf("%c ", current->element);
                current = current->next;
            }
            printf("]\n");

        }

};

int main(void){

    LinkedList LL;
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();

    for(int i = 0; i <= 3; i ++){
        char temp = 65 + i;
        LL.AddNode(temp, 1); //不指定位置新增節點
    }
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();

    char target = 'A';
    Node* position = LL.SearchNode(target);
    printf("\n往右新增節點, 新增在%c後面.\n", target);
    LL.AddNode('X', 1, position);
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();
    LL.DeleteNode('X');
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();

    printf("\n往左新增節點, 新增在%c前面.\n", target);
    LL.AddNode('X', -1, position);
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();
    LL.DeleteNode('X');
    printf("length: %d, ", LL.length);
    LL.ViewAllNode();
    return 0;

}