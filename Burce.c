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

void addToCollection(FracCollection *arr, Fraction a);

Fraction addAllFractions(FracCollection fracs);
Fraction subtractAllFractions(FracCollection fracs);
Fraction multiplyAllFractions(FracCollection fracs);
Fraction divideAllFractions(FracCollection fracs);

void displayWholeFraction(Fraction f);
void displayCurrentCollection(FracCollection arr);

int main() {
    FracCollection arr;
    String menu[11] = {"Add", "Subtract", "Multiply", "Divide", "Create/Add to Collection", "Add all in Collection", "Subtract all in Collection", "Multiply all in Collection", "Divide all in Collection","Display Collection", "EXIT"};
    int i;
    int choice;
    Fraction x, y, z, w;
    arr.fracs = (Fraction*)malloc(sizeof(Fraction)*MAX);
    arr.count = 0;
    arr.max = MAX;
    do {
        printf("\n\nFRACTION CALCULATOR\n");
        for(i=0; i<11; ++i) {
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
                printf("Modifying Collection...\n");
                x = inputFraction("Enter fraction");
                addToCollection(&arr, x);
                //y = inputFraction("Enter fraction 2");
                //z = divideFraction(x, y);
                //w = simplyFraction(z);
                break;
            case 6: // add all
                printf("Adding all Fractions in Collection...\n");
                y = addAllFractions(arr);
                w = simplyFraction(y);
                printf("\nSum of all fraction in the collection: ");
                displayWholeFraction(w);
                break;
            case 7: // sub all
                printf("Subtracting all Fractions in Collection...\n");
                y = subtractAllFractions(arr);
                printf("\nDifference of all fraction in the collection: ");
                if(y.den != 0){
                w = simplyFraction(y);
                }else{
                    w = y;
                }
                displayWholeFraction(w);
                break;
            case 8: // mult all
            printf("Multiplying all Fractions in Collection...\n");
                y = multiplyAllFractions(arr);
                if(y.den != 0){
                w = simplyFraction(y);
                }else{
                    w = y;
                }
                printf("\nProduct of all fraction in the collection: ");
                displayWholeFraction(w);
                break;
            case 9: // div all
                printf("Dividing all Fractions in Collection...\n");
                y = divideAllFractions(arr);
                if(y.den != 0){
                w = simplyFraction(y);
                }else{
                    w = y;
                }
                printf("\nQuotient of all fraction in the collection: ");
                displayWholeFraction(w);
                break;
            case 10: // display collection
                displayCurrentCollection(arr);
                break;
            case 11:
                break;
            default:
                printf("Invalid Input");
        }

    } while(choice != 11);
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
        printf("\nDenominator can't be 0!");
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
void displayCurrentCollection(FracCollection arr){
    int i;
    if(arr.count == 0){
        printf("\nCollection is currently Empty..");
    }else{
        printf("\nCollection: { ");
        for(i=0; i<arr.count; i++){
            printf("%d/%d ", arr.fracs[i].num, arr.fracs[i].den);
        }
        printf("}");
    }
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

    result.num = (a.num * b.den) - (a.den * b.num);
    result.den = a.den * b.den; // this doesnt take into account result = 0
    if(result.num == 0){
        result.num = 0;
        result.den = 0;
        result.whole = 0;
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
// helper
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
        // if proper, get gcd
        temp.num = ( temp.num > 0) ? temp.num : -temp.num;
        temp.den = ( temp.den > 0) ? temp.den : -temp.den;
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
        if(arr->fracs == NULL){
            printf("\nError on realloc()");
            return 0;
        }
    }
        arr->fracs[arr->count++] = a;
        printf("Fraction Added to Collection");
        displayCurrentCollection(*arr);

}
// Collection Ops
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
Fraction subtractAllFractions(FracCollection fracs) {
    Fraction result = newFraction(0,1);
    int i;
    if(fracs.count == 0){
        printf("Collection is Empty");
    }
    for(i=0; i<fracs.count; ++i) {
        result = subtractFraction(fracs.fracs[i], result);
    }
    printf("\n\nImproper: %d/%d", result.num, result.den);
    return result;
}
Fraction multiplyAllFractions(FracCollection fracs) {
    Fraction result = newFraction(1,1);
    int i;
    if(fracs.count == 0){
        printf("Collection is Empty");
    }
    for(i=0; i<fracs.count; ++i) {
        result = multiplyFraction(result, fracs.fracs[i]);
    }
    printf("\n\nImproper: %d/%d", result.num, result.den);
    return result;
}
Fraction divideAllFractions(FracCollection fracs) {
    Fraction result = newFraction(1,1);// first fraction gets flipped here, needs to be a value that results the same // kay initial value sa result kay 1/1, then og 
    Fraction temp;
    int i;
    if(fracs.count == 0){
        printf("Collection is Empty");
    }
    for(i=0; i<fracs.count; ++i) {
        result = divideFraction(result, fracs.fracs[i]); 
        if(i==0){ // reciprocal function as result when i=0 inverses the fraction
            temp.num = result.num;
            result.num = result.den;
            result.den = temp.num;
        }
    }
    printf("\n\nImproper: %d/%d", result.num, result.den);
    return result;
}
