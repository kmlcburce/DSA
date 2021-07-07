// Burce
// Insert student before Nth element 
Boolean insertBefore(Student list[], int *n, Student s); // paningbatan
Boolean insertBefore(Student list[], int *n, Student s, int elem); // yu

// Insert student after Nth element
Boolean insertAfter(Student list[], int *n, Student s); // paningbatan
Boolean insertAfter(Student list[], int *n, Student s, int elem); // yu

// Delete Student with a given ID number
Student deleteStudent(Student list[], int id); // paningbatan
Student deleteStudent(Student list[], int *n, int id); // yu

// Sort student list based on Last Name
void sortStudents(Student list[], String lname, int n); // paningbatan
void sortList(Student list[], int *n); // yu

void sortStudentByLastName(Student *list, int n);
void sortStudentByLastName(Student list[], int n);
--------------------
#define MAX 10
int max = 10;

struct stud {
    int idNum;
    char name[20];
} Student;

typedef struct stud {
    int idNum;
    char name[20];
} Student;

int main() {
    Student studList1[MAX];
    Student studList2[MAX];
    Student *studList3;

    int count = 0;
    populateStudent(studList1, &count);

    studList2 = studList1; // not correct
    studList3 = studList1; // correct

    sortStudentByLastName(studList, count);
    sortStudentByLastName(&studList[0], count); 

} 
//
// Create and return a new list based on students that have passed the semester (3.0)
Student passStudent(Student list[], int *n, float score); // paningbatan
void passStudent(Student list[], int n, Student newList[], int *newN);
Student *passStudent2(Student list[], int n);
int main() {
    Student studList[MAX];
    Student newStudList[MAX];
    Student *newListDynamic;
    int count = 0;
    int countNew = 0;
    populateStudent(studList, &count);

    passStudent(studList, count, newList, &countNew);
    newListDynamic = passStudent2(studList, count);
}

// Go 
// Getting names with similar last name and transfer to another array
Student *findSimilar(Student list[]); // Burce
// Sorting by first name alphabetically
Student sortName(Student list[]); // Burce
// search student by ID
Student searchId(Student list[], int id); // Burce
// Transfer differents students in a different array by their "years"(1styr,2nd,3rd,4th)
// there are no years in the struct tho - Burce
// insert in position(hatest pa teach)
Student insertAt(Student list[], int pos, int *count); // Burce

// Fitz
// Display students with a passing average grade. Pass = 3.0
void displayGrade(Student a); // go
// Disaply students with a starting ID of any specific ID no. else display none.
void displayID(Student a); // go
// Insert new student in the middle of the list.
void insertMid(Student[], int *count, Student a); //go
// Transfer all failed students to a new list. nya e return(?)
Student failStuds(Student[], int *count); //go
;// Display all honor students. honor students = Grade of 1.0-2.0 
void displayHonorStuds(Student[]); //go

// Christoph
// 1. if studID is found in the list, remove it and transfer to new list
void transferStud(Student list[], studID); //Fitz
// 2. if studName is found in the list, delete all his/her scores(make it NULL)
void deleteScore(Student *s, Students list[]); //Fitz
// 3. search for last name of student, return true if found
Boolean searchLname(Student list[]); //Fitz
// 4. search student in the list and if found, duplicate information and insert it in the last index
void duplicate(Student list[]); //Fitz
// 5. make a mirror copy of the list
void mirrorList(Student list[]); //Fitz

// Verano
Christoph
//*1.) Find and return the student with the highest average score.
student returnHighAveStud(Student list[]);
//2.) Find and return the student with the lowest average score.
student returnLowAveStud(Student list[]);
//3.) return 0 if the average score of the student is greater than or equal to 3.0 return 1 
//if the average score is below 3.0.
int returnAveScore(Student list[]);
//4.) Get those students with the same family name and insert it to the new student list.
student getStudFamName(Student list[]);
//5.) Check if the student exist return TRUE if not return FALSE. */
boolean checkStud(Student list[], int studID);
OK mana ko sir

