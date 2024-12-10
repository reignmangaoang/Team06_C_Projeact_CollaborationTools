#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
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

    // Input Student Email
    printf("Enter Student Email: ");
    scanf(" %[^\n]s", newStudent.email);

    // Validate Email (simple check for '@')
    if (strchr(newStudent.email, '@') == NULL)
    {
        printf("Invalid email format. Please try again.\n");
        return;
    }

    newStudent.grade = -1; // Default grade

    // Add the student to the list
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
        printf("ID: %d, Name: %s, Email: %s, Grade: %.2f\n",
               students[i].id, students[i].name,
               students[i].email,
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
    printf("Enter Student ID to set grade: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter grade for %s: ", students[i].name);
            scanf("%f", &grade);
            students[i].grade = grade;
            // Bug 4: No validation for negative grades or unrealistic values
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Bug 1: Incomplete function (removeStudent)
void removeStudent()
{
    int id;
    printf("Enter Student ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
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