/*Write a C program to solve ordinary differential equation using Runge Kutta method
Algorithm
start
Read initial values x and y say x0 and y0
Read the value at which functional value is required say xp
Read step size say h
Set x  =x0 y=y0
Compute values of y(xp) as below
For x= x0 to xp
	m1 = f(x,y)
	m2 = f(x+h/2,y+h/2*m1)
	m3 = f(x+h/2,y+h/2*m2)
	m4 = f(x+h, y+h*m3)
	y = y+16*h(m1+2m2+2m3+m4)End for
Display functional value y
stop

C program*/
#include<stdio.h>
#include<conio.h>
#define f(x,y) 2*(y)/(x)
int main()
{
	float x, xp, x0,y0, y,h,m1,m2,m3,m4;
	printf("Enter initial value of x and y\n");
	scanf("%f%f",&x0,&y0);
	printf("Enter the value at which function is to be evaluated\n");
	scanf("%f",&xp);
	printf("Enter step size\n");
	scanf("%f",&h);
	y = y0;
	x = x0;
	for(x=x0;x<xp;x=x+h)
	{
		m1 = f(x,y);
		m2 = f(x+1/2.0*h,y+1/2.0*h*m1);
		m3 = f(x+1/2.0*h,y+1/2.0*h*m2);
		m4 = f(x+h,y+h*m3);
		y = y+(m1+2*m2+2*m2+m4)*h/6;
	}
	printf("Function value at x %f =%f",x,y);
		printf("\nName:Jenisha Pandit\nRollno:61\nLab no 24");
	return 0;
}
/*Output:
Enter initial value of x and y
1 2
Enter the value at which function is to be evaluated
2
Enter step size
0.25
Function value at x 2.000000 =7.952565*/

