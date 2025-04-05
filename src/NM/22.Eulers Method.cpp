/*Write a C program to solve ordinary differential equation using Euler�s method

Algorithm for Euler �s Method
start
Read initial values of x and y say x0 and y0
Read the value at which functional value is required, say xp
Read the step size say h
Set y=y0 and x = x0
Compute the value of y as below
For x=x0 to xp
y = y+f(x,y)
y = x+h
End for
Display the functional value y
Stop


C program for Euler Method*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x,y) 2*y/x
int main()
{
	float x,xp,x0,y1,y,h,y0;
	printf("Enter initial values of x and y\n");
	scanf("%f%f",&x0,&y0);
	printf("Enter x at which function to be evaluated \n");
	scanf("%f",&xp);
	printf("Enter the step size\n");
	scanf("%f",&h);
	y = y0;
	x= x0;
	for(x=x0;x<xp;x = x+h)
	{
		y = y+f(x,y)*h;
	}
	printf ("Function value at x = %f is %f\n",xp,y);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 22");
	fflush(stdin);
	getchar();
	getchar();
	return 0;	
}
/*Output
Enter initial values of x and y
1 2
Enter x at which function to be evaluated
2
Enter the step size
0.25
Function value at x = 2.000000 is 7.200000*/

