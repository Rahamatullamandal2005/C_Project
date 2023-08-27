#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure 
struct student {
    int rollNumber;
    char name[50];
    float marks;
};

// add student
void addStudent(struct student *students, int *count) {
    struct student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newStudent.name);
    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;
}

// print all student
void displayStudents(struct student *students, int count) {
    if (count == 0) {
        printf("No students found.\n");
    } else {
        printf("Student Records:\n");
        printf("Roll Number\tName\t\tMarks\n");
        printf("------------------------------------\n");

        for (int i = 0; i < count; i++) {
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
        }
    }
}

// search by roll
void searchStudent(struct student *students, int count) {
    int rollNumber;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Found:\n");
            printf("Roll Number\tName\t\tMarks\n");
            printf("------------------------------------\n");
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
}
// search by marks
void searchByMarks(struct student *students, int count) {
    float Marks;
    printf("Enter Marks to search: ");
    scanf("%f", &Marks);

    for (int i = 0; i < count; i++) {
        if (students[i].marks == Marks) {
            printf("Student Found:\n");
            printf("Roll Number\tName\t\tMarks\n");
            printf("------------------------------------\n");
        for (int i = 0; i < count; i++) {
            if (students[i].marks == Marks){ 
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            }
        }
            return;
        }
    }

    printf("Student with Marks %.2f not found.\n", Marks);
}
// search by name
void searchByName(struct student *students, int count, const char* name) {

int found=0;

    for (int i = 0; i < count; i++) {
       if (strcmp(students[i].name, name) == 0) {
            printf("Student Found:\n");
            printf("Roll Number\tName\t\tMarks\n");
            printf("------------------------------------\n");
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0){ 
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            }
        }
            return;
        }
    }

    printf("Student with Name %s not found.\n", name);
}
// delete sudent
void deleteStudent(struct student *students, int *count) {
    int rollNumber;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
}

int main() {
    struct student students[100];
    int count = 0;
    int choice;
    printf("-------------------------------------\n");
    printf("|    Well come To my Mini Project   |\n");
    printf("|     Student Management System     |\n");
    printf("-------------------------------------\n");
    printf("Create By: \n");
    printf("-------------------------------------\n");
    printf("|\tName: Rahamatulla Mandal    |\n");
    printf("|\tID : 2213986040             |\n");
    printf("|\tDepartment: BCA(22)         |\n");
    printf("-------------------------------------\n");
    do {
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student By roll number\n");
        printf("4. Search Student By Name\n");
        printf("5. Search Student By Marks\n");
        printf("6. Delete Student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                 {
              char searchname[20];
              printf("Enter the name: ");
              scanf(" %[^\n]s",searchname);
              searchByName(students, count , searchname);
                }
                break;               
            case 5:
                searchByMarks(students, count);
                break;
            case 6:
                deleteStudent(students, &count);
                break;
            case 7:
                printf("End of Program | Thank You !\n");
                break;
            default:
                printf("Wrong Number Choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
