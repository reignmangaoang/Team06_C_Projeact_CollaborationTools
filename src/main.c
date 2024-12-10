#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    while (1)
    {
        printf("\nSTUDENT MANAGEMENT SYSTEM:\n");
        printf("----------------------------\n");
        printf("1. Add New Student\n");
        printf("2. Remove Student\n");
        printf("3. Update Student Details\n");
        printf("4. Search Student\n");
        printf("5. List All Students\n");
        printf("6. View Student Grade\n");
        printf("7. Set Student Grade\n");
        printf("8. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 8)
        {
            printf("Invalid input. Please enter a number between 1 and 8.\n");
            while (getchar() != '\n')
                ; // clear the buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            updateStudentDetails();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            listAllStudents();
            break;
        case 6:
            viewStudentGrade();
            break;
        case 7:
            setStudentGrade();
            break;
        case 8:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