// Paningbatan
// Create a function that will list the students' last name alphabetically (ascending)
void ascending(Student list[]); //Verano
// Create a function that will list the students' last name alphabetically (descending)
void descending(Student list[]); // Verano
// Create a function that will check if the student has passed. (initialize a passing score)
Student studGrade(Student list[]); // Verano
// Create a function that will swap two students
void swapStud(Student list[]); // Verano
// Create a function that will display students with the same ID (first 4 numbers or year)
void displayStud(student list[]); // Verano

// Comar

// Create a function that sorts the array by student name on decending order and returns the list
Student sortNamebyDescending(Student list[]);
// Create a function that sorts the array by student name on ascending order and returns the list
Student sortNamebyAscending(Student list[]);
// Create a function that sorts the array by student ID on decending order and returns the list
Student sortIDbyDescending(Student list[]);
// Create a function that sorts the array by student ID on ascending order and returns the list
Student sortIDbyAscending(Student list[]);
// Create a function that searches for the student name in the array and returns its position in the array
int searchName(Student list);
// Create a function that checks the array for duplicate data and returns TRUE or FALSE depending on the result

// Ruales

// Create a function that deletes a specific student record
Student deletePos(Student list[], int pos);
// Create a function that  diplay students alphabetically
Student displayAlphabetical(Student list[]);
// Create a function that find the highest graded student
Student findHighestGrade(Student list[]);
// Create a function that insert in a specific position
Student insertPos(Student list[], int pos);
// Create a function that swap the position of the first student in the list with the last student
Student swapStudent(Student list[], int *count);





/*
⠄⠄⠄⠄⠄⠄⢀⣠⣤⣶⣶⣶⣤⣄⠄⠄⢀⣠⣤⣤⣤⣤⣀⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⢠⣾⣿⣿⣿⣿⠿⠿⢿⣿⣿⡆⣿⣿⣿⣿⣿⣿⣿⣷⡄⠄⠄⠄⠄⠄
⠄⠄⠄⣴⣿⣿⡟⣩⣵⣶⣾⣿⣷⣶⣮⣅⢛⣫⣭⣭⣭⣭⣭⣭⣛⣂⠄⠄⠄⠄
⠄⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣭⠛⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠄
⣠⡄⣿⣿⣿⣿⣿⣿⣿⠿⢟⣛⣫⣭⠉⠍⠉⣛⠿⡘⣿⠿⢟⣛⡛⠉⠙⠻⢿⡄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣶⣶⣶⣶⣭⣍⠄⣡⣬⣭⣭⣅⣈⣀⣉⣁⠄
⣿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣛⡻⠿⠿⢿⣿⡿⢛⣥⣾⣿⣿⣿⣿⣿⣿⣿⠿⠋⠄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⣩⣵⣾⣿⣿⣯⣙⠟⣋⣉⣩⣍⡁⠄⠄⠄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣷⡄⠄⠄
⣿⣿⣿⣿⣿⣿⡿⢟⣛⣛⣛⣛⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⡀⠄
⣿⣿⣿⣿⣿⡟⢼⣿⣯⣭⣛⣛⣛⡻⠷⠶⢶⣬⣭⣭⣭⡭⠭⢉⡄⠶⠾⠟⠁⠄
⣿⣿⣿⣿⣟⠻⣦⣤⣭⣭⣭⣭⣛⣛⡻⠿⠷⠶⢶⣶⠞⣼⡟⡸⣸⡸⠿⠄⠄⠄
⣛⠿⢿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠷⡆⣾⠟⡴⣱⢏⡜⠆⠄⠄⠄
⣭⣙⡒⠦⠭⣭⣛⣛⣛⡻⠿⠿⠟⣛⣛⣛⣛⡋⣶⡜⣟⣸⣠⡿⣸⠇⣧⡀⠄⠄
⣿⣿⣿⣿⣷⣶⣦⣭⣭⣭⣭⣭⣭⣥⣶⣶⣶⡆⣿⣾⣿⣿⣿⣷⣿⣸⠉⣷⠄⠄
*/