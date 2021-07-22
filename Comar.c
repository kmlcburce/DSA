#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

typedef char String[20];

typedef struct n{
    int whole;
    int num;
    int den;
}Fraction;

typedef struct node{
	Fraction f;
	struct node* next;
}*List;

void initList(List* L);
Fraction initFraction(int a, int b);
void insertFirst(List* L, Fraction newData);
void insertLast(List* L, Fraction newData);
void insertSorted(List* L, Fraction newData);
void deleteList(List* L, Fraction newData);

void displayFraction(Fraction f);
void displayList(List L);

int main(){
	List L;
	Fraction frac;
	
	initList(&L);
	
	frac = initFraction(1, 2);
	insertFirst(&L, frac);
	
	frac = initFraction(3, 4);
	insertFirst(&L, frac);
	
	frac = initFraction(2, 3);
	insertFirst(&L, frac);
	
	displayList(L);
	
	return 0;
	
}

void initList(List* L){
	*L = NULL;
}

Fraction initFraction(int a, int b){
	Fraction t;
	
	t.num = a;
	t.den = b;
	t.whole = t.num/t.den;
	
	return t;
}

void insertFirst(List* L, Fraction newData){
	List temp;
	
	temp = (List)malloc(sizeof(struct node));
	if(temp!=NULL){
		temp->f = newData;
		temp->next = *L;
		*L = temp;
	}
}

//
void insertLast(List* L, Fraction newData)
{
	List temp, *trav;
	
	temp = (List)malloc(sizeof(struct node));
	
	if(temp != NULL){
		for(trav = L; *trav != NULL; trav = &(*trav)->next){}
		temp->f = newData;
		temp->next = *trav;
		*trav = temp;
	}
		
}

void insertSorted(List* L, Fraction newData)
{
	List temp, *trav;
	
	temp = (List)malloc(sizeof(struct node));
	
	if(temp != NULL){
		for(trav = L; *trav != NULL && (*trav)->f.whole < newData.whole; trav = &(*trav)->next){}
		temp->f = newData;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteList(List* L, Fraction newData)
{
	List temp, *trav;
	
	for(trav = L; *trav != NULL && (*trav)->f.whole != newData.whole; trav = &(*trav)->next){}
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

void displayFraction(Fraction f){
	printf("%d/%d", f.num, f.den);
}

void displayList(List L){
	for(; L != NULL; L = L->next) {
        printf("%d/%d -> ", L->f.num, L->f.den);
    }
}
