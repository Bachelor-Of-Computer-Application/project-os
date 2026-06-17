#include<stdio.h>

typedef struct{
	int id;
	char name[30];
	float fine;
}student;

int main(){
	student s[5];

	int i,n;
	printf("Enter number of students:");
	scanf("%d",&n); 
	//Input
	for(i=0;i<n;i++){
		printf("\nstudent %d\n",i+1);
		
		printf("ID:");
		scanf("%d",&s[i].id);
		
		printf("Fine Amount:");
		scanf("%f",&s[i].fine);
		
	}
	//Display
	printf("\n-studnet fine Records-\n");
	printf("ID\tName\tFine\n");
	
	for(i=0;i<n;i++){
		printf("%d\t%s\t%.2f\n",s[i].id,s[i].name,s[i].fine);
		printf("\n STUDENT FINE MANAGEMENT SYSTEM");
		printf("\n1.Add student");
		printf("\n2.Display All students");
		printf("\n3.Search student");
		printf("\n4.Update fine");
		printf("\n5.Pay fine");
		printf("\n6.Delete student");
		printf("\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			printf("\nEnter Student ID:");
			scanf("%d",&s[n].id);

			printf("Enter Student Name:");
			scanf("%s",s[n].fine);

			printf("Enter fine amount:");
			scanf("%f",&s[n].fine);

			n++;

			printf("\nstudent Added successfully!\n");
			break;

			case 2:

			if (n==0){
				printf("\nNo records found!\n");
				break;
			}
			printf("\nID\tName\tFine\n");

			for(i=0;i<n;i++){
				printf("%d\t%s\t%.2f\n",s[i].id,s[i].name,s[i].fine);
			}
			break;

			case 3:

			printf("\nEnter student ID to search:");
			scanf("%d",&id);
			found=0;

			for(i=0;i<n;i++){
				if(s[i].id==id){
					printf("\nstudent found\n");
					printf("ID:%D\n",s[i].id);
					printf("Name:%S\n",s[i].name);
					printf("fine:%.2f\n",s[i].fine);
					found=1;
					break;
				}
			}
			if(found==0)
			printf("\nStudent not found!\n");

			break;

			case 4:

			printf("\nEnter Student ID:");
			scanf("%d",&id);

			found=0;

			for(i=0;i<n;i++){
				if(s[i].id==id){
					printf("Enter New fine amount:");
					scanf("%f",&s[i].fine);
					printf("Fine updated successfully!\n");
					found=1;
					break;
				}
			}

			if(found==0)
			printf("student not found!\n");

			braek;
			


		}
	}
	return 0;
}






