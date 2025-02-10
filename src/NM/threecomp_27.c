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
	getch();
	return 0;
}
