//WAP to find derivative ofa  function using two point forward difference formula
#define F(x) (x*x+2*x+1)
#include<stdio.h>
int main(){
	float xi, h, d, f1,f2, x1;
	printf("Enter value of xi andh\n");
	scanf("%f%f",&xi, &h);
	f1=F(xi);
	x1=xi+h;
	f2=F(x1);
	d=(f2-f1)/h;
	printf("derivative is %f",d);
	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 6");
	return 0;
}
