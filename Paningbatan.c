#include<stdio.h>

typedef struct {
    int numerator;
    int denominator;
    int wholeNo;
} Frac;

void properFrac(int numer, int denom);
void GCD(int numer, int denom);

void addition(int a, int b, int c, int d);
void subtraction(int a, int b, int c, int d);
void multiplication(int a, int b, int c, int d);
void division(int a, int b, int c, int d);

int main() {
    int x1, x2, y1, y2,op;
    char choice;

    printf("Enter first value x1 and y1 (x1/y1):\n");
    scanf("%d%d", &x1, &y1);
    printf("Enter second value x2 and y2 (x2/y2):\n");
    scanf("%d%d", &x2, &y2);

    do{
        printf("\nEnter an operator:");
        printf("\n\t1: Addition\n\t2: Subtraction\n\t3: Multiplication\n\t4: Division");
        printf("\nChoice: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                addition(x1,y1,x2,y2);
                break;
            case 2:
                subtraction(x1,y1,x2,y2);
                break;
            case 3:
                multiplication(x1,y1,x2,y2);
                break;
            case 4:
                division(x1,y1,x2,y2);
                break;
            default:
                printf("Chosen operator is not one of the choices");
        }

        fflush(stdin);
        printf("\n\nDo you want another operator? (y-yes/n-no):");
        scanf("%c", &choice);
    } while(choice == 'y');
}

void GCD(int numer, int denom) {
    int GCD;
    
    if (numer < denom) {
        GCD = numer;
    }else {
        GCD = denom;
    }
    while (GCD > 1) {
        if (numer % GCD == 0 && denom % GCD == 0) {
            break;
            GCD--;
        }
    }
    printf("Result is %d/%d", numer/GCD, denom/GCD);
}
void properFrac(int numer, int denom) {
   	int wholeNo;
    
  	if (numer < denom) {
       GCD(numer,denom);
  	}else if (numer%denom == 0) {
       wholeNo = numer/denom;
       printf("Result is %d", wholeNo);
   	}else {
       wholeNo = numer/denom;
       numer = numer%denom;
       printf("Result is %d %d/%d", wholeNo, numer, denom);
   	}
}

void addition(int a, int b, int c, int d) {
    Frac x;
    int num1, num2;
    
    x.denominator = b*d;
    num1 = x.denominator/b * a;
    num2 = x.denominator/d * c;
    x.numerator = num1 + num2;

    properFrac(x.numerator, x.denominator);

}

void subtraction(int a, int b, int c, int d) {
    Frac x;
    int num1, num2;
    
    x.denominator = b*d;
    num1 = x.denominator/b * a;
    num2 = x.denominator/d * c;
    x.numerator = num1 - num2;

    properFrac(x.numerator, x.denominator);
}

void multiplication(int a, int b, int c, int d) {
    Frac x;
    
    x.numerator = a*c;
    x.denominator = b*d;
    
    properFrac(x.numerator, x.denominator);
}

void division(int a, int b, int c, int d) {
    Frac x;
    
    x.numerator = a*d;
    x.denominator = b*c;
    
    properFrac(x.numerator, x.denominator);
}