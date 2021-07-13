#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SCORE 5
#define MAX_STUDENT 5
#define TRUE 1
#define FALSE 0

typedef char String[20];
typedef int Boolean;

typedef struct {
    String fname;
    String mname;
    String lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    float studScore[MAX_SCORE];
} Student;

typedef struct {
    Student studList[MAX_STUDENT];
    int count;
} StudentList;

typedef struct {
    Student *studList;
    int count;
    int max;
} StudentDynamicList;


void displayStudent(Student s);
void displayStudents(StudentList list);
float getScoreAverage(Student s);
void recordScore(Student *s, float scores[], int n);

Name createName(String fname, String mname, String lname);
Student createStudent(int id, Name name);
StudentList createStudentList();
StudentDynamicList createStudentDL(int size);

void displayName(Name n);
void displayAllNames(Name *nList);

Boolean insertFirst(StudentList *list, Student s);
Boolean insertLast(StudentList *list, Student s);
Student deleteFirst(StudentList *list);
Student deleteLast(StudentList *list);
int search(StudentList list, int id);

//to be added
Boolean insertSorted(StudentDynamicList *list, Student s); //lastname 
StudentList searchStudent(StudentDynamicList *list, String keyword);

Name *getNamesPassed(Student list[], int n);
StudentList getStudentPassed(StudentList list); //
// e copy nalang ninyo daan then paste sa DEVC
int main() {
    StudentList list = createStudentList();

    float s1[5] = {5.0, 5.0, 5.0, 1.0, 5.0};
    float s2[5] = {3.0, 3.0, 3.0, 3.0, 3.0};
    float s3[5] = {1.0, 2.0, 2.0, 3.0, 3.0};
    float s4[5] = {3.0, 3.0, 2.0, 1.0, 1.0};
    float s5[5] = {1.0, 2.0, 1.0, 1.0, 1.0};
    Name *passed;

    insertFirst(&list, createStudent(1001, createName("Kyle", "Castro", "Burce")));
    insertFirst(&list, createStudent(1002, createName("Sugar", "Librero", "Vender")));
    insertFirst(&list, createStudent(1003, createName("Christoph", "Gwapo", "Carreon")));
    insertFirst(&list, createStudent(1004, createName("Gwapo", "Gibert", "Kaayo")));
    insertFirst(&list, createStudent(1005, createName("Fitz", "Napulihan", "Martin")));

    recordScore(&list.studList[0], s1, 5); //ruales 
    recordScore(&list.studList[1], s2, 5); //sugar
    recordScore(&list.studList[2], s3, 5);
    recordScore(&list.studList[3], s4, 5); //yu
    recordScore(&list.studList[4], s5, 5); //Joshua
    // recordScore(&list.studList[0], s2, 5); //paningbatan

    printf("\n\nDisplay All Student:\n");
    displayStudents(list);

    return 0;
}

void displayStudent(Student s) {
    int i;

    printf("%20s: %d\n", "Student ID", s.studID);
    printf("%20s: %s, %s %c.\n", "Student Name", s.studName.lname, s.studName.fname, s.studName.mname[0]);
    printf("%20s: {", "Scores");
    for(i=0; i<MAX_SCORE; ++i) {
        printf("%.2f", s.studScore[i]);
        if(i < MAX_SCORE-1) {
            printf(", ");
        }
    }
    printf("}");
}

