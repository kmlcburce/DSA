#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int num;
    int dem;
}fraction;

//operations
void add(fraction a, fraction b);
void subtract(fraction a, fraction b);
void multiply(fraction a, fraction b);
void divide(fraction a, fraction b);

//helpers
void simplifyFraction(fraction f);
void getGcd(int num, int dem);
void show(fraction a);

int main(){
    //view()?
    fraction f1, f2;
    printf("Enter first and second fraction: \n");
    scanf("%d/%d", &f1.num, &f1.dem);
    scanf("%d/%d", &f2.num, &f2.dem);
    
    input x;
    printf("choose operation: (1)addition, (2)subtraction, (3)multiplication, (4)division,\n")
    scanf("%x", &x);
    switch(x){
        case 1: add(f1, f2);
        case 2: subtract(f1, f2);
        case 3: multiply(f1, f2);
        case 4: divide( f1, f2);
        default: printf("invalid input!");  
    }
}

void simplifyFraction(fraction f){
    int gcdValue;
    gcdValue = getGcd(f.num, f.dem);
    f.num /= gcdValue;
    f.dem /= gcdValue;
    show(f);
    //return f?
}

void show(fraction a){
    printf("%d/%d\n", a.num, a.dem); //proper fraction

    int g, h;
    h = a.num/a.dem;
    g = a.num%a.dem;
    printf("%d %d/%d", h, g, a.dem); //improper fraction view
}

void getGcd(int num, int dem){
    if(dem==0){
        return dem;
    }else{
        getGcd(dem, num%dem);
    }
}

void add(fraction a, fraction b){
    fraction x;
    x.num = (a.num * b.dem) + (a.dem * b.num);
    x.dem = a.dem * b.dem;
    show(x);
    simplifyFraction(x);
}
void subtract(fraction a, fraction b){  
    fraction x;
    x.num = (a.num * b.dem) - (a.dem * b.num);
    x.dem = a.dem * b.dem;
    show(x);
    simplifyFraction(x);
}
void multiply(fraction a, fraction b){
    fraction x;
    x.num = a.num * b.num;
    x.dem = a.dem * b.dem;
    show(x);
    simplifyFraction(x);
}
void divide(fraction a, fraction b){
    fraction x;
    x.num = a.num * b.dem;
    x.dem = a.dem * b.num;
    show(x);
    simplifyFraction(x);
}