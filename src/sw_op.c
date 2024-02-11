#include<stdio.h>
int main(){
	float r,s,res;
	char o;
	printf("Enter any two numbers");
	scanf("%f %f",&r,&s);
	printf("Enter any arithmetic operator:");
	scanf(" %c",&o);
	switch(o){
		case '+':
			res= r+s;
			break;
		case '-':
			res= r-s;
			break;
		case'*':
			res= r*s;
			break;
		case'%':
			int res=(int)r % (int) s;
			break;
		case'/':
			if(s!=0){
			res= r/s;
			}
		    else{
		    printf("Division by zero is invalid");	
			}
			break;
			default:
				printf("Enter a valid operator\n");
	}
	printf("The result of given arithmetic operator for %f and %f is %f\n",r,s,res);
	printf("Name:Oshin Pant\n Roll No:19\n Lab No:6");
    getch();
	return 0;
}