
#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    char reason[100];
    float totalFine;
    float paidAmount;
    float remainingFine;
};

void title() {
    printf("\n====================================================");
    printf("\n          STUDENT FINE MANAGEMENT SYSTEM");
    printf("\n====================================================");
    printf("\n              MINI PROJECT IN C");
    printf("\n----------------------------------------------------");
    printf("\n Developed By : Aastha and Shital");
    printf("\n Admin Login Required");
    printf("\n====================================================\n");
}

int login() {
    char username[20], password[20];

    printf("\n============= LOGIN SYSTEM =============\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "1234") == 0) {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");
    return 0;
}

int main() {

    struct Student s[100];
    int n = 0;
    int choice, i, id, found;
    float amount;

    title();

    if(login() == 0)
        return 0;

    while(1) {

        printf("\n=================================");
        printf("\n STUDENT FINE MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Update Fine");
        printf("\n5. Pay Fine");
        printf("\n6. Delete Student");
        printf("\n7. Total Students");
        printf("\n8. Fine Report");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:

            printf("\nEnter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {
                if(s[i].id == id) {
                    found = 1;
                    break;
                }
            }

            if(found) {
                printf("Student ID already exists!\n");
                break;
            }

            s[n].id = id;

            printf("Enter Student Name: ");
            scanf("%s", s[n].name);

            printf("Enter Reason for Fine: ");
            scanf(" %[^\n]", s[n].reason);

            printf("Enter Total Fine Amount: ");
            scanf("%f", &s[n].totalFine);

            s[n].paidAmount = 0;
            s[n].remainingFine = s[n].totalFine;

            n++;

            printf("\nStudent Added Successfully!\n");
            break;

        case 2:

            if(n == 0) {
                printf("\nNo Records Found!\n");
                break;
            }

            printf("\n--------------------------------------------------------------------------------");
            printf("\nID\tName\tReason\t\tTotal\tPaid\tRemaining");
            printf("\n--------------------------------------------------------------------------------\n");

            for(i = 0; i < n; i++) {
                printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\n",
                       s[i].id,
                       s[i].name,
                       s[i].reason,
                       s[i].totalFine,
                       s[i].paidAmount,
                       s[i].remainingFine);
            }

            break;

        case 3:

            printf("\nEnter Student ID to Search: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {

                if(s[i].id == id) {

                    printf("\nStudent Found\n");
                    printf("ID              : %d\n", s[i].id);
                    printf("Name            : %s\n", s[i].name);
                    printf("Reason for Fine : %s\n", s[i].reason);
                    printf("Total Fine      : %.2f\n", s[i].totalFine);
                    printf("Paid Amount     : %.2f\n", s[i].paidAmount);
                    printf("Remaining Fine  : %.2f\n", s[i].remainingFine);

                    if(s[i].remainingFine == 0)
                        printf("Status          : Fully Paid\n");
                    else
                        printf("Status          : Unpaid/Partial Paid\n");

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");

            break;

        case 4:

            printf("\nEnter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {

                if(s[i].id == id) {

                    printf("Enter New Total Fine Amount: ");
                    scanf("%f", &s[i].totalFine);

                    s[i].remainingFine =
                        s[i].totalFine - s[i].paidAmount;

                    printf("Fine Updated Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");

            break;

        case 5:

            printf("\nEnter Student ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {

                if(s[i].id == id) {

                    printf("\nTotal Fine      : %.2f\n",
                           s[i].totalFine);
                    printf("Paid Amount     : %.2f\n",
                           s[i].paidAmount);
                    printf("Remaining Fine  : %.2f\n",
                           s[i].remainingFine);

                    printf("Enter Payment Amount: ");
                    scanf("%f", &amount);

                    if(amount > s[i].remainingFine) {
                        printf("Payment exceeds remaining fine!\n");
                        break;
                    }

                    s[i].paidAmount += amount;
                    s[i].remainingFine -= amount;

                    printf("\nPayment Successful!\n");
                    printf("Paid Amount     : %.2f\n",
                           s[i].paidAmount);
                    printf("Remaining Fine  : %.2f\n",
                           s[i].remainingFine);

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");

            break;

        case 6:

            printf("\nEnter Student ID to Delete: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++) {

                if(s[i].id == id) {

                    int j;

                    for(j = i; j < n - 1; j++) {
                        s[j] = s[j + 1];
                    }

                    n--;

                    printf("Record Deleted Successfully!\n");

                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");

            break;

        case 7:

            printf("\nTotal Students = %d\n", n);
            break;

        case 8: {

            float totalOutstanding = 0;
            float totalPaid = 0;

            for(i = 0; i < n; i++) {
                totalOutstanding += s[i].remainingFine;
                totalPaid += s[i].paidAmount;
            }

            printf("\n========== FINE REPORT ==========\n");
            printf("Total Students        : %d\n", n);
            printf("Total Fine Collected  : %.2f\n",
                   totalPaid);
            printf("Outstanding Fine      : %.2f\n",
                   totalOutstanding);

            break;
        }

        case 9:

            printf("\nThank You For Using Student Fine Management System.\n");
            return 0;

        default:

            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

