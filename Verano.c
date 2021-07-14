#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct{
	int numerator;
	int denominator;
	int wholeNum;
}fraction;

void calculatorMenu();
void addition(fraction a, fraction b);
void subtraction(fraction a, fraction b);
void multiplication(fraction a, fraction b);
void division(fraction a, fraction b);
void convertImproper(fraction a);

int main()
{
	calculatorMenu();
	
	
	return 0;	
}

void calculatorMenu(){
	char operation;
	fraction x,y;
	printf("-OPERATION MENU-\n A.) Addition\n B.) Subtraction\n C.) Multiplication\n D.) Division\n E.) ConvertImproper\n");
	printf("Enter Operation: ");
	scanf("%c", &operation);
	printf("---------------------\n\n");
	switch(operation){
		case 'A':
		case 'a':	
			printf("--Addition--\n\n");
			addition(x,y);
			break;
		case 'B':
		case 'b':
			printf("--Subtraction--\n\n");	
			subtraction(x,y);
			break;
		case 'C':
		case 'c':	
			printf("--Multiplication--\n\n");
			multiplication(x,y);
			break;		
		case 'D':
		case 'd':	
			printf("--Division--\n\n");
			division(x,y);
			break;
		case 'E':
		case 'e':
			printf("--Convert Improper Fraction--\n\n");
			convertImproper(x);
			break;	
			
	}
	

}

void addition(fraction a, fraction b)
{
    fraction c;
	printf("Enter first numerator:\n ");
	scanf("%d", &a.numerator);
	printf("Enter first denominator:\n ");
	scanf("%d", &a.denominator);
	printf("Enter second numerator:\n ");
	scanf("%d", &b.numerator);
	printf("Enter second denominator:\n ");
	scanf("%d", &b.denominator);
	if(a.denominator == 0 || b.denominator == 0){
		printf("Syntax Error Denominator should not be 0!!!");
	}else{
	c.numerator = (a.numerator*b.denominator) + (b.numerator*a.denominator);
	c.denominator = a.denominator*b.denominator;
	printf("The answer is: %d/%d", c.numerator, c.denominator);
	}	
}

void subtraction(fraction a, fraction b)
{
    fraction c;
	printf("Enter first numerator:\n ");
	scanf("%d", &a.numerator);
	printf("Enter first denominator:\n ");
	scanf("%d", &a.denominator);
	printf("Enter second numerator:\n ");
	scanf("%d", &b.numerator);
	printf("Enter second denominator:\n ");
	scanf("%d", &b.denominator);
	if(a.denominator == 0 || b.denominator == 0){
		printf("Syntax Error Denominator should not be 0!!!");
	}else{
	c.numerator = (a.numerator*b.denominator) - (b.numerator*a.denominator);
	c.denominator = a.denominator*b.denominator;
	printf("The answer is: %d/%d", c.numerator, c.denominator);
	}
}

void multiplication(fraction a, fraction b)
{
    fraction c;
	printf("Enter first numerator:\n ");
	scanf("%d", &a.numerator);
	printf("Enter first denominator:\n ");
	scanf("%d", &a.denominator);
	printf("Enter second numerator:\n ");
	scanf("%d", &b.numerator);
	printf("Enter second denominator:\n ");
	scanf("%d", &b.denominator);
	if(a.denominator == 0 || b.denominator == 0){
		printf("Syntax Error Denominator should not be 0!!!");
	}else{
	c.numerator = a.numerator*b.numerator;
	c.denominator = a.denominator*b.denominator;
	printf("The answer is: %d/%d", c.numerator, c.denominator);
	}
}

void division(fraction a, fraction b)
{
    fraction c;
	printf("Enter first numerator:\n ");
	scanf("%d", &a.numerator);
	printf("Enter first denominator:\n ");
	scanf("%d", &a.denominator);
	printf("Enter second numerator:\n ");
	scanf("%d", &b.numerator);
	printf("Enter second denominator:\n ");
	scanf("%d", &b.denominator);
	if(a.denominator == 0 || b.denominator == 0){
		printf("Syntax Error Denominator should not be 0!!!");
	}else{
	c.numerator = a.numerator*b.denominator;
	c.denominator = a.denominator*b.numerator;
	printf("The answer is: %d/%d", c.numerator, c.denominator);
	}
}

void convertImproper(fraction a)
{
	printf("Enter first numerator:\n ");
	scanf("%d", &a.numerator);
	printf("Enter first denominator:\n ");
	scanf("%d", &a.denominator);
	if(a.numerator<a.denominator){
		printf("Entered fraction is not an improper fraction!!!");
	}else if(a.numerator % a.denominator == 0){
		a.wholeNum = a.numerator / a.denominator;
		printf("the answer is: %d", a.wholeNum);
	}else{
		a.wholeNum = a.numerator / a.denominator;
		a.numerator = a.numerator%a.denominator;
		printf("The answer is: %d %d/%d\n", a.wholeNum, a.numerator, a.denominator); 
	}
			
}

