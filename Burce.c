#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef char String[100];

typedef struct {
    int whole;
    int num;
    int den;
} Fraction;

typedef struct node{
    Fraction f;
    struct node *next;
}Node, *NodePtr;

// Init
void initList(NodePtr* list, Fraction a);
// Insert
void insertFirst(NodePtr* list, Fraction x);
void insertLast(NodePtr* list, Fraction a);
// Delete
void deleteNode(NodePtr* list, Fraction a);
void deleteFirst(NodePtr* list);
void deleteLast(NodePtr* list);
// Display
void displayList(NodePtr* list);
int main() {
    NodePtr list = NULL;
    Fraction x = {0,1,2};
    Fraction y = {0,3,4};
    initList(&list, x);
    insertLast(&list, y);
    deleteLast(&list);
    displayList(&list);
    free(list);
    return 0;
}
// Init
void initList(NodePtr* list, Fraction a){
    (*list)= (NodePtr)malloc(sizeof(Node));
    (*list)->f = a;
    (*list)->next = NULL;
}
// Helper
// // Ops
void addAll(NodePtr* list){
    NodePtr temp;
}
// // List
void insertFirst(NodePtr* list, Fraction x){
    NodePtr temp;
    initList(&temp, x);
    temp->f = x;
    temp->next = *list;
    *list = temp;

}
void insertLast(NodePtr* list, Fraction a){
    NodePtr temp, newNode;
    initList(&newNode, a);
    newNode->next = NULL;
    for(temp = (*list); temp->next!=NULL; temp = temp->next){
    }
    temp->next = newNode;

}

void deleteFirst(NodePtr* list){
    NodePtr temp;
    temp = (*list);
    (*list) = (*list)->next;
    free(temp);
}
void deleteLast(NodePtr* list){
    NodePtr temp, holder;
    for(temp = (*list);temp->next->next = NULL; temp = temp->next){
    }
    holder = temp->next;
    temp->next = NULL;
    *list = temp;
    free(holder);
}
void deleteNode(NodePtr* list, Fraction a){
    NodePtr temp, holder;
    for(temp = (*list); temp!=NULL; temp = temp->next){
        if(temp->f.den == a.den && temp->f.num == a.num){ // assuming the function hasn't been simplified yet
            holder = temp;
            temp = temp->next;
            free(holder);
        }
    }
    *list = temp;
}
void displayList(NodePtr* list){
    NodePtr temp;
    for(temp = (*list); temp!=NULL; temp = temp->next){
        printf("(%d)%d/%d -> ", temp->f.whole,temp->f.num, temp->f.den);
    }
}
