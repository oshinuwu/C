#include<stdio.h>
#include<string.h>
int main (){
	//with using library function
	char str[100];
	int len;
	printf("Enter the string");
	gets(str);
	len=strlen(str);
	printf("Length of given string with library function is%d",len);
	// with out using library function
	char arr[]="A thousand things";
	int i=0;
	do{
		i++;
		
	}while(arr[i]!='\0');
	len=i;
	printf("\nThe length of string without library function is %d",len);
	printf("\nName=Oshin Pant\n Roll no=19\n Lab no=10");
    getch();
	return 0;
}