void displayStudents(StudentList list) {
    int i, j;
    printf("%10s | %30s | %s\n", "ID", "NAME", "SCORE");
    for(i=0; i<list.count; i++) {
        printf("%10d | %14s %15s | {", list.studList[i].studID, list.studList[i].studName.fname, list.studList[i].studName.lname); 
        for(j=0; j<MAX_SCORE; ++j) {
            printf("%.2f", list.studList[i].studScore[j]);
            if(j < MAX_SCORE-1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

float getScoreAverage(Student s) {
    float sum = 0;
    int i;

    for(i=0; i<MAX_SCORE; ++i) {
        sum += s.studScore[i];
    }

    return sum/MAX_SCORE;
}

void recordScore(Student *s, float scores[], int n) {
    memcpy(s->studScore, scores, sizeof(float)*n);
}

Name createName(String fname, String mname, String lname) {
    Name n;

    strcpy(n.fname, fname);
    strcpy(n.mname, mname);
    strcpy(n.lname, lname);

    return n;
}

Student createStudent(int id, Name name) {
    Student s = {id, name, {5.0, 5.0, 5.0, 5.0, 5.0}}; 

    return s;
}

Boolean insertFirst(StudentList *list, Student s) {
    int i;
    if((list->count) < MAX_STUDENT) {
        for(i=list->count; i>0; --i) {
            list->studList[i] = list->studList[i-1]; 
        }
        list->studList[0] = s;
        list->count++;
        return TRUE;
    }
    return FALSE;
}

Boolean insertLast(StudentList *list, Student s) {
    if(list->count < MAX_STUDENT) {
        list->studList[list->count++] = s;
        return TRUE;
    }
    return FALSE;
}

Student deleteFirst(StudentList *list) {
    int i;
    Student deleted = createStudent(0, createName("", "", ""));

    if(list->count > 0) {
        deleted = list->studList[0];                                                             
        for(i=0; i < list->count-1; ++i) { 
            list->studList[i] = list->studList[i+1];   
        }
        list->count--;
    }

    return deleted;
}

Student deleteLast(StudentList *list) {
    Student deleted = {0, {"", "", ""}, {0, 0, 0, 0, 0}};

    if(list->count > 0) {
        deleted = list->studList[--(list->count)];
    }

    return deleted;
}

int search(StudentList list, int id) {
    int i;

    if(list.count>0) {
        for(i=0; i<list.count; ++i) {
           if(list.studList[i].studID == id) {
               return i;
           }
        }
    }
    
    return -1;
}

void displayName(Name n) {
    printf("%s, %s %s", n.lname, n.fname, n.mname);
}

void displayAllNames(Name *nList) {
    int i = 0;
    while(strcmp(nList[i].fname, "") != 0 && strcmp(nList[i].mname, "") != 0 && strcmp(nList[i].lname, "") != 0) {
        displayName(nList[i++]);
        printf("\n");
    }
}

StudentList createStudentList() {
    StudentList list;

    list.count = 0;

    return list;
}

Name *getNamesPassed(Student list[], int n) {
    Name *nameList;
    Name temp[MAX_STUDENT];
    int i, count;

    for(i=0, count=0; i<n; ++i) {
        if(getScoreAverage(list[i]) <= 3.0) {
            temp[count++] = list[i].studName;
        }
    }
    temp[count++] = createName("", "", "");

    nameList = (Name *) malloc(sizeof(Name)*count);

    if(nameList != NULL) {
        memcpy(nameList, temp, sizeof(Name)*count);
    }
    
    return nameList;    
}

StudentList getStudentPassed(StudentList list) {
    StudentList passed = createStudentList();
    int i;

    for(i=0; i<list.count; ++i) {
        if(getScoreAverage(list.studList[i]) <= 3.0) {
            passed.studList[passed.count++] = list.studList[i]; 
        }
    } 

    return passed;
}

Boolean insertSorted(StudentDynamicList *list, Student s) {
    if(list->count >= list->max) {
        list->max *= 2;
        list->studList = realloc(list->studList, sizeof(Student)*list->max);
        if(list->studList == NULL) {
            return FALSE;
        }
    }

    for(i=list->count; i>0 && strcmp(list->studList[i-1].studName.lname, s.studName.lname)>0; --i) {
        list->studList[i] = list->studList[i-1];
    }
    list->studList[i] = s;
    list->count++;

    return TRUE;
}


StudentDynamicList searchStudent(StudentDynamicList *list, String keyword) {
    StudentDynamicList result = createStudentDL(5);
    int i;

    for(i=0; i<list->count; ++i) {
        if(strstr(list->studList[i].studName.lname, keyword)!=NULL) {
            insertSorted(&result, list->studList[i]);
        }
    }

    return result;
}

StudentDynamicList searchStudent(StudentDynamicList *list, String keyword) {
    StudentDynamicList result = createStudentDL(5);
    int i;

    for(i=0; i<list->count; ++i) {
        if(strstr(list->studList[i].studName.lname, keyword)!=NULL) {
            if(result->count >= result->max) {
                result->max *= 2;
                result->studList = realloc(result->studList, sizeof(Student)*result->max);
                if(result->studList == NULL) {
                    break;
                }
            }
            result->studList[result->count++] = list->studList[i];
        }
    }

    return result;
}































