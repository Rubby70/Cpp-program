#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class treeNode{

    public:
        char data;
        treeNode* leftchild;
        treeNode* rightchild;
        treeNode(char input){
            data = input;
            leftchild = NULL;
            rightchild = NULL;
        }

};

void inorder_recursive(treeNode* Node){

    if(Node != NULL){
        inorder_recursive(Node->leftchild);
        cout << Node->data << " ";
        inorder_recursive(Node->rightchild);
    }
    
}
void preorder_recursive(treeNode* Node){

    if(Node != NULL){
        cout << Node->data << " ";
        preorder_recursive(Node->leftchild);
        preorder_recursive(Node->rightchild);
    }
    
}
void postorder_recursive(treeNode* Node){

    if(Node != NULL){
        postorder_recursive(Node->leftchild);
        postorder_recursive(Node->rightchild);
        cout << Node->data << " ";
    }

}
void inorder_iterator(treeNode* Node){

    stack<treeNode*> S;
    treeNode* currentNode = Node;
    while(1){
        while(currentNode){
            S.push(currentNode);
            currentNode = currentNode->leftchild;
        }
        if(S.empty())
            return;
        currentNode = S.top();
        S.pop();
        cout << currentNode->data << " ";
        currentNode = currentNode->rightchild;

    }

}
void levelorder_iterator(treeNode* Node){

    queue<treeNode*> Q;
    treeNode* currentNode = Node;
    while(currentNode){
        cout << currentNode->data << " ";
        if(currentNode->leftchild){
            Q.push(currentNode->leftchild);
        }
        if(currentNode->rightchild){
            Q.push(currentNode->rightchild);
        }
        currentNode = Q.front();
        Q.pop();
    }

}

int main(void){

    treeNode T('A');
    T.leftchild = new treeNode('B');
    T.rightchild = new treeNode('C');
    T.leftchild->leftchild = new treeNode('D');
    T.leftchild->rightchild = new treeNode('E');
    T.rightchild->leftchild = new treeNode('F');
    T.rightchild->rightchild = new treeNode('G');

    // inorder_recursive(&T);
    // cout << "\n";
    // preorder_recursive(&T);
    // cout << "\n";
    // postorder_recursive(&T);
    // cout << "\n";
    // inorder_iterator(&T);
    // cout << "\n";
    // levelorder_iterator(&T);
    // cout << "\n";
    return 0;

}