#include <stdio.h>

typedef char String[20];

typedef struct {
    int whole;
    int num;
    int den;
} Fraction;

typedef struct {
    Fraction *fracs;
    int count;
    int max;
} FracCollection;

Fraction newFraction(int num, int den);
Fraction inputFraction(String msg);

void displayFraction(Fraction f);

Fraction addFraction(Fraction a, Fraction b);
Fraction subtractFraction(Fraction a, Fraction b);
Fraction multiplyFraction(Fraction a, Fraction b);
Fraction divideFraction(Fraction a, Fraction b);

Fraction simplyFraction(Fraction f);
int fracGCD(Fraction a, Fraction b);
Fraction addAllFractions(FracCollection fracs); 

int main() {
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
                x = inputFraction("Enter fraction 1: ");
                y = inputFraction("Enter fraction 2: ");
                z = addFraction(x, y);
               	// w = simplify(z);
                displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                // printf(" = ");
                // displayFraction(w);
                break;
            case 2:
            	printf("Subtracting two fractions..\n");
            	x = inputFraction("Enter fraction 1: ");
            	y = inputFraction("Enter fraction 2: ");
            	z = subtractFraction(x, y);
            	displayFraction(x);
            	printf("-");
            	displayFraction(y);
                printf(" = ");
                displayFraction(z);
                break;
            case 3:
            	printf("Multiplying two fractions..\n");
            	x = inputFraction("Enter fraction 1: ");
            	y = inputFraction("Enter fraction 2: ");
            	z = multiplyFraction(x, y);
            	displayFraction(x);
            	printf("x");
            	displayFraction(y);
                printf(" = ");
                displayFraction(z);
                break;
            case 4:
            	printf("Dividing two fractions..\n");
            	x = inputFraction("Enter fraction 1: ");
            	y = inputFraction("Enter fraction 2: ");
            	z = divideFraction(x, y);
            	displayFraction(x);
            	printf("/");
            	displayFraction(y);
                printf(" = ");
                displayFraction(z);
                break;
            case 5:
            	printf("Thank you!!!");
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

void displayFraction(Fraction f) {
    printf("%d/%d", f.num, f.den);
}

Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) + (b.num * a.den); 
    
    return result;
}

Fraction subtractFraction(Fraction a, Fraction b) {
    Fraction result;

    result.num = (a.num * b.den) - (b.num * a.num);
    result.den = a.den*b.den; 
    
    return result;
}

Fraction multiplyFraction(Fraction a, Fraction b)
{
	Fraction result;

    result.num = a.num*b.num;
    result.den = a.den*b.den; 
    
    return result;
}

Fraction divideFraction(Fraction a, Fraction b)
{
	Fraction result;

    result.num = a.num*b.den;
    result.den = a.den*b.num; 
    
    return result;
}

Fraction simplify(Fraction a, Fraction b)
{
	Fraction ret;
	int temp = fracGCD(a, b); // ????
	ret.num = ret.num/temp; // ???
	ret.den = ret.den/temp; // ???
	
	return ret;	
}

int fracGCD(Fraction a, Fraction b)
{
	int gcd,i;
	for(i=1;i<=a.den&&i<=b.den;i++){
		if(a.den%i==0&&b.den%i){
			gcd=i;
		}
		return gcd;
	}
}
//murag kuan na swa ang numerator og denom kuhaon ang gcd

// Fraction subtractFraction(Fraction a, Fraction b);
// Fraction multiplyFraction(Fraction a, Fraction b);
// Fraction divideFraction(Fraction a, Fraction b);

// Fraction simplyFraction(Fraction f);

Fraction addAllFractions(FracCollection fracs) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<fracs.count; ++i) {
        result = addFraction(result, fracs.fracs[i]); 
    }

    return result;
}



