
// Create a structure for student that contains the following:
//     studID, studName, studScore

// The name must be a structure also of a firstname, middlname, and lastname.
// The student scores is an array of 5 scores. ( accepts values from 1.0 to 5.0)

// Create an array of 5 students.

// Create a function that will display a student information.
// Create a function that will display all the students in the array.
// Create a function that will get the average score of a student.
// Create a function that will encode the 5 scores of the student.


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

Fraction simplifyFraction(Fraction f);

Fraction addAllFractions(FracCollection fracs); 

int getGCD(Fraction f);
Fraction retMixfrac(Fraction f);

int main() {
    String menu[5] = {"Add", "Subtract", "Multiply", "Divide", "EXIT"};
    int i,gcd=0;
    int choice;
    Fraction x, y, z, w;
    Fraction mix;

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
                mix = retMixfrac(w);
                displayFraction(x);
                printf(" + ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                
                break;
            case 2:
            	printf("Adding two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = subtractFraction(x, y);
                w = simplifyFraction(z);
                mix = retMixfrac(w);
                displayFraction(x);
                printf(" - ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                break;
            case 3:
            	printf("Adding two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = multiplyFraction(x, y);
                w = simplifyFraction(z);
                mix = retMixfrac(w);
                displayFraction(x);
                printf(" x ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
                break;
            case 4:
            	printf("Adding two fractions...\n");
                x = inputFraction("Enter fraction 1");
                y = inputFraction("Enter fraction 2");
                z = divideFraction(x, y);
                w = simplifyFraction(z);
                mix = retMixfrac(w);
                displayFraction(x);
                printf(" / ");
                displayFraction(y);
                printf(" = ");
                displayFraction(z);
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

Fraction addFraction(Fraction a, Fraction b) 
{
	Fraction ret;
	int gcd,sum;
	
	sum = a.num + b.num;
	gcd = a.den + b.den;
	
	if(a.den != b.den){
		
		sum = (a.num*b.den) + (a.den*b.num);
		gcd = a.den * b.den;
	}
	ret.num = sum;
	ret.den = gcd;
	
	return ret;
}
Fraction subtractFraction(Fraction a, Fraction b)
{
	Fraction ret;
	int gcd,diff;
	
	diff = a.num - b.num;
	gcd = a.den + b.den;
 	
 	if(a.den != b.den){
 		diff = (a.num*b.den) - (a.den*b.num);
		gcd = a.den * b.den; 
	 }
 	
 	ret.num = diff;
	ret.den = gcd;
	
	return ret;
}

Fraction multiplyFraction(Fraction a, Fraction b)
{
	Fraction ret;
	
	ret.num = a.num * b.num;
	ret.den = a.den * b.den;
	
	return ret;
}

Fraction divideFraction(Fraction a, Fraction b)
{
	Fraction ret;
	
	ret.num = a.num * b.den;
	ret.den = a.den * b.num;
	
	return ret;
}

Fraction simplifyFraction(Fraction f)
{

	
}

int getGCD(Fraction f)
{
	
}

Fraction retMixfrac(Fraction f)
{
	
	
}



// typedef struct stud{
//     char studID[10];
//     Name studName;
//     float studScore[5];
// }Student;

// typedef struct{
//     char fname[15];
//     char lname[15];
//     char mname;
// }Name;

// typedef char String[20];
// typedef int Boolean;

// Boolean insertFirst(Student list[], int *n, Student s);
// Boolean insertLast(Student list[], int *n, Student s);
// Student deleteFirst(Student list[], int *n);
// Student deleteLast(Student list[], int *n);

// int search(Student[], int n, int id);
// void displayStudent(Student s);
// void displayStudents(Student studs[], int n);
// float getScoreAverage(Student s);
// void recordScore(Student *s, float scores[], int n);
// Name createName(String fname, String mname, String lname);
// Student createStudent(int id, Name name);

// Student *getLastname(Student list[],int count, String lastname);

// int main(void)
// {
//     String lastN;
//     Student list[MAX_STUDENT];
//     String IDnum;
//     int count = 0;
//     float s1[5] = {5.0, 5.0, 5.0, 1.0, 5.0};
//     float s2[5] = {3.0, 3.0, 3.0, 3.0, 3.0};
//     float s3[5] = {1.0, 2.0, 2.0, 3.0, 3.0};
//     float s4[5] = {3.0, 3.0, 2.0, 1.0, 1.0};
//     float s5[5] = {1.0, 2.0, 1.0, 1.0, 1.0};
//     Name *passed;

//     list[0] = createStudent(1001, createName("Kyle", "Castro", "Burce"));
//     list[1] = createStudent(1002, createName("Sugar", "Librero", "Vender"));
//     list[2] = createStudent(1003, createName("Christoph", "Gwapo", "Carreon"));
//     list[3] = createStudent(1004, createName("Gwapo", "Gibert", "Kaayo")); 
//     list[4] = createStudent(1005, createName("Fitz", "Napulihan", "Martin")); 
//     count = 5;

//     recordScore(&list[0], s1, 5);
//     recordScore(&list[1], s2, 5);
//     recordScore(&list[2], s3, 5);
//     recordScore(&list[3], s4, 5);
//     recordScore(&list[4], s5, 5);

//     printf("\n\nDisplay All Student:\n");
//     displayStudents(list, 5);

//     printf("Search lastname");
//     scanf("%s",&lastN);         //Search last name

//     IDnum = getLastname(list,count,lastN); //Inserts lastname in the function to search
//     displayStudents(lastNlist); //display

//     return 0;
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

// void displayStudents(Student studs[], int n) {
//     int i, j;
//     printf("%10s | %30s | %s\n", "ID", "NAME", "SCORE");
//     for(i=0; i<n; i++) {
//         printf("%10d | %14s %15s | {", studs[i].studID, studs[i].studName.fname, studs[i].studName.lname); 
//         for(j=0; j<MAX_SCORE; ++j) {
//             printf("%.2f", studs[i].studScore[j]);
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

// void getAvg(Student a)
// {
//     int i,avg;

//     for(i=0;i<5;i++)
//     {
//         avg = a.studScore[i]+a.studScore[++i];
//     }

//     avg = avg/5;
// }

// void studScore()
// {


// }

// Boolean insertFirst(Student list[], int *n, Student s)
// {
//     int i;
//     int j = *n; 
//     Student studtemp;

//     if((*n)>= 5)
//     {
//         printf("ERROR!! FULL");
//         return FALSE;
//     }else
//         {           
//         for(i=0; i<(*n);++i)
//         {		
//             list[j] = list[--j];
//             studtemp = list[i];
//             list[--j] = studtemp;
//         }
// 	      list[j] = s;
// 	      (*n)++;
//         return TRUE;
//         }
// }

// Boolean insertLast(Student list[], int *n, Student s)
// {
//     int i;

//     if((*n) >= 5){
//         printf("ERROR!! FULL");
//         return FALSE;
//     }else{
//         for(i=0;i<=(*n);i++){}
//         list[i] = s;
//     }
// }

// Student deleteFirst(Student list[], int *n)
// {
//     int i;
//     Student deleted;
//     if(n >= MAX_STUDENT)
//     {
//         printf("ERROR!! FULL");
//     }else{
//         deleted = list[i];
//         for(i=0;i<(*n);i++){
            
//         }

//     }




// }
// Student deleteLast(Student list[], int *n);
// int search(Student[], int n, int id);

// String getLastname(Student list[],int count,String lastname)
// {
//     int i,lastNcount;
//     String tempList;
//     Student *newList
//     String ret = NULL;

//     for(i=0,lastNcount=0; i<count; i++){
//         if(strcmp(list[i].studName.lname,lastname)==0){ //if strcmp is true
//             strcpy(tempList,list[i].studID);            //templist copies the ID
//             lastNcount++;                               //lastNcount increments
//         }
//     }

//     newList = (Student *)malloc(sizeof(Student)*count); //

//     if(newList != NULL){
//         memcpy(tempList, newList, sizeof(Student)*lastNcount);
//     }

//     return ret;

// }

////FRACTIONS
