/*write a C program to find integration using Composite Simpson�s 1/3 l rule
Algorithm for Composite Simpson�s 1/3 rule
Start
Read value of upper limit xn and value lower limit x0
Read number of segments say k
Calculate h = (xn-x0)/k
Set result = f(x0)+f(xn)
For i-1 to k-1
Set result = result+4*f(x0+i*h)
		i = i+2
For i=2 to k-2
Set result =  result+2*f(x0+i*h)
	i= i+2
Calculate the value of integration by using formula I = h3*result
Display the value of integration �I�
Stop
C program for composite Simpson�s1/3 rule*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)
int main()
{
	float x0,x1,xn,f0,fn,f1,h,a,result,I;
	int i,k;	
	printf("Enter lower limit\n");
	scanf("%f",&x0);
	printf("Enter upper limit\n");
	scanf("%f",&xn);
	printf("Enter number of segments\n");
	scanf("%d",&k);
    h = (xn-x0)/k;
    x1 = x0+h;
    f0 = f(x0);
    fn = f(xn);
    result = f0+fn;
    for(i=1;i<=k-1;i=i+2)
    {
    	a =x0+i*h;
    	result = result+4*f(a);
	}
	for(i=2;i<=k-2;i=i+2)
    {
    	a =x0+i*h;
    	result = result+2*f(a);
	}
	I =  h*result/3;
	printf("The value of integration =%f\n",I);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 17");
	fflush(stdin);
	getchar();
	getchar();
	return 0;
} 

/*Output:
Enter lower limit
0
Enter upper limit
1
Enter number of segments
4
The value of integration =0.770899

*/
