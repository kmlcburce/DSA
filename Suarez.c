#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// #define MAX_SCORE 5
// #define MAX_STUDENT 5
// #define TRUE 1
// #define FALSE 0

// typedef char String[20];
// typedef int Boolean;

// typedef struct {
//     String fname;
//     String mname;
//     String lname;
// } Name;

// typedef struct {
//     int studID;
//     Name studName;
//     float studScore[MAX_SCORE];
// } Student;

// typedef struct {
//     Student studList[MAX_STUDENT];
//     int count;
// } StudentList;

// typedef struct {
//     Student *studList;
//     int count;
//     int max;
// } StudentDynamicList;


// void displayStudent(StudentDynamicList s);
// void displayStudents(StudentDynamicList list);
// float getScoreAverage(Student s);
// void recordScore(Student *s, float scores[], int n);

// Name createName(String fname, String mname, String lname);
// Student createStudent(int id, Name name);
// StudentDynamicList createStudentList();

// void displayName(Name n);
// void displayAllNames(Name *nList);

// Boolean insertFirst(StudentDynamicList *list, Student s);
// Boolean insertLast(StudentDynamicList *list, Student s);
// Student deleteFirst(StudentDynamicList *list);
// Student deleteLast(StudentDynamicList *list);
// int search(StudentDynamicList list, int id);

// //to be added
// Boolean insertSorted(StudentDynamicList *list, Student s);  
// StudentList searchStudent(StudentDynamicList *list, String keyword);

// Name *getNamesPassed(Student list[], int n);
// StudentList getStudentPassed(StudentList list);
 
// int main() {
//     StudentList list = createStudentList();

//     float s1[5] = {5.0, 5.0, 5.0, 1.0, 5.0};
//     float s2[5] = {3.0, 3.0, 3.0, 3.0, 3.0};
//     float s3[5] = {1.0, 2.0, 2.0, 3.0, 3.0};
//     float s4[5] = {3.0, 3.0, 2.0, 1.0, 1.0};
//     float s5[5] = {1.0, 2.0, 1.0, 1.0, 1.0};
//     Name *passed;

//     insertFirst(&list, createStudent(1001, createName("Kyle", "Castro", "Burce")));
//     insertFirst(&list, createStudent(1002, createName("Sugar", "Librero", "Vender")));
//     insertFirst(&list, createStudent(1003, createName("Christoph", "Gwapo", "Carreon")));
//     insertFirst(&list, createStudent(1004, createName("Gwapo", "Gibert", "Kaayo")));
//     insertFirst(&list, createStudent(1005, createName("Fitz", "Napulihan", "Martin")));

//     recordScore(&list->studList[0], s1, 5); 
//     recordScore(&list->studList[1], s2, 5); 
//     recordScore(&list->studList[2], s3, 5);
//     recordScore(&list->studList[3], s4, 5);
//     recordScore(&list->studList[4], s5, 5);
//     // recordScore(&list.studList[0], s2, 5);

//     printf("\n\nDisplay All Student:\n");
//     displayStudents(list);

//     return 0;
// }

// void displayStudent(Student s) {
//     int i;

//     printf("%20s: %d\n", "Student ID", s.studID);
//     printf("%20s: %s, %s %c.\n", "Student Name", s.studName.lname, s.studName.fname, s.studName.mname[0]);
//     printf("%20s: {", "Scores");
//     for(i=0; i<MAX_SCORE; ++i) {
//         printf("%.2f", s.studScore[i]);
//         if(i < MAX_SCORE-1) {
//             printf(", ");
//         }
//     }
//     printf("}");
// }

// void displayStudents(StudentDynamicList list) {
//     int i, j;
//     printf("%10s | %30s | %s\n", "ID", "NAME", "SCORE");
//     for(i=0; i<list.count; i++) {
//         printf("%10d | %14s %15s | {", list.studList[i].studID, list.studList[i].studName.fname, list.studList[i].studName.lname); 
//         for(j=0; j<MAX_SCORE; ++j) {
//             printf("%.2f", list.studList[i].studScore[j]);
//             if(j < MAX_SCORE-1) {
//                 printf(", ");
//             }
//         }
//         printf("}\n");
//     }
// }

// float getScoreAverage(Student s) {
//     float sum = 0;
//     int i;

//     for(i=0; i<MAX_SCORE; ++i) {
//         sum += s.studScore[i];
//     }

//     return sum/MAX_SCORE;
// }

