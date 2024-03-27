#include<stdio.h>
#include<string.h>
int main(){
	//with using library function 
	char string[100];
	printf("Enter string");
	gets(string);
	strupr(string);
	printf("The string after strupr is %s \n",string);
	
	//without using library function
	char str[100];
	int i=0;
	printf("Enter a string ");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	str[i]-=32;
	printf("The string in uppercase  without library function is:");
	puts(str);
	
	
	//for lowercase with library function
	char a[100];
	printf("Enter another string");
	gets(a);
	strlwr(a);
	printf("The string after strlwr is %s\n",a);
	
	
	//for lowercase without library function 
	char c[100];
	
	printf("Enter a string ");
	gets(c);
	for(i=0;c[i]!='\0';i++)
	c[i]+=32;
	printf("The string in lowercase  without library function is:");
	puts(c);
	printf("\nName=Oshin Pant\n Rollno=19\n Labno=14");
    getch();
	return 0;
}