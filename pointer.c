#include<stdio.h>
int main( )
{
	char text[ 20];
	FILE *fp;
	fp=fopen(" BCA. txt","r" );
	if(fp==NULL)
	
	
	fgets( text,20,fp);
	if( strcmp ( text, " shital")==0)
	{
		printf( " Hi, i am %s", text);
		
	}
	
	else
	{
		printf( "comparision fall");
		
	}
	fclose( fp);
}
