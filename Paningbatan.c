#include <stdio.h>
#include<stdlib.h>

typedef char String[20];

typedef struct {
    int whole;
    int num;
    int den;
} Fraction;

typedef struct node {
    int data;
    struct node *next;
} NodeType, *NodePtr;

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

Fraction simplifyFraction(Fraction f);

Fraction addAllFractions(FracCollection fracs); 

Fraction convertIMFraction(Fraction f);

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
                w = simplifyFraction(z);
                displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                printf(" = ");
                displayFraction(w);
                printf(" = ");
                displayFraction(convertIMFraction(w)); 
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
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
    if(f.whole != 0) {
        printf("%d ", f.whole);
    }
    
    printf("%d/%d", f.num, f.den);
}

Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;

    result.den = a.den * b.den;
    result.num = (a.num * b.den) + (b.num * a.den); 
    
    return result;
}


// Fraction subtractFraction(Fraction a, Fraction b);
// Fraction multiplyFraction(Fraction a, Fraction b);
// Fraction divideFraction(Fraction a, Fraction b);

Fraction simplifyFraction(Fraction f) {
    int common = gcd(f.num, f.den);

    f.num /= common;
    f.den /= common; 

    return f;
}

int gcd(int a, int b){
    int hcf;
    for(int i=1; i<=a && i<=b; i++) {
        if(a%i==0 && b%i==0) {
            hcf = i;
        }
    }
    return hcf;
}

Fraction addAllFractions(FracCollection f) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<f.count; ++i) {
        result = addFraction(result, f.fracs[i]); 
    }

    return result;
}

Fraction convertIMFraction(Fraction f) {
    if(f.whole == 0) {
        if(f.num > f.den)  {
            f.whole = f.num / f.den;
            f.num = f.num % f.den;
        }
    } else {
        f.num = f.whole * f.den + f.num;
        f.whole = 0;
    }
}



typedef struct {
    Fraction *fracs;
    int count;
    int max;
} FracCollection; 

FracCollection *f = (Fraction)malloc(sizeof(Fraction)*max);

FracCollection *f = (FracCollection *) malloc(sizeof(FracCollection) * max);

int x;
x = 5;

int *p = &x;

int a[5]; --> static arrays
int *a;   --> dynamic arrays using pointers
int *a = (int *) malloc(sizeof(int) * max); // MAX == 5
int *a = (int *) malloc(20);

FracCollection f;

f.max = MAX;
f.fracs = (Fraction *) malloc(sizeof(Fraction) * f.max);



char names[20];

gets(names); // hello

h = 0
e = 1
l = 2
l = 3
o = 4
\0 = 5

for(i=0; names[i] != '\0'; ++i) {

}
// #include <stdio.h>
// #include<stdlib.h>

// typedef char String[20];

// typedef struct {
//     int whole;
//     int num;
//     int den;
// } Fraction;

// typedef struct {
//     Fraction *fracs;
//     int count;
//     int max;
// } FracCollection; 

// Fraction newFraction(int num, int den);
// Fraction inputFraction(String msg);

// void displayFraction(Fraction f);

// void GCD(Fraction f);
// Fraction addFraction(Fraction a, Fraction b);
// Fraction subtractFraction(Fraction a, Fraction b);
// Fraction multiplyFraction(Fraction a, Fraction b);
// Fraction divideFraction(Fraction a, Fraction b);

// void simplyFraction(Fraction f);

// Fraction addAllFractions(FracCollection fracs); 

// int main() {
//     String menu[5] = {"Add", "Subtract", "Multiply", "Divide", "EXIT"};
//     int i;
//     int choice;
//     Fraction x, y, z, w;

