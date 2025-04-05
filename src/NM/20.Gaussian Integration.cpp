/*Write a C program to find integral value by using Gaussian Integration
Algorithm for Gaussian Integration
Start
Read value of lower and upper bound say a and b
Set w1 = w2 =1, z1 = -0.57735, z2 = 0.57735
Compute x1 = (b-a)2z1+(b-a)2
x1 = b-a2z1+b-a2
Compute v = x1 = (b-a)2{f(x1)+f(x2)}
Display �v�
Stop
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x*x+1
int main()
{
	float a,b,z1,z2,c1,c2,x1,x2,v;
	printf("Enter lower limit\n");
	scanf("%f",&a);
	printf("Enter upper limit\n");
	scanf("%f",&b);
	c1=c2=1;
	z1 = -0.57735;
	z2 = 0.57735;
	x1 = (b-a)/2*z1+(b+a)/2;
	x2 = (b-a)/2*z2+(b+a)/2;
	v = (b-a)/2*((f(x1))+f(x2));
	printf("Value of integration =%f",v);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 20");
	fflush(stdin);
	getchar();
	getchar();
	return 0;
}
/*Output:
Enter lower limit
2
Enter upper limit
4
Value of integration =61.999996
*/

