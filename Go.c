
// Create a structure for student that contains the following:
//     studID, studName, studScore

// The name must be a structure also of a firstname, middlname, and lastname.
// The student scores is an array of 5 scores. ( accepts values from 1.0 to 5.0)

// Create an array of 5 students.

// Create a function that will display a student information.
// Create a function that will display all the students in the array.
// Create a function that will get the average score of a student.
// Create a function that will encode the 5 scores of the student.
Boolean insertFirst(Student list[], int *n, Student s);
Boolean insertLast(Student list[], int *n, Student s);
Student deleteFirst(Student list[], int *n);
Student deleteLast(Student list[], int *n);
int search(Student[], int n, int id);



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



typedef struct stud{
    char studID[10];
    Name studName;
    float studScore[5];
}Student;

typedef struct{
    char fname[15];
    char lname[15];
    char mname;
}Name;

int main(void)
{
    Student stud[5];
    int i;

    




    return 0;
}

void displayStudInfo(Student a)
{   
    printf("%s", a.studID);
    printf("%s", a.studName.fname);
    printf("%s", a.studName.lname);
    printf("%s", a.studName.mname);
}

void displayStuds()
{


}

void getAvg(Student a)
{
    int i,avg;

    for(i=0;i<5;i++)
    {
        avg = a.studScore[i]+a.studScore[++i];
    }

    avg = avg/5;
}

void studScore()
{


}

Boolean insertFirst(Student list[], int *n, Student s)
{
    int i;
    int j = *n; 
    Student studtemp;

    if((*n)>= 5)
    {
        printf("ERROR!! FULL");
        return FALSE;
    }else
        {           
        for(i=0; i<(*n);++i)
        {		
            list[j] = list[--j];
            studtemp = list[i];
            list[--j] = studtemp;
        }
	      list[j] = s;
	      (*n)++;
        return TRUE;
        }
}

Boolean insertLast(Student list[], int *n, Student s)
{
    int i;

    if((*n) >= 5){
        printf("ERROR!! FULL");
        return FALSE;
    }else{
        for(i=0;i<=(*n);i++){}
        list[i] = s;
    }
}

Student deleteFirst(Student list[], int *n)
{
    int i;
    Student deleted;
    if(n >= MAX_STUDENT)
    {
        printf("ERROR!! FULL");
    }else{
        deleted = list[i];
        for(i=0;i<(*n);i++){
            
        }

    }




}
Student deleteLast(Student list[], int *n);
int search(Student[], int n, int id);