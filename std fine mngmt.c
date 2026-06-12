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
	}
	return 0;
}




int roll, days;
float fine;
printf (" Enter Roll number:");
scanf("%d",&roll);
printf( " Enter Late Days: ");
Scanf("%d, &days");
fine = days * 5;  // Rs.5 fine per day
printf("\nRoll Number: %d", roll);
printf(" \nLate Days:%d", days);
printf("\nTotal Fine: Rs.%.2f",fine);
return 0;
} 

