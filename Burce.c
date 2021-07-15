#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef char String[100];

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

Fraction addAllFractions(FracCollection fracs);

int main() {
    FracCollection arr;
    String menu[10] = {"Add", "Subtract", "Multiply", "Divide", "Create Collection", "Add all in Collection", "Subtract all in Collection", "Multiply all in Collection", "Divide all in Collection", "EXIT"};
    int i;
    int choice;
    Fraction x, y, z, w;
    arr.fracs = (FracCollection*)malloc(sizeof(FracCollection)*MAX);
    arr.count = 0;
    arr.max = MAX;
    do {
        printf("\n\nFRACTION CALCULATOR\n");
        for(i=0; i<10; ++i) {
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
                printf(" = ");
                displayWholeFraction(w);
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
                printf(" = ");
                displayWholeFraction(w);
                break;
            case 3:
                printf("Multiplying two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                w = simplyFraction(z);
                displayFraction(x);
                printf(" x ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                displayWholeFraction(w);
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
                printf(" = ");
                displayWholeFraction(w);
                break;
            case 5: // create collection
                printf("Creating Collection...\n");
                x = inputFraction("Enter fraction");
                addToCollection(&arr, x);
                //y = inputFraction("Enter fraction 2");
                //z = divideFraction(x, y);
                //w = simplyFraction(z);
                break;
            case 6: // add all
                printf("Adding all Fractions in Collection...\n");
                addAllFractions(arr);
                break;
            case 7: // sub all
                break;
            case 8: // mult all
                break;
            case 9: // div all
                break;
            case 10:
                break;
            default:
                printf("Invalid Input");
        }

    } while(choice != 10);





    return 0;
}
// Init
Fraction newFraction(int num, int den) {
    Fraction f = {0, num, den};

    return f;
}

Fraction inputFraction(String msg) {
    Fraction f;

    printf("%s: ", msg);
    scanf("%d/%d", &f.num, &f.den);
    if(f.den == 0){
        printf("Denominator can't be 0!");
    }
    return f;
}
// Display
void displayFraction(Fraction f) {
    printf("%d/%d", f.num, f.den);
}
void displayWholeFraction(Fraction f) {
    printf("(%d)%d/%d", f.whole, f.num, f.den);
}
// Ops
Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) + (b.num * a.den);

    return result;
}
Fraction subtractFraction(Fraction a, Fraction b){
    Fraction result;

    result.num = (a.num * b.den) - (b.num * a.den);
    result.den = a.den * b.den;
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

Fraction simplyFraction(Fraction f){
    Fraction temp = f;
    if(f.num>f.den){
        // If improper
        f.whole = f.num / f.den;
        f.num = f.num - (f.den * f.whole);
    }else if(f.num/f.den == 1){
        f.whole = f.num / f.den;
        f.den = 0;
        f.num = 0;
    }else{
        // if proper get gcd
        while (temp.num!=temp.den)
        {
            if(temp.num>temp.den){
                temp.num -= temp.den;
            }else {
                temp.den -= temp.num;
            }
        }
        f.num = f.num / temp.num;
        f.den = f.den / temp.num;
        f.whole = 0;
    }
    return f;
}
// Collection
void addToCollection(FracCollection *arr, Fraction a){
    int i;
    if(arr->count>= arr->max){
        arr->max *= 2;
        arr->fracs = realloc(arr->fracs, sizeof(Fraction)*arr->max);
    }
        for(i=arr->count; i>0;i--){
            arr->fracs[i] = arr->fracs[i-1];
        }
        arr->fracs[0] = a;
        arr->count++;
        printf("Fraction Added to Collection");
}
Fraction addAllFractions(FracCollection fracs) {
    Fraction result = newFraction(0,1);
    int i;
    if(fracs.count == 0){
        printf("Collection is Empty");
    }
    for(i=0; i<fracs.count; ++i) {
        result = addFraction(result, fracs.fracs[i]);
    }

    return result;
}



