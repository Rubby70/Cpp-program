#include<iostream>
#include<stack>
using namespace std;


class tree{

    private:
    public:
        int data;
        tree* left;
        tree* right;
        tree(int e, tree* left_child = NULL, tree* right_child = NULL){
            data = e;
            left = left_child;
            right = right_child;
        }

};

void inorder_recursive(tree* node){

    if(node != NULL){
        inorder_recursive(node->left);
        cout << node->data << " ";
        inorder_recursive(node->right);
    }

}
void inorder_iterator(tree* node){

    stack<tree*> S;
    while(1){
        while(node != NULL){
            S.push(node);
            node = node->left;
        }
        if(S.empty())
            return ;
        node = S.top();
        S.pop();
        cout << node->data << " ";
        node = node->right;
    }

}
int searchBST(tree* node, int target){

    while(1){
        if(node == NULL){
            cout << "Not found.\n";
            return 0;
        }
        if(target == node->data){
            cout << "Found.\n";
            return 1;
        }
        if(target > node->data){
            node = node->right;
        }
        else{
            node = node->left;
        }
    }

}
void insertBST(tree* node, int target){

    while(node){
        if(target == node->data){
            cout << "This number is already exist.\n";
            return ;
        }
        if(target > node->data){
            if(node->right == NULL){
                node->right = new tree(target);
                return ;
            }
            node = node->right;
        }
        else{
            if(node->left == NULL){
                node->left = new tree(target);
                return ;
            }
            node = node->left;
        }
    }

}
void deleteBST(tree* node, int target){

    tree* current = node;
    tree* parent = NULL;
    while(current){
        if(target > current->data){
            parent = current;
            current = current->right;
        }
        else if(target < current->data){
            parent = current;
            current = current->left;
        }
        else if(target == current->data){
            tree* target2delete = current;
            if(current->left != NULL && current->right != NULL){ //有兩個子樹
                current = current->left;
                if(current->right == NULL){
                    int element = current->data;
                    target2delete->left = NULL;
                    target2delete->data = element;
                    return ;
                }
                tree* previous = NULL;
                while(current->right != NULL){
                    previous = current;
                    current = current->right;
                }
                int element = current->data;
                previous->right = NULL;
                target2delete->data = element;
                return ;
            }
            else if(current->left == NULL && current->right == NULL){ //沒有子樹
                if(parent->left->data == target){
                    parent->left = NULL;
                    return ;
                }
                else{
                    parent->right = NULL;
                    return ;
                }
            }
            else if(current->left != NULL){ //只有左子樹
                if(parent->left == current){
                    parent->left = current->left;
                }
                else if(parent->right == current){
                    parent->right = current->left;
                }
                return ;
            }
            else if(current->right != NULL){ //只有右子樹
                if(parent->left == current){
                    parent->left = current->right;
                }
                else if(parent->right == current){
                    parent->right = current->right;
                }
                return ;
            }
        }
    }
    cout << target << " 不存在這棵二元樹中.\n";

}

int main(void){

    tree BST(8);
    BST.left = new tree(3);
    BST.left->left = new tree(1);
    //BST.left->left->right = new tree(2); //additional
    BST.left->right = new tree(6);
    BST.left->right->left = new tree(4);
    BST.left->right->right = new tree(7);
    BST.right = new tree(10);
    BST.right->right = new tree(14);
    BST.right->right->left = new tree(13);

    // insertBST(&BST, 7);
    // insertBST(&BST, 11);
    // insertBST(&BST, 4);
    // insertBST(&BST, 20);

    cout << "請輸入目標數字: ";
    int target;
    cin >> target;
    // searchBST(&BST, target);
    deleteBST(&BST, target);

    cout << "BST: ";
    inorder_recursive(&BST);
    cout << "\n";
    // inorder_iterator(&BST);
    // cout << "\n";
    return 0;

}