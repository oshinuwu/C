#include<stdio.h>
#include<string.h>
int main(){
	//with using library function
	char a[]="pigs don't fly";
	char b[]="birds do";
	printf("a=%s\nb=%s\n",a,b);
	printf("\nstrcat(a,b)=%s\n", strcat(a,b));
	
	//without library function
	char str1[50];
	char str2[50];
	
	int i=0,j=0;
	printf("Enter the first string");
	gets(str1);
	printf("Enter the second string");
	gets(str2);
	
	while( str1[i]!='\0'){
	
		i++;
	}
	while(str2[j]!='\0'){
		str1[i]=str2[j];
		i++;
		j++;
	}
	str1[i]='\0';
	printf("\nconcatenated string is %s",str1);
	

	printf("\nName=Oshin Pant\n Rollno=19\n Lab no=13");
    getch();
	return 0;
	
}