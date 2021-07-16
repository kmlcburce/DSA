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

void checkIfProperFraction(Fraction f);
Fraction simplyFraction(Fraction f);
int getGcd(int a, int b);
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
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = addFraction(x, y);
                w = simplyFraction(z);
                displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf("\n");
                displayFraction(w);
                printf("\n");
                checkIfProperFraction(w);
                break;
                // printf(" = ");
                // displayFraction(w);
                break;
            case 2:
            	printf("Subtracting two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = subtractFraction(x, y);
                w = simplyFraction(z);
                displayFraction(x);
                printf(" - ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf("\n");
                displayFraction(w);
                printf("\n");
                checkIfProperFraction(w);
                break;
            case 3:
            	printf("Multiplying two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                w = simplyFraction(z);
                displayFraction(x);
                printf(" * ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf("\n");
                displayFraction(w);
                printf("\n");
                checkIfProperFraction(w);
                break;
            case 4:
            	printf("Dividing two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = divideFraction(x, y);
                w = simplyFraction(z);
                displayFraction(x);
                printf(" / ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf("\n");
                displayFraction(w);
                printf("\n");
                checkIfProperFraction(w);
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

void displayFraction(Fraction f) {
    printf("%d/%d", f.num, f.den);
}

void checkIfProperFraction(Fraction f){
    printf("checking if fraction is proper...\n");
	if(f.num > f.den){
		if(f.num % f.den == 0){
			f.whole = f.num/f.den;
			printf("Whole number: %d\n", f.whole);
		}else{
			int mod, ans;
			ans = f.num / f.den;
			mod = f.den % f.num;
			printf("Mixed fraction: %d %d/%d\n", ans, mod, f.den);
		}
	}else{
		printf("Proper fraction:");
		displayFraction(f);
	}
}

Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) + (b.num * a.den); 
    
    return result;
}


Fraction subtractFraction(Fraction a, Fraction b){
	Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) - (b.num * a.den); 
    
    return result;
}
Fraction multiplyFraction(Fraction a, Fraction b){
	Fraction result;

    result.den = a.den * b.den;
    result.num = a.num * b.num; 
    
    return result;
}
Fraction divideFraction(Fraction a, Fraction b){
	Fraction result;

    result.den = a.den * b.num;
    result.num = a.num * b.den;
    
    return result;
}

Fraction simplyFraction(Fraction f){
	int gcd;
	gcd = getGcd(f.num, f.den);
	f.num /= gcd;
	f.den /= gcd;
	return f;
	
}

int getGcd(int x, int y){
	if(x%y==0){
		return y;
	}else{
		getGcd(y, x%y);
	}
}

Fraction addAllFractions(FracCollection fracs) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<fracs.count; ++i) {
        result = addFraction(result, fracs.fracs[i]); 
    }

    return result;
}