//     do {
//         printf("\n\nFRACTION CALCULATOR\n");
//         for(i=0; i<5; ++i) {
//             printf("[%d.] %s\n", i+1, menu[i]);
//         }
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch(choice) {
//             case 1:
//                 printf("Adding two fractions...\n");
//                 x = inputFraction("Enter fraction 1");
//                 y = inputFraction("Enter fraction 2");
//                 z = addFraction(x, y);
//                 //w = simplyFraction(z);
//                 displayFraction(x);
//                 printf(" + ");
//                 displayFraction(y);
//                 printf(" = ");
//                 displayFraction(z);
//                 printf(" = ");
//                 //displayFraction(w);
//                 simplyFraction(z);
//                 break;
//             case 2:
//             	printf("Subtracting two fractions...\n");
//                 x = inputFraction("Enter fraction 1");
//                 y = inputFraction("Enter fraction 2");
//                 z = subtractFraction(x, y);
//                 //w = simplyFraction(z);
//                 displayFraction(x);
//                 printf(" - ");
//                 displayFraction(y);
//                 printf(" = ");
//                 displayFraction(z);
//                 printf(" = ");
//                 //displayFraction(w);
//                 simplyFraction(z);
//                 break;
//             case 3:
//             	printf("Multiplying two fractions...\n");
//                 x = inputFraction("Enter fraction 1");
//                 y = inputFraction("Enter fraction 2");
//                 z = multiplyFraction(x, y);
//                 //w = simplyFraction(z);
//                 displayFraction(x);
//                 printf(" x ");
//                 displayFraction(y);
//                 printf(" = ");
//                 displayFraction(z);
//                 printf(" = ");
//                 //displayFraction(w);
//                 simplyFraction(z);
//                 break;
//             case 4:
//             	printf("Dividing two fractions...\n");
//                 x = inputFraction("Enter fraction 1");
//                 y = inputFraction("Enter fraction 2");
//                 z = divideFraction(x, y);
//                 //w = simplyFraction(z);
//                 displayFraction(x);
//                 printf(" / ");
//                 displayFraction(y);
//                 printf(" = ");
//                 displayFraction(z);
//                 printf(" = ");
//                 //displayFraction(w);
//                 simplyFraction(z);
//                 break;
//             case 5:
//                 break;
//             default:
//                 printf("Invalid Input");
//         }

//     } while(choice != 5);


//     return 0;
// }

// Fraction newFraction(int num, int den) {
//     Fraction f = {0, num, den};

//     return f;
// } 

// Fraction inputFraction(String msg) {
//     Fraction f;

//     printf("%s: ", msg);
//     scanf("%d/%d", &f.num, &f.den);

//     return f;
// }

// void displayFraction(Fraction f) {
// 	printf("%d/%d", f.num, f.den);
// }

// Fraction addFraction(Fraction a, Fraction b) {
//     Fraction result;

//     result.den = a.den * b.den;
//     result.num = (a.num * b.den) + (b.num * a.den); 
    
//     return result;
// }

// Fraction subtractFraction(Fraction a, Fraction b) {
// 	Fraction result;
	
// 	result.den = a.den * b.den;
// 	result.num = (a.num * b.den) - (b.num * a.den);
	
// 	return result;
// }
// Fraction multiplyFraction(Fraction a, Fraction b) {
// 	Fraction result;
	
// 	result.den = a.den * b.den;
// 	result.num = a.num * b.num;
	
// 	return result;
// }
// Fraction divideFraction(Fraction a, Fraction b) {
// 	Fraction result;
	
// 	result.den = a.den * b.num; 
// 	result.num = a.num * b.den;
	
// 	return result;
// }

// void simplyFraction(Fraction f) {

//   	if (f.num < f.den) {
//    		GCD(f);
//   	}else if (f.num%f.den == 0) {
//        f.whole = f.num/f.den;
//        printf("%d", f.whole);
//    	}else {
//        f.whole = f.num/f.den;
//        f.num = f.num%f.den;
//        printf("%d %d/%d", f.whole, f.num, f.den);
//    	}
// //	return f;
// }

// void GCD(Fraction f){
// 	int GCD;
	
// 	if(f.num < f.den) {
//         GCD = f.num;
//   	}else {
//         GCD = f.den;
//     }
//     while (GCD > 1) {
//         if (f.num % GCD == 0 && f.den % GCD == 0) {
//             break;
//             GCD--;
//         }
//    	}
//    	printf("%d/%d", f.num / GCD, f.den / GCD);
// //   f.num = f.num/GCD;
// //   f.den = f.den/GCD;
// //    
// //   return f;
// }
// Fraction addAllFractions(FracCollection f) {
//     Fraction result = newFraction(0,1);
//     int i;

//     for(i=0; i<f.count; ++i) {
//         result = addFraction(result, f.fracs[i]); 
//     }

//     return result;
// }
