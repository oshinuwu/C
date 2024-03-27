#include<stdio.h>
#include<conio.h>
int main()
{
	char sen1[200],sen2[200],sen3[300];
	printf("Enter any sentence\n");
	gets(sen1);
	printf("The senetence you entered is:");
	puts(sen1);
	fflush(stdin);
	printf("Enter a sentence,Hit RETURN to finish\n");
	scanf("%[^\n]s",&sen2);
	printf("%s",sen2);
	fflush(stdin);
	printf("\nEnter a sentence,Hit '+' to finish\n");
	scanf("%[^+]s",&sen3);
	printf("%s",sen3);
	printf("\nName=Oshin Pant\n Roll no=19\n Lab no=9");
    getch();
	return 0;
}