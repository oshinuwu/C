#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
	//using library function
	char string[100];
	printf("Enter string:");
	gets(string);
	strrev(string);
	
	printf("string after strrev with library function is %s\n",string);
	
	//without using library function
	char a[25];
	char b[25];
	int len=0, i,j;
	printf("Input the string to be reversed");
	gets(a);
	
	
	for(i=0;a[i]!='\0';i++){
		len+=1;
	}
	for(i=len-1;i>=0;i--){
		b[j++]=a[i];
	}
	b[j++]='\0';
	printf("Reverse of string  without library function is %s",b);
	
	
	
	printf("\nName=Oshin Pant\n Rollno=19\n lab no=15");
    getch();
	return 0;
    }