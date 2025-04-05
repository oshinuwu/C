/*Algorithm for Simpson�s 1/3 rule
Start
Read upper limit xn and lower limit x0
Set n=2
Compute h = (xn-x0)/n
Compute x1 = x0+h
Calculate I = h3*[f(x0)+4*f(x1)+f(x2)]
Print �I�
Stop

C program for Simpson�s 1/3 rule*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) 3*x*x+2*x-5
int main()
{
	float x0,x1,x2,f0,f2,f1,i,h,a,r;	
	printf("Enter lower limit\n");
	scanf ("%f",&x0);
	printf ("Enter upper limit\n");
	scanf ("%f",&x2);
  	  h = (x2-x0)/2;
    	x1 = x0+h;
    	f0 = f(x0);
    	f1 = f(x1);
    	f2 = f(x2);
	i = (f0+4*f1+f2)*h/3;
	printf("The value of integration =%f\n",i);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 16");
	getchar();
	getch();
	return 0;
}
/*Output:
Enter lower limit
0
Enter upper limit
2
The value of integration =2.000000*/

