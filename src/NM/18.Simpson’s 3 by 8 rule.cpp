/*Write a C program to find integration using Simpson’s 3/8 I rule
Algorithm for Simpson’s 3/8 Rule
Start
Read value of upper limit say x3
Read value of lower limit say x0
Set n=3
Computer h = (x3-x0)/n
Set x1 = x0+h
Set x2 = x0+2h
Compute f0 = f(x0), f1 = (x1), f2(x2), f3 = (x3)
Calculate the value of integration by using formula I = 3/8*[f0+3*f1+3*f2+f3]
Display value of “I”
Stop
………………………………………………….
C program for composite Simpson’s 3/8 rule
Write a C program to find integration using simpson 3/8 rule*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) sqrt(1-x*x);
int main()
{
	float x0,x1,x2,x3,h,I,f0,f1,f2,f3;	
	printf("Enter upper limit\n");
	scanf("%f",&x3);
	printf("Enter lower limit\n");
	scanf("%f",&x0);
	h = (x3-x0)/3;
	x1 = x0+h;
	x2 = x0+2*h;
	x3 = x0+3*h;	
	f0 = f(x0);
	f1 = f(x1);
	f2 = f(x2);
	f3 = f(x3);
	I  = 3*h*(f0+3*f1+3*f2+f3)/8;
 	printf("Integration =%f",I);
	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 18");
	return 0;
}
/*Output:
Enter upper limit
1
Enter lower limit
0
Integration =0.758062
*/
