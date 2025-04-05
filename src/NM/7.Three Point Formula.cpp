//WAP to find derivative ofa  function using three point formula
#define F(x) (3*x*x+5*x+1)
#include<stdio.h>
int main(){
	float xi, h, d, f1,f2, x1, x2;
	printf("Enter value of xi andh\n");
	scanf("%f%f",&xi, &h);
	x1=xi+h;
	x2=xi-h;
	f1=F(x1);
	f2=F(x2);
	d=(f1-f2)/(2*h);
	printf("derivative by using three point difference formula is %f",d);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 7");
	fflush(stdin);
	getchar();
	getchar();
	return 0;
}