// void recordScore(Student *s, float scores[], int n) {
//     memcpy(s->studScore, scores, sizeof(float)*n);
// }

// Name createName(String fname, String mname, String lname) {
//     Name n;

//     strcpy(n.fname, fname);
//     strcpy(n.mname, mname);
//     strcpy(n.lname, lname);

//     return n;
// }

// Student createStudent(int id, Name name) {
//     Student s = {id, name, {5.0, 5.0, 5.0, 5.0, 5.0}}; 

//     return s;
// }

// Boolean insertFirst(StudentDynamicList *list, Student s) {
//     int i;
//     if((list->count) < list->max ) {
//         for(i=list->count; i>0; --i) {
//             list->studList[i] = list->studList[i-1]; 
//         }
//         list->studList[0] = s;
//         list->count++;
//         return TRUE;
//     }
//     return FALSE;
// }

// Boolean insertLast(StudentDynamicList *list, Student s) {
//     if(list->count < list->max) {
//         list->studList[list->count++] = s;
//         return TRUE;
//     }
//     return FALSE;
// }

// Student deleteFirst(StudentDynamicList *list) {
//     int i;
//     Student deleted = createStudent(0, createName("", "", ""));

//     if(list->count > 0) {
//         deleted = list->studList[0];                                                             
//         for(i=0; i < list->count-1; ++i) { 
//             list->studList[i] = list->studList[i+1];   
//         }
//         list->count--;
//     }

//     return deleted;
// }

// Student deleteLast(StudentDynamicList *list) {
//     Student deleted = {0, {"", "", ""}, {0, 0, 0, 0, 0}};

//     if(list->count > 0) {
//         deleted = list->studList[--(list->count)];
//     }

//     return deleted;
// }

// int search(StudentDynamicList list, int id) {
//     int i;

//     if(list.count>0) {
//         for(i=0; i<list.count; ++i) {
//            if(list.studList[i].studID == id) {
//                return i;
//            }
//         }
//     }
    
//     return -1;
// }

// void displayName(Name n) {
//     printf("%s, %s %s", n.lname, n.fname, n.mname);
// }

// void displayAllNames(Name *nList) {
//     int i = 0;
//     while(strcmp(nList[i].fname, "") != 0 && strcmp(nList[i].mname, "") != 0 && strcmp(nList[i].lname, "") != 0) {
//         displayName(nList[i++]);
//         printf("\n");
//     }
// }

// StudentDynamicList createStudentList() {
//     StudentDynamicList *list;
// 	list = (StudentDynamicList *) malloc(sizeof(StudentDynamicList)*count);
//     list->count = 0;
//     return list;
// }

// Name *getNamesPassed(Student list[], int n) {
//     StudentDynamicList dList;
// 	Name *nameList;
//     Name temp[dList.max];
//     int i, count;

//     for(i=0, count=0; i<n; ++i) {
//         if(getScoreAverage(list[i]) <= 3.0) {
//             temp[count++] = list[i].studName;
//         }
//     }
//     temp[count++] = createName("", "", "");

//     nameList = (Name *) malloc(sizeof(Name)*count);

//     if(nameList != NULL) {
//         memcpy(nameList, temp, sizeof(Name)*count);
//     }
    
//     return nameList;    
// }

// StudentDynamicList getStudentPassed(StudentDynamicList list) {
//     StudentDyamicList passed = createStudentList();
//     int i;

//     for(i=0; i<list.count; ++i) {
//         if(getScoreAverage(list.studList[i]) <= 3.0) {
//             passed.studList[passed.count++] = list.studList[i]; 
//         }
//     } 

//     return passed;
// }

// Boolean insertSorted(StudentDynamicList *list, Student s){
// 	int i,x;
// 	char temp;
// 	if((list->count)< list->max){
// 		for(i=1; i<list->count; i++){
// 			temp = list[i];
// 			x = i-1;
// 			while(x>=0 && list[x]>temp){
// 				list[x+1] = list[x]; 
// 				x--;
// 			}
// 			list[x+1] = temp;
// 		}
// 		return TRUE;
// 	}
// 	return FALSE;
// }
  
// StudentDynamicList searchStudent(StudentDynamicList *list, String keyword){
// 	StudentDynamicList ret;
// 	String result
// 	int i;
// 	if(list->count > 0){
// 		for(i=0; i<list->count; i++){
// 			if(strcmp(list->studList[i].studName.lname, keyword) == 0){
// 				result = list[i];
// 			}
// 			ret = result;
// 		}
// 		return ret;
// 	}
// }

