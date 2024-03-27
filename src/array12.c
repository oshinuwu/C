#include<stdio.h>
#include<conio.h>
#include<string.h>
int main (){
	//with library function
	char a[50],b[50];
	printf("Enter the first string");
	gets(a);
	printf("Enter the second string");
	gets(b);
	if(strcmp(a,b)==0)
	printf("\nEqual string");
	else if (strcmp(a,b)>0)
	printf("\nFirst string is greater");
	else
	printf("\nsecond string is greater");
	
	
	
	//with out using library function
	char c[25],d[15];
	int i,f=0;
	printf("\nEnter the first string without library function");
	gets(c);
	
	printf("Enter the second string without library function");
	gets(d);
	
for( i=0; c[i]!='\0'&&d[i]!='\0';i++){
	
	
	
	if(c[i]!=d[i]){
	     f=1;
		break;
		} 
	}
		if(f==1)
		printf("not equal string");
		else
		printf(" equal string");
		
		
		printf("\nName=Oshin Pant\n Rollno=19\n Lab no=12");

	getch();
	return 0;
}