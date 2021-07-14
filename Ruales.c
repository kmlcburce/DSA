#include <stdio.h>

typedef char String[40];

typedef struct{
	int num;
	int denom;
	int wholeNum;
}Fraction;

float addition(int n);
void displayOperations();
void addInput();
void subInput();
void mulInput();
void divInput();
void calculate(int num,int denom);

int main(){
	Fraction f;
    int choice;
    displayOperations();
    printf("%35s","");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    	printf("%40s","ADDITION\n");
    	addInput(f);
    	break;
    	
    	case 2:
    	printf("%40s","SUBTRACTION\n");
    	subInput(f);
    	break;
    	
    	case 3:
    	printf("%42s","MULTIPLICATION\n");
    	mulInput(f);
    	break;
    	
    	case 4:
    	printf("%40s","DIVISION\n");
    	divInput(f);
    	break;
	}
}

void displayOperations(){
	printf("%50s\n","Select one of the Operations");
    printf("%40s  \n","1. Addition");
    printf("%43s  \n","2. Subtraction");
    printf("%46s  \n","3. Multiplication");
    printf("%40s  \n","4. Division");
}


void addInput(Fraction f){
    int a,b,c,d,r,mixnum;
    
    printf("%30s  \n","First Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&a);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&b);
    printf("\n%30s  \n","Second Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&c);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&d);
    if(b==d){
    f.num = a + c;
    f.denom = b;
	}else{
    f.num = a*d + b*c;
    f.denom = b*d;
	}
    printf("%30s %d/%d","Result is:",f.num,f.denom);
    if(f.num%f.denom==0){
    	f.wholeNum = f.num/f.denom;
    	printf("\n%20s %d","The result in whole number is:",f.wholeNum);
	}else{
		f.wholeNum = f.num/f.denom;
		mixnum = f.num%f.denom;
		if(f.wholeNum!=0){
    	printf("\n%30s %d %d/%d","The result in mixed number is:",f.wholeNum,mixnum,f.denom);
	}
	}
}

void subInput(Fraction f){
	
    int a,b,c,d,r,mixnum;
    
    printf("%30s  \n","First Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&a);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&b);
    printf("\n%30s  \n","Second Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&c);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&d);
    if(b==d){
    f.num = a - c;
    f.denom = b;
	}else{
    f.num = a*d - b*c;
    f.denom = b*d;
	}
    printf("%30s %d/%d","Result is:",f.num,f.denom);
    if(f.num%f.denom==0){
    	f.wholeNum = f.num/f.denom;
    	printf("\n%20s %d","The result in whole number is:",f.wholeNum);
	}else{
		f.wholeNum = f.num/f.denom;
		mixnum = f.num%f.denom;
		if(f.wholeNum!=0){
    	printf("\n%30s %d %d/%d","The result in mixed number is:",f.wholeNum,mixnum,f.denom);
	}
	}
}

void mulInput(Fraction f){
	
    int a,b,c,d,r,mixnum;
    
    printf("%30s  \n","First Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&a);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&b);
    printf("\n%30s  \n","Second Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&c);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&d);
    f.num = a*c;
    f.denom = b*d;
    printf("%30s %d/%d","Result is:",f.num,f.denom);
    if(f.num%f.denom==0){
    	f.wholeNum = f.num/f.denom;
    	printf("\n%20s %d","The result in whole number is:",f.wholeNum);
	}else{
		f.wholeNum = f.num/f.denom;
		mixnum = f.num%f.denom;
		if(f.wholeNum!=0){
    	printf("\n%30s %d %d/%d","The result in mixed number is:",f.wholeNum,mixnum,f.denom);
	}
	}
}

void divInput(Fraction f){
	
    int a,b,c,d,r,mixnum;
    
    printf("%30s  \n","First Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&a);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&b);
    printf("\n%30s  \n","Second Fraction\n");
    printf("%30s  ","Enter the first number: ");
    scanf("%d",&c);
    printf("%30s  ","Enter the second number: ");
    scanf("%d",&d);
    
    f.num = a*d;
    f.denom = b*c;
    printf("%30s %d/%d","Result is:",f.num,f.denom);
    if(f.num%f.denom==0){
    	f.wholeNum = f.num/f.denom;
    	printf("\n%20s %d","The result in whole number is:",f.wholeNum);
	}else{
		f.wholeNum = f.num/f.denom;
		mixnum = f.num%f.denom;
		if(f.wholeNum!=0){
    	printf("\n%30s %d %d/%d","The result in mixed number is:",f.wholeNum,mixnum,f.denom);
	}
	}
}