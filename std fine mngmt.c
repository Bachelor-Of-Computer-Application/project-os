#include<stdio.h>

typedef struct{
	int id;
	char name[30];
	float fine;
} student;

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
	}
	return 0;
}

