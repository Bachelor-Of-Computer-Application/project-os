#include <stdio.h>
#include <string.h>
#include <direct.h>

struct Student {
    int id;
    char name[30];
    float totalFine;
    float paidFine;
    float remainingFine;
};

void title() {
    printf("\n====================================================");
    printf("\n          STUDENT FINE MANAGEMENT SYSTEM");
    printf("\n====================================================");
    printf("\n              MINI PROJECT IN C");
    printf("\n----------------------------------------------------");
    printf("\n Developed By : Aastha and shital");
    printf("\n Purpose      : Manage Student Fine Records");
    printf("\n====================================================\n");
}

void saveToFile(struct Student s[], int n) {
    FILE *fp;
    int i;

    mkdir("StudentData");
    fp = fopen("StudentData/students.txt", "w");

    if(fp == NULL) return;

    fprintf(fp, "%d\n", n);

    for(i=0;i<n;i++) {
        fprintf(fp,"%d %s %.2f %.2f %.2f\n",
                s[i].id,s[i].name,s[i].totalFine,
                s[i].paidFine,s[i].remainingFine);
    }
    fclose(fp);
}

int loadFromFile(struct Student s[]) {
    FILE *fp;
    int n=0,i;

    fp=fopen("StudentData/students.txt","r");
    if(fp==NULL) return 0;

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++) {
        fscanf(fp,"%d %s %f %f %f",
               &s[i].id,s[i].name,
               &s[i].totalFine,
               &s[i].paidFine,
               &s[i].remainingFine);
    }
    fclose(fp);
    return n;
}

int login() {
    char username[20], password[20];

    printf("\n============= LOGIN SYSTEM =============\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if(strcmp(username,"admin")==0 &&
       strcmp(password,"1234")==0) {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");
    return 0;
}

int main() {
    struct Student s[100];
    int n = loadFromFile(s);
    int choice, i, id, found;
    float amount;

    title();

    if(login()==0)
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
        scanf("%d",&choice);

        switch(choice) {

        case 1:
            printf("\nEnter Student ID: ");
            scanf("%d",&id);

            found=0;
            for(i=0;i<n;i++) {
                if(s[i].id==id) {
                    found=1;
                    break;
                }
            }

            if(found) {
                printf("Student ID already exists!\n");
                break;
            }

            s[n].id=id;

            printf("Enter Student Name: ");
            scanf("%s",s[n].name);

            printf("Enter Total Fine Amount: ");
            scanf("%f",&s[n].totalFine);

            s[n].paidFine=0;
            s[n].remainingFine=s[n].totalFine;

            n++;
            saveToFile(s,n);

            printf("\nStudent Added Successfully!\n");
            break;

        case 2:
            if(n==0) {
                printf("\nNo Records Found!\n");
                break;
            }

            printf("\n--------------------------------------------------------");
            printf("\nID\tName\tTotal\tPaid\tRemaining");
            printf("\n--------------------------------------------------------\n");

            for(i=0;i<n;i++) {
                printf("%d\t%s\t%.2f\t%.2f\t%.2f\n",
                       s[i].id,s[i].name,
                       s[i].totalFine,
                       s[i].paidFine,
                       s[i].remainingFine);
            }
            break;

        case 3:
            printf("\nEnter Student ID to Search: ");
            scanf("%d",&id);

            found=0;

            for(i=0;i<n;i++) {
                if(s[i].id==id) {
                    printf("\nStudent Found");
                    printf("\nID : %d",s[i].id);
                    printf("\nName : %s",s[i].name);
                    printf("\nTotal Fine : %.2f",s[i].totalFine);
                    printf("\nPaid Fine : %.2f",s[i].paidFine);
                    printf("\nRemaining Fine : %.2f\n",s[i].remainingFine);

                    found=1;
                    break;
                }
            }

            if(found==0)
                printf("\nStudent Not Found!\n");

            break;

        case 4:
            printf("\nEnter Student ID: ");
            scanf("%d",&id);

            found=0;

            for(i=0;i<n;i++) {
                if(s[i].id==id) {
                    printf("Enter New Total Fine Amount: ");
                    scanf("%f",&s[i].totalFine);

                    s[i].remainingFine=s[i].totalFine-s[i].paidFine;

                    saveToFile(s,n);

                    printf("Fine Updated Successfully!\n");

                    found=1;
                    break;
                }
            }

            if(found==0)
                printf("Student Not Found!\n");

            break;

        case 5:
            printf("\nEnter Student ID: ");
            scanf("%d",&id);

            found=0;

            for(i=0;i<n;i++) {
                if(s[i].id==id) {

                    printf("Remaining Fine = %.2f\n",s[i].remainingFine);

                    printf("Enter Payment Amount: ");
                    scanf("%f",&amount);

                    if(amount>s[i].remainingFine) {
                        printf("Payment exceeds remaining fine!\n");
                        found=1;
                        break;
                    }

                    s[i].paidFine+=amount;
                    s[i].remainingFine=s[i].totalFine-s[i].paidFine;

                    saveToFile(s,n);

                    printf("Payment Successful!\n");
                    printf("Paid Fine = %.2f\n",s[i].paidFine);
                    printf("Remaining Fine = %.2f\n",s[i].remainingFine);

                    found=1;
                    break;
                }
            }

            if(found==0)
                printf("Student Not Found!\n");

            break;

        case 6:
            printf("\nEnter Student ID to Delete: ");
            scanf("%d",&id);

            found=0;

            for(i=0;i<n;i++) {
                if(s[i].id==id) {

                    int j;

                    for(j=i;j<n-1;j++) {
                        s[j]=s[j+1];
                    }

                    n--;
                    saveToFile(s,n);

                    printf("Record Deleted Successfully!\n");

                    found=1;
                    break;
                }
            }

            if(found==0)
                printf("Student Not Found!\n");

            break;

        case 7:
            printf("\nTotal Students = %d\n",n);
            break;

        case 8:
        {
            float totalRemaining=0;

            for(i=0;i<n;i++) {
                totalRemaining+=s[i].remainingFine;
            }

            printf("\n========== FINE REPORT ==========\n");
            printf("Total Students : %d\n",n);
            printf("Total Outstanding Fine : %.2f\n",totalRemaining);
            break;
        }

        case 9:
            saveToFile(s,n);
            printf("\nData Saved Successfully.\n");
            printf("\nThank You For Using Student Fine Management System.\n");
            return 0;

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
