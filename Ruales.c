#include <stdio.h>
#include <stdlib.h>

typedef char String[20];

typedef struct {
    int whole;
    int num;
    int den;
} Fraction;

typedef struct node{
    Fraction fracs;
    struct node *next;
}NodeType,*NodePtr;

typedef struct {
    Fraction *fracs;
    int count;
    int max;
} FracCollection; 

Fraction newFraction(int num, int den);
Fraction inputFraction(String msg);

//linked list
void insertFirst(NodePtr *fracptr,Fraction f);

//display
void displayFraction(Fraction f);
void displaySimplified(Fraction f);

Fraction addFraction(Fraction a, Fraction b);
Fraction subtractFraction(Fraction a, Fraction b);
Fraction multiplyFraction(Fraction a, Fraction b);
Fraction divideFraction(Fraction a, Fraction b);

Fraction simplyFraction(Fraction a);

Fraction addAllFractions(FracCollection fracs); 

int main() {
    NodePtr myList = NULL;
    String menu[5] = {"Add", "Subtract", "Multiply", "Divide", "EXIT"};
    int i;
    int choice;
    Fraction x, y, z, w; 

    do {
        printf("\n\nFRACTION CALCULATOR\n");
        for(i=0; i<5; ++i) {
            printf("[%d.] %s\n", i+1, menu[i]);
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Adding two fractions...\n");
                x = inputFraction("Enter fraction 1");
                printf(" + \n");
                y = inputFraction("Enter fraction 2");
                z = addFraction(x, y);
                w = simplyFraction(z);
                printf("\nInitial Fraction Result:");
                displayFraction(z);
                if(z.num<z.den){
                	printf("The Fraction is already in proper form");
				}else{
					displaySimplified(w);
				}
                break;
            case 2:
            	printf("Subtracting two fractions...\n");
                x = inputFraction("Enter fraction 1");
                printf(" - \n");
                y = inputFraction("Enter fraction 2");
                z = subtractFraction(x, y);
                w = simplyFraction(z);
                printf("\nInitial Fraction Result:");
                displayFraction(z);
                if(z.num<z.den){
                	printf("The Fraction is already in proper form");
				}else{
					displaySimplified(w);
				}
                break;
            case 3:
            	printf("Multiplying two fractions...\n");
                x = inputFraction("Enter fraction 1");
                printf(" * \n");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                w = simplyFraction(z);
                printf("\nInitial Fraction Result:");
                displayFraction(z);
                if(z.num<z.den){
                	printf("The Fraction is already in proper form");
				}else{
					displaySimplified(w);
				}
                break;
            case 4:
            	printf("Dividing two fractions...\n");
                x = inputFraction("Enter fraction 1");
                printf(" / \n");
                y = inputFraction("Enter fraction 2");
                z = divideFraction(x, y);
                w = simplyFraction(z);
                printf("\nInitial Fraction Result:");
                displayFraction(z);
                if(z.num<z.den){
                	printf("The Fraction is already in proper form");
				}else{
					displaySimplified(w);
				}// wala sad niya gi display ang simplifyFraction
                break;
            case 5:
                break;
            default:
                printf("Invalid Input");
        }

    } while(choice != 5);

    return 0;
}

Fraction newFraction(int num, int den) {
    Fraction f = {0, num, den};

    return f;
} 

Fraction inputFraction(String msg) {
    Fraction f;

    printf("%s: ", msg);
    scanf("%d/%d", &f.num, &f.den);

    return f;
}

void displayFraction(Fraction f){
	if(f.num==0){
		f.whole = 0;
		printf("%d\n",f.whole);
	}else{
		printf("%d/%d\n",f.num, f.den);
	}
}

void displaySimplified(Fraction f){
	
	printf("\nThe simplified fraction is:");
	if(f.num%f.den==0){
		//displays whole number
		f.whole = f.num/f.den;
		printf("%d",f.whole);
	}else if(f.num!=0 || f.num>f.den || f.num%f.den!=0){
		//displays improper/mixed fraction
		printf("%d %d/%d",f.whole,f.num,f.den);
	}
}


Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;
    
    if(a.den==b.den){
    	result.num = a.num + b.num;
    	result.den = b.den;
	}else{
    	result.num = (a.num * b.den) + (b.num * a.den); 
    	result.den = a.den * b.den;
	}
    
    return result;
}


Fraction subtractFraction(Fraction a, Fraction b) {
    Fraction result;
    if(a.den==b.den){
    	result.num = a.num - b.num;
    	result.den = b.den;
	}else{
    	result.num = (a.num * b.den) - (b.num * a.den); 
    	result.den = a.den * b.den;
	}
    
    return result;
}
 Fraction multiplyFraction(Fraction a, Fraction b){
 	Fraction result;

    result.num = a.num * b.num;
    result.den = a.den * b.den;
    
    return result;
 }

 Fraction divideFraction(Fraction a, Fraction b){
 	Fraction result;

    result.num = a.num * b.den;
    result.den = a.den * b.num;
    
    return result;
 }

Fraction simplyFraction(Fraction a){
	Fraction ret;
	if(a.num%a.den==0){
		ret.whole = a.num/a.den; 
	}else{
		ret.whole = a.num/a.den;
		ret.num = a.num%a.den;
		ret.den = a.den;
	}	
	return ret;	
}

Fraction addAllFractions(FracCollection f) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<f.count; ++i) {
        result = addFraction(result, f.fracs[i]); 
    }

    return result;
}

void insertFirst(NodePtr *fracptr,Fraction f){
    NodePtr temp = (NodePtr)malloc(sizeof(NodeType));

    if(temp != NULL){
        temp->fracs = f;
        temp->next = *fracptr;
        *fracptr = temp;
    }
}

void deleteFirst(NodePtr *fracptr){
    NodePtr temp;
    
    if(*fracptr!=NULL){
        temp = *fracptr;
        *fracptr = temp->next;
        free(temp);
    }
}

void insertLinkedSorted(NodePtr *fracptr, Fraction f){
    NodePtr temp = (NodePtr)malloc(sizeof(NodeType));
    NodePtr trav;


    if(temp != NULL){
        for(trav = *fracptr; trav != NULL && trav->fracs.num >= 8; trav = trav->next){}
        temp->fracs = f;
        temp->next = trav;
        trav = temp;
    }
}

void displayLinked(NodePtr fracptr){
    for(;fracptr!=NULL;fracptr=fracptr->next){
        printf("%d",fracptr->fracs.num,fracptr->fracs.num);
    }
}