#include <iostream>
using namespace std;


class tree{

    private:
    public:
        int data;
        tree* left_child;
        tree* right_child;

        tree(int input, tree* left = NULL, tree* right = NULL){
            data = input;
            left_child = left;
            right_child = right;
        };
        void inorder_recursive(tree* current){
            
            if(current->left_child != NULL){
                inorder_recursive(current->left_child);
            }
            cout << current->data << " ";
            if(current->left_child != NULL){
                inorder_recursive(current->right_child);
            }

        }
        void inorder_iterator(){}

};

int main(void){

    tree BST(8);
    BST.left_child = new tree(3);
    BST.right_child = new tree(10);
    BST.left_child->left_child = new tree(1);
    BST.left_child->right_child = new tree(6);
    BST.left_child->right_child->left_child = new tree(4);
    BST.left_child->right_child->right_child = new tree(7);
    BST.right_child->right_child = new tree(14);
    BST.right_child->right_child->left_child = new tree(13);

    cout << "[ ";
    BST.inorder_recursive(&BST);
    cout << "]" << "\n";
    return 0;

}