#include <stdio.h>
#include <stdlib.h>

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
void displaywholeNumber(Fraction f);

Fraction addFraction(Fraction a, Fraction b);
Fraction subtractFraction(Fraction a, Fraction b);
Fraction multiplyFraction(Fraction a, Fraction b);
Fraction divideFraction(Fraction a, Fraction b);

Fraction simplyFraction(Fraction f);

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
                printf("Answer: ");
				displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                simplyFraction(z);
                break;
            case 2:
            	printf("Subtracting two fractions...\n");
            	x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = subtractFraction(x, y);
                printf("Answer: ");
                displayFraction(x);
                printf(" - ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                simplyFraction(z);
                break;
            case 3:
            	printf("Multiplying two fractions...\n");
            	x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                printf("Answer: ");
                displayFraction(x);
                printf(" * ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                simplyFraction(z);
                break;
            case 4:
            	printf("Dividing two fractions...\n");
            	x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = divideFraction(x, y);
                printf("Answer: ");
                displayFraction(x);
                printf(" / ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
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

//void displaywholeNumber(Fraction f){
//	printf(" = %d", f.whole);
//}

Fraction addFraction(Fraction a, Fraction b) {
    Fraction result;
	
	result.num = (a.num * b.den) + (b.num * a.den);
    result.den = a.den * b.den;
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
	int i;
	if(f.num < 0 || f.den < 0 ){//Checks if fraction is negative
		f.num = abs(f.num);
		f.den = abs(f.den);
		if(f.num == f.den){ //if both numerator and denomenator are the same
			f.whole = (f.num / f.den) * -1;
			printf(" = %d", f.whole);
		} else if(f.num == 0){ // if numerator is 0 the answer is 0
			printf(" = %d", f.num);	
		} else if(f.den == 0){ // if denomenator is 0 the answer is undefined
			printf(" or undifined");	
		} else if(f.num > f.den && f.num % f.den == 0){ // if fraction is improper and numerator is divisible by the denomenator
			f.whole = (f.num / f.den) * -1;
			printf(" = %d", f.whole);
		} else if(f.num > f.den){ // if fraction is improper get gcd to simplify
			for(i=1; i<=f.num && i<=f.den; ++i){
				if(f.num%i==0 && f.den%i==0){ // checking for gcd
					f.num /= i * -1;
					f.den /= i * -1;
				}
			}
			printf(" = %d/%d", f.num, f.den);
			if(f.num > f.den){ // if fraction is still improper
				f.whole = (f.num / f.den);
				f.num %= f.den * -1;
				printf(" = %d %d/%d", f.whole, f.num, f.den );
			} 
		} 
	}else if(f.num == f.den){ //if both numerator and denomenator are the same
		f.whole = f.num / f.den;
		printf(" = %d", f.whole);
	} else if(f.num == 0){ // if numerator is 0 the answer is 0
		printf(" = %d", f.num);	
	} else if(f.den == 0){ // if denomenator is 0 the answer is undefined
		printf(" or undifined");
	} else if(f.num > f.den && f.num % f.den == 0){ // if fraction is improper and numerator is divisible by the denomenator
		f.whole = f.num / f.den;
		printf(" = %d", f.whole);
	} else if(f.num > f.den){ // if fraction is improper get gcd to simplify
		for(i=1; i<=f.num && i<=f.den; ++i){
			if(f.num%i==0 && f.den%i==0){ // checking for gcd
				f.num /= i;
				f.den /= i;
			}
		}
		printf(" = %d/%d", f.num, f.den);
		if(f.num > f.den){ // if fraction is still improper
			f.whole = f.num / f.den;
			f.num %= f.den;
		printf(" = %d %d/%d", f.whole, f.num, f.den );
		} 
	}
	
//	for(i=1; i<=f.num && i<=f.den; ++i){
//		if(f.num%i==0 && f.den%i==0){ // checking for gcd
//			f.num /= i;
//			f.den /= i;
//		}
//	}
//	printf(" = %d %d/%d", f.whole, f.num, f.den);	
	return f;
}

Fraction addAllFractions(FracCollection f) {
    Fraction result = newFraction(0,1);
    int i;

    for(i=0; i<f.count; ++i) {
        result = addFraction(result, f.fracs[i]); 
    }
    return result;
}
