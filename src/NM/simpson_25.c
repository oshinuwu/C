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
	getch();
	return 0;
} 
