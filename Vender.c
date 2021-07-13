#include <stdio.h>
#include <string.h>

typedef struct{
    int numerator;  
    int denominator;
}Fraction; 

void print_fraction(Fraction f);
Fraction add_fractions(Fraction f1, Fraction f2); 
Fraction minus_fractions(Fraction f1, Fraction f2);
Fraction times_fractions(Fraction f1, Fraction f2);
Fraction divide_fractions(Fraction f1, Fraction f2);
Fraction simplify_fraction(Fraction fraction); 

int main (){

}