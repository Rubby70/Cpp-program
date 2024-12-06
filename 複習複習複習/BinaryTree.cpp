#include <bits/stdc++.h>
using namespace std;


class TreeNode{

    public:
        int value;
        TreeNode* address;
        TreeNode* LeftChild;
        TreeNode* RightChild;
        
        TreeNode(int value, TreeNode* Now = NULL, TreeNode* Left = NULL, TreeNode* Right = NULL){
            
            this->value = value;
            this->address = Now;
            this->LeftChild =Left;
            this->RightChild = Right;

        }

};

class Queue{

    private:
    public:
        int front;
        int rear;
        int capacity;
        TreeNode** arr;

        Queue(int capacity){
            
            this->front = -1;
            this->rear = -1;
            this->capacity = capacity;
            arr = (TreeNode**)malloc(sizeof(TreeNode*) * capacity);
            for(int i = 0; i < capacity; i ++){
                arr[i] = NULL;
            }
            
        }
        TreeNode* Front(){

            if(this->IsEmpty()){
                cout << "Queue is empty.\n";
                return 0;
            }
            return arr[front];

        }
        void Pop(){

            if(front == -1){
                cout << "Queue is empty.\n";
                return ;
            }

            if((front + 1 == capacity)){
                arr[front] = NULL;
                front = 0;
            }
            else if(front == rear){
                arr[front] = NULL;
                front = -1;
                rear = -1;
            }
            else{
                arr[front ++] = NULL;
            }

        }
        void Push(TreeNode* element){

            if((rear + 1) % capacity == front){
                cout << "Queue is full.\n";
                return ;
            }

            if(rear == -1){
                front = 0;
                rear = 0;
                arr[rear] = element;
            }
            else if(rear + 1 == capacity){
                rear = 0;
                arr[rear] = element;
            }
            else{
                arr[++ rear] = element;
            }
            //cout << "front: " << front << ", rear: " << rear << "\n";

        }
        bool IsEmpty(){

            return  front == -1;

        }
        void ShowAll(){

            if(front == -1){
                cout << "Queue is empty.\n";
                return ;
            }

            cout << "Current in Queue: ";
            if(rear >= front){
                cout << "[ ";
                for(int i = front; i <= rear; i ++){
                    cout << arr[i]->value << " ";
                }
                cout << "]\n";
            }
            else if(rear < front){
                cout << "[ ";
                for(int i = front; i < capacity; i ++){
                    cout << arr[i]->value << " ";
                }
                for(int i = 0; i <= rear; i ++){
                    cout << arr[i]->value << " ";
                }
                cout << "]\n";
            }

        }

};

void LevelOrder(TreeNode* root){

    queue<TreeNode*> Q;
    TreeNode* current = root;
    Q.push(current);
    cout << "LevelOrder: [ ";
    while(!Q.empty()){
        current = Q.front();
        Q.pop();
        cout << current->value << " ";
        if(current->LeftChild != NULL){
            Q.push(current->LeftChild);
        }
        if(current->RightChild != NULL){
            Q.push(current->RightChild);
        }
    }
    cout << "]\n";

}
void LevelOrder2(TreeNode* root){

    Queue Q(10);
    TreeNode* current = root;
    Q.Push(current);
    // Q.Push(current->RightChild);
    // Q.Push(current->RightChild->RightChild);
    // Q.Push(current->RightChild->RightChild->RightChild);
    // Q.ShowAll();

    cout << "LevelOrder2: [ ";
    while(!Q.IsEmpty()){
        current = Q.Front();
        Q.Pop();
        cout << current->value << " "; 
        if(current->LeftChild != NULL){
            Q.Push(current->LeftChild);
            //cout << " Push: " << current->LeftChild->value << " ." << "\n";
        }
        if(current->RightChild != NULL){
            Q.Push(current->RightChild);
            //cout << " Push: " << current->RightChild->value << " ." << "\n";
        }
    }
    cout << "]\n";

}

int main(void){

    TreeNode root(1);
    root.address = &root;
    root.LeftChild = new TreeNode(2);
    root.LeftChild->RightChild = new TreeNode(4);
    root.RightChild = new TreeNode(3);
    root.RightChild->LeftChild = new TreeNode(5);
    root.RightChild->RightChild = new TreeNode(6);

    LevelOrder(root.address);//123456
    LevelOrder2(&root);
    return 0;

}