#include <iostream>
using namespace std;


class treeNode{

    friend class tree;
    private:
        char data;
        treeNode* leftchild;
        treeNode* rightchild;
    public:
        treeNode(char input, treeNode* left = NULL, treeNode* right = NULL){
            data = input;
            leftchild = left;
            rightchild = right;
        }

};

class tree{

    private:
        treeNode* root;
    public:
        tree(treeNode* rootposition = NULL){
            root = rootposition;
        }
        void createNode(char data, treeNode* left = NULL, treeNode* right = NULL){
            
        }
        void deleteNode(){}
        
};

class tree{

    private:
        tree* root = NULL;
        char data;
        tree* left_child;
        tree* right_child;
    public:
        tree(char input, tree* left = NULL, tree* right = NULL){
            data = input;
            left_child = left;
            right_child = right;
        }
        void set_root(tree* position){
            root = position;
        }

};

int main(void){

    return 0;

}