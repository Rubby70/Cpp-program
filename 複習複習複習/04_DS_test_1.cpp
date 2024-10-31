// 第一題, linked list
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct List list;

struct List {
    int value;
    struct List* next;
};

void showList(list* root){

    printf("[ ");
    while(root){
        printf("%d ", root->value);
        root = root->next;
    }
    printf("]\n");

}
list* insertList(list* root, int val){

    list* root_after_insert = root;
    if(root == NULL){
        root = (list*) malloc(sizeof(list));
        root->value = val;
        root->next = NULL;
        root_after_insert = root;
    }
    else{
        while(root->next != NULL)
            root = root->next;
        root->next = (list*) malloc(sizeof(list));
        root->next->value = val;
        root->next->next = NULL;
    }
    return root_after_insert;

}
list* deleteList(list* root, int val){
    
    list* root_afer_delete = root;
    list* previous = NULL;
    while(root->value != val){ //移動要準備刪除的list
        previous = root;
        root = root->next;
        if(root == NULL){ //若移動到最後一個list都還沒找到
            printf("%d不存在Linked List中\n", val);
            return root_afer_delete;
        }
    }
    printf("%d已被移除\n", val);
    if(previous == NULL){ //如果要刪除的list是第一個
        root_afer_delete = root->next;
        free(root);
        return root_afer_delete;
    }
    else{ //如果要刪除的list不是第一個
        if(root->next == NULL){ //如果要刪除的list是最後一個
            previous->next = NULL;
        }
        previous->next = root->next;
        free(root);
        return root_afer_delete;
    }

}
list* reverseList(list* root){
    
    list* least_list_after_reverse = root;
    
    list* previous_list = root;
    if(root->next == NULL){ //若LL中只有一個list
        return root;
    }
    list* current_list = root->next;
    if(root->next->next == NULL){ //若LL中只有兩個list
        current_list->next = previous_list;
        least_list_after_reverse->next = NULL; //新的盡頭
        return current_list; //新的root
    }

    list* next_list = root->next->next;
    
    do{ //若LL中有2個以上的list
        current_list->next = previous_list;
        previous_list = current_list;
        current_list = next_list;
        if(next_list->next == NULL){
            current_list->next = previous_list;
            break;
        }
        next_list = next_list->next;
    }while(1);
    
    least_list_after_reverse->next = NULL; //新的盡頭
    list* root_after_reverse = current_list; //新的root
    return root_after_reverse;

}

int main(void){

    srand(time(0));
    list* root = NULL;
    for (int i = 0; i < 10; i++){
        int val = rand() % 20;
        printf("inserting %d\n", val);
        root = insertList(root, val);
    }
    showList(root);

    // deleteList(root, 12);
    // showList(root);

    root = reverseList(root);
    showList(root);
    return 0;

}