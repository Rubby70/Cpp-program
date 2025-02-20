#include <bits/stdc++.h>
using namespace std;


class LinkedList{

    public:
        int value;
        LinkedList* next;

        LinkedList(int value, LinkedList* next = NULL){

            this->value = value;
            this->next = next;

        };
        void ShowAll(LinkedList* root){

            LinkedList* current = root;
            cout << "[ ";
            while(1){
                cout << current->value << " ";
                if(current->next == NULL){
                    break;
                }
                current = current->next;
            }
            cout << "]\n";

        }
        void Search(int target, LinkedList* root, LinkedList** ptr2_TargetPosition, LinkedList** ptr2_PreTargetPosition){
            
            LinkedList* current = root;
            while(current->value != target){
                if(current->next == NULL){
                    break;
                }
                *ptr2_PreTargetPosition = current;
                current = current->next;
            }
            *ptr2_TargetPosition = current;
            
        }
        void Insert(int value, LinkedList* root, int target = -1){

            LinkedList* PreTargetPosition = NULL;
            LinkedList* TargetPosition = NULL;
            this->Search(target, root, &TargetPosition, &PreTargetPosition);
            LinkedList* NewNode = new LinkedList(value);
            NewNode->next = TargetPosition->next;
            TargetPosition->next = NewNode;

        }
        void Delete(int value, LinkedList** ptr2root){

            LinkedList* PreTargetPosition = NULL;
            LinkedList* TargetPosition = NULL;
            this->Search(value, *ptr2root, &TargetPosition, &PreTargetPosition);
            if(TargetPosition == *ptr2root){ //root
                *ptr2root = TargetPosition->next;
            }
            else if(TargetPosition->next == NULL){ //last
                PreTargetPosition->next = NULL;
                free(TargetPosition); 
            }
            else{
                PreTargetPosition->next = PreTargetPosition->next->next;
                free(TargetPosition); 
            }
            
        }

};
class CircularLinkedList{

    public:
        int value;
        CircularLinkedList* next;

        CircularLinkedList(int value, CircularLinkedList* root = NULL, CircularLinkedList* next = NULL){

            this->value = value;
            this->next = next;

        }
        void ShowAll(CircularLinkedList* root){

            CircularLinkedList* current = root;
            cout << "[ ";
            do{
                cout << current->value << " ";
                current = current->next;
            }while(current != root);
            cout << "]\n";

        }
        void Search(int target, CircularLinkedList* root, CircularLinkedList** ptr2_TargetPosition, CircularLinkedList** ptr2_PreTargetPosition = NULL){

            CircularLinkedList* current = root;
            while(current->value != target){
                if(current->next == root){
                    break;
                }
                if(ptr2_PreTargetPosition != NULL){
                    *ptr2_PreTargetPosition = current;
                }
                current = current->next;
            }
            *ptr2_TargetPosition = current;

        }
        void Insert(int value, CircularLinkedList* root, int target = -1){

            CircularLinkedList* TargetPosition = NULL;
            this->Search(target, root, &TargetPosition);
            CircularLinkedList* NewNode = new CircularLinkedList(value, root);
            NewNode->next = TargetPosition->next;
            TargetPosition->next = NewNode;

        }
        void Delete(int value, CircularLinkedList** ptr2root){

            CircularLinkedList* PreTargetPosition = NULL;
            CircularLinkedList* TargetPosition = NULL;
            this->Search(value, *ptr2root, &TargetPosition, &PreTargetPosition);
            if(TargetPosition == *ptr2root){
                *ptr2root = TargetPosition->next;
                PreTargetPosition->next = *ptr2root;
            }
            else if(TargetPosition->next == *ptr2root){
                PreTargetPosition->next = *ptr2root;
                free(TargetPosition);
            }
            else{
                PreTargetPosition->next = TargetPosition->next;
                free(TargetPosition);
            }

        }

};

int main(void){

    cout << "LinkedList\n";
    LinkedList LL(1); //create
    LinkedList* root_LL = &LL;
    LinkedList* current_LL = root_LL; 
    for(int i = 2; i <= 5; i ++){
        current_LL->next = new LinkedList(i);
        current_LL = current_LL->next;
    }
    LL.ShowAll(root_LL); //read
    LL.Insert(9, &LL, 3); //update
    LL.ShowAll(root_LL);
    LL.Delete(9, &root_LL); //delete
    LL.ShowAll(root_LL);

    // cout << "\nQueue\n";
    // CircularLinkedList Q(1); // create
    // CircularLinkedList* root_Q = &Q;
    // CircularLinkedList* current_Q = root_Q;
    // for(int i = 2; i <= 5; i ++){
    //     current_Q->next = new CircularLinkedList(i, root_Q, root_Q);
    //     current_Q = current_Q->next;
    // }
    // Q.ShowAll(root_Q); //read
    // Q.Insert(9, root_Q, 3); //update
    // Q.ShowAll(root_Q);
    // Q.Delete(9, &root_Q); //delete
    // Q.ShowAll(root_Q);
    return 0;

}