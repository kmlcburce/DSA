#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeType, *NodePtr;


void insertFront(NodePtr *list, int data) {
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        temp->data = data;
        temp->next = *list;
        *list = temp; //ah *list refers to mylist in main then mylist gets whichever gi point ni temp?
    }
}
//
// 
NodePtr insertFront2(NodePtr list, int data) {
    NodePtr temp = (NodePtr) malloc(sizeof(NodeType));

    if(temp != NULL) {
        temp->data = data;
        temp->next = list;
        list = temp; 
    }

    return list;
}

void display(NodePtr list) {
    for(; list != NULL; list = list->next) {
        printf("%d ", list->data);
    }
}

void display(NodePtr list) {
    NodePtr trav;
    for(trav = list; trav != NULL; trav = trav->next) {
        printf("%d ", trav->data);
    }
}// so bale kuhaon ni trav ang gi point ni trav->next?

void display(NodePtr list) {
    NodePtr *trav;
    for(trav = &list; *trav != NULL; trav = &(*trav)->next) {
        printf("%d ", (*trav)->data);
    }
}


void display(NodePtr list) {
    for(; list != NULL; list = list->next) {
        if(strcmp(list.data.name.lname, "something") == 0)
        printf("%d ", list->data);
    }
}

void display(NodePtr list) {
    NodePtr *trav;
    for(trav = &list; *trav != NULL; trav = &(*trav)->next) {
        if(strcmp((*trav)->data.name.lname, "something") == 0) 
        if(strcmp((**trav).data.name.lname, "something") == 0)
        printf("%d ", (*trav)->data);
    }
}

int main() {
    NodePtr myList = NULL;

    insertFront(&myList, 10);
    insertFront(&myList, 23);

    myList = insertFront2(myList, 50);


    return 0;
}

    