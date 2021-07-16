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

void GCD(Fraction f);
Fraction addFraction(Fraction a, Fraction b);
Fraction subtractFraction(Fraction a, Fraction b);
Fraction multiplyFraction(Fraction a, Fraction b);
Fraction divideFraction(Fraction a, Fraction b);

void simplyFraction(Fraction f);

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
                //w = simplyFraction(z);
                displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                //displayFraction(w);
                simplyFraction(z);
                break;
            case 2:
            	printf("Subtracting two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = subtractFraction(x, y);
                //w = simplyFraction(z);
                displayFraction(x);
                printf(" - ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                //displayFraction(w);
                simplyFraction(z);
                break;
            case 3:
            	printf("Multiplying two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                //w = simplyFraction(z);
                displayFraction(x);
                printf(" x ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                //displayFraction(w);
                simplyFraction(z);
                break;
            case 4:
            	printf("Dividing two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = divideFraction(x, y);
                //w = simplyFraction(z);
                displayFraction(x);
                printf(" / ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                //displayFraction(w);
                simplyFraction(z);
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

Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) + (b.num * a.den); 
    
    return result;
}

Fraction subtractFraction(Fraction a, Fraction b) {
	Fraction result;
	
	result.den = a.den * b.den;
	result.num = (a.num * b.den) - (b.num * a.den);
	
	return result;
}
Fraction multiplyFraction(Fraction a, Fraction b) {
	Fraction result;
	
	result.den = a.den * b.den;
	result.num = a.num * b.num;
	
	return result;
}
Fraction divideFraction(Fraction a, Fraction b) {
	Fraction result;
	
	result.den = a.den * b.num; 
	result.num = a.num * b.den;
	
	return result;
}

void simplyFraction(Fraction f) {

  	if (f.num < f.den) {
   		GCD(f);
  	}else if (f.num%f.den == 0) {
       f.whole = f.num/f.den;
       printf("%d", f.whole);
   	}else {
       f.whole = f.num/f.den;
       f.num = f.num%f.den;
       printf("%d %d/%d", f.whole, f.num, f.den);
   	}
//	return f;
}

void GCD(Fraction f){
	int GCD;
	
	if(f.num < f.den) {
        GCD = f.num;
  	}else {
        GCD = f.den;
    }
    while (GCD > 1) {
        if (f.num % GCD == 0 && f.den % GCD == 0) {
            break;
            GCD--;
        }
   	}
   	printf("%d/%d", f.num / GCD, f.den / GCD);
//   f.num = f.num/GCD;
//   f.den = f.den/GCD;
//    
//   return f;
}
Fraction addAllFractions(FracCollection f) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<f.count; ++i) {
        result = addFraction(result, f.fracs[i]); 
    }

    return result;
}
