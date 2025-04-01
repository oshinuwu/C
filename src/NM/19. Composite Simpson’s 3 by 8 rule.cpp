/*Write a C program to find integration using Composite Simpson’s 3/8 I rule

Algorithm for Composite Simpson 3/8 rule
Start
Read the value of lower limit and upper limit x0 and xn
Read the number of segments say k
Calculate h = (xn-x0)/k
Computer result = f(x0)+f(xn)
For i=1 to k-1
if(mod3!=0) 
result = result+3*f(x0+i*h)
else
result = result+2*f(x0+i*h)
End for
Calculate the value of integration by using formula v = 3/8*h*result
Stop
…………………………………………………*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)
int main()
{
	float x0,x1,xn,h,f0,fn,result,a,I;
	int k,i;	
	printf("Enter lower limit\n");
	scanf("%f",&x0);
	printf("Enter upper limit\n");
	scanf("%f",&xn);
	printf("Enter number of segments\n");
	scanf("%d",&k);
	h = (xn-x0)/k;
	f0  =f(x0);
	fn = f(xn);	
	result = f0+fn;
	for(i=1;i<=k-1;i++)
	{
		if(i%3!=0)
		{
			a = x0+i*h;
			result = result+3*f(a);
		}
		else
		{
			a = x0+i*h;
			result = result+2*f(a);
		}
	}
	
	I=  3*h*result/8;
 	printf("Integration =%f",I);
printf("\nName:Jenisha Pandit\nRollno:61\nLab no 19");
	return 0;
}
/*Output:
Enter lower limit
0
Enter upper limit
1
Enter number of segments
6

Integration =0.775806
*/
