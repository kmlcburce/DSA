#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5
#define true 1;
#define false 0;
typedef struct {
    int numerator;
    int denominator;
    int wholeNum;
}Number;
typedef struct {
    Number *fract;
    int count;
    int max;
}FractCollection;

Number add(Number x, Number y);
Number sub(Number x, Number y);
Number mult(Number x, Number y);
Number div(Number x, Number y);
void createFraction(int numerator, int denominator);
void fractCalMenu(Number x, Number y);
void displayProper(Number z);
void displayImproper()

int main(){
    FractCollection arr;
    initializeCollection(&arr);
    printf("Fraction Calculator");
    createFraction(&arr,1,2);
    createFraction(&arr,1,4);
    fractCalMenu(&arr);
}
// Helpers
void initializeCollection(FractCollection *arr){
    arr->count = 0;
    arr->max = MAX;
}
Number checkIfProper(Number a){
    if(a.numerator%a.denominator == 0){ // if wholenumber
        a.numerator = 0;
        a.denominator = 0;
        a.wholeNum = a.numerator / a.denominator;
    }else if(a.numerator < a.denominator){// if proper fraction
        a = simplify(a);
    }else if(a.numerator > a.denominator){ // if improper
        a.wholeNum = a.numerator / a.denominator;
        a.numerator = a.numerator - (a.wholeNum * a.denominator);
    }
    return a;
}
Number simplify(Number x){
    int gcd = x.denominator % x.numerator;
    x.numerator = x.numerator / gcd;
    x.denominator = x.denominator / gcd;
}
// Collection Ops
void createFraction(FractCollection *arr, int n, int d){
    int i;
    Number fract;
    fract.numerator = n;
    fract.denominator = d;
    fract.wholeNum = 0;
    fract = checkIfProper(fract);
    if(arr->count>=arr->max){
        arr->max *=2;
        arr->fract = realloc(arr->fract, sizeof(Number)*arr->max);
        if(arr->fract == NULL){
            printf("Error on realloc()");
        }
    }
        insertFirst(&arr, fract);   
    
}
void insertFirst(FractCollection *arr, Number a){
    int i;
    if((arr->count) < (arr->max)){
        for(i=arr->count;i>0;i--){
            arr->fract[i] = arr->fract[i-1];
        }
        arr->fract[0] = a;
        arr->count++;
        return true;
    }
    return false;
}
// Menus
void fractCalMenu(FractCollection *arr){
    int choice;
    Number z;
    printf("\nChoose Operation Type: ");
    printf("\n1. Add all fraction in collection\n2. Subtract all fraction in collection\n3. Multiply all fraction in collection\n4. Divide all fraction in collection");
    printf("\n5. Find Fraction")
    printf("\nInput Choice:");
    scanf("%d", &choice);
    switch(choice){
        case 1: addAll(&arr) break;
        case 2: subAll(&arr) break;
        case 3: multAll(&arr) break;
        case 4: divAll(&arr) break;
    }
    display(z);
    
}
// Math Operations

void addAll(FractCollection *arr){
    FractCollection temp;
    initializeCollection(&temp);
    int i;
    if(arr->count == 0){
        print("Nothing to add");
    }else{
        for(i=0;i<arr->count;i++){
            temp.fract[temp.count++] = add(arr->fract[i], arr->fract[++i]);
        }
        addAll(&temp);
        
    }
}
Number add(Number x, Number y){
    Number fract;
    float sum1,sum2;
    int lcd;
    sum1 = (x.numerator * y.denominator) + (x.denominator * y.numerator);
    lcd = x.denominator * y.denominator
    if((sum1/lcd)%1 == 0){ // if it doesnt result in decimal, divide to basic form
        fract.numerator = sum1;
        fract.denominator = lcd;
        fract = checkIfProper(fract); // Will return whole num
    }else{
        fract.numerator = (int)sum1;
        fract.denominator = lcd;
    }
    return fract;
}

void subAll(FractCollection *arr){
    FractCollection temp;
    initializeCollection(&temp);
    int i;
    if(arr->count == 0){
        print("Nothing to add");
    }
    for(i=0;i<arr->count;i++){
        temp.fract[temp.count++] = add(arr->fract[i], arr->fract[++i]);
        arr->count--;
    }
    subAll(&temp);

}
Number sub(Number x, Number y){
    Number fract;
    float sum1,sum2;
    int lcd;
    sum1 = (x.numerator * y.denominator) - (x.denominator * y.numerator);
    lcd = x.denominator * y.denominator
    if((sum1/lcd)%1 == 0){ // if it doesnt result in decimal, divide to basic form
        fract.numerator = sum1;
        fract.denominator = lcd;
        fract = checkIfProper(fract); // Will return whole num
    }else{
        fract.numerator = (int)sum1;
        fract.denominator = lcd;
    }
    return fract;
}
 
 void multAll(FractCollection *arr){
    FractCollection temp;
    initializeCollection(&temp);
    int i;
    if(arr->count == 0){
        print("Nothing to add");
    }
    for(i=0;i<arr->count;i++){
        temp.fract[temp.count++] = add(arr->fract[i], arr->fract[++i]);
        arr->count--;
    }
    multAll(&temp);

}
Number mult(Number x, Number y){
    Number fract;
    float sum1,sum2;
    int lcd;
    sum1 = (x.numerator * y.numerator);
    lcd = (x.denominator * y.denominator);
    if((sum1/lcd)%1 == 0){ // if it doesnt result in decimal, divide to basic form
        fract.numerator = sum1;
        fract.denominator = lcd;
        fract = checkIfProper(fract); // Will return whole num
    }else{
        fract.numerator = (int)sum1;
        fract.denominator = lcd;
    }
    return fract;
}

 void divAll(FractCollection *arr){
    FractCollection temp;
    initializeCollection(&temp);
    int i;
    if(arr->count == 0){
        print("Nothing to add");
    }
    for(i=0;i<arr->count;i++){
        temp.fract[temp.count++] = add(arr->fract[i], arr->fract[++i]);
        arr->count--;
    }
    divAll(&temp);

}
Number div(Number x, Number y){
    Number fract;
    float sum1,sum2;
    int lcd;
    sum1 = (x.numerator * y.denominator);
    lcd = (x.denominator * y.numerator);
    if((sum1/lcd)%1 == 0){ // if it doesnt result in decimal, divide to basic form
        fract.numerator = sum1;
        fract.denominator = lcd;
        fract = checkIfProper(fract); // Will return whole num
    }else{

    }
}
// Display
void displayAll(FractCollection *arr){
    int i;
    printf("\nDisplaying all:");
    for(i=0;i<arr->count;i++){
        printf("\n[%d](%d)%20d/%d", i+1, arr->fract[i].wholeNum, arr->fract[i].numerator, arr->fract[i].denominator)
    }
}