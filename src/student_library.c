#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("Cannot add more students. The list is full.\n");
        return;
    }

    Student newStudent;

    // Input Student ID with validation
    printf("Enter Student ID: ");
    while (scanf("%d", &newStudent.id) != 1 || newStudent.id <= 0)
    {
        printf("Invalid ID. Please enter a positive integer: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    // Check for duplicate ID
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == newStudent.id)
        {
            printf("Student ID already exists. Cannot add duplicate.\n");
            return;
        }
    }

    // Input Student Name
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", newStudent.name);
    newStudent.grade = -1; // Default grade

    students[studentCount++] = newStudent;
    printf("Student added successfully.\n");
}

void updateStudentDetails()
{
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter new name for the student: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Student details updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void searchStudent()
{
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Student ID: %d\nName: %s\nGrade: %.2f\n",
                   students[i].id, students[i].name,
                   students[i].grade == -1 ? 0 : students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void listAllStudents()
{
    if (studentCount == 0)
    {
        printf("No students to display.\n");
        return;
    }

    printf("List of All Students:\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("ID: %d, Name: %s, Grade: %.2f\n",
               students[i].id, students[i].name,
               students[i].grade == -1 ? 0 : students[i].grade);
    }
}

void viewStudentGrade()
{
    int id;
    printf("Enter Student ID to view grade: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Grade for %s (ID: %d): %.2f\n",
                   students[i].name, students[i].id,
                   students[i].grade == -1 ? 0 : students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void setStudentGrade()
{
    int id;
    float grade;

    // Input Student ID
    printf("Enter Student ID to set grade: ");
    while (scanf("%d", &id) != 1 || id <= 0)
    {
        printf("Invalid ID. Please enter a positive integer: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            // Input Grade with validation
            printf("Enter grade for %s: ", students[i].name);
            while (scanf("%f", &grade) != 1 || grade < 0 || grade > 100)
            {
                printf("Invalid grade. Enter a value between 0 and 100: ");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            students[i].grade = grade;
            printf("Grade updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void removeStudent()
{
    int id;

    // Input Student ID
    printf("Enter Student ID to remove: ");
    while (scanf("%d", &id) != 1 || id <= 0)
    {
        printf("Invalid ID. Please enter a positive integer: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            // Shift elements to remove student
            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student removed successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}