#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[30];
    float fine;
} student;

int main()
{
    student s[100];
    int n, i;
    int choice, id, found;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Initial Input
    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Fine Amount: ");
        scanf("%f", &s[i].fine);
    }

    while (1)
    {
        printf("\n\n===== STUDENT FINE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Fine\n");
        printf("5. Pay Fine\n");
        printf("6. Delete Student\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add Student
            printf("\nEnter Student ID: ");
            scanf("%d", &s[n].id);

            printf("Enter Student Name: ");
            scanf("%s", s[n].name);

            printf("Enter Fine Amount: ");
            scanf("%f", &s[n].fine);

            n++;

            printf("Student added successfully!\n");
            break;

        case 2: // Display Students
            if (n == 0)
            {
                printf("No records found!\n");
                break;
            }

            printf("\nID\tName\t\tFine\n");
            printf("---------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t\t%.2f\n",
                       s[i].id,
                       s[i].name,
                       s[i].fine);
            }
            break;

        case 3: // Search Student
            printf("Enter Student ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].id == id)
                {
                    printf("\nStudent Found\n");
                    printf("ID   : %d\n", s[i].id);
                    printf("Name : %s\n", s[i].name);
                    printf("Fine : %.2f\n", s[i].fine);

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student not found!\n");
            }

            break;

        case 4: // Update Fine
            printf("Enter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].id == id)
                {
                    printf("Enter New Fine Amount: ");
                    scanf("%f", &s[i].fine);

                    printf("Fine updated successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student not found!\n");
            }

            break;

        case 5: // Pay Fine
            printf("Enter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].id == id)
                {
                    s[i].fine = 0;

                    printf("Fine paid successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student not found!\n");
            }

            break;

        case 6: // Delete Student
            printf("Enter Student ID to delete: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].id == id)
                {
                    int j;

                    for (j = i; j < n - 1; j++)
                    {
                        s[j] = s[j + 1];
                    }

                    n--;

                    printf("Student deleted successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student not found!\n");
            }

            break;

        case 7: // Exit
            printf("Thank you for using the system.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
