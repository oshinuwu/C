#include<stdio.h>
#include<string.h>
int main (){
	//with using library function
	char source[]="perfect";
	char target[50];
	strcpy(target,source);
	printf("The target string with using library function  is %s",target);
	//without using library function
	
	char s1[50],s2[50];
	int i;
	printf("\nEnter string");
	gets(s1);
	for(i=0;s1[i]!='\0';i++){
		s2[i]=s1[i];
	}
	s2[i]='\0';
	printf("The target string without using library function is %s",s2);
	
	printf("\nName=Oshin Pant\n Rollno=19\n Lab no=11");
    getch();
	return 0;
}