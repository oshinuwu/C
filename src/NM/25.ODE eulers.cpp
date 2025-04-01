/*Write a C program for solving system of ordinary differential equations using Euler’s method
Algorithm for Solving System of Two ODE’s
Start
Read initial values of x,y and z say x0, y0, and z
Read the value at which functional value is required say xp
Read step size say h
Set y = y0 and x =  x0
Compute value of y as below
For x =x0 to xp
ny = y+f(x,y,z)*h
nz = z+f(x,y,x)*h
y = ny
z = nz
End for
Display functional value y
Stop

C Program for solving system of ODE’s by using Euler’s method*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f1(x,y,z) z
#define f2(x,y,z) exp(-x)-2*(z)-(y)
int main()
{
	float x, xp, x0,y0,z0,y,z,ny,nz,h;
	printf("Enter initial value of x and y and z\n");
	scanf("%f%f%f",&x0,&y0,&z0);
	printf("Enter the value at which function is to be evaluated\n");
	scanf("%f",&xp);
	printf("Enter step size\n");
	scanf("%f",&h);
	y = y0;
	x = x0;
	z = z0;
	for(x=x0;x<xp;x=x+h)
	{
		ny = y+(f1(x,y,z))*h;
		nz = z+(f2(x,y,z))*h;
		y = ny;
		z = nz;
	}
	printf("Function value at x %f =%f",x,y);
	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 25");
	return 0;
}
/*Output:
Enter initial value of x and y and z
0 1 2
Enter the value at which function is to be evaluated
0.75
Enter step size
0.25
Function value at x 0.750000 =1.829925